// CharMake.cpp: implementation of the CCharMake class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CharMake.h"

#include "WindowIDEnum.h"
#include "./Interface/cWindowManager.h"
#include "./Interface/cEditBox.h"
#include "./Interface/cResourceManager.h"

#include "ObjectManager.h"
#include "GameResourceManager.h"
#include "MHCamera.h"
#include "MHTimeManager.h"
#include "MAINGAME.h"

#include "cWindowSystemFunc.h"
#include "ChatManager.h"
#include "cMsgBox.h"
#include "HelperManager.h"

#include "CharMakeDialog.h"

#include "mhMap.h"
#include "./Input/UserInput.h"

//#include "Gamein.h"
#include "GMNotifyManager.h"
//#include "EventNotifyDialog.h"


//VECTOR3				g_v3CreatePos = { 3600.0f, 0.0f, 1850.0f };
//SW070725 ĳ���ͼ���/����â
VECTOR3				g_v3CreatePos = { 16021.421875f, 0.0f, 12884.078125f };

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#define DEFAULT_JOB 0
GLOBALTON(CCharMake)
CCharMake::CCharMake()
{
	m_pCharMakeDlg = NULL;
	m_pCharMakeCamera = NULL;
}

CCharMake::~CCharMake()
{

}

BOOL CCharMake::Init(void* pInitParam)
{	
//	m_imageLoginBarTop.LoadSprite("image/login_bar00.TIF");
//	m_imageLoginBarBottom.LoadSprite("image/login_bar02.TIF");	
	m_imageLoginBarTop.LoadSprite("image/2D/login_bar00.TIF");
	m_imageLoginBarBottom.LoadSprite("image/2D/login_bar02.TIF");

	if(MAP->IsInited() == FALSE)
	{
		MAP->InitMap(103);
		//MAP->InitMap(97);
	}
	
	NETWORK->SetCurState(this);

	// ���̾�α� ����
	CreateCharMakeDlg();
	

	CHARMAKEMGR->Init();
	CHARMAKEMGR->CreateNewCharacter(&g_v3CreatePos);	

	m_pCharMakeDlg->ChangeComboStatus( 0 ); // �޺� ������ �⺻ ���ڷ� �����Ѵ�.

	// ����� �ʱ�ȭ
	HELPERMGR->Init();
	HELPERMGR->ShowRespect( 1, FALSE );

	WINDOWMGR->AfterInit();
	
//ī�޶� ����
/*	vPivot.x = 23058 - 600; // + �ڷ�  - ������
	vPivot.y = 530;
	vPivot.z = 31780 + 420; // + ����������  - ��������
	CAMERA->InitCamera(0, -4.0f, 90.0f, 4215, &vPivot);// �Ÿ� ���� 
*/	

/*	�̵��Ƚ�ų�� �̰ɷ�..
	VECTOR3 vPivot;
	vPivot.x = 24480;
	vPivot.y = 6020;
	vPivot.z = 9884;

	CAMERA->InitCamera(0, -6.0f, 0.0f, 2000, &vPivot);// �Ÿ� ���� 
//*/

	//VECTOR3 v3Eye		= { 3427.488525f, 410.0f, 1218.216919f };	
	//VECTOR3 v3Eye		= { 3427.488525f + 71.680961f, 410.0f -118.823507f, 1218.216919f + 237.419061f};	
	//VECTOR3 v3Rotate	= { -0.446804f, 0.293215f, 0.0f };

	//SW070725 ĳ���ͼ���/����â
	//���� ���÷� GAMEIN ���� ���¿����� CAMERA->InitCamera( ���.
	//CCharMake::Init ������ CAMERA->InitCamera( �� ������� �ʴ´�. CEngineCamera::m_LastPos �� ������ ���� ����.
	//�̺κ��� �������־�� �ٸ� ���¿����� CAMERA->InitCamera( �� ���� ī�޶� ��ġ�� ���ð����ϴ�.
	VECTOR3 vPivot;
	vPivot.x = 1;
	vPivot.y = 1;
	vPivot.z = 1;
	CAMERA->InitCamera( 0, 0.6f, 360.f, -500, &vPivot);

	VECTOR3 v3Eye		= { 16307.261719f, 30.643303f, 12567.238281f };	
	VECTOR3 v3Rotate	= { -6.136824f, -6.966158f, 0.0f };

	CAMERA->SetCurCamera(0);
	CAMERA->SetCameraMode(eCM_LOGIN);	

	if (NULL == m_pCharMakeCamera)
	{
		m_pCharMakeCamera = new CCharMakeCamera;
		m_pCharMakeCamera->InitCamera(g_pExecutive, &v3Eye, &v3Rotate, 0);
	}

	return TRUE;
}

void CCharMake::Release(CGameState* pNextGameState)
{
	m_imageLoginBarTop.Release();
	m_imageLoginBarBottom.Release();	

	if (NULL != m_pCharMakeCamera)
	{
		delete m_pCharMakeCamera;
		m_pCharMakeCamera = NULL;
	}

	OBJECTMGR->RemoveAllObject();
	
	WINDOWMGR->DestroyWindowAll();
	RESRCMGR->ReleaseResource(12);
	CHARMAKEMGR->Release();
	HELPERMGR->Release();
		
	if(pNextGameState == NULL)
		MAP->Release();
			
}

void CCharMake::Process()
{	
	if(IsBlock()) return;
	
	if(	!CHARMAKEMGR->GetNewPlayer() ) // ���ڸ��� ���� ���� �μ���... LBS
	{
		CHARMAKEMGR->CreateNewCharacter(&g_v3CreatePos);	
	}
	
	CHARMAKEMGR->ApplyScale();

///	MHTIMEMGR->Process();
		
	/*
	if(CAMERA->GetGotoPosition() != -1)
		CAMERA->Process();
		*/	

	static int s_iLastY = MOUSE->GetMouseY();
	static int s_iLastX = MOUSE->GetMouseX();	
	
	if( MOUSE->RButtonDrag() )
	{
		//CHARMAKEMGR->NewCharacterRotate( MOUSE->GetMouseAxisX() );		

		int iCurrentY		= MOUSE->GetMouseY();
		int iCurrentX		= MOUSE->GetMouseX();

		if (abs(iCurrentY - s_iLastY) > abs(iCurrentX - s_iLastX) )
		{
			GXOBJECT_HANDLE gxh = CHARMAKEMGR->GetNewPlayer()->GetEngineObject()->GetGXOHandle();		
			m_pCharMakeCamera->RotateCamera(gxh, 0, s_iLastY, 0, iCurrentY);		
		}
		else
		{
			CHARMAKEMGR->NewCharacterRotate( MOUSE->GetMouseAxisX() );
		}	

		s_iLastY = iCurrentY;
		s_iLastX = iCurrentX;		
	}
	
	int iWheel	= MOUSE->GetWheel();
	if (0 < iWheel)
	{
		m_pCharMakeCamera->ZoomInCamera();			
	}
	else if (0 > iWheel)
	{		
		m_pCharMakeCamera->ZoomOutCamera();		
	}
}

void CCharMake::BeforeRender()
{
	g_pExecutive->GetRenderer()->BeginRender(0,0,0);
	g_pExecutive->GetRenderer()->EndRender();
	MAP->Process( gCurTime );
}

void CCharMake::AfterRender()
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

void CCharMake::NetworkMsgParse(BYTE Category,BYTE Protocol,void* pMsg)
{
	switch(Category) 
	{
	case MP_USERCONN:
		{
			switch(Protocol) 
			{
			case MP_USERCONN_CHARACTER_NAMECHECK_NACK:
				{
					MSG_WORD* pmsg = (MSG_WORD*)pMsg;

//					LOG(EC_CHARNAME_EXIST);
					CHARMAKEMGR->GetCharacterMakeInfo()->bDuplCheck = FALSE;

					cEditBox * editboxName = (cEditBox *)WINDOWMGR->GetWindowForIDEx(CMID_IDEDITBOX);
					editboxName->SetEditText("");
				
					switch(pmsg->wData)
					{
					case 2:
						CHARMAKE->DisplayNotice( 14 );
						break;
					case 3:
						CHARMAKE->DisplayNotice( 14 );
						break;
					case 4:
						CHARMAKE->DisplayNotice( 14 );
						break;
					default:
						CHARMAKE->DisplayNotice( 14 );
						break;
					}

					CHARMAKE->SetDisableDlg( FALSE );
				}
				return;
			case MP_USERCONN_CHARACTER_NAMECHECK_ACK:
				{
//					LOG(EC_CHARNAME_SUCCESS);
					CHARMAKEMGR->GetCharacterMakeInfo()->bDuplCheck =TRUE;
					
					CHARMAKE->DisplayNotice( 13 );
					CHARMAKE->SetDisableDlg( FALSE );
				}
				return;
			case MP_USERCONN_CHARACTER_MAKE_NACK:
				{
					CHARMAKE->DisplayNotice( 16 );
					SetDisableDlg( FALSE );
				}
				return;
			case MP_USERCONN_CHARACTERLIST_ACK:
				{		
					SEND_CHARSELECT_INFO* pmsg = (SEND_CHARSELECT_INFO*)pMsg;
					SetDisableDlg( FALSE );
					MAINGAME->SetGameState(eGAMESTATE_CHARSELECT, (void *)pmsg, sizeof(SEND_CHARSELECT_INFO));									
					
					CAMERA->MoveStart(eCP_CHARSEL);				
					
					
					//WINDOWMGR->AddListDestroyWindow( WINDOWMGR->GetWindowForID( MBI_NOBTNMSGBOX ) );
				}
				return;
			}
		}
		return;
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
		break;
	}
//	LOG(EC_UNKNOWN_PROTOCOL);
}


void CCharMake::DisplayNotice( int MsgNum )
{
	WINDOWMGR->MsgBox( MBI_CHARMAKEERROR, MBT_OK, CHATMGR->GetChatMsg(MsgNum) );
	SetDisableDlg( TRUE );
}

void CCharMake::SetDisableDlg( BOOL val )
{
	if( m_pCharMakeDlg )
		m_pCharMakeDlg->SetDisable( val );
}


//////////////////////////////////////////////////////////////////////////


/*
	//CPlayer* CObjectManager::AddPlayer(BASEOBJECT_INFO* pBaseObjectInfo,BASEMOVE_INFO* pMoveInfo,CHARACTER_TOTALINFO* pTotalInfo)

struct BASEOBJECT_INFO
{
	DWORD dwObjectID;
	char ObjectName[MAX_NAME_LENGTH+1];
	BYTE ObjectState;
};

struct BASEMOVE_INFO
{
	VECTOR3 CurPosition;
	VECTOR3 TargetPosition;

	bool bMoving;
	bool MoveMode;		 // 0:�ٱ� 1:�ȱ�

	WORD KyungGongIdx;	// ���Idx 0: ������� �ƴϴ�  !0: ������� �����ȣ
};
struct CHARACTER_TOTALINFO
{
	WORD	Life;							// �����
	WORD	MaxLife;						// �ִ� �����
	
	char	NickName[MAX_NAME_LENGTH+1];	// ��Ī(ȣ)
	char	HonorName[MAX_NAME_LENGTH+1];	// ��ȣ(?)

	BYTE	Gender;							// ����
	BYTE	FaceType;						// �󱼹�ȣ
	BYTE	HairType;						// �Ӹ���� ��ȣ

	WORD	WearedItemIdx[eWearedItem_Max];	// ������ �����Ƶ��� ����

	BYTE	Job;							// ����
	BYTE	Stage;							// ����
	BYTE	Level;							// ����
	BYTE	Map;							// ��


	bool	bPeace;							// ��/��ȭ��� FALSE �� ���� TRUE �� ��ȭ

};
*/