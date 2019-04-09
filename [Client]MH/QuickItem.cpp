// QuickItem.cpp: implementation of the CQuickItem class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QuickItem.h"
#include "./interface/cWindowManager.h"
#include "./interface/cFont.h"
#include "Item.h"
#include "MugongBase.h"
#include "ItemManager.h"
#include "Hero.h"
#include "ObjectManager.h"
#include "SkillManager_client.h"
#include "GameIn.h"
#include "MugongDialog.h"
#include "ChatManager.h"
#include "./Interface/cScriptManager.h"
#include "./Input/UserInput.h"
#include "AbilityIcon.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CQuickItem::CQuickItem(CBaseItem * pItemLink)
{
	m_type = WT_QUICKITEM;
	m_pItemLink = pItemLink;
	m_QDur = 0;
	m_bRemainTime	= FALSE;
	m_dwLastSecond	= 0;
}

CQuickItem::~CQuickItem()
{

}

void CQuickItem::SetImage2(cImage * low, cImage * high)
{
	SetBasicImage(low);
	if(high)
	m_HighLayerImage = *high;
	
	SCRIPTMGR->GetImage( 127, &m_DelayImage  );	

	//////////////////////////////////////////////////////////////////////////
	// 06. 06. 2�� ���� - �̿���
	// ���� ��ȯ �߰�
	SCRIPTMGR->GetImage( 87, &m_OptionImage, PFT_MUGONGPATH );
	//////////////////////////////////////////////////////////////////////////
}
void CQuickItem::Render()
{
	DWORD colorBackup = m_dwImageRGB;
	//m_dwImageRGB = RGB_HALF(255, 60,60);
	if( !m_bActive ) return;

//	if( m_bRemainTime )
//	{
//		m_dwImageRGB &= RGB_HALF(200,200,200);		
//	}

	cIcon::Render();

	if(!m_HighLayerImage.IsNull())
		m_HighLayerImage.RenderSprite( NULL, NULL, 0, &m_absPos, RGBA_MERGE(m_dwImageRGB, m_alpha * m_dwOptionAlpha / 100));

	if(!m_LinkImage.IsNull())
	{
		VECTOR2 pos = { m_absPos.x+1, m_absPos.y+29 };
		m_LinkImage.RenderSprite(NULL, NULL, NULL, &pos, RGBA_MERGE(m_dwImageRGB, m_alpha * m_dwOptionAlpha / 100));
	}
	
	if(m_pItemLink)
	{
		if(GetIconKind( m_pItemLink->GetItemIdx()) != eMUGONG_ICON && ITEMMGR->IsDupItem(m_pItemLink->GetItemIdx()))
		{		
			static char nums[4];
			wsprintf(nums,"%3d", m_QDur);	// �����۴���â�� ���� ǥ�� �κ��� ����. 3�ڸ�����.. & ��ġ�� �������� ���� ��� by Stiner(6)
			RECT rect={(LONG)m_absPos.x+21, (LONG)m_absPos.y+29, 1,1};
			CFONT_OBJ->RenderFont(0,nums,strlen(nums),&rect,RGBA_MERGE(m_dwImageRGB, m_alpha * m_dwOptionAlpha / 100));		// color hard coding : taiyo 
		}

		if(GetIconKind( m_pItemLink->GetItemIdx()) == eABILITY_ICON)
		{
			((CAbilityIcon*)m_pItemLink)->RenderInfo(&m_absPos);
		}

		if(GetIconKind( m_pItemLink->GetItemIdx()) == eITEM_ICON)
		{
			CItem* pItem = ITEMMGR->GetItem(m_pItemLink->GetDBIdx());
			if( pItem )
			{
				if( pItem->GetItemBaseInfo()->ItemParam & ITEM_PARAM_TITAN_REGIST )
				{
					cDialog::Render();

					RECT rect={(LONG)m_absPos.x+9, (LONG)m_absPos.y+15, 1,1};
					CFONT_OBJ->RenderFont(0,CHATMGR->GetChatMsg(1515),4,&rect,RGBA_MAKE(250,250,128,255));	// magi82 - Titan(070427)

					// magi82 - Titan(070913) Ÿ��ź ���� ������
					DWORD dwRemainTime = 0;
					float delayRate = HERO->GetDelayGroup()->CheckDelay(CDelayGroup::eDK_Item,pItem->GetItemIdx(), &dwRemainTime );
					if( delayRate > 0.0f )
					{
						VECTOR2 vScale = { 1.0f, delayRate };
						VECTOR2 pos = { m_absPos.x, m_absPos.y + m_height*(1 - delayRate) };
						m_DelayImage.RenderSprite( &vScale, NULL, 0.0f, &pos, 0xff000000  );
					}
				}
				else if( pItem->GetItemKind() == eYOUNGYAK_ITEM_TITAN )
				{
					DWORD dwRemainTime = 0;
					float delayRate = HERO->GetDelayGroup()->CheckTitanPotionDelay(&dwRemainTime );
					if( delayRate > 0.0f )
					{
						VECTOR2 vScale = { 1.0f, delayRate };
						VECTOR2 pos = { m_absPos.x, m_absPos.y + m_height*(1 - delayRate) };
						m_DelayImage.RenderSprite( &vScale, NULL, 0.0f, &pos, 0xff000000  );
					}

				}
			}
		}
	}

	if( GetIconKind( m_pItemLink->GetItemIdx()) == eMUGONG_ICON )
	{
		//////////////////////////////////////////////////////////////////////////
		// 06. 06. 2�� ���� - �̿���
		// ���� ��ȯ �߰�
		if(((CMugongBase*)m_pItemLink)->GetOption())
			m_OptionImage.RenderSprite( NULL, NULL, 0, &m_absPos, RGBA_MERGE(m_dwImageRGB, m_alpha * m_dwOptionAlpha / 100));
		//////////////////////////////////////////////////////////////////////////

		DWORD dwRemainTime = 0;
		//SW070127 Ÿ��ź
		//float delayRate = HERO->GetDelayGroup()->CheckDelay(CDelayGroup::eDK_Skill,m_pItemLink->GetItemIdx(), &dwRemainTime );
		DWORD mugongIdx = 0;
		if( FALSE == HERO->InTitan() )	//Ÿ��ź ��ž�½ð� �� ���� ���̴�.
		{
			mugongIdx = m_pItemLink->GetItemIdx();
		}
		else
		{
			mugongIdx = m_pItemLink->GetItemIdx();
		}
		float delayRate = HERO->GetDelayGroup()->CheckDelay(CDelayGroup::eDK_Skill,(WORD)mugongIdx, &dwRemainTime );
//		if(delayRate)
//		{
//			m_dwImageRGB = RGB_HALF(BYTE(255*delayRate),0,0);
//		}


		if( delayRate > 0.0f )
		{
			VECTOR2 vScale = { 1.0f, delayRate };
			VECTOR2 pos = { m_absPos.x, m_absPos.y + m_height*(1 - delayRate) };
			m_DelayImage.RenderSprite( &vScale, NULL, 0.0f, &pos, 0xff000000  );
		}

	
		if( WINDOWMGR->IsMouseOverUsed() )
		{
			
			int mx = g_UserInput.GetMouse()->GetMouseX();
			int my = g_UserInput.GetMouse()->GetMouseY();
			
			if( PtInWindow( mx, my ) == TRUE )
			{
				
				if( dwRemainTime )
				{
					if( m_dwLastSecond != dwRemainTime/1000+1 )
					{
						m_dwLastSecond = dwRemainTime/1000+1;
						SetMugongIconToolTip( dwRemainTime );
						m_bRemainTime = TRUE;
					}
				}
				else if( m_bRemainTime == TRUE )
				{
					SetMugongIconToolTip( dwRemainTime );
					m_bRemainTime = FALSE;
					m_dwLastSecond = 0;
				}
				else
				{
					SetMugongIconToolTip( dwRemainTime );	//���콺�� ������ �׻� �������� �ʿ䰡 �ִ�.
				}
			}
		}

	}
	
	m_dwImageRGB = colorBackup;
}


void CQuickItem::SetMugongIconToolTip( DWORD dwRemainTime )
{
	CSkillInfo* pCommSkill	= SKILLMGR->GetSkillInfo( GetSrcIdx() );
	
	if( pCommSkill )
	{
		char ToolTipText[256] = { 0, };

		// magi82 - �Լ��� �ݺ��� �ʿ����. �ٱ��� �ϳ��� ������.
		WORD wCommSkillWeaponType = pCommSkill->GetWeaponType();
		WORD wCommSkillKind = pCommSkill->GetSkillKind();
		
		//				cImage imgToolTip;
		//				SCRIPTMGR->GetImage( 63, &imgToolTip, PFT_HARDPATH );
		//				SetToolTip( "", RGB_HALF( 255, 255, 255), &imgToolTip, TTCLR_ITEM_CANEQUIP );
		SetToolTip( "", RGB_HALF( 255, 255, 255), NULL, TTCLR_ITEM_CANEQUIP );
		
		wsprintf(ToolTipText, "[%s]", pCommSkill->GetSkillName() );
		AddToolTipLine( ToolTipText, TTTC_DEFAULT );
		
		CMugongBase* pMugongBase = GAMEIN->GetMugongDialog()->GetMugongAbs( GetSrcPosition() );
		
		if( pMugongBase )
		{
			//������ ��� �� / �ʿ䳻��
			int NeedExp = pCommSkill->GetNeedExp( pMugongBase->GetSung() );
			
			if( NeedExp > 0 )
			{
				if( pMugongBase->GetSung() < 12 )
				{
					float percent = pMugongBase->GetExpPoint() * 100.0f / NeedExp;
					if( percent > 99.99f )
					{
						if( pMugongBase->GetExpPoint() != NeedExp - 1 )
						{
							percent = 99.99f;
						}
					}

					sprintf( ToolTipText, CHATMGR->GetChatMsg(471), pMugongBase->GetSung(), percent );
				}
				else
				{
					if(SKILLMGR->IsDeadlyMugong(pMugongBase->GetItemIdx()) == FALSE)
						sprintf( ToolTipText, CHATMGR->GetChatMsg(405), pMugongBase->GetSung() );
				}
				AddToolTipLine( ToolTipText, TTTC_MUGONGEXP );
			}
			
			if( pMugongBase->GetSung() > 0 )
			{
				wsprintf( ToolTipText, CHATMGR->GetChatMsg(472), pCommSkill->GetNeedNaeRyuk( pMugongBase->GetSung() ) );
				AddToolTipLine( ToolTipText, TTTC_MUGONGNEEDMANA );
			}

			// magi82 - Titan(070911) Ÿ��ź ����������Ʈ
			//QuickSlot�� ��ϵ� ������ Ÿ��ź ���� ���� �����ֱ�
			//if(HERO->InTitan())
			//{
			//	CSkillInfo* pSkillInfo = SKILLMGR->GetSkillInfo(pCommSkill->GetSkillIndex());
			//	if( !pSkillInfo )
			//	{
			//		ASSERT(0);
			//	}

			//	AddToolTipLine( "" );

			//	// Ÿ��ź �̿밡���ϴٴ°� ǥ��
			//	wsprintf(ToolTipText, CHATMGR->GetChatMsg(1561));
			//	AddToolTipLine( ToolTipText, TTTC_MUGONGNEEDMANA );

			//	//���¼Ҹ�
			//	wsprintf( ToolTipText, CHATMGR->GetChatMsg(472), pSkillInfo->GetNeedNaeRyuk(pMugongBase->GetSung()) );
			//	AddToolTipLine( ToolTipText, TTTC_MUGONGNEEDMANA );
			//}

			//���ѷ��� üũ�ؼ� �̹��� rgb �ٲٱ�
			if( pCommSkill->GetSkillInfo()->RestrictLevel > HERO->GetLevel() )
			{
				wsprintf( ToolTipText, CHATMGR->GetChatMsg(460), pCommSkill->GetSkillInfo()->RestrictLevel );
				AddToolTipLine( ToolTipText, TTTC_LIMIT );
				m_dwImageRGB = RGBA_MAKE( 255, 100, 100, 255 );
			}
			else
			{
				m_dwImageRGB = RGBA_MAKE( 255, 255, 255, 255 );
			}
		}
		
		// magi82 - Titan(070911) Ÿ��ź ����������Ʈ
		if( wCommSkillKind == SKILLKIND_TITAN && HERO->InTitan() == FALSE )
			AddToolTipLine( CHATMGR->GetChatMsg(1655), TTTC_LIMIT );

		if( wCommSkillKind != SKILLKIND_TITAN && HERO->InTitan() == TRUE )
			AddToolTipLine( CHATMGR->GetChatMsg(1656), TTTC_LIMIT );

		BOOL bFlag = FALSE;
		WORD wHeroWeaponType = HERO->GetWeaponEquipType();
		WORD wTitanWeaponType = HERO->GetTitanWeaponEquipType();

		if(HERO->InTitan() == TRUE)	// Ÿ��ź ž�����϶�..
		{
			if( wCommSkillKind == SKILLKIND_TITAN )
			{
				if( wCommSkillWeaponType != WP_WITHOUT )	// ������ ���Ⱑ ����
				{
					if( wCommSkillWeaponType != wTitanWeaponType )
						bFlag = TRUE;					
				}
			}			
		}
		else	// Ÿ��ź ž������ �ƴҶ�..
		{
			if( wCommSkillKind == SKILLKIND_OUTERMUGONG && wCommSkillWeaponType != wHeroWeaponType )
			{
				bFlag = TRUE;
			}
		}

		if( bFlag == TRUE )
		{
			switch(wCommSkillWeaponType)
			{
			case WP_GUM:
				AddToolTipLine( CHATMGR->GetChatMsg(465), TTTC_LIMIT );
				break;
			case WP_GWUN:	
				AddToolTipLine( CHATMGR->GetChatMsg(466), TTTC_LIMIT );
				break;
			case WP_DO:	
				AddToolTipLine( CHATMGR->GetChatMsg(467), TTTC_LIMIT );
				break;
			case WP_CHANG:	
				AddToolTipLine( CHATMGR->GetChatMsg(468), TTTC_LIMIT );
				break;
			case WP_GUNG:	
				AddToolTipLine( CHATMGR->GetChatMsg(469), TTTC_LIMIT );
				break;
			case WP_AMGI:	
				AddToolTipLine( CHATMGR->GetChatMsg(470), TTTC_LIMIT );
				break;
			}
		}

		// magi82 - Titan(071011) Ÿ��ź ����������Ʈ
		// Ÿ��ź�� ĳ������ ������ �ٸ��� ��� ���ϰ� �ؾ��Ѵ�.
		if( wCommSkillKind == SKILLKIND_TITAN )
		{
			if( wCommSkillWeaponType != WP_WITHOUT )	// ������ ���Ⱑ ����
			{
				if( wHeroWeaponType != wTitanWeaponType )
					AddToolTipLine( CHATMGR->GetChatMsg(1660), TTTC_LIMIT );
			}
		}

		if( dwRemainTime )
		{
			wsprintf(ToolTipText, CHATMGR->GetChatMsg(582), dwRemainTime/1000+1 );
			AddToolTipLine( ToolTipText, TTTC_QUESTITEM );
		}
	}		
}
