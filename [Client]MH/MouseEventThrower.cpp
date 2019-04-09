// MouseEventThrower.cpp: implementation of the CMouseEventThrower class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MouseEventThrower.h"
#include "MouseEventReceiver.h"
#include "Object.h"
#include "interface\cWindowManager.h"

#include "MousePointer.h"
#include "ObjectManager.h"
#include "gamein.h"
#include "MouseCursor.h"
#include "MHMap.h"

#include "MonsterGuageDlg.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMouseEventThrower::CMouseEventThrower()
{
	m_pCurrentReceiver	= NULL;
	m_pDefaultReceiver	= NULL;

	m_bCancelSelect		= FALSE;
}

CMouseEventThrower::~CMouseEventThrower()
{

}

void CMouseEventThrower::SetDefaultReceiver(CMouseEventReceiver* pDefaultReceiver)
{
	m_pDefaultReceiver = pDefaultReceiver;
}

void CMouseEventThrower::SetCurrentReceiver(CMouseEventReceiver* pCurrentReceiver)
{
	m_pCurrentReceiver = pCurrentReceiver;
}

void CMouseEventThrower::SetReceiverToDefault()
{
	ASSERT(m_pDefaultReceiver);
	m_pCurrentReceiver = m_pDefaultReceiver;
}


#define MOUSE_MOVE_TICK		400
#define MOUSE_PRESS_TICK	400
#define MOUSE_ON_TICK		200

void CMouseEventThrower::Process(CMouse* Mouse)
{
	static CObject* pOldMouseOverObject		= NULL;
	static DWORD dwMouseMoveTick			= 0;
	static DWORD dwMouseOnTick				= 0;
	static DWORD dwMousePressTick			= 0;

	if( WINDOWMGR->IsMouseInputProcessed() || WINDOWMGR->IsDragWindow() )
	{
		if( pOldMouseOverObject )
		{
			m_pCurrentReceiver->OnMouseLeave( pOldMouseOverObject );
			pOldMouseOverObject = NULL;
		}
		
		dwMousePressTick = gCurTime;
		return;	//������ �巡�����϶��� ���콺 �̺�Ʈ üũ�� ���ʿ�.
	}

	DWORD MouseEvent = MOUSEEVENT_NONE;

	if( Mouse->LButtonDoubleClick() || Mouse->RButtonDoubleClick() )
		MouseEvent = MOUSEEVENT_DBLCLICK;
	else
	{
		if( Mouse->LButtonDown() )
			MouseEvent = MOUSEEVENT_LCLICK;
		else if( Mouse->RButtonDown() )
			MouseEvent = MOUSEEVENT_RCLICK;

		if( Mouse->LButtonPressed() )
			MouseEvent |= MOUSEEVENT_LPRESS;
	}

//---ĳ���� ���� ��������
	if( Mouse->RButtonDown() )	m_bCancelSelect = TRUE;
	if( Mouse->RButtonDrag() )	m_bCancelSelect = FALSE;

	if( OBJECTMGR->GetSelectedObjectID() && Mouse->RButtonUp() && m_bCancelSelect )
	{
		OBJECTMGR->SetSelectedObject( NULL );
//		if( GAMEIN->GetMonsterGuageDlg())
//			GAMEIN->GetMonsterGuageDlg()->SetActive(FALSE);
//		if(GAMEIN->GetPlayerGuageDlg())
//			GAMEIN->GetPlayerGuageDlg()->SetActive(FALSE);

		m_bCancelSelect = FALSE;
	}
	
	if( MouseEvent == MOUSEEVENT_NONE )
	{
		if( gCurTime - dwMouseOnTick > MOUSE_ON_TICK )
		{
			dwMouseOnTick = gCurTime;
			//if( OPTIONMGR->GetGameOption()->bGraphicCursor ) //�׷���Ŀ���϶���
			//---���콺�� ������Ʈ ����, �Ʒ��Լ� ���� FPSüũ confirm
			CObject* pOverObject = (CObject*)GetSelectedObject( Mouse->GetMouseX(), Mouse->GetMouseY() );
			//		CObject* pOverObject = NULL;
			
			if( pOldMouseOverObject != pOverObject )
			{
				m_pCurrentReceiver->OnMouseLeave( pOldMouseOverObject );
				m_pCurrentReceiver->OnMouseOver( pOverObject );
				
				pOldMouseOverObject = pOverObject;
			}
			//---���콺�� Ÿ�� ����
			if( pOverObject == NULL )
			{
				// magi82 - Titan(070511) Ÿ��ź ���������� �����Ҷ�
				if( CURSOR->GetCursor() != eCURSOR_TITANREPAIR )
                    CURSOR->SetCursor( eCURSOR_DEFAULT );
				//������ ���� ���콺Ŀ�� �ٲٱ�
/*				VECTOR3* TargetPos = GetPickedPosition( Mouse->GetMouseX(), Mouse->GetMouseX() );
				if( TargetPos )
				{
					if( MAP->CollisionTilePos( TargetPos->x, TargetPos->z, MAP->GetMapNum(), HERO ) )
						CURSOR->SetCursor( eCURSOR_CANTMOVE );//on ground but can't go there
					else
						CURSOR->SetCursor( eCURSOR_DEFAULT );//on ground, can go there
				}
				else
					CURSOR->SetCursor( eCURSOR_CANTMOVE );//not on ground
					*/
			}
		}
		
/*		
		/////�����߿�.. �ڵ� ���󰡱�
		if( HERO )
		if( HERO->IsAutoAttacking() )
		{
			HERO->GetAutoAttackTarget()->g
			if( )
			dwMouseMoveTick = gCurTime
		pHero->SetCurComboNum(0);
		CAction MoveAction;
		if(pSkillInfo->IsMugong() == FALSE)
		{
			pSkillInfo = GetSkillInfo(GetComboSkillIdx(pHero));
		}
		MoveAction.InitSkillAction(pSkillInfo,&target);
		MOVEMGR->SetHeroActionMove(&target,&MoveAction);
		return FALSE;
*/		
	}
//---���콺 Ŭ��
	else
	{
		CObject* pObject = (CObject*)GetSelectedObject( Mouse->GetMouseEventX(), Mouse->GetMouseEventY() );

		if( pObject )
		{
			if( pObject->GetEngineObjectType() == eEngineObjectType_Character ||
				pObject->GetEngineObjectType() == eEngineObjectType_Titan )
			{
				m_pCurrentReceiver->OnClickPlayer(MouseEvent,(CPlayer*)pObject);					
			}
			else if( pObject->GetEngineObjectType() == eEngineObjectType_Monster)
			{
				m_pCurrentReceiver->OnClickMonster(MouseEvent,(CMonster*)pObject);
			}
			else if( pObject->GetEngineObjectType() == eEngineObjectType_Npc)
			{
				m_pCurrentReceiver->OnClickNpc(MouseEvent,(CNpc*)pObject);
			}
			else if( pObject->GetEngineObjectType() == eEngineObjectType_SkillObject)
			{
				m_pCurrentReceiver->OnClickSkillObject(MouseEvent,(CSkillObject*)pObject);
			}
			else if( pObject->GetEngineObjectType() == eEngineObjectType_Effect)
			{
				ASSERT(0);
			}
			else if( pObject->GetEngineObjectType() == eEngineObjectType_Pet)
			{
				m_pCurrentReceiver->OnClickPet(MouseEvent,(CPetBase*)pObject);
			}
			else if( pObject->GetEngineObjectType() == eEngineObjectType_MapObject )
			{
				m_pCurrentReceiver->OnClickMapObject(MouseEvent,(CPetBase*)pObject);
			}
			else
			{
				ASSERT(0);
			}
			
			if( MouseEvent & MOUSEEVENT_DBLCLICK )
			{
				if( pObject->GetEngineObjectType() == eEngineObjectType_Character ||
					pObject->GetEngineObjectType() == eEngineObjectType_Titan )
				{
					m_pCurrentReceiver->OnDbClickPlayer( MouseEvent,(CPlayer*)pObject );
				}
				else if( pObject->GetEngineObjectType() == eEngineObjectType_Monster )
				{
					m_pCurrentReceiver->OnDbClickMonster( MOUSEEVENT_LCLICK, (CMonster*)pObject );
				}
//				else if( pObjectBase->GetEngineObjectType() == eEngineObjectType_Npc )
//				{
//					m_pCurrentReceiver->OnDbClickNpc( MouseEvent, (CNpc*)pObject );
//				}
			}

			if( MouseEvent & MOUSEEVENT_LCLICK && pObject != HERO )	//�ڽ��� Ŭ���� �ȵȴ�.
			{

				if( !HERO->GetCharacterTotalInfo()->bPeace && pObject->GetEngineObjectType() == eEngineObjectType_Pet)
					OBJECTMGR->SetSelectedObject( NULL );
				else
					OBJECTMGR->SetSelectedObject( pObject );
			}
		}
		else
		{
			if( MouseEvent & MOUSEEVENT_LCLICK )
			{
				if( gCurTime - dwMouseMoveTick >= MOUSE_MOVE_TICK )
				{
					dwMouseMoveTick = gCurTime;
					dwMousePressTick = gCurTime;
					VECTOR3* TargetPos = GetPickedPosition(Mouse->GetMouseEventX(),Mouse->GetMouseEventY());
					if(!TargetPos)
						return;
					m_pCurrentReceiver->OnClickGround(MouseEvent,TargetPos);				
				}
			}
			else if( MouseEvent & MOUSEEVENT_LPRESS )
			{
				if( gCurTime - dwMousePressTick >= MOUSE_PRESS_TICK )
				{
					dwMousePressTick = gCurTime;
					VECTOR3* TargetPos = GetPickedPosition(Mouse->GetMouseX(), Mouse->GetMouseY());
					if(!TargetPos)
						return;
					m_pCurrentReceiver->OnClickGround(MouseEvent,TargetPos);
				}				
			}
		}
	}
}
