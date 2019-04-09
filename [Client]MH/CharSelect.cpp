// CharSelect.cpp: implementation of the CCharSelect class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CharSelect.h"
#include "MainGame.h"
#include "MainTitle.h"
#include "cWindowSystemFunc.h"
#include "WindowIDEnum.h"
#include "./interface/cWindowManager.h"
#include "./Interface/cPushupButton.h"
#include "./Interface/cResourceManager.h"
#include "ObjectManager.h"
#include "MHTimeManager.h"
#include "ChatManager.h"
#include "OptionManager.h"
#include "MHMap.h"
#include "MHCamera.h"
#include "./Interface/cScriptManager.h"
#include "GameResourceManager.h"

#include "cMsgBox.h"
#include "./Input/UserInput.h"

//#include "Gamein.h"
#include "GMNotifyManager.h"
//#include "EventNotifyDialog.h"

#ifdef TAIWAN_LOCAL
#include "BillingManager.h"
#endif


#define CHARSELECT_STAND_POSX	27930
#define CHARSELECT_STAND_POSZ	7834
#define CHARSELECT_STAND_GAP	145
#define CHARSELECT_STAND_HEIGHT	100


#ifdef _JAPAN_LOCAL_

#define _MAX_CHARACTER_NUM 5

const VECTOR3 c_MAN_STAND_POS[_MAX_CHARACTER_NUM] = 
{ 
	{ 1969.792f, 0.0f, 1863.346f },
	{ 2077.243f, 0.0f, 1702.041f },
	{ 2274.891f, 0.0f, 1709.814f },
	{ 2321.619f, 0.0f, 1564.172f }, 
	{ 2096.065f, 0.0f, 2087.791f }
};

const VECTOR3 c_WOMAN_STAND_POS[_MAX_CHARACTER_NUM] = 
{		
	{ 1969.792f, 0.0f, 1863.346f },
	{ 2077.243f, 0.0f, 1702.041f },
	{ 2274.891f, 0.0f, 1709.814f },
	{ 2321.619f, 0.0f, 1564.172f },
	{ 2096.065f, 0.0f, 2087.791f }
};

#elif defined _HK_LOCAL_

#define _MAX_CHARACTER_NUM 5

const VECTOR3 c_MAN_STAND_POS[_MAX_CHARACTER_NUM] = 
{ 
	{ 1969.792f, 0.0f, 1863.346f },
	{ 2077.243f, 0.0f, 1702.041f },
	{ 2274.891f, 0.0f, 1709.814f },
	{ 2321.619f, 0.0f, 1564.172f }, 
	{ 2096.065f, 0.0f, 2087.791f }
};

const VECTOR3 c_WOMAN_STAND_POS[_MAX_CHARACTER_NUM] = 
{		
	{ 1969.792f, 0.0f, 1863.346f },
	{ 2077.243f, 0.0f, 1702.041f },
	{ 2274.891f, 0.0f, 1709.814f },
	{ 2321.619f, 0.0f, 1564.172f },
	{ 2096.065f, 0.0f, 2087.791f }
};

#elif defined _TL_LOCAL_

#define _MAX_CHARACTER_NUM 5

const VECTOR3 c_MAN_STAND_POS[_MAX_CHARACTER_NUM] = 
{ 
	{ 1969.792f, 0.0f, 1863.346f },
	{ 2077.243f, 0.0f, 1702.041f },
	{ 2274.891f, 0.0f, 1709.814f },
	{ 2321.619f, 0.0f, 1564.172f }, 
//	{ 2321.619f, 0.0f, 1564.172f },
	{ 2096.065f, 0.0f, 2087.791f }
};

const VECTOR3 c_WOMAN_STAND_POS[_MAX_CHARACTER_NUM] = 
{		
	{ 1969.792f, 0.0f, 1863.346f },
	{ 2077.243f, 0.0f, 1702.041f },
	{ 2274.891f, 0.0f, 1709.814f },
	{ 2321.619f, 0.0f, 1564.172f },
	{ 2096.065f, 0.0f, 2087.791f }
};

#else

#define _MAX_CHARACTER_NUM 4
/*
const VECTOR3 c_MAN_STAND_POS[_MAX_CHARACTER_NUM] = 
{ 
	{ 1969.792f, 0.0f, 1863.346f },
	{ 2077.243f, 0.0f, 1702.041f },
	{ 2274.891f, 0.0f, 1709.814f },
	{ 2321.619f, 0.0f, 1564.172f } 
};

const VECTOR3 c_WOMAN_STAND_POS[_MAX_CHARACTER_NUM] = 
{		
	{ 1969.792f, 0.0f, 1863.346f },
	{ 2077.243f, 0.0f, 1702.041f },
	{ 2274.891f, 0.0f, 1709.814f },
	{ 2321.619f, 0.0f, 1564.172f }
};*/
const VECTOR3 c_MAN_STAND_POS[_MAX_CHARACTER_NUM] = 
{ 
	{ 13625.4f, 0.0f, 11376.3f },
	{ 13525.4f, 0.0f, 11537.7f },
	{ 13561.5f, 0.0f, 11697.f },
	{ 13781.9f, 0.0f, 11792.7f } 
};

const VECTOR3 c_WOMAN_STAND_POS[_MAX_CHARACTER_NUM] = 
{		
	{ 13625.4f, 0.0f, 11376.3f },
	{ 13625.4f, 0.0f, 11537.7f },
	{ 13661.5f, 0.0f, 11697.f },
	{ 13781.9f, 0.0f, 11792.7f } 
};
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
GLOBALTON(CCharSelect)
CCharSelect::CCharSelect()
{
	m_CurSelectedPlayer = -1;
	m_pDoublcClickedPlayer = NULL;
//	m_bDoublcClicked	= FALSE;

	ZeroMemory( m_pPlayer, sizeof(CPlayer*)*MAX_CHARACTER_NUM );

	m_pSelectDlg = NULL;
	m_pChannelDlg = NULL;

	m_ExtraCharacterCount = 0;

	m_bEnterGame = FALSE;
}

CCharSelect::~CCharSelect()
{
	
}

BOOL CCharSelect::Init(void* pInitParam)
{	
//	m_imageLoginBarTop.LoadSprite("image/login_bar00.TIF");
//	m_imageLoginBarBottom.LoadSprite("image/login_bar02.TIF");

	m_imageLoginBarTop.LoadSprite("image/2D/login_bar00.TIF");
	m_imageLoginBarBottom.LoadSprite("image/2D/login_bar02.TIF");	

	//YH2DO -_-
	if(MAP->IsInited() == FALSE)
	{
		//MAP->InitMap(103);
		MAP->InitMap(97);
	}
	else
	{
		MAP->Release();
		MAP->InitMap(97);
	}

	ZeroMemory( m_pPlayer, MAX_CHARACTER_NUM * sizeof(sizeof(CPlayer*)) );
	
	NETWORK->SetCurState(this);

	NewCreateCharSelect_m();
	m_pSelectDlg = WINDOWMGR->GetWindowForID( CS_CHARSELECTDLG );
	CreateChannelDlg();
	m_pChannelDlg = (CChannelDialog*)WINDOWMGR->GetWindowForID( CHA_CHANNELDLG );
#ifndef _KOR_LOCAL_
	if(m_pChannelDlg)
	{
		m_pChannelDlg->Linking();
	}
#endif

	WINDOWMGR->AfterInit();
	ASSERT(pInitParam);
	SEND_CHARSELECT_INFO * pmsg = (SEND_CHARSELECT_INFO *)pInitParam;
	NetworkMsgParse(pmsg->Category, pmsg->Protocol, pInitParam);

	//////////////////////////////////////////////////////////////////////////
	// �׸��� ó���� ����
	VECTOR3 pos = {0,0,0};
	float xpos = CHARSELECT_STAND_POSX;
	float zpos = CHARSELECT_STAND_POSZ;
	float gap = CHARSELECT_STAND_GAP;
	for(int n=0;n<MAX_CHARACTER_NUM;++n)
	{
//		pos.x += CHARSELECT_STAND_POSX;
//		pos.y += CHARSELECT_STAND_HEIGHT;		
//		pos.z += CHARSELECT_STAND_POSZ + n * CHARSELECT_STAND_GAP + 100;
		
		pos.x = xpos + (n *120);
		pos.y = CHARSELECT_STAND_HEIGHT;
		pos.z = zpos + 30 * n;
	}
//	pos.x /= 4.f;
//	pos.y /= 4.f;
//	pos.z /= 4.f;
	pos.x = 13625.4f;
	pos.z = 11700.7f;

	MAP->SetShadowPivotPos(&pos);
	//////////////////////////////////////////////////////////////////////////
	
//KES 030827 �Űܿ� <-- �Ľ��Լ��� ����
	InitCameraInCharSelect();
	
	m_CurSelectedPlayer = -1;
	SelectPlayer( -1 );
	m_pDoublcClickedPlayer = NULL;
	SetDisablePick( FALSE );

	m_bBackToMainTitle = FALSE;
//	m_ExtraCharacterCount = 0;
//	m_bCharacterSlotInit = FALSE;

	m_bEnterGame = FALSE;

	return TRUE;
}

void CCharSelect::Release(CGameState* pNextGameState)
{
	m_imageLoginBarTop.Release();
	m_imageLoginBarBottom.Release();	

	OBJECTMGR->RemoveAllObject();
	WINDOWMGR->DestroyWindowAll();
	RESRCMGR->ReleaseResource(11);
		
	if(pNextGameState == NULL || m_bEnterGame )
		MAP->Release();
			
	//map release()�ϴ� ���� ����?

}

void CCharSelect::Process()
{
///	MHTIMEMGR->Process();	

	/*
	if(CAMERA->GetGotoPosition() != -1)
		CAMERA->Process();
		*/		

	if( m_pDoublcClickedPlayer )
	{
		int iMotionNum = m_pDoublcClickedPlayer->GetEngineObject()->GetCurMotion();

		// magi82 - Motion(070920) ĳ���� ����â���� ĳ���� ���ý� ��� ���� ������Ʈ
#ifdef _KOR_LOCAL_
		if( iMotionNum == eMotion_Gum_AfterStop ||
			iMotionNum == eMotion_Kwon_AfterStop ||
			iMotionNum == eMotion_Do_AfterStop ||
			iMotionNum == eMotion_Chang_AfterStop ||
			iMotionNum == eMotion_Gung_AfterStop ||
			iMotionNum == eMotion_Amki_AfterStop)		

		{
			SendMsgGetChannelInfo();

			// ī�޶� �̵����� ����, ����Ʈ�ʵ� ����
			//			CAMERA->ResetInterPolation();

			m_pDoublcClickedPlayer = NULL;

		}
#else
		if( iMotionNum == eMotion_Sel1Afterstop ||
			iMotionNum == eMotion_Sel2Afterstop ||
			iMotionNum == eMotion_Sel3Afterstop ||
			iMotionNum == eMotion_Sel4Afterstop ||
			iMotionNum == eMotion_Sel5Afterstop)		

		{
			SendMsgGetChannelInfo();

			// ī�޶� �̵����� ����, ����Ʈ�ʵ� ����
			//			CAMERA->ResetInterPolation();

			m_pDoublcClickedPlayer = NULL;

		}
#endif
	}	

//KES
	if( WINDOWMGR->IsMouseInputProcessed() ) return;	//dialog�� ���ȴ�.
	if( m_bDiablePick ) return;							//�޼����ڽ��� ����.
//

//���콺�� Ŭ��
	if( MOUSE->LButtonDoubleClick() )
	{
		// ĳ���� ����ȭ�鿡���� Ư���� bone box �� picking�Ѵ�.
		//CPlayer* pPlayer = (CPlayer*)GetSelectedObject( MOUSE->GetMouseEventX(), MOUSE->GetMouseEventY());
		CPlayer* pPlayer = (CPlayer*)GetSelectedObjectBoneCheck( MOUSE->GetMouseEventX(), MOUSE->GetMouseEventY());

		if( pPlayer && m_pDoublcClickedPlayer == NULL )
		if( pPlayer == GetCurSelectedPlayer() )
		{
			m_pDoublcClickedPlayer = pPlayer;
			SetDisablePick( TRUE );
		}
	}
	else if( MOUSE->LButtonDown()  )
	{		
		if( GetCurSelectedPlayer() )		
		{
			int iMotionNumber = GetCurSelectedPlayer()->GetEngineObject()->GetCurMotion();

// magi82 - Motion(070920) ĳ���� ����â���� ĳ���� ���ý� ��� ���� ������Ʈ
#ifdef _KOR_LOCAL_
			if( iMotionNumber != eMotion_Gum_AfterStop &&
				iMotionNumber != eMotion_Kwon_AfterStop &&
				iMotionNumber != eMotion_Do_AfterStop &&
				iMotionNumber != eMotion_Chang_AfterStop &&
				iMotionNumber != eMotion_Gung_AfterStop &&
				iMotionNumber != eMotion_Amki_AfterStop)		
		
			{
				return;				
			}
#else
			if( iMotionNumber != eMotion_Sel1Afterstop &&
				iMotionNumber != eMotion_Sel2Afterstop &&
				iMotionNumber != eMotion_Sel3Afterstop &&
				iMotionNumber != eMotion_Sel4Afterstop &&
				iMotionNumber != eMotion_Sel5Afterstop)		
		
			{
				return;				
			}
#endif
		}

		//CPlayer* pPlayer = (CPlayer*)GetSelectedObject( MOUSE->GetMouseEventX(), MOUSE->GetMouseEventY());
		CPlayer* pPlayer = (CPlayer*)GetSelectedObjectBoneCheck( MOUSE->GetMouseEventX(), MOUSE->GetMouseEventY());

		if( pPlayer && m_pDoublcClickedPlayer == NULL )
		{
			for( int i = 0 ; i < MAX_CHARACTER_NUM ; ++i )
			{
				if( m_pPlayer[i] == pPlayer )
				{
 					SelectPlayer( i );
					break;
				}
			}
		}
	}
}

void CCharSelect::BeforeRender()
{
	g_pExecutive->GetRenderer()->BeginRender(0,0,0);
	g_pExecutive->GetRenderer()->EndRender();
	MAP->Process( gCurTime );
}

void CCharSelect::AfterRender()
{
	VECTOR2 v2TopPos = { 0, 0 };
	VECTOR2 v2BottomPos = { 0, 640 	};

	//SW061111 ���ػ󵵿ɼ�
	/*m_imageLoginBarTop.RenderSprite(0,0,0,&v2TopPos,0xffffffff);
	m_imageLoginBarBottom.RenderSprite(0,0,0,&v2BottomPos,0xffffffff);
	*/

	VECTOR2 PosScale = { 1, 1 };
	if( GAMERESRCMNGR->IsLowResolution() )
	{
		float scaleRate = (float)LOWRSLTN_W / MIDRSLTN_W;

		v2BottomPos.x *= scaleRate;
		v2BottomPos.y *= scaleRate;
		PosScale.x = PosScale.y = scaleRate;
	}

	m_imageLoginBarTop.RenderSprite(&PosScale,0,0,&v2TopPos,0xffffffff);
	m_imageLoginBarBottom.RenderSprite(&PosScale,0,0,&v2BottomPos,0xffffffff);

	WINDOWMGR->Render();
}

CPlayer* CCharSelect::GetCurSelectedPlayer()
{
	if(m_CurSelectedPlayer == -1)
		return NULL;
	CPlayer* pPlayer = m_pPlayer[m_CurSelectedPlayer];
		return pPlayer;
}

void CCharSelect::NetworkMsgParse(BYTE Category,BYTE Protocol,void* pMsg)
{
	switch(Category) 
	{
	case MP_USERCONN:
		{
			switch(Protocol) 
			{
#ifdef TAIWAN_LOCAL
			case MP_USERCONN_REMAINTIME_NOTIFY:
				{
					MSG_INT* pmsg = (MSG_INT*)pMsg;
					BILLINGMGR->SetUseRemainTime(TRUE);
					BILLINGMGR->SetRemainTime( pmsg->nData );	//
				}
				break;
#endif
				
			case MP_USERCONN_CHARACTERLIST_ACK:
				{	
					
					SEND_CHARSELECT_INFO* pmsg = (SEND_CHARSELECT_INFO*)pMsg;

					memset(m_pPlayer,0,sizeof(CPlayer*)*MAX_CHARACTER_NUM);

					VECTOR3 pos;
//					float xpos[4] = { 25755, 25684, 25613, 25542 };

					/*
					float xpos = CHARSELECT_STAND_POSX;
					float zpos = CHARSELECT_STAND_POSZ;
					float gap = CHARSELECT_STAND_GAP;
					float height = CHARSELECT_STAND_HEIGHT;
					*/


					DWORD basiccolor = RGBA_MAKE(255,255,255,255);
					DWORD overcolor = RGBA_MAKE(255,255,255,255);
					DWORD presscolor = RGBA_MAKE(255,255,0,255);

					int t = -1;
					for(int i = 0; i < pmsg->CharNum ; i++)
					{
						WORD standpoint = pmsg->StandingArrayNum[i];
						
						// YH �ϴ� ����â���� ���� ������.
						// magi82 - Motion(070920) ĳ���� ����â���� ĳ���� ���ý� ��� ���� ������Ʈ
						// pmsg->ChrTotalInfo[i].WearedItemIdx[eWearedItem_Weapon] = 0;		// �������ʹ� ĳ���ͼ���â�� ���� ������ �������־���Ѵ�.
						pmsg->ChrTotalInfo[i].MunpaID = 0;
						pmsg->ChrTotalInfo[i].MarkName = 0;
						
						//m_pPlayer[standpoint] = OBJECTMGR->AddPlayer(&pmsg->BaseObjectInfo[i],NULL,&pmsg->ChrTotalInfo[i],NULL);
						//SW070127 Ÿ��ź
						m_pPlayer[standpoint] = OBJECTMGR->AddPlayer(&pmsg->BaseObjectInfo[i],NULL,&pmsg->ChrTotalInfo[i],NULL,NULL,FALSE);
						CPlayer* pPlayer = m_pPlayer[standpoint];						

						pPlayer->GetEngineObject()->ApplyHeightField(FALSE);
						pPlayer->SetOverInfoOption(0);

//						pos.x = xpos[standpoint] + 2000;


						/*
						pos.x = xpos + (standpoint *120);
						pos.y = height;
						pos.z = zpos + 30 * standpoint;
						*/

						if (1 == pPlayer->GetGender())
						{
							pos = c_WOMAN_STAND_POS[standpoint];
						}
						else
						{
							pos = c_MAN_STAND_POS[standpoint];
						}		
											
						char LevelName[255];
/*
						//�ӽ÷� ������ �����ϴ� ���� �𸥴�. ���߿� �������̽� �ٽ� ���鶧 �� ������ �����ؼ� ������.
						if( MAINGAME->GetUserLevel() <= eUSERLEVEL_DEVELOPER )
							sprintf(LevelName,"[Lv%2d] %-16s[%s]",pmsg->ChrTotalInfo[i].Level,pmsg->BaseObjectInfo[i].ObjectName, GetMapName(pmsg->ChrTotalInfo[i].LoginMapNum) );
						else
							sprintf(LevelName,"[Lv%2d] %-16s",pmsg->ChrTotalInfo[i].Level,pmsg->BaseObjectInfo[i].ObjectName );
*/
						cPushupButton * btn = (cPushupButton *)WINDOWMGR->GetWindowForIDEx(MT_FIRSTCHOSEBTN+standpoint);
						wsprintf(LevelName,"[Lv%2d] %-16s",pmsg->ChrTotalInfo[i].Level,pmsg->BaseObjectInfo[i].ObjectName );
						btn->SetText(LevelName, basiccolor, overcolor, presscolor);
						cImage ToolTipImg;
						SCRIPTMGR->GetImage( 63, &ToolTipImg, PFT_HARDPATH );
//						if( MAINGAME->GetUserLevel() <= eUSERLEVEL_DEVELOPER )
						{
							// magi82(37) �� �Ӽ� ������
                            // btn->SetToolTip( GetMapName(pmsg->ChrTotalInfo[i].LoginMapNum), RGB_HALF(255,255,255), &ToolTipImg, TTCLR_ITEM_CANEQUIP );
							 btn->SetToolTip( MAP->GetMapName(pmsg->ChrTotalInfo[i].LoginMapNum), RGB_HALF(255,255,255), &ToolTipImg, TTCLR_ITEM_CANEQUIP );
						}

						if( standpoint == 4 )	//������ ĳ������ ��� �ϵ��ڵ� ����
						{
							pos.x -= ( pmsg->ChrTotalInfo[standpoint].Height - 1.0f ) * 200.f;
							pos.z += ( pmsg->ChrTotalInfo[standpoint].Height - 1.0f ) * 100.f;
						}

						pPlayer->SetPosition(&pos);
						
						/*
						pPlayer->SetAngle(DEGTORAD(50 - 20*standpoint ));	// ���� ������
						

						//KES �ӽ�.. 4��° ĳ���� ���� �ణ ����
						if( standpoint == 3 )
							pPlayer->SetAngle(DEGTORAD(50 - 20*standpoint + 10 ));	// ���� ������
							*/
					
						/*
						pPlayer->ChangeBaseMotion(eMotion_Sel1Before);//+4*standpoint);
						pPlayer->ChangeMotion(eMotion_Sel1Before,0);//+4*standpoint, 0);
						*/

						//pPlayer->SetAngle(DEGTORAD(50 - 20*standpoint ));	// ���� ������						

						//pPlayer->SetAngle(1.56);
						pPlayer->SetAngle(1.56 + (standpoint * -0.18f));

#ifdef _JAPAN_LOCAL_
						if( standpoint == 4 ) //������ 5��° ĳ����
						{
							pPlayer->ChangeBaseMotion(eMotion_Sel5Before);
							pPlayer->ChangeMotion(eMotion_Sel5Before, 0);							
						}
						else
						{
							pPlayer->ChangeBaseMotion(eMotion_Sel1Before+4*standpoint);
							pPlayer->ChangeMotion(eMotion_Sel1Before+4*standpoint, 0);
						}
#elif defined _HK_LOCAL_
						if( standpoint == 4 ) //������ 5��° ĳ����
						{
							pPlayer->ChangeBaseMotion(eMotion_Sel5Before);
							pPlayer->ChangeMotion(eMotion_Sel5Before, 0);							
						}
						else
						{
							pPlayer->ChangeBaseMotion(eMotion_Sel1Before+4*standpoint);
							pPlayer->ChangeMotion(eMotion_Sel1Before+4*standpoint, 0);
						}
#elif defined _TL_LOCAL_
						if( standpoint == 4 ) //������ 5��° ĳ����
						{
							pPlayer->ChangeBaseMotion(eMotion_Sel5Before);
							pPlayer->ChangeMotion(eMotion_Sel5Before, 0);							
						}
						else
						{
							pPlayer->ChangeBaseMotion(eMotion_Sel1Before+4*standpoint);
							pPlayer->ChangeMotion(eMotion_Sel1Before+4*standpoint, 0);
						}
#else
                        DWORD dwWeaponType = pPlayer->GetWeaponEquipType();
						//2007. 10. 26. CBH - ��, ��, ��, â, ��, �ϱ� �̿��� ����Ÿ����
						//�ش� ����� ����Ÿ������ �مR�ش�.
						dwWeaponType = CheckWeaponType(dwWeaponType);	
                        pPlayer->ChangeMotion(eMotion_Gum_Before + 4*(dwWeaponType-1),0);
                        pPlayer->ChangeBaseMotion(eMotion_Gum_Before + 4*(dwWeaponType-1));

//						pPlayer->ChangeBaseMotion(eMotion_Sel1Before+4*standpoint);
//						pPlayer->ChangeMotion(eMotion_Sel1Before+4*standpoint, 0);
#endif
						
						pPlayer->ShowObjectName( FALSE );
						pPlayer->GetEngineObject()->EnableShadow(TRUE);
						
//						OPTIONMGR->ClrKyungGong();//***
					}

					InitCameraInCharSelect();
				}				
				return;
			case MP_USERCONN_CHARACTERLIST_NACK:
				{
					LOG(EC_CHARACTERLIST_FAILED);
				}				
				return;
			case MP_USERCONN_CHARACTER_REMOVE_ACK:
				{
					CPlayer* pPlayer = GetCurSelectedPlayer();
					if(!pPlayer)
					{
						ASSERTMSG(0, "ĳ���� ����-�÷��̾ �����ϴ�.No Character For Delete!");
						return;
					}				
					
					cPushupButton * editboxName = (cPushupButton *)WINDOWMGR->GetWindowForIDEx(MT_FIRSTCHOSEBTN + m_CurSelectedPlayer);
					editboxName->SetText("",RGBA_MAKE(255,255,255,255),NULL,NULL);
					editboxName->SetPush(FALSE);
					
					m_pPlayer[m_CurSelectedPlayer] = NULL;
					m_CurSelectedPlayer = -1;
					OBJECTMGR->AddGarbageObject(pPlayer);
				
					SelectPlayer(-1);
					SetDisablePick( FALSE );
				}
				return;
			case MP_USERCONN_CHARACTER_REMOVE_NACK:
				{
					MSG_DWORD* pmsg = (MSG_DWORD*)pMsg;

					if( pmsg->dwData == 3 )
						WINDOWMGR->MsgBox( MBI_DELETECHARFAIL, MBT_OK, CHATMGR->GetChatMsg(995) );
					else
						WINDOWMGR->MsgBox( MBI_DELETECHARFAIL, MBT_OK, CHATMGR->GetChatMsg(25) );

					SetDisablePick( FALSE );
				}
				return;

			case MP_USERCONN_DISCONNECT_ACK:
				{
					SetDisablePick( TRUE );
//					OBJECTMGR->RemoveAllObject();	//���⼭ ������� release���� ����� maintitleȭ�鿡 ��� ���δ�.
//					MAINGAME->SetGameState(eGAMESTATE_TITLE);	//������Ʈ�� ������..
//					SetBlock(FALSE);
					
					//���� ����� ������ ��.
					m_bBackToMainTitle = TRUE;
					

				}
				return;
			case MP_USERCONN_CHANNELINFO_ACK:
				{
					MSG_CHANNEL_INFO * pmsg = (MSG_CHANNEL_INFO*)pMsg;
					GetChannelDialog()->SetChannelList(pmsg);
					SetDisablePick(TRUE);
					
					// ü���� �ϳ��̸� �ٷ� ���� ��
					if(pmsg->Count == 1)
					{
						GetChannelDialog()->OnConnect();	
						GetChannelDialog()->SetActive(FALSE);
					}
				}
				return;
			case MP_USERCONN_CHANNELINFO_NACK:
				{
					MSG_BYTE* msg = (MSG_BYTE*)pMsg;
					if( msg->bData == 0 )
					{
						//���� ������.
						//����â�� disable�Ǿ��ֳ�?
						WINDOWMGR->MsgBox( MBI_MAPSERVER_CLOSE, MBT_OK, CHATMGR->GetChatMsg(449) );
					}
					else
					{						
						//ĳ������ �߸��Ǿ���.
						WINDOWMGR->MsgBox( MBI_MAPSERVER_CLOSE, MBT_OK, CHATMGR->GetChatMsg(450) );
					}
				}
				return;
			}
		}
		break; 
	case MP_CHEAT:
		{
			switch(Protocol) 
			{
				case MP_CHEAT_EVENTNOTIFY_ON:
				{
					MSG_EVENTNOTIFY_ON* pmsg = (MSG_EVENTNOTIFY_ON*)pMsg;

					NOTIFYMGR->SetEventNotifyStr( pmsg->strTitle, pmsg->strContext );
					NOTIFYMGR->SetEventNotify( TRUE );

//					if( GAMEIN->GetEventNotifyDialog() )
//					{
//						GAMEIN->GetEventNotifyDialog()->SetTitle( pmsg->strTitle );
//						GAMEIN->GetEventNotifyDialog()->SetContext( pmsg->strContext );
//						GAMEIN->GetEventNotifyDialog()->SetActive( TRUE );
//						NOTIFYMGR->SetEventNotifyChanged( FALSE );
//						//����?
//					}
//					else
//					{
						NOTIFYMGR->SetEventNotifyChanged( TRUE );
//					}
						
					NOTIFYMGR->ResetEventApply();
					for(int i=0; i<eEvent_Max; ++i)
					{
						if( pmsg->EventList[i] )
							NOTIFYMGR->SetEventApply( i );
					}						
				}
				break;
		
				case MP_CHEAT_EVENTNOTIFY_OFF:
				{
					MSGBASE* pmsg = (MSGBASE*)pMsg;
					NOTIFYMGR->SetEventNotify( FALSE );
					NOTIFYMGR->SetEventNotifyChanged( FALSE );
//					if( GAMEIN->GetEventNotifyDialog() )
//						GAMEIN->GetEventNotifyDialog()->SetActive( FALSE );
				}	
				break;

			}
		}		
	}
	
//	LOG(EC_UNKNOWN_PROTOCOL);
}

void CCharSelect::InitCameraInCharSelect()
{
	//���� ���õ� ���
//	VECTOR3 vPivot;

//* ī�޶� �̵�
	/*
	if(CAMERA->IsMoved() == FALSE)
	{
		vPivot.x = 27740;
		vPivot.y = 4960;
		vPivot.z = 9104;

		CAMERA->InitCamera(0, -2.0f, 17.0f, 2000, &vPivot);// �Ÿ� ���� 

		//
		MHCAMERAPOS CPos;
		CPos.m_AngleX = -2.0f;
		CPos.m_AngleY = 17.0f;
		CPos.m_Dist = 2000;
		CPos.m_Pivot = vPivot;
		CAMERA->SetMovePos(eCP_CHARSEL, &CPos);

		vPivot.x = 24480;
		vPivot.y = 6045;
		vPivot.z = 9854;	
		CPos.m_AngleX = -6.0f;
		CPos.m_AngleY = 0.0f;
		CPos.m_Dist = 2000;
		CPos.m_Pivot = vPivot;
		CAMERA->SetMovePos(eCP_CHARMAKE, &CPos);
	}
//*/

	/*if(CAMERA->IsMoved() == FALSE)
	{			
		vPivot.x = 1545.0f;
		vPivot.y = 310.0f;
		vPivot.z = 1047.269f;

		CAMERA->InitCamera(0, RADTODEG(-0.076794f), RADTODEG(0.649262f), 2000, &vPivot);// �Ÿ� ���� 
		*/

	/*
		//MHCamera Object�� �̿��ϸ� ��ǥ ����� �ǵ��Ѵ�� ���� �ʴ´�. �׷��� ���� Camera�� ����.
		VECTOR3 v3Eye		= { 1899.600586f, 460.0f, 864.214050f };
		VECTOR3 v3Rotate	= { -0.335103f, 0.300197f, 0.0f	};

		g_pExecutive->GetGeometry()->SetCameraPos(&v3Eye, 0);
		g_pExecutive->GetGeometry()->SetCameraAngleRad(&v3Rotate, 0);*/

		//SW070725 ĳ���ͼ���/����â
		/*VECTOR3 v3Eye		= { 14443.752930f, 136.457611f, 11398.751953f };
		VECTOR3 v3Rotate	= { -6.230824f, -1.246164f, 0.0f };
		
		g_pExecutive->GetGeometry()->SetCameraPos(&v3Eye, 0);
		g_pExecutive->GetGeometry()->SetCameraAngleRad(&v3Rotate, 0);*/

		VECTOR3 vPivot;
		vPivot.x = 14443.752930f;
		vPivot.y = 0;
		vPivot.z = 11398.751953f;
		CAMERA->InitCamera( 0, 357.000183f, 71.700043f, 0, &vPivot);

		
		/*
		MHCAMERAPOS CPos;
		CPos.m_AngleX = -0.237365f;
		CPos.m_AngleY = 0.293216f;
		CPos.m_Dist = 2000;
		CPos.m_Pivot = vPivot;
		CAMERA->SetMovePos(eCP_CHARSEL, &CPos);

	}*/
	

/* �̵��Ƚ�ų�� �̰ɷ�..
	vPivot.x = 27740;
	vPivot.y = 4960;
	vPivot.z = 9104;

	CAMERA->InitCamera(0, -2.0f, 17.0f, 2000, &vPivot);// �Ÿ� ���� 
//*/
	CAMERA->SetCameraMode(eCM_LOGIN);
	CAMERA->SetCurCamera(0);

	//ī�޶� ���... Ÿ����ġ���� �ִϸ��̼�(ī�޶�, �ǹ�) �ʿ�.	

/*
	VECTOR3 vPivot;
	vPivot.x = 23558;
	vPivot.y = 671;
	vPivot.z = 31780;

	CAMERA->InitCamera(0, 0.0f, 90.0f, 5115, &vPivot);// �Ÿ� ���� 
	CAMERA->SetCameraMode(eCM_LOGIN);
*/	/// ����Ÿ��Ʋ�� ���û�Ȳ
	
/*
	VECTOR3 pos;

//	pos.x = 25400; //���� ���̸� �������� 
	pos.x = 25750;
//	pos.y = -100;
	pos.y = -70;
	pos.z = 39900;
	
	CAMERA->InitCamera(0, 0.17f, 0, 10500, &pos);// �Ÿ� ���� 
//	CAMERA->InitCamera(0, 2.0, 0, 10500, &pos);// �Ÿ� ���� 
	CAMERA->SetCameraMode(eCM_LOGIN);

	CAMERA->SetCurCamera(0);
	
	if(m_bReturnOfCharMake == FALSE)
	{
//		CAMERA->ZoomDistance(0, -1200.f, 1700);		
		CAMERA->ZoomDistance(0, -0550.f, 1700);			
		CAMERA->SetTargetAngleX(0,0.8f,1700);
		CAMERA->SetTargetAngleY(0,0.25f,1700);
		CAMERA->SetTargetAngleY(0,0.6f,0);
	}
	else
	{
//		CAMERA->ZoomDistance(0, 900, 1700); // pjs ī�޶� �ڷ� �̵� [5/13/2003]
		CAMERA->ZoomDistance(0, 1200, 1700);
	}
*/


}

void CCharSelect::SetCurSelctedPlayer(int num)
{	
	cPushupButton * charBtn[MAX_CHARACTER_NUM];

	if(num == -1)
	{
		for(int n=0;n<MAX_CHARACTER_NUM;++n)
		{
			charBtn[n] = (cPushupButton *)WINDOWMGR->GetWindowForIDEx(MT_FIRSTCHOSEBTN+n);
			charBtn[n]->SetPush(FALSE);
		}
		m_CurSelectedPlayer = -1;
		return;
	}
	for(int n=0;n<MAX_CHARACTER_NUM;++n)
	{
		charBtn[n] = (cPushupButton *)WINDOWMGR->GetWindowForIDEx(MT_FIRSTCHOSEBTN+n);
		if(n == num)
			charBtn[n]->SetPush(TRUE);
		else
			charBtn[n]->SetPush(FALSE);
	}
	m_CurSelectedPlayer = num;
}

void CCharSelect::SelectPlayer(int num)
{
	if( GetCurSelectedPlayer() )
	{
		int iMotionNum = GetCurSelectedPlayer()->GetEngineObject()->GetCurMotion();

		// magi82 - Motion(070920) ĳ���� ����â���� ĳ���� ���ý� ��� ���� ������Ʈ
#ifdef _KOR_LOCAL_
		if( iMotionNum != eMotion_Gum_AfterStop &&
			iMotionNum != eMotion_Kwon_AfterStop &&
			iMotionNum != eMotion_Do_AfterStop &&
			iMotionNum != eMotion_Chang_AfterStop &&
			iMotionNum != eMotion_Gung_AfterStop &&
			iMotionNum != eMotion_Amki_AfterStop)		

		{
			cPushupButton * charBtn = (cPushupButton *)WINDOWMGR->GetWindowForIDEx(MT_FIRSTCHOSEBTN + num);
			charBtn->SetPush( FALSE );
			return;
		}
#else
		if( iMotionNum != eMotion_Sel1Afterstop &&
			iMotionNum != eMotion_Sel2Afterstop &&
			iMotionNum != eMotion_Sel3Afterstop &&
			iMotionNum != eMotion_Sel4Afterstop &&
			iMotionNum != eMotion_Sel5Afterstop)		

		{
			cPushupButton * charBtn = (cPushupButton *)WINDOWMGR->GetWindowForIDEx(MT_FIRSTCHOSEBTN + num);
			charBtn->SetPush( FALSE );
			return;
		}
#endif
	}
	
	if( num == m_CurSelectedPlayer) 
	{
		return;
	}

	if(num != -1)
	if(m_pPlayer[num] == NULL)
	{
			cPushupButton * charBtn[MAX_CHARACTER_NUM];
			charBtn[num] = (cPushupButton *)WINDOWMGR->GetWindowForIDEx(MT_FIRSTCHOSEBTN+num);
			charBtn[num]->SetPush(FALSE);
			return;

//		cPushupButton * charBtn[4];
//		charBtn[num] = (cPushupButton *)WINDOWMGR->GetWindowForIDEx(MT_FIRSTCHOSEBTN+num);
//		charBtn[num]->SetPush(FALSE);
//		return;
	}

/*
	if(num == m_CurSelectedPlayer)
	{
		//���ִ� �ָ� �ڵ��ư��� �ϰ� 
		SetCurSelctedPlayer(-1);
		PlayDeselectedMotion(num);
		return;
	}
*/
	
	PlayDeselectedMotion(m_CurSelectedPlayer);
	PlaySelectedMotion(num);

	SetCurSelctedPlayer(num);
}

BOOL CCharSelect::IsFull()
{
#ifdef _JAPAN_LOCAL_

	for(DWORD n=0; n<GIVEN_CHARACTER_SLOT+m_ExtraCharacterCount; ++n)
	{
		if(m_pPlayer[n] == NULL)
			return FALSE;
	}
	
#elif defined _HK_LOCAL_

	for(int n=0; n<GIVEN_CHARACTER_SLOT+m_ExtraCharacterCount; ++n)
	{
		if(m_pPlayer[n] == NULL)
			return FALSE;
	}
#elif defined _TL_LOCAL_

	for(int n=0; n<GIVEN_CHARACTER_SLOT+m_ExtraCharacterCount; ++n)
	{
		if(m_pPlayer[n] == NULL)
			return FALSE;
	}
	
#else

	for(int n=0;n<MAX_CHARACTER_NUM;++n)
	{
		if(m_pPlayer[n] == NULL)
			return FALSE;
	}

#endif

	return TRUE;
}

BOOL CCharSelect::EnterGame()
{
	CPlayer* pPlayer = GetCurSelectedPlayer();
	if(pPlayer == NULL)
		return FALSE;

#ifdef _JAPAN_LOCAL_
	if( gChannelNum == 1 )
	if( pPlayer->GetBadFame() > 0 )
	{
		DisplayNotice( 1490 );
		return TRUE;
	}
#endif

	GameLoadingParam loadingParam;
	loadingParam.selectedCharNum = pPlayer->GetID();
	loadingParam.m_MapNum = pPlayer->GetCharacterTotalInfo()->LoginMapNum;

	MAINGAME->SetGameState(eGAMESTATE_GAMELOADING, (void *)&loadingParam, sizeof(GameLoadingParam));

	m_bEnterGame = TRUE;

	// ī�޶� �̵����� ����, ����Ʈ�ʵ� ����
	CAMERA->ResetInterPolation();

	return TRUE;
}

void CCharSelect::DeleteCharacter()
{
	CPlayer* pPlayer = GetCurSelectedPlayer();
	if(pPlayer == NULL)
		return;
		
	MSG_DWORD  msg;
	msg.Category = MP_USERCONN;
	msg.Protocol = MP_USERCONN_CHARACTER_REMOVE_SYN;
	msg.dwData = pPlayer->GetID();
	NETWORK->Send(&msg,sizeof(msg));
}

void CCharSelect::PlaySelectedMotion(int num)
{
	if(num == -1)
		return;
	if(m_pPlayer[num] == NULL)
		return;

#ifdef _JAPAN_LOCAL_
	if( num < MAX_CHARACTER_NUM-1 )
	{
		m_pPlayer[num]->ChangeMotion(eMotion_sel1After+4*num,0);
		m_pPlayer[num]->ChangeBaseMotion(eMotion_Sel1Afterstop+4*num);
	}
	else
	{
		m_pPlayer[num]->ChangeMotion(eMotion_Sel5After,0);
		m_pPlayer[num]->ChangeBaseMotion(eMotion_Sel5Afterstop);
	}

#elif defined _HK_LOCAL_

	if( num < MAX_CHARACTER_NUM-1 )
	{
		m_pPlayer[num]->ChangeMotion(eMotion_sel1After+4*num,0);
		m_pPlayer[num]->ChangeBaseMotion(eMotion_Sel1Afterstop+4*num);
	}
	else
	{
		m_pPlayer[num]->ChangeMotion(eMotion_Sel5After,0);
		m_pPlayer[num]->ChangeBaseMotion(eMotion_Sel5Afterstop);
	}

#elif defined _TL_LOCAL_
	if( num < MAX_CHARACTER_NUM-1 )
	{
		m_pPlayer[num]->ChangeMotion(eMotion_sel1After+4*num,0);
		m_pPlayer[num]->ChangeBaseMotion(eMotion_Sel1Afterstop+4*num);
	}
	else
	{
		m_pPlayer[num]->ChangeMotion(eMotion_Sel5After,0);
		m_pPlayer[num]->ChangeBaseMotion(eMotion_Sel5Afterstop);
	}

#else
	// magi82 - Motion(070920) ĳ���� ����â���� ĳ���� ���ý� ��� ���� ������Ʈ
	DWORD dwWeaponType = m_pPlayer[num]->GetWeaponEquipType();

	//2007. 10. 26. CBH - ��, ��, ��, â, ��, �ϱ� �̿��� ����Ÿ����
	//�ش� ����� ����Ÿ������ �مR�ش�.
	dwWeaponType = CheckWeaponType(dwWeaponType);	

	m_pPlayer[num]->ChangeMotion(eMotion_Gum_After + 4*(dwWeaponType-1),0);
	m_pPlayer[num]->ChangeBaseMotion(eMotion_Gum_AfterStop + 4*(dwWeaponType-1));

#endif



//KES 030904
//	m_pPlayer[num]->DisPlayObjectName(RGB_HALF(255,255,0), 1000000000 );
}
void CCharSelect::PlayDeselectedMotion(int num)
{
	if(num == -1)
		return;
	if(m_pPlayer[num] == NULL)
		return;
			
#ifdef _JAPAN_LOCAL_
	if( num < MAX_CHARACTER_NUM-1 )
	{
		m_pPlayer[num]->ChangeMotion(eMotion_Sel1Back+4*num, 0);
		m_pPlayer[num]->ChangeBaseMotion(eMotion_Sel1Before+4*num);
	}
	else
	{
		m_pPlayer[num]->ChangeMotion(eMotion_Sel5Back, 0);
		m_pPlayer[num]->ChangeBaseMotion(eMotion_Sel5Before);
	}

#elif defined _HK_LOCAL_
	if( num < MAX_CHARACTER_NUM-1 )
	{
		m_pPlayer[num]->ChangeMotion(eMotion_Sel1Back+4*num, 0);
		m_pPlayer[num]->ChangeBaseMotion(eMotion_Sel1Before+4*num);
	}
	else
	{
		m_pPlayer[num]->ChangeMotion(eMotion_Sel5Back, 0);
		m_pPlayer[num]->ChangeBaseMotion(eMotion_Sel5Before);
	}

#elif defined _TL_LOCAL_
	if( num < MAX_CHARACTER_NUM-1 )
	{
		m_pPlayer[num]->ChangeMotion(eMotion_Sel1Back+4*num, 0);
		m_pPlayer[num]->ChangeBaseMotion(eMotion_Sel1Before+4*num);
	}
	else
	{
		m_pPlayer[num]->ChangeMotion(eMotion_Sel5Back, 0);
		m_pPlayer[num]->ChangeBaseMotion(eMotion_Sel5Before);
	}

#else
	// magi82 - Motion(070920) ĳ���� ����â���� ĳ���� ���ý� ��� ���� ������Ʈ
	DWORD dwWeaponType = m_pPlayer[num]->GetWeaponEquipType();

	//2007. 10. 26. CBH - ��, ��, ��, â, ��, �ϱ� �̿��� ����Ÿ����
	//�ش� ����� ����Ÿ������ �مR�ش�.
	dwWeaponType = CheckWeaponType(dwWeaponType);	

	m_pPlayer[num]->ChangeMotion(eMotion_Gum_Back + 4*(dwWeaponType-1),0);
	m_pPlayer[num]->ChangeBaseMotion(eMotion_Gum_Before + 4*(dwWeaponType-1));
#endif

//KES 030904
//	m_pPlayer[num]->DisPlayObjectName(RGB_HALF(255,255,255), 1000000000 );
}

void CCharSelect::DisplayNotice(int MsgNum)
{
	WINDOWMGR->MsgBox( MBI_CHARSELERROR, MBT_OK, CHATMGR->GetChatMsg(MsgNum) );
	SetDisablePick( TRUE );
}


void CCharSelect::SetDisablePick( BOOL val )
{
	m_bDiablePick = val;
	if( m_pSelectDlg )
		m_pSelectDlg->SetDisable( val );
}

void CCharSelect::BackToMainTitle()
{
	MSGBASE msg;
	msg.Category = MP_USERCONN;
	msg.Protocol = MP_USERCONN_DISCONNECT_SYN;
	NETWORK->Send(&msg,sizeof(msg));

	SetBlock(TRUE);
	
	gUserID = 0;
	
	SetDisablePick(TRUE);
	m_bBackToMainTitle = TRUE;
}

void CCharSelect::OnDisconnect()
{
//	if( !m_bBlockScreen )			//backtomaintitle�϶��� ����´�.
//		CGameState::OnDisconnect();

	if( m_bBackToMainTitle )
	{
		SetBlock(FALSE);
		OBJECTMGR->RemoveAllObject();	//���⼭ ������� release���� ����� maintitleȭ�鿡 ��� ���δ�.
		MAINGAME->SetGameState(eGAMESTATE_TITLE);	//������Ʈ�� ������..
		m_bBackToMainTitle = FALSE;
		NETWORK->ReleaseKey();
	}
	else
	{
		CGameState::OnDisconnect();
	}


	// do nothing
}

void CCharSelect::SendMsgGetChannelInfo()
{
	CPlayer* pPlayer = GetCurSelectedPlayer();
	if(pPlayer == NULL)
	{
		DisplayNotice(18);
		return;
	}

	MSGBASE msg;
	msg.Category = MP_USERCONN;
	msg.Protocol = MP_USERCONN_CHANNELINFO_SYN;
	msg.dwObjectID = pPlayer->GetID();
	
	NETWORK->Send( &msg, sizeof(msg) );
}

//2007. 10. 26. CBH - ��, ��, â, ��, �ϱ�, �� �̿��� ���� Ÿ�� �˻�.
//�и�ġ, ����尩�� WeaponType�� Ʋ���� ����� ���δ�.
//��, ��, â, ��, �ϱ�, �� �̿��� ���� Ÿ���� ���⿡ �߰��ؼ�
//�ش� ����� ���� Ÿ������ �ٲ�����Ѵ�.
DWORD CCharSelect::CheckWeaponType(DWORD dwWeaponType)
{
	//����尩 ����Ÿ�� (���� ����� ���� ������ �� ����Ÿ������ ü����)
	if(dwWeaponType == WP_EVENT)
	{
		dwWeaponType = WP_GWUN;
	}
	//�и�ġ ����Ÿ�� (���� ����� ���� ������ �� ����Ÿ������ ü����)
	else if(dwWeaponType == WP_EVENT_HAMMER)
	{
		dwWeaponType = WP_GUM;
	}

	return dwWeaponType;
}
