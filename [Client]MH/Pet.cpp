#include "stdafx.h"
#include ".\pet.h"
#include "GameResourceManager.h"
#include "ObjectManager.h"
#include "ObjectBalloon.h"
//#include "PetManager.h"
#include "MoveManager.h"
#include "ChatManager.h"
#include "MOTIONDESC.h"
#include "MHMap.h"

CPet::CPet(void)
{
	m_pMaster = NULL;

	m_dwMaxStamina	= 0;
	m_dwStateCheckTime	= gCurTime;
	m_dwStaminaDecrease	= 0;
	m_bRest	= TRUE;
	m_dwMasterID = 0;
}

CPet::~CPet(void)
{
}

void CPet::InitPet(PET_TOTALINFO* pTotalInfo)
{
	memcpy(&m_PetTotalInfo,pTotalInfo,sizeof(PET_TOTALINFO));
	m_pSInfo = GAMERESRCMNGR->GetPetListInfo(GetPetKind());

	m_pMaster = NULL;
// 	m_pMaster = (CPlayer*)OBJECTMGR->GetObject(m_PetTotalInfo.PetMasterID);
// 	ASSERT(m_pMaster); //���ΰ� ���� �׸��尡 �ٸ��� �����ϴ�.
// 	if(m_pMaster)
// 	{
// 		m_pMaster->SetPet(this);
// 	}

	if(m_PetTotalInfo.PetGrade < 1)
	{
		ASSERT(0);
		return;
	}

	m_dwMaxStamina = m_pSInfo->StaminaMax[m_PetTotalInfo.PetGrade-1];
}

void CPet::PetGradeUp()
{
//������ ����
	if(m_PetTotalInfo.PetGrade<PET_MAX_GRADE)
	{m_PetTotalInfo.PetGrade++;}

//�� ��ȭ �Ǵ� ���ο� ������Ʈ ����...- -; AppearanceMgr ���� �Ƿ���..üũ��!
	m_EngineObject.Release();

	m_EngineObject.Init(m_pSInfo->ChxName_PerGrade[GetPetGrade()],this,eEngineObjectType_Pet);

	SetPosition(&m_MoveInfo.CurPosition);
	m_EngineObject.ApplyHeightField(TRUE);
	SetAngle(m_RotateInfo.Angle.ToRad());

	m_EngineObject.ChangeMotion(1);
	//MOTIONMGR->SetMotionInfo(this, pList->MotionID);

	VECTOR3 Scale;

	Scale.x = Scale.y = Scale.z = m_pSInfo->Scale;
	m_EngineObject.SetScale(&Scale);
	
}

BOOL CPet::IsPetStaminaFull()
{
	if(m_pSInfo)
		return (m_dwMaxStamina == m_PetTotalInfo.PetStamina);
	else
	{
		ASSERT(0);
		return FALSE;
	}
}

void CPet::Process()
{
	CObject::Process();

	if(GetState() == eObjectState_None && m_pMaster)
	{
		MOVEMGR->SetLookatPos(this, &m_pMaster->GetCurPosition(), 0, gCurTime);
	}

	if(IsDied())
	{
		DWORD time;
		time = REMOVEFADE_START_TIME;

		if( gCurTime - m_DiedTime > time )
		{
			ShowObjectName( FALSE );
			ShowChatBalloon( FALSE, NULL );
			//�׸��ڵ� ��������.
			if(m_ShadowObj.IsInited())
			{
				m_ShadowObj.Release();
			}

			//DWORD ToTime = REMOVEFADE_START_TIME;
			//DWORD ElTime = gCurTime - m_DiedTime - REMOVEFADE_START_TIME;
			//float alp = 1 - (ElTime / (float)ToTime);
			float alp = GetAlphaValue(REMOVEFADE_START_TIME, m_DiedTime + REMOVEFADE_START_TIME, FALSE);
			if(alp <= 0)
				alp = 0;
			GetEngineObject()->SetAlpha(alp);

//			if( GAMEIN->GetMonsterGuageDlg() )
//				if( GAMEIN->GetMonsterGuageDlg()->IsActive() == TRUE )
//				{
//					if( GAMEIN->GetMonsterGuageDlg()->GetCurMonster() == this )
//					{
//						GAMEIN->GetMonsterGuageDlg()->SetActive(FALSE);
//					}
//				}

		}
#ifdef _TESTCLIENT_
		if(gCurTime - m_DiedTime > MONSTERREMOVE_TIME)
		{
			OBJECTMGR->AddGarbageObject(this);
		}
#endif
	}

// 	VECTOR3 pos;
// 	GetPosition(&pos);
// 
// 	// �׸��ڿ� ����Ʈ
// 	MAP->SetShadowPivotPos(&pos);

//	CalcStamina();

//	CalcSkillRecharge();
}

void CPet::SetMaxStamina( DWORD dwMaxStamina )
{	
	m_dwMaxStamina = dwMaxStamina;

	if(m_PetTotalInfo.PetStamina > m_dwMaxStamina)
	{
		m_PetTotalInfo.PetStamina = m_dwMaxStamina;
	}
}

void CPet::CalcStamina()
{
	//���� ���¿� �´� ���ҷ� ����
	if(gCurTime - m_dwStateCheckTime < PET_STATE_CHECK_TIME) return;

	switch(GetState())
	{
	case eObjectState_None:
	case eObjectState_Ungijosik:
		{m_dwStaminaDecrease = eSDA_STAND;}
		break;
	case eObjectState_Move:
		{m_dwStaminaDecrease = eSDA_MOVE;}
		break;
	case eObjectState_Rest:
		{m_dwStaminaDecrease = eSDA_REST;}
		break;
	case eObjectState_SkillUsing:	//!!! �̺�Ʈ ������ ó���ؾ��ҵ�
		{
			m_dwStaminaDecrease = 999; //!!! ��ų���ô� ��� ���� �����ۿ� ���� �ٸ�.
		}
		break;
	default:
		{m_dwStaminaDecrease = 0;}
	}

	m_PetTotalInfo.PetStamina -= m_dwStaminaDecrease;

	CalcFriendship();

	m_dwStateCheckTime = gCurTime;
}

void CPet::PlusStamina(DWORD amount)
{
	m_PetTotalInfo.PetStamina += amount;
	//DWORD dwCurMaxStamina = m_pSInfo->StaminaMax[m_PetTotalInfo.PetGrade-1];
	if( m_PetTotalInfo.PetStamina > m_dwMaxStamina )
	{m_PetTotalInfo.PetStamina = m_dwMaxStamina;}
}

void CPet::CalcFriendship()
{
	if( 0 == m_PetTotalInfo.PetStamina )
	{	m_PetTotalInfo.PetFriendly -= PET_REDUCE_FRIENDLY_ZEROSTAMINA;	}
}

// void CPet::CalcSkillRecharge()
// {
// 	//�������� ���� �����ۿ� ���� ���ʸ��� ����
// }

void CPet::SetMotionInState(BYTE State)
{
	m_MoveInfo.KyungGongIdx = eMA_WALKAROUND;
//	if(m_pMaster)
//	{
//		BASEMOVE_INFO MoveInfo;
//		m_pMaster->GetBaseMoveInfo(&MoveInfo);
//		m_MoveInfo.KyungGongIdx = MoveInfo.KyungGongIdx;
//	}

	switch(State)
	{
	case eObjectState_Move:
		{
			if(m_MoveInfo.KyungGongIdx)
			{
				m_ObjectState.State_Start_Motion = ePM_KGONG;
				m_ObjectState.State_Ing_Motion = ePM_KGONG;
				m_ObjectState.State_End_Motion = ePM_KGONG;
			}
			else
			{
				m_ObjectState.State_Start_Motion = ePM_MOVE;
				m_ObjectState.State_Ing_Motion = ePM_MOVE;
				m_ObjectState.State_End_Motion = ePM_MOVE;
			}
			m_ObjectState.State_End_MotionTime = 0;

			ChangeMotion(m_ObjectState.State_Start_Motion,FALSE);
			if(m_ObjectState.State_Ing_Motion != -1)
				ChangeBaseMotion(m_ObjectState.State_Ing_Motion);
		}
		break;
	case eObjectState_None:
		{
			//if(m_ObjectState.State_Start_Motion != ePM_SUBSTAND)
			{
				m_ObjectState.State_Start_Motion = ePM_STAND;
				m_ObjectState.State_Ing_Motion = ePM_STAND;
				m_ObjectState.State_End_Motion = ePM_STAND;
				m_ObjectState.State_End_MotionTime = 0;
			}
		}
		break;
	default:
		{
			m_ObjectState.State_Start_Motion = -1;
			m_ObjectState.State_Ing_Motion = -1;
			m_ObjectState.State_End_Motion = -1;
			m_ObjectState.State_End_MotionTime = 0;
		}
		break;
	}
}

float CPet::DoGetMoveSpeed()
{
	float speed = 400;	//����ĳ���͸� ��ã���� �ÿ� ���� ��(���꿬���� ���� ���ʿ�)
	if(m_pMaster)
	{
		speed = m_pMaster->DoGetMoveSpeed() * m_pSInfo->SpeedFromHero;
	}
	return speed;
}

void CPet::SetMaster(CPlayer* pPlayer)
{
	m_pMaster=pPlayer;
	if(pPlayer)
		m_dwMasterID = pPlayer->GetID();	
	else
		m_dwMasterID = 0;
}
void CPet::SetPetMasterName( DWORD dwMasterIdx )
{
	CPlayer* pMaster = (CPlayer*)OBJECTMGR->GetObject(dwMasterIdx);
	//ASSERT(pMaster); //���ΰ� ���� �׸��尡 �ٸ��� �����ϴ�.
	if(pMaster)
	{
		if( m_pObjectBalloon )
		{
			char szBuf[MAX_MASTERNAME_LENGTH+1] = {0,};
			sprintf(szBuf, "%s%s", pMaster->GetObjectName(), CHATMGR->GetChatMsg(1248));
			m_pObjectBalloon->SetMasterName(szBuf);
		}
	}

	ASSERT(dwMasterIdx);
	//m_dwMasterID = dwMasterIdx;
}

void CPet::SetPetMasterName( char* pMasterName )
{
	if( m_pObjectBalloon )
	{
		char szBuf[MAX_MASTERNAME_LENGTH+1] = {0,};
		sprintf(szBuf, "%s%s", pMasterName, CHATMGR->GetChatMsg(1248));
		m_pObjectBalloon->SetMasterName(szBuf);
	}
}

void CPet::Die()
{
	int DieEffect = GAMERESRCMNGR->GetPetListInfo(GetPetIdx())->DieDramaNum[GetPetCurGrade()-1];

	if(DieEffect != -1)
	{
		TARGETSET set;
		set.pTarget = this;

		EFFECTMGR->StartEffectProcess(DieEffect,this,&set,1,GetID(),
			EFFECT_FLAG_DIE|EFFECT_FLAG_GENDERBASISTARGET);

	}

	GetEngineObject()->ChangeBaseMotion(ePM_DIED);

	SetDieFlag();
}
