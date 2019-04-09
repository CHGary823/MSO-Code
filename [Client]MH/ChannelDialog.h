// ChannelDialog.h: interface for the CChannelDialog class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHANNELDIALOG_H__2799AAF3_2A8B_402D_86D4_EB2547D1888B__INCLUDED_)
#define AFX_CHANNELDIALOG_H__2799AAF3_2A8B_402D_86D4_EB2547D1888B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "./interface/cDialog.h"
#include ".\interface\cWindowHeader.h"


class cListCtrl;
class CChannelDialog  : public cDialog
{
	int m_BaseChannelIndex;
	cListCtrl * m_pChannelLCtrl;
	BOOL m_bInit;
	int m_SelectRowIdx;
#ifdef _KOR_LOCAL_
	WORD m_wMoveMapNum;	//2008. 5. 9. CBH - �̵��� ���� ��ȣ�� ����
	DWORD m_dwChangeMapState;	//2008. 5. 9. CBH - �̵��� ���� �Ű�ü ����
#endif

public:
	CChannelDialog();
	virtual ~CChannelDialog();

	virtual DWORD ActionEvent(CMouse * mouseInfo);
	void Linking();
	void SetChannelList(MSG_CHANNEL_INFO* pInfo);
	virtual void SetActive(BOOL val);

	void SelectChannel(int rowidx);
	void OnConnect();

#ifdef _KOR_LOCAL_
	//2008. 5. 8. CBH - ���̵� ä�� ���� ���� �Լ� �߰�
	void SendMapChannelInfoSYN(WORD wMapNum, DWORD dwState = eMapChange_General);	//�̵��� ���� ä�� ������ ��û�ϴ� �Լ�
	void MapChange();
#endif
};

#endif // !defined(AFX_CHANNELDIALOG_H__2799AAF3_2A8B_402D_86D4_EB2547D1888B__INCLUDED_)
