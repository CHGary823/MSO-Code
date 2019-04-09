#ifndef __STREETSTALLMANAGER__
#define __STREETSTALLMANAGER__

#include "IndexGenerator.h"
// LYJ 051017 ���Գ����� �߰�
#include "StallKindSelectDlg.h"

#define STREETSTALLMGR USINGTON(CStreetStallManager)

#define STREETSTALL_MAX_LINKITEM 5

class CItem;
class CExchangeItem;
class CBuyItem;
class CObject;
// LYJ 051017 ���Գ����� �߰�
class CStallKindSelectDlg;
class CMapObject;
class CPlayer;

class CStreetStallManager 
{
	CIndexGenerator m_IconIndexCreator;
	WORD m_wStallKind;
protected:
	int m_nLinkedItemNum;				// ��� ������ ����
//	int m_selectedQuickAbsPos;
	
	BOOL m_bOpenMsgBox;

//	STREETSTALL_BUYINFO m_BuyMsg;
	
	char m_strOldTitle[MAX_STREETSTALL_TITLELEN + 1];

//KES
//	POSTYPE	m_posWantBuy;
	DWORD	m_dwWantBuyNum;
	DWORD	m_dwWantSellNum;

public:
	//MAKESINGLETON(CStreetStallManager);

	CStreetStallManager();
	virtual ~CStreetStallManager();
	
	void Init();

	void SetOpenMsgBox(BOOL bOpen) { m_bOpenMsgBox = bOpen; }
	
	BOOL LinkItem( CItem* pItem, ITEMBASE* pBase );
	BOOL LinkItem(POSTYPE pos, ITEMBASE ItemInfo, WORD Volume, DWORD Money);
	void UnlinkItem( CExchangeItem* pItem );
	void UnlinkItem( CBuyItem* pItem );
	void LinkBuyItem( STREETSTALL_INFO* pStallInfo );
	void LinkSellItem( STREETSTALL_INFO* pStallInfo );
	int GetLinkedItemNum() { return m_nLinkedItemNum; }
	
	void ToggleHero_StreetStallMode( BOOL bOpen );
	void Toggle_StreetStallMode( CObject* pObject, BOOL bStreet);

	void ChangeDialogState();

	// ��Ʈ��ũ
	void OpenStreetStall();
	void CloseStreetStall();
	void EnterStreetStall( DWORD OwnerId );

	void RegistItemEx( CItem* pItem , DWORD money );
	void RegistItemEx( ITEMBASE ItemInfo, WORD wAbsPosition, WORD Volume , DWORD money );

	void ItemStatus( CExchangeItem* pItem, BOOL bLock );
	void ItemStatus( POSTYPE pos, BOOL bLock );
	void EditTitle();
	void NetworkMsgParse( BYTE Protocol, void* pMsg );

	void BuyItem();
	void BuyItemDur( POSTYPE pos, DWORD dwNum );

	void SendBuyItemMsg();

	BOOL SellItem();
	BOOL SellItemDur( DWORD dwNum );
	
	BOOL SendSellItemMsg();

	WORD GetStallKind() { return m_wStallKind; }
	void SetStallKind(WORD wStallKind) { m_wStallKind = wStallKind; }

	// magi82(44) - ������ �ٹ̱� ������Ʈ
	CMapObject* AddStreetStallDecoration(CPlayer* pPlayer, DWORD dwStreetStallKind);
};
EXTERNGLOBALTON(CStreetStallManager);

#endif //__STREETSTALLMANAGER__
