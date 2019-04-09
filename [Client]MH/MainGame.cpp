// MainGame.cpp: implementation of the CMainGame class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainGame.h"
#include "MainTitle.h"
#include "Intro.h"	// magi82 - Intro(070712)
#include "ServerConnect.h"
#include "CharSelect.h"
#include "CharMake.h"
#include "GameLoading.h"
#include "GameIn.h"
#include "MapChange.h"
#include "MurimNet.h"
#include "MHTimeManager.h"
#include "mhnetwork.h"
#include "./Engine/Engine.h"
#include "./Interface/cResourceManager.h"
#include "./Interface/cWindowManager.h"

#include "../[CC]Header/GameResourceManager.h"
#include "AppearanceManager.h"
#include "ObjectManager.h"
#include "OptionManager.h"

#include "StringLoader.h"
#include "MovePoint.h"
#include "./Input/cIMEWnd.h"
#include "./Audio/MHAudioManager.h"

#include "mhMap.h"
#include "./Input/UserInput.h"

#include "CQuestManager.h"
#include "MacroManager.h"
#include "MixManager.h"
#include "NpcScriptManager.h"
#include "HelpDicManager.h"

#include "AbilityManager.h"
#include "CheatMsgparser.h"

#include "MouseCursor.h"
#include "ChatManager.h"
//050630SW
#include "cChatTipManager.h"
//-
#include "ReinforceManager.h"
#ifdef _GMTOOL_
#include "GMToolManager.h"
#endif

#include "GuildManager.h"
#include "SkillDelayManager.h"

#ifdef _DEBUG
#include "MiniDumper.h"
#endif // _DEBUG


#ifdef TAIWAN_LOCAL
#include "BillingManager.h"
#endif


#ifndef _RESOURCE_WORK_NOT_APPLY_
#include "./Engine/EngineObject.h"
#include "./Engine/EngineObjectCache.h"
#endif

#include "cScriptManager.h"

#define MAX_PROFILE_NUM 6


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//DWORD _stdcall BeforeRenderFunc();
//DWORD _stdcall AfterRenderFunc();
GLOBALTON(CMainGame);
CMainGame* pTempMainGame = NULL;
HWND gHwnd = NULL;



CMainGame::CMainGame()
{
	ASSERT(!pTempMainGame);

	m_bChangeState = FALSE;
	m_ChangeState = -1;
	m_ppGameState = NULL;
	m_pCurrentGameState = NULL;
	m_pEngine = NULL;
	m_bEndGame = FALSE;
	m_pStateInitParam = NULL;

	pTempMainGame = this;
	m_nUserLevel = eUSERLEVEL_USER;	
}

CMainGame::~CMainGame()
{
//	Release();		//PJH ���⼭ �����ϸ� �ι� Release�ϰ� �ȴ�
}

void CMainGame::Init(HWND hMainWnd)
{
	srand( GetTickCount() );

#ifndef _HACK_SHIELD_
	DIRECTORYMGR->Init();
#endif

	DIRECTORYMGR->SetLoadMode(eLM_EffectScript);
	LoadEffectFileTable("list_m.befl");
	DIRECTORYMGR->SetLoadMode(eLM_Root);
	
	m_pEngine = new CEngine;
	m_pEngine->Init(hMainWnd,&GAMERESRCMNGR->m_GameDesc.dispInfo,
		GAMERESRCMNGR->m_GameDesc.MaxShadowNum,GAMERESRCMNGR->m_GameDesc.MaxShadowTexDetail,0,
		GAMERESRCMNGR->m_GameDesc.FramePerSec);

	RESRCMGR->Init(FILE_IMAGE_PATH, FILE_IMAGE_MSG);

	SCRIPTMGR->InitParseTypeData();  //2007. 5. 21. CBH - Parse Type List �ʱ�ȭ �߰� (WindowManager�� �̱��� �α����� ����.)

	NETWORK->Init(hMainWnd);

	//interface : window manager
	WINDOWMGR->Init();	//��Ʈ, �޼����ڽ� �ʱ�ȭ

	gHwnd = hMainWnd;
	STRINGLOADER->Init(".\\Resource\\string.mhs");

//KES 030828 �����ο��� �Űܿ�
	OPTIONMGR->Init();			//�ɼ� �޴���, ä�ø޴����� ���ʿ�?//***
	OPTIONMGR->ApplySettings();	//***
	
	LOGFILE("MACROMGR->Init()");
	MACROMGR->Init();									//ó������ �ε��ø�
	MIXMGR->LoadMixList();

	REINFORCEMGR->LoadReinforceItemInfo();
	REINFORCEMGR->LoadRareReinnforceItemInfo();


	// LBS Npc���� Help���� �ε�
	LOGFILE("NPCSCRIPTMGR->Init()");
	NPCSCRIPTMGR->Init();
	LOGFILE("HELPDICMGR->Init()");
	HELPDICMGR->Init();
//------------

	//�����ϸ� ���尡 �ȳ����⸸ �ؾ��Ѵ�.
	AUDIOMGR->Initialize( hMainWnd );
	


//	if( !AUDIOMGR->Initialize( hMainWnd ) )
//		WINDOWMGR->MsgBox( MBI_VERCHKERROR, 1, "���� ī�带 Ȯ���ϼ���!!" );

	//�������ʾ�Ĺ��ָʾ
	MOVEPOINT->Init();

//DirectInput�ʱ�ȭ
	g_UserInput.Init();

//guild resource & guild mark init
	GUILDMGR->Init();
	
//0604SW
	CHATTIPMGR->Init();

// EVENT
//	CHEATMGR->LoadItem();

	SKILLDELAYMGR->LoadSkillUseInfo();
	
#ifdef TAIWAN_LOCAL
	BILLINGMGR->Init();
#endif
	

#ifndef _RESOURCE_WORK_NOT_APPLY_
	
	g_pEngineObjectCache = new CEngineObjectCache;
	g_pEngineObjectCache->Init(g_pExecutive, CEngineObjectCache::MAX_ENGINE_OBJECT_CACHE_SIZE);

#endif

#ifdef _DEBUG
	MiniDumper md(MiniDumper::DUMP_LEVEL_0);
#endif // _DEBUG

}



void CMainGame::Release()
{
	MOVEPOINT->Release();

	if(m_pCurrentGameState)
	{
		m_pCurrentGameState->Release(NULL);
		m_pCurrentGameState = NULL;
	}

//0604SW
	CHATTIPMGR->Release();

	EFFECTMGR->Release();
	
	WINDOWMGR->Release();
	RESRCMGR->Release();
	NETWORK->Release();
	
//	MAP->Release();



	SAFE_DELETE_ARRAY(m_pStateInitParam);
//	SAFE_DELETE(gMp3);

	AUDIOMGR->Terminate();

//DirectInputRelease
	g_UserInput.Release();

	CURSOR->Release();

//guild resource & guild mark init
	GUILDMGR->Release();


#ifndef _RESOURCE_WORK_NOT_APPLY_
	
	g_pEngineObjectCache->Release();
	delete g_pEngineObjectCache;
	g_pEngineObjectCache = NULL;

#endif


//------�� ���߿� �ϴ°��� ����.
	if(m_pEngine)
	{
		m_pEngine->Release();
		delete m_pEngine;
		m_pEngine = NULL;
	}
}

void CMainGame::SetGameState(int StateNum,void* pStateInitParam,int ParamLen)
{
	m_bChangeState = TRUE;
	m_ChangeState = StateNum;
	if(m_ChangeState == eGAMESTATE_END)
	{
		m_bEndGame = TRUE;
#ifdef _GMTOOL_
	GMTOOLMGR->DestroyGMDialog();
#endif
	}

	//ASSERT(m_pStateInitParam == NULL);
	if(pStateInitParam && ParamLen)
	{ 
		m_pStateInitParam = new char[ParamLen];
		memcpy(m_pStateInitParam,pStateInitParam,ParamLen);
	}
}

extern BOOL g_bActiveApp;
int CMainGame::Process()
{
	if(g_bActiveApp == FALSE)
		Sleep( 10 );

	Sleep(1);		//������ ���ִ� ���콺�� �� �ȿ����̳�.. 1�̶� ����.

	if(m_bEndGame)
	{
//		if(m_pCurrentGameState)
//		{
//			m_pCurrentGameState->Release(GetGameState(m_ChangeState));
//			m_pCurrentGameState->SetBlock(TRUE);
//		}
		Release();
		return -1;
	}

	BeforeRenderFunc();
	BOOL rt = m_pEngine->BeginProcess(NULL,AfterRenderFunc);	//���ϰ��� ������ �������̴�. --;
	if(rt)
	{
		if(m_pCurrentGameState)
		{
			if(m_pCurrentGameState->IsBlock() == FALSE)
			{
				MHTIMEMGR->Process();
				//Input Process
				g_UserInput.Process();
				
				//Window Process
				WINDOWMGR->Process();
				
				m_pCurrentGameState->Process();
			}
#ifdef TAIWAN_LOCAL
			BILLINGMGR->Process();	//////
#endif

			AUDIOMGR->Process();
		}
	}

	//YH2DO �ӽ� �ϵ��ڵ�
	if(m_pCurrentGameState == GAMEIN && GAMEIN->IsGameInAcked() == FALSE)
	{
		g_pExecutive->GetRenderer()->BeginRender(0,0,0);
		g_pExecutive->GetRenderer()->EndRender();
	}

	m_pEngine->EndProcess();
	
	if(m_bChangeState)
	{
		if(m_pCurrentGameState)
		{
			m_pCurrentGameState->Release(GetGameState(m_ChangeState));
			m_pCurrentGameState->SetBlock(FALSE);
		}
		
		m_pCurrentGameState = GetGameState(m_ChangeState);

		if(!m_pCurrentGameState)		// ����
		{
			Release(); //KES 030827 �߰�
//			GAMEIN->ReleaseForGame();

			return -1;
		}

		m_nCurStateNum = m_ChangeState; //KES 030827 �߰�
		CIMEWND->SetDockingEx( NULL, TRUE ); //KES �߰�.
	}

	// ���μ��� �߿� GXObject�� ����ų� �ϸ� ������ ���⶧���� ���⿡ �־� ��
	// ����� ���� �ٲ��� ����!!!

#ifndef _RESOURCE_WORK_NOT_APPLY_
	APPEARANCEMGR->ProcessReservation();
	APPEARANCEMGR->ProcessAlphaAppearance();	
#endif

	APPEARANCEMGR->ProcessAppearance();
	OBJECTMGR->ProcessGarbage();

#ifndef _RESOURCE_WORK_NOT_APPLY_

	g_pEngineObjectCache->ProcessCacheDelete();

#endif


	if(m_bChangeState)
	{
		m_pCurrentGameState->SetBlock(FALSE);
		if( m_pCurrentGameState->Init(m_pStateInitParam) == FALSE )
		{
//			MessageBox(0,"Cannot initialize GameState ",0,0);// pjslocal [5/29/2003]
//			m_pCurrentGameState = NULL;
//			SAFE_DELETE_ARRAY(m_pStateInitParam);
//			Release(); // MainGame�� ���� Release�� ����� �Ѵ�. LBS 03.11. 26
//			return -1;

			if( m_nCurStateNum == eGAMESTATE_TITLE )	//maintitle���ӺҴ�(distribute������)
			{
				m_pCurrentGameState->SetBlock( FALSE );
				TITLE->OnLoginError( LOGIN_ERROR_NODISTRIBUTESERVER, 0 );
			}
			else if(m_nCurStateNum == eGAMESTATE_INTRO)
			{
                MAINGAME->SetGameState(eGAMESTATE_CONNECT);
				return 0;
			}
			else
			{
				MessageBox( 0, CHATMGR->GetChatMsg(444), 0, 0 );
				SAFE_DELETE_ARRAY(m_pStateInitParam);
				Release(); // MainGame�� ���� Release�� ����� �Ѵ�. LBS 03.11. 26
//				GAMEIN->ReleaseForGame();
				//�����̶�� relaseforgame();
				return -1;				
			}
		}

		SAFE_DELETE_ARRAY(m_pStateInitParam);

		m_bChangeState = FALSE;
	}
	
	return 0;

}

void CMainGame::BeforeRender()
{
	if(m_pCurrentGameState)
		m_pCurrentGameState->BeforeRender();
}


void CMainGame::AfterRender()
{
	if(m_pCurrentGameState)
		m_pCurrentGameState->AfterRender();
}


void CMainGame::PauseRender( BOOL bPause )
{
	m_pEngine->PauseRender( bPause);
}

CGameState* CMainGame::GetGameState(int StateNum)
{
	CGameState* pState=NULL;
	switch(StateNum) 
	{
	case eGAMESTATE_INTRO:	// magi82 - Intro(070712)
		pState = INTRO;
		break;
	case eGAMESTATE_CONNECT:
		pState = SERVERCONNECT;
		break;
	case eGAMESTATE_TITLE:
		pState = TITLE;
		break;
	case eGAMESTATE_CHARSELECT:
		pState = CHARSELECT;
		break;
	case eGAMESTATE_CHARMAKE:
		pState = CHARMAKE;
		break;
	case eGAMESTATE_GAMELOADING:
		pState = GAMELOADING;
		break;
	case eGAMESTATE_GAMEIN:
		pState = GAMEIN;
		break;
	case eGAMESTATE_MAPCHANGE:
		pState = MAPCHANGE;
		break;
	case eGAMESTATE_MURIMNET:
		pState = MURIMNET;
		break;
	case eGAMESTATE_END:
		pState = NULL;
		break; 
	default:
		break;
	}
	return pState;
}


DWORD _stdcall BeforeRenderFunc()
{
	pTempMainGame->BeforeRender();
	return 0;
}

DWORD _stdcall AfterRenderFunc()
{
	pTempMainGame->AfterRender();
	return 0;
}
DWORD _stdcall AfterRenderFunc__()
{
	WINDOWMGR->Render();
	return 0;
}


DWORD __stdcall MapLoadCallback(DWORD dwCurCount,DWORD dwTotalCount,void* pArg)
{

	// dwCurCount �� ���� �ݹ�ī��Ʈ�̴�.0���� �����Ѵ�.
	// dwTotalCount�� �� �ݹ� ī��Ʈ �����̴�.
	// ex)
	//	if (dwCurCount+1 >= dwTotalCount)
	//		Message(�ε� �Ϸ�);


	// ���� ���μ����� ����.
	//g_v2Scale.x += 0.01f;


	g_pExecutive->Run(0xff000000,NULL,AfterRenderFunc__,0);

//	WINDOWMGR->Process();

	// ȭ�鿡 �Ѹ���.
	g_pExecutive->GetGeometry()->Present(NULL);
	
	return 0;
}
