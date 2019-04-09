// cScriptManager.h: interface for the cScriptManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CSCRIPTMANAGER_H__B9C3CDD2_6869_4A8A_801C_BA26B097B799__INCLUDED_)
#define AFX_CSCRIPTMANAGER_H__B9C3CDD2_6869_4A8A_801C_BA26B097B799__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "cWindowDef.h"

//2007. 5. 18. Parse Type ���� ������� �߰�
#include "ClientGameDefine.h"
#include "ClientGameStruct.h"
//

class cWindow;
class cImage;
class CMHFile;


#define SCRIPTMGR	USINGTON(cScriptManager)
enum ePATH_FILE_TYPE
{
	PFT_HARDPATH = 0,
	PFT_ITEMPATH	,
	PFT_MUGONGPATH	,
	PFT_ABILITYPATH ,
	PFT_BUFFPATH ,
	PFT_MINIMAPPATH ,
	PFT_JACKPOTPATH,
};

struct sIMAGHARDPATH
{
	int	idx;
	LONG left;
	LONG top;
	LONG right;
	LONG bottom;
};

class cScriptManager  
{
public:
//	MAKESINGLETON(cScriptManager);
	cScriptManager();
	virtual ~cScriptManager();

	cWindow * GetDlgInfoFromFile(char * filePath, char* mode = "rt");

	cWindow * GetInfoFromFile(cWindow * wnd, CMHFile * fp);
	cWindow * GetCtrlInfo(cWindow * wnd, char * buff, CMHFile * fp);

	void GetImage( int idx, cImage * pImage, cImageRect * rect );
	void GetImage( int hard_idx, cImage * pImage , ePATH_FILE_TYPE type = PFT_HARDPATH );

	void CheckPosForResolution(cPoint* pPos);

	//////////// 2007. 5. 18. Parse ���� �߰� //////////////////
	BOOL InitParseTypeData();		//Parse Type ������ �ʱ�ȭ �� �ε�
	void ReleaseParseTypeData();	//Parse Type ������ ����
	////////////////////////////////////////////////////////////

	void InitScriptManager();

	// 2007. 11. 1. CBH - IMAGEPATH ���̺� �޸� ���� �Լ�
	void cScriptManager::ReleaseImagePathTable();
protected:
	void GetImage( CMHFile * fp, cImage * pImage );
	char * GetMsg( int idx );

	//////////// 2007. 5. 18. Parse ���� �߰� /////////////
	int ChangeHashKey(const char* cpTypeName, int nMaxNum);		//���ڿ��� �ؽ�Ű������ �ٲٴ� �Լ�
	PARSE_TYPE GetParseType(const char* str);		//�ش� �Ľ� ���ڿ��� �ش��ϴ� ���̵� �� ��ȯ
	CYHHashTable<PARSE_TYPE_INFO> m_ParseTypeTable; //�Ľ̵� ���� Ÿ������ �ؽ����̺�	
	///////////////////////////////////////////////////////

	CYHHashTable<sIMAGHARDPATH> m_ImageHardPath;
	CYHHashTable<sIMAGHARDPATH>	m_ItemHardPath;
	CYHHashTable<sIMAGHARDPATH> m_MugongHardPath;
	CYHHashTable<sIMAGHARDPATH> m_AbilityHardPath;
	CYHHashTable<sIMAGHARDPATH>	m_BuffHardPath;
	CYHHashTable<sIMAGHARDPATH> m_MiniMapHardPath;
	CYHHashTable<sIMAGHARDPATH> m_JackPotHardPath;
};
EXTERNGLOBALTON(cScriptManager);
#endif // !defined(AFX_CSCRIPTMANAGER_H__B9C3CDD2_6869_4A8A_801C_BA26B097B799__INCLUDED_)
