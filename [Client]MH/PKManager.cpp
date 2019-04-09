// PKManager.cpp: implementation of the CPKManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PKManager.h"
#include "ObjectManager.h"
#include "GameIn.h"
#include "CharStateDialog.h"
#include "ChatManager.h"
#include "./Interface/cWindowManager.h"
#include "WindowIdEnum.h"
#include "cMsgBox.h"
#include "VimuManager.h"
#include "PKLootingDialog.h"
#include "ItemManager.h"
#include "InventoryExDialog.h"
#include "QuickManager.h"
#include "GameEventManager.h"
#include "MugongManager.h"
#include "ObjectStateManager.h"
#include "SkillManager_Client.h"
#include "PartyWar.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

GLOBALTON(CPKManager)

CPKManager::CPKManager()
{
	m_dwPKContinueTime	= PKMODETIME;
	m_htLootingDlg.Initialize( 3 );
}

CPKManager::~CPKManager()
{
}

void CPKManager::Init()
{
	m_IndexGenerator.Init(1000, IG_PKLOOTINGDLG_START);	
	m_bSyncing			= FALSE;
	m_bLooted			= FALSE;
	m_bLooting			= FALSE;
	m_bPKAllow			= FALSE;
}

void CPKManager::Release()
{
	m_htLootingDlg.RemoveAll();	//window new�Ѱ� windowmanager�� �����ش�
	m_IndexGenerator.Release();
}

BOOL CPKManager::HEROPKModeOn()
{
	if( !IsPKAllow() )
	{
		CHATMGR->AddMsg( CTC_SYSMSG, CHATMGR->GetChatMsg( 145 ) );
		return FALSE;
	}		
	if( PARTYWAR->IsPartyWar() )
	{
		CHATMGR->AddMsg( CTC_SYSMSG, CHATMGR->GetChatMsg( 550 ) );
		return FALSE;
	}
	if( m_bSyncing )			return FALSE;
	if( !HERO )					return FALSE;
	if( HERO->IsPKMode() )		return FALSE;	//�̹� on�����̴�.
	if( WINDOWMGR->GetWindowForID( MBI_PKMODE ) ) return FALSE;		//�̹� â�� �����.

	cMsgBox* pMsgBox = WINDOWMGR->MsgBox( MBI_PKMODE, MBT_YESNO, CHATMGR->GetChatMsg( 149 ) );		
	if( !pMsgBox ) return FALSE;

	GAMEEVENTMGR->AddEvent( eGameEvent_PKInterface );

	return TRUE;
}

void CPKManager::SendMsgPKOn()
{
/*	
	if( HERO->GetState() != eObjectState_None && HERO->GetState() != eObjectState_Move )
	{
		CHATMGR->AddMsg( CTC_SYSMSG, CHATMGR->GetChatMsg( 557 ) );
		return;			//������¿����� ����
	}
*/

	if( HERO->GetState() == eObjectState_Die )
	{
		CHATMGR->AddMsg( CTC_SYSMSG, CHATMGR->GetChatMsg( 557 ) );
		return;			//�������¸� �ƴϸ�
	}

	if( VIMUMGR->IsVimuing() )	//���߿� �ȵȴ�.
	{
		CHATMGR->AddMsg( CTC_SYSMSG, CHATMGR->GetChatMsg( 550 ) );
		return;
	}

	////////////////////////////////////////////////////////////////////////////////
	// 06. 06. 2�� ���� - �̿���
	// ���� / ����
	// ���� �г�Ƽ
	if( HERO->GetSingleSpecialState(eSingleSpecialState_Hide) )
	{
		CHATMGR->AddMsg(CTC_SYSMSG, CHATMGR->GetChatMsg(1329));
		return;
	}
	////////////////////////////////////////////////////////////////////////////////

	MSGBASE msg;
	msg.Category	= MP_PK;
	msg.Protocol	= MP_PK_PKON_SYN;
	msg.dwObjectID	= HERO->GetID();
	NETWORK->Send( &msg, sizeof(msg) );

	m_bSyncing		= TRUE;
}

BOOL CPKManager::HEROPKModeOff()
{
	if( m_bSyncing )		return FALSE;
	if( !HERO )				return FALSE;
	if( !HERO->IsPKMode() )	return FALSE;	//�̹� off�����̴�.

	if( gCurTime - m_dwPKModeStartTime >= m_dwPKContinueTime )
	{
		MSGBASE msg;
		msg.Category	= MP_PK;
		msg.Protocol	= MP_PK_PKOFF_SYN;
		msg.dwObjectID	= HERO->GetID();
		NETWORK->Send( &msg, sizeof(msg) );

		m_bSyncing		= TRUE;
		
		return TRUE;
	}
	else
	{
		int nRemain = (int)( m_dwPKContinueTime - (gCurTime - m_dwPKModeStartTime) ) / 1000;
		if( nRemain < 0 ) nRemain = 0;				
//		else if( nRemain > 60 ) nRemain = 60;//���߿� ���¿����� �ʰ� �þ���Ѵ�.
		CHATMGR->AddMsg( CTC_SYSMSG, CHATMGR->GetChatMsg(146), nRemain + 1); // �ø�+1
	}

	return FALSE;
}

void CPKManager::SetPlayerPKMode( CPlayer* pPlayer, BOOL bPKMode )
{
	pPlayer->SetPKMode( bPKMode );
}

BOOL CPKManager::ToggleHeroPKMode()
{
	if( HERO )
	if( HERO->IsPKMode() )
	{
		return HEROPKModeOff();
	}
	else
	{
		return HEROPKModeOn();
	}

	return FALSE;

}

void CPKManager::NetworkMsgParse( BYTE Protocol, void* pMsg )
{
	switch(Protocol)
	{
	case MP_PK_PKON_ACK:
		{
			MSG_DWORD* pmsg = (MSG_DWORD*)pMsg;

			CPlayer* pPlayer = (CPlayer*)OBJECTMGR->GetObject( pmsg->dwData );
			if( !pPlayer ) break;

			if( HERO )
			if( pmsg->dwData == HEROID )
			{
				m_bSyncing			= FALSE;
				m_dwPKModeStartTime	= gCurTime;
				m_dwPKContinueTime	= HERO->GetBadFame()/200 + PKMODETIME; //������ ����.
				if( m_dwPKContinueTime > 3600000 )
					m_dwPKContinueTime = 3600000;

				HERO->DisableAutoAttack();	//�ڵ� ���� ���
				HERO->SetNextAction(NULL);	//��ų ���
				if( HERO->GetState() == eObjectState_Immortal )
					OBJECTSTATEMGR->EndObjectState( HERO, eObjectState_Immortal );

				CHATMGR->AddMsg( CTC_SYSMSG, CHATMGR->GetChatMsg(147) );
			}
			
			pPlayer->SetPKMode( TRUE );

			//ĳ���� �������� �ٲٱ�
			OBJECTMGR->ApplyOverInfoOption( pPlayer );
			if( pPlayer->InTitan() )
			{
				OBJECTEFFECTDESC desc(FindEffectNum("t_maintain_PK_S.beff"));
				pPlayer->AddObjectEffect( PK_EFFECT_ID, &desc, 1, HERO);

			}
			else
			{
				OBJECTEFFECTDESC desc(FindEffectNum("maintain_PK_S.beff"));
				//SW050915 ���� ����Ʈ �ɼǿ� ������� �׻� ���̱�
				//pPlayer->AddObjectEffect( PK_EFFECT_ID, &desc, 1 );
				pPlayer->AddObjectEffect( PK_EFFECT_ID, &desc, 1, HERO);	//HERO �� MakeEffectUnit( ���� �����ֱ����� �ϵ��ڵ�
			}
		}
		break;

	case MP_PK_PKON_NACK:
		{
			MSG_BYTE* pmsg = (MSG_BYTE*)pMsg;
			m_bSyncing		= FALSE;

			switch( pmsg->bData )
			{
			case ePKCODE_VIMUING:
				CHATMGR->AddMsg( CTC_SYSMSG, CHATMGR->GetChatMsg( 550 ) );
				break;
			case ePKCODE_STATECONFLICT:
				CHATMGR->AddMsg( CTC_SYSMSG, CHATMGR->GetChatMsg( 557 ) );
				break;
			case ePKCODE_NOTALLAW:
				CHATMGR->AddMsg( CTC_SYSMSG, CHATMGR->GetChatMsg( 145 ) );
				break;
			}
		}
		break;

	case MP_PK_PKOFF_ACK:
		{
			MSG_DWORD* pmsg = (MSG_DWORD*)pMsg;

			CPlayer* pPlayer = (CPlayer*)OBJECTMGR->GetObject( pmsg->dwData );
			if( !pPlayer ) break;

			pPlayer->SetPKMode( FALSE );
			
			if( HERO )
			if( pmsg->dwData == HERO->GetID() )
			{
				m_bSyncing		= FALSE;
				CHATMGR->AddMsg( CTC_SYSMSG, CHATMGR->GetChatMsg(148) );
			}
			else
			{
				//���� ����Ÿ���� pk�� Ų ������� Ÿ���� ������.
				HERO->ClearTarget( pPlayer );				
			}

			//ĳ���� �������� �ٲٱ�
			OBJECTMGR->ApplyOverInfoOption( pPlayer );
			pPlayer->RemoveObjectEffect( PK_EFFECT_ID );


		}
		break;

	case MP_PK_DISAPPEAR:	//PK_OFF�� �޼����� �ٸ���...--;
		{
			MSG_DWORD* pmsg = (MSG_DWORD*)pMsg;

			CPlayer* pPlayer = (CPlayer*)OBJECTMGR->GetObject( pmsg->dwData );
			if( !pPlayer ) break;

			pPlayer->SetPKMode( FALSE );
			
			if( HERO )
			if( pmsg->dwData == HERO->GetID() )
			{
				//m_bSyncing		= FALSE;
				CHATMGR->AddMsg( CTC_SYSMSG, CHATMGR->GetChatMsg(628) );
			}
			else
			{
				//���� ����Ÿ���� pk�� Ų ������� Ÿ���� ������.
				HERO->ClearTarget( pPlayer );
			}

			//ĳ���� �������� �ٲٱ�
			OBJECTMGR->ApplyOverInfoOption( pPlayer );
			pPlayer->RemoveObjectEffect( PK_EFFECT_ID );
		}
		break;

	case MP_PK_PKOFF_NACK:
		{
			//�ð��̾ȵǾ���.
			m_bSyncing		= FALSE;
		}
		break;

	case MP_PK_LOOTING_START:
		{
			MSG_DWORD* pmsg = (MSG_DWORD*)pMsg;
			CreateLootingDlg( pmsg->dwData );
			SetPKLooting( TRUE );

			GAMEEVENTMGR->AddEvent( eGameEvent_KillPK );

		}
		break;

	case MP_PK_LOOTING_BEINGLOOTED:
		{
			MSG_DWORD* pmsg = (MSG_DWORD*)pMsg;
			CPlayer* pAttacker = (CPlayer*)OBJECTMGR->GetObject( pmsg->dwData );
			if( pAttacker )
				CHATMGR->AddMsg( CTC_SYSMSG, CHATMGR->GetChatMsg( 562 ), pAttacker->GetObjectName() );

			SetPKLooted( TRUE );

			GAMEEVENTMGR->AddEvent( eGameEvent_DieFromPK );
			//��Ȱ�� �ȵǵ��� ����. �������� �����ִ� ������� �ٲٴ°� ����
			//���ᵵ �ȵǵ��� ����.
			//������ ������ �ȵǵ�������
			//������ �������� �����ϰ� �־��ٸ� ��� �ּҽ�Ų��.(������ ��� �ȱ��)
		}
		break;

	case MP_PK_LOOTING_ITEMLOOTING:
		{
			//SW070127 Ÿ��ź
			//���� ����ó���� ���� //SW070308 �����ۺΰ��ɼǵ� ���� ����
			/*
			MSG_LOOTINGIEM* pmsg = (MSG_LOOTINGIEM*)pMsg;
			if( pmsg->bOptionItem )
				ITEMMGR->AddItemOption(&pmsg->sOptionInfo);
			if( pmsg->bRareOptionItem )
				ITEMMGR->AddItemRareOption(&pmsg->sRareOptionInfo);
			
			CItem* pItem = ITEMMGR->MakeNewItem(&pmsg->ItemInfo,"MP_PK_LOOTING_ITEMLOOTING");
			GAMEIN->GetInventoryDialog()->AddItem(pItem);
			QUICKMGR->RefreshQickItem();

			CPKLootingDialog* pDlg = m_htLootingDlg.GetData( pmsg->dwDiePlayerIdx );*/
			MSG_LOOTINGITEM* pmsg = (MSG_LOOTINGITEM*)pMsg;
			CItem* pItem = ITEMMGR->MakeNewItem(&pmsg->ItemInfo,"MP_PK_LOOTING_ITEMLOOTING");
			ITEMMGR->GetItemOptionsAndToolTipFromInfoMsg(pItem, (MSG_LINKITEMOPTIONS*)pmsg);

			GAMEIN->GetInventoryDialog()->AddItem(pItem);
			QUICKMGR->RefreshQickItem();

			CPKLootingDialog* pDlg = m_htLootingDlg.GetData( pmsg->dwMoney );
////

			if( pDlg )
			{
				pDlg->ChangeIconImage( pmsg->wAbsPosition, eLIK_ITEM, pmsg->ItemInfo.wIconIdx );
				pDlg->AddLootingItemNum();
				pDlg->SetMsgSync( FALSE );
			}

			CHATMGR->AddMsg( CTC_SYSMSG, CHATMGR->GetChatMsg( 563 ), 
				ITEMMGR->GetItemInfo(pmsg->ItemInfo.wIconIdx)->ItemName );

			ITEMMGR->ItemDropEffect( pmsg->ItemInfo.wIconIdx );
		}
		break;

	case MP_PK_LOOTING_ITEMLOOTED:
		{
			MSG_EXCHANGE_REMOVEITEM* pmsg = (MSG_EXCHANGE_REMOVEITEM*)pMsg;
			WORD wTableIdx = ITEMMGR->GetTableIdxForAbsPos( pmsg->wAbsPosition );
			const ITEMBASE* pItemInfo = ITEMMGR->GetItemInfoAbsIn( HERO, pmsg->wAbsPosition );
			ITEMMGR->DeleteItemofTable( wTableIdx, pmsg->wAbsPosition );
			QUICKMGR->RefreshQickItem();
			
			CHATMGR->AddMsg( CTC_SYSMSG, CHATMGR->GetChatMsg( 564 ), 
				ITEMMGR->GetItemInfo(pItemInfo->wIconIdx)->ItemName );
		}
		break;

	case MP_PK_LOOTING_MOENYLOOTING:
		{
			MSG_DWORD3* pmsg = (MSG_DWORD3*)pMsg;
			CPKLootingDialog* pDlg = m_htLootingDlg.GetData( pmsg->dwData1 );
			if( pDlg )
			{
				pDlg->ChangeIconImage( (WORD)pmsg->dwData2, eLIK_MONEY );
				pDlg->AddLootingItemNum();
				pDlg->SetMsgSync( FALSE );
			}
			CHATMGR->AddMsg( CTC_SYSMSG, CHATMGR->GetChatMsg( 565 ), AddComma( pmsg->dwData3 ) );
			ITEMMGR->MoneyDropEffect();
		}
		break;

	case MP_PK_LOOTING_MOENYLOOTED:
		{
			MSG_DWORD3* pmsg = (MSG_DWORD3*)pMsg;

			CHATMGR->AddMsg( CTC_SYSMSG, CHATMGR->GetChatMsg( 566 ), AddComma( pmsg->dwData3 ) );
		}
		break;

	case MP_PK_LOOTING_EXPLOOTING:
		{
			MSG_DWORD3* pmsg = (MSG_DWORD3*)pMsg;
			CPKLootingDialog* pDlg = m_htLootingDlg.GetData( pmsg->dwData1 );
			if( pDlg )
			{
				pDlg->ChangeIconImage( (WORD)pmsg->dwData2, eLIK_EXP );
				pDlg->AddLootingItemNum();
				pDlg->SetMsgSync( FALSE );
			}
			CHATMGR->AddMsg( CTC_SYSMSG, CHATMGR->GetChatMsg( 567 ), pmsg->dwData3 );

			// magi82(4) - Titan(071022) Ÿ��ź�϶� ����Ʈ ó��(pk ����ġ ����)
			if( HERO->InTitan() == TRUE )
                EFFECTMGR->StartHeroEffectProcess(eEffect_Titan_PK_LootExp);
			else
				EFFECTMGR->StartHeroEffectProcess(eEffect_PK_LootExp);
		}
		break;

	case MP_PK_LOOTING_EXPLOOTED:
		{
			MSG_DWORD3* pmsg = (MSG_DWORD3*)pMsg;
			CHATMGR->AddMsg( CTC_SYSMSG, CHATMGR->GetChatMsg( 568 ), pmsg->dwData3 );
		}
		break;

	case MP_PK_LOOTING_NOLOOTING:
		{
			MSG_DWORD2* pmsg = (MSG_DWORD2*)pMsg;
			CPKLootingDialog* pDlg = m_htLootingDlg.GetData( pmsg->dwData1 );
			if( pDlg )
			{
				pDlg->ChangeIconImage( (WORD)pmsg->dwData2, eLIK_NONE );	//�������
				pDlg->SetMsgSync( FALSE );
			}
		}
		break;
		
	case MP_PK_LOOTING_NOINVENSPACE:
		{
			MSG_DWORD* pmsg = (MSG_DWORD*)pMsg;
			CHATMGR->AddMsg( CTC_SYSMSG, CHATMGR->GetChatMsg( 569 ) );
			CPKLootingDialog* pDlg = m_htLootingDlg.GetData( pmsg->dwData );
			if( pDlg )
				pDlg->SetMsgSync( FALSE );
		}
		break;

	case MP_PK_LOOTING_ENDLOOTING:
		{
			MSG_DWORD* pmsg = (MSG_DWORD*)pMsg;
			if( pmsg->dwData == HEROID )
			{
				SetPKLooted( FALSE );
			}
			else
			{
				CPKLootingDialog* pDlg = m_htLootingDlg.GetData( pmsg->dwData );
				if( pDlg )
				{
					pDlg->SetLootingEnd( TRUE );
					CloseLootingDialog( pDlg, FALSE );
				}
			}
		}
		break;

	case MP_PK_DESTROY_ITEM:
		{
			MSG_ITEM_DESTROY* pmsg = (MSG_ITEM_DESTROY*)pMsg;

			WORD wTableIdx = ITEMMGR->GetTableIdxForAbsPos( pmsg->wAbsPosition );
			const ITEMBASE* pItemInfo = ITEMMGR->GetItemInfoAbsIn( HERO, pmsg->wAbsPosition );

			if( pItemInfo == NULL ) return;
			ITEMMGR->DeleteItemofTable( wTableIdx, pmsg->wAbsPosition );
			QUICKMGR->RefreshQickItem();
			
			ITEM_INFO* pInfo = ITEMMGR->GetItemInfo( pItemInfo->wIconIdx );
			if( pInfo )
			{
				if( pmsg->cbReason == 0 )
					CHATMGR->AddMsg( CTC_SYSMSG, CHATMGR->GetChatMsg( 569 ), pInfo->ItemName );
				else
					CHATMGR->AddMsg( CTC_SYSMSG, CHATMGR->GetChatMsg( 688 ), pInfo->ItemName );
			}
		}
		break;
	case MP_PK_LOOTING_ERROR:
		{
			MSG_DWORD2* pmsg = (MSG_DWORD2*)pMsg;
			CPKLootingDialog* pDlg = m_htLootingDlg.GetData( pmsg->dwData1 );
			if( pDlg )
				pDlg->SetMsgSync( FALSE );

			//����
			switch( pmsg->dwData2 )
			{
			case eLOOTINGERROR_OVER_DISTANCE:
				CHATMGR->AddMsg( CTC_SYSMSG, CHATMGR->GetChatMsg( 561 ) ); //�Ÿ��� �ʹ� �־�.
				break;
			default:
				break;
			}
		}
		break;
	case MP_PK_PKALLOW_CHANGED:
		{
			MSG_BYTE* pmsg = (MSG_BYTE*)pMsg;
			PKMGR->SetPKAllow( (BOOL)pmsg->bData );

			//��� �÷��̾��� PK��� ����.
			if( PKMGR->IsPKAllow() )
			{
				CHATMGR->AddMsg( CTC_SYSMSG, CHATMGR->GetChatMsg(627) );
			}
			else
			{
				OBJECTMGR->AllPlayerPKOff();
				CHATMGR->AddMsg( CTC_SYSMSG, CHATMGR->GetChatMsg(626) );
			}
		}
		break;
	}
}


//--------------
//�������̽� ����
CPKLootingDialog* CPKManager::CreateLootingDlg( DWORD dwDiePlayerIdx )
{
	//�Ź� ���Ͽ��� �о�´�...?
#ifdef _FILE_BIN_	
//	CPKLootingDialog* pLootDlg = (CPKLootingDialog*)WINDOWMGR->GetDlgInfoFromFile( "./image/Looting.bin", "rb" );
	CPKLootingDialog* pLootDlg = (CPKLootingDialog*)WINDOWMGR->GetDlgInfoFromFile( "./image/InterfaceScript/Looting.bin", "rb" );
#else
	CPKLootingDialog* pLootDlg = (CPKLootingDialog*)WINDOWMGR->GetDlgInfoFromFile( "./image/Looting.txt" );
#endif
	pLootDlg->Linking();

	LONG x = ( 1024 - 251 ) / 2;
	LONG y = ( 768 - 275 ) / 2;

	//ǥ������ ��ġ�� dlg�� ������ ��ġ����
	PositioningDlg( x, y );

	pLootDlg->InitPKLootDlg( AllocWindowId(), x, y, dwDiePlayerIdx );
	WINDOWMGR->AddWindow( pLootDlg );
	
	pLootDlg->SetActive(TRUE);


//�̹� �����ϴ°� �ѹ� ����	//�ݵ�� ����ġ. ������ ���� �˻��ϸ� �ȵȴ�. ������ ���̵���.
	CPKLootingDialog* pLootTempDlg = m_htLootingDlg.GetData( dwDiePlayerIdx );
	if( pLootTempDlg )
		CloseLootingDialog( pLootTempDlg, FALSE );

	m_htLootingDlg.Add( pLootDlg, dwDiePlayerIdx );

	return pLootDlg;
}

void CPKManager::PositioningDlg( LONG& rX, LONG& rY )
{
	int nCount = 0;
	m_htLootingDlg.SetPositionHead();
	CPKLootingDialog* pLootDlg = NULL;
	while( pLootDlg = m_htLootingDlg.GetData() )
	{
		if( (LONG)pLootDlg->GetAbsX() == rX )
		if( (LONG)pLootDlg->GetAbsY() == rY )
		{
			rX += 20;
			rY += 20;
			if( ++nCount >= 10 )//�Ѿ��� �������°� ����
			{
				rX -= 200;
				rY -= 200;
				nCount = 0;
			}
		}
	}
}


void CPKManager::CloseLootingDialog( CPKLootingDialog* pLootingDlg, BOOL bMsgToServer )
{
	pLootingDlg->SetDisable( FALSE );		//^^ disable�ΰ� acitve�� �ȸԾ�.
	pLootingDlg->SetActiveRecursive( FALSE );
	pLootingDlg->ReleaseAllIcon();
	pLootingDlg->SetDisable( TRUE );
	m_htLootingDlg.Remove( pLootingDlg->GetDiePlayerIdx() );
	FreeWindowId( pLootingDlg->GetID() );
	WINDOWMGR->AddListDestroyWindow( pLootingDlg );

	if( m_htLootingDlg.GetDataNum() == 0 )
	{
		SetPKLooting( FALSE );	//������ ���߾�� ���ٵ�
	}

	if( bMsgToServer )
	{
		MSG_DWORD	msg;
		msg.Category	= MP_PK;
		msg.Protocol	= MP_PK_LOOTING_ENDLOOTING;
		msg.dwObjectID	= HEROID;
		msg.dwData		= pLootingDlg->GetDiePlayerIdx();

		NETWORK->Send( &msg, sizeof(msg) );
	}
}

int CPKManager::GetLootingChance( DWORD dwBadFame )
{
#ifdef _HK_LOCAL_
#ifndef _TW_LOCAL_
	if( dwBadFame < 1000 )
		return 3;
	else if( dwBadFame < 2000 )
		return 4;
	else if( dwBadFame < 5000 )
		return 5;
	else if( dwBadFame < 10000 )
		return 6;
	else if( dwBadFame < 20000 )
		return 7;
	else if( dwBadFame < 50000 )
		return 8;
	else if( dwBadFame < 100000 )
		return 9;
	else
		return 10;
#else

	if( dwBadFame < 100000 )
		return 3;
	else if( dwBadFame < 500000 )
		return 4;
	else if( dwBadFame < 1000000 )
		return 5;
	else if( dwBadFame < 5000000 )
		return 6;
	else if( dwBadFame < 10000000 )
		return 7;
	else if( dwBadFame < 50000000 )
		return 8;
	else if( dwBadFame < 100000000 )
		return 9;
	else
		return 10;
#endif
#else

	if( dwBadFame < 100000 )
		return 3;
	else if( dwBadFame < 500000 )
		return 4;
	else if( dwBadFame < 1000000 )
		return 5;
	else if( dwBadFame < 5000000 )
		return 6;
	else if( dwBadFame < 10000000 )
		return 7;
	else if( dwBadFame < 50000000 )
		return 8;
	else if( dwBadFame < 100000000 )
		return 9;
	else
		return 10;
#endif
}

int CPKManager::GetLootingItemNum( DWORD dwBadFame )
{
#ifdef _HK_LOCAL_
#ifndef _TW_LOCAL	//ȫ�Ḹ �ϴ� �ٲ㼭 ����
	if( dwBadFame < 100000 )
		return 1;
	else if( dwBadFame < 200000 )
		return 2;
	else if( dwBadFame < 500000 )
		return 3;
	else if( dwBadFame < 1000000 )
		return 4;
	else
		return 5;
#else
	if( dwBadFame < 100000000 )
		return 1;
	else if( dwBadFame < 400000000 )
		return 2;
	else if( dwBadFame < 700000000 )
		return 3;
	else if( dwBadFame < 1000000000 )
		return 4;
	else
		return 5;
#endif
#else
	if( dwBadFame < 100000000 )
		return 1;
	else if( dwBadFame < 400000000 )
		return 2;
	else if( dwBadFame < 700000000 )
		return 3;
	else if( dwBadFame < 1000000000 )
		return 4;
	else
		return 5;
#endif
}

/*
void CPKManager::RemoveAllLootingDlg()
{
	m_htLootingDlg.SetPositionHead();

	CPKLootingDialog* pLootDlg = NULL;
	while( pLootDlg = m_htLootingDlg.GetData() )
	{
		WINDOWMGR->AddListDestroyWindow( pLootDlg );	//delete�� �Ŵ����� ���ش�
		
	}
}
*/
