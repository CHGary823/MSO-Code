// PeaceWarModeManager.cpp: implementation of the CPeaceWarModeManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PeaceWarModeManager.h"

#include "MoveManager.h"
#include "ObjectManager.h"
#include "ObjectStateManager.h"
#include "AppearanceManager.h"
#include "GameIn.h"
#include "MHTimeManager.h"


#include "CharStateDialog.h"



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
GLOBALTON(CPeaceWarModeManager);
CPeaceWarModeManager::CPeaceWarModeManager()
{
	m_dwBeginCheckTime	= 0;
}

CPeaceWarModeManager::~CPeaceWarModeManager()
{

}

void CPeaceWarModeManager::InitPeace_WarMode(CPlayer* pPlayer)
{
	BOOL bPeace = pPlayer->GetCharacterTotalInfo()->bPeace;
	if(bPeace == TRUE)
		//MOVEMGR->SetWalkMode(pPlayer);
		MOVEMGR->SetRunMode(pPlayer);		// ¹«Á¶°Ç ¶Ù±â·Î... [6/3/2003]
	else
		MOVEMGR->SetRunMode(pPlayer);	
	
//	Peace_WarMode( pPlayer, bPeace );
//KES CHARSTATEDLG 031016
//	if( pPlayer == HERO )
//	if( GAMEIN->GetCharStateDialog() )
//		GAMEIN->GetCharStateDialog()->SetPeaceWarMode( bPeace );
}

void CPeaceWarModeManager::ToggleHeroPeace_WarMode()
{
	// »óÅÂ°¡ None ?Ï¶§¸¸ ¹Ù²Ü¼ö ?Ö´Ù.
	if( HERO->GetState() != eObjectState_None &&
		HERO->GetState() != eObjectState_Move &&
		HERO->GetState() != eObjectState_Immortal )
		return;


	BOOL bPeace = HERO->GetCharacterTotalInfo()->bPeace;

	if( bPeace == FALSE && HERO->InTitan() == TRUE )
		return;

	bPeace = !bPeace;	// Åä±Û ½ÃÅ´

	//for DoCheckForPeaceMode()
	//SW050829
	if( bPeace == FALSE )
	{
		m_dwBeginCheckTime = gCurTime;
	}
	else
	{
		//���� ���������� ������ �ɷ��ִٸ� ��ȭ��尡 ���� �ʴ´�.
		for( int i=0 ; i < eSpecialState_Max ; ++i )
		{
			if( HERO->IsInSpecialState( i ) == TRUE )
			{
				m_dwBeginCheckTime = gCurTime;
				return;
			}
		}
	}

	if( MOVEMGR->IsMoving(HERO) )
		MOVEMGR->HeroMoveStop();


// ¸¸¾à ?üÅõ¸ðµå·Î ¹Ù²Ù´Âµ¥ °È±â?Ì¸é ¶Ù±â·Î ¹Ù²Û´Ù.
//	if(bPeace==FALSE && MOVEMGR->GetMoveMode(HERO) == eMoveMode_Walk)
//	{
//		MOVEMGR->ToggleHeroMoveMode();
//	}
// ¸¸¾à ÆòÈ­¸ðµå·Î ¹Ù²Ù´Âµ¥ ¶Ù±â?Ì¸é °È±â·Î ¹Ù²Û´Ù.
//	if(bPeace==TRUE && MOVEMGR->GetMoveMode(HERO) == eMoveMode_Run)
//	{
//		MOVEMGR->ToggleHeroMoveMode();
//	}

	Peace_WarMode(HERO,bPeace);

	// ¼­¹ö¿¡ ¸Þ¼¼Áö º¸³¿
	MSGBASE msg;
	msg.Category = MP_PEACEWARMODE;
	if(bPeace)
		msg.Protocol = MP_PEACEWARMODE_PEACE;
	else
		msg.Protocol = MP_PEACEWARMODE_WAR;
	msg.dwObjectID = HEROID;
	NETWORK->Send(&msg,sizeof(msg));

//KES CHARSTATEDLG 031016
//	if(GAMEIN->GetCharStateDialog())
//		GAMEIN->GetCharStateDialog()->SetPeaceWarMode( bPeace );
}

void CPeaceWarModeManager::Peace_WarMode(CPlayer* pPlayer, BOOL bPeace)
{
	pPlayer->SetPeaceMode(bPeace?true:false);
	if(bPeace) //ÆòÈ­ ¸ðµå
	{
		// ?Ú¼¼¸¦ ¹Ù²Ù´Â ÇÔ¼ö¸¦ È£ÃâÇÑ´Ù.
		if(pPlayer->GetObjectKind() == eObjectKind_Player)
		{
			// ���� ������ �ƴϹǷ�...
			/* 2008. 6. 30. CBH - ��ȭ����϶� ���� ��� ���̰� ����
			if( //pPlayer->GetWeaponEquipType() == WP_GWUN ||
				pPlayer->GetWeaponEquipType() == WP_AMGI )
				APPEARANCEMGR->HideWeapon(pPlayer);
				*/
			(pPlayer)->SetBaseMotion();
		}
	}
	else //?üÅõ ¸ðµå
	{
		if(pPlayer->GetObjectKind() == eObjectKind_Player)
		{			
			APPEARANCEMGR->ShowWeapon(pPlayer);
			(pPlayer)->SetBaseMotion();
		}
	}
	if(pPlayer->GetState() == eObjectState_None)
		OBJECTSTATEMGR->EndObjectState(pPlayer,eObjectState_None);
}

BOOL CPeaceWarModeManager::IsPeaceMode(CPlayer* pPlayer)
{
	return pPlayer->GetCharacterTotalInfo()->bPeace;
}

void CPeaceWarModeManager::NetworkMsgParse(BYTE Protocol,void* pMsg)
{
	CPlayer* pObject;
	MSGBASE* pmsg = (MSGBASE*)pMsg;
	pObject = (CPlayer*)OBJECTMGR->GetObject(pmsg->dwObjectID);
	ASSERT(pObject);
	if(pObject==NULL)
		return;
	ASSERT(pObject->GetObjectKind() == eObjectKind_Player);	
	
	switch(Protocol) 
	{
	case MP_PEACEWARMODE_PEACE:
		{
			Peace_WarMode(pObject,TRUE);
		}
		break;
	case MP_PEACEWARMODE_WAR:
		{
			Peace_WarMode(pObject,FALSE);
		}
		break;
	}
}

//SW050810 ��ȭ��� �ڵ���ȯ
void CPeaceWarModeManager::DoCheckForPeaceMode(CPlayer* pPlayer)
{
/*
	if( pPlayer->GetCharacterTotalInfo()->bPeace == FALSE )
	{
		if( pPlayer->GetState() == eObjectState_None )	// ���������̰� �ൿ�� ������
		{
			if( gCurTime - m_dwBeginCheckTime > MODEVALIDTIME )
				ToggleHeroPeace_WarMode();
		}
	}
	else
		m_dwBeginCheckTime = gCurTime;
*/

	if( pPlayer->InTitan() == TRUE )
		return;
	//SW050829 ����: pPlayer->GetState() == eObjectState_None �϶��� ��ȭ��� �ð� üũ
	if( pPlayer->GetCharacterTotalInfo()->bPeace == FALSE )
	{
		if( pPlayer->GetState() == eObjectState_None )//			|| pPlayer->GetState() == eObjectState_Deal )
		{
			if( gCurTime - m_dwBeginCheckTime > MODEVALIDTIME )
			{
				ToggleHeroPeace_WarMode();				
			}
		}
		else
		{
			m_dwBeginCheckTime = gCurTime;
		}
	}
/*
	if( pPlayer->GetCharacterTotalInfo()->bPeace == TRUE ) return;
	
	if( pPlayer->GetState() == eObjectState_None )	// ���������̰� �ൿ�� ������
	{
		if( !m_bStartCheck )
		{
			m_dwBeginCheckTime = gCurTime;
			m_bStartCheck	= TRUE;
		}				
		
		if( m_bStartCheck )
		{
			if( gCurTime - m_dwBeginCheckTime > MODEVALIDTIME )
			{
				ToggleHeroPeace_WarMode();
				m_bStartCheck = FALSE;
				return;
			}		
		}
	}
	else
		m_bStartCheck = FALSE;
		*/
}
