// MacroManager.h: interface for the CMacroManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MACROMANAGER_H__A85EAD4A_B009_45AE_AC28_B00E31856F59__INCLUDED_)
#define AFX_MACROMANAGER_H__A85EAD4A_B009_45AE_AC28_B00E31856F59__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define MACROMGR USINGTON(CMacroManager)

class CKeyboard;
//---------------------------------------------------------------------------------------
// taiyo 
// ����� �ӽ÷� ����Ű�� ����������,
// ����Ű ����� ���� �߰��� ����!
//---------------------------------------------------------------------------------------
//KES_030806
// ����Ű ���
//---------------------------------------------------------------------------------------


////////////
//����Ű���
//#define START_CONFLICT_CHAT		ME_USE_QUICKITEM01	//ä�ð� �浹�Ǵ� ����Ű.

enum eMacroEvent {	//���̾�α׿� ������ ���߾�� �Ѵ�.

//�̸� üũ�ؾ��Ұ�.
	ME_TOGGLE_EXITDLG,
//	ME_TOGGLE_UNGIMODE,		//*****

///////////////////////////
	ME_USE_QUICKITEM01,
	ME_USE_QUICKITEM02,
	ME_USE_QUICKITEM03,
	ME_USE_QUICKITEM04,
	ME_USE_QUICKITEM05,
	ME_USE_QUICKITEM06,
	ME_USE_QUICKITEM07,

	ME_USE_QUICKITEM08,
	ME_USE_QUICKITEM09,
	ME_USE_QUICKITEM10,

	ME_TOGGLE_MUGONGDLG,
	ME_TOGGLE_INVENTORYDLG,
	ME_TOGGLE_CHARACTERDLG,
	ME_TOGGLE_MUNPADLG,
//	ME_TOGGLE_PARTYDLG,

	ME_TOGGLE_MINIMAP,

	ME_TOGGLE_QUESTDLG,
//New
//	ME_APPLY_EXCHANGE,		//*****
//	ME_OPEN_STREETSTALL,	//*****
	ME_TOGGLE_OPTIONDLG,
//	ME_CLOSE_ALLWINDOW,			//*****
	ME_TOGGLE_FRIENDLIST,
	ME_SEND_MEMO,
//	ME_APPLY_VIMU,			//*****
//
//	ME_CLOSE_ACTIVEDLG,	//��ũ�ΰ� �� �ʿ� ���� �Ǿ��ִ�.. ���߿� �����.
	
	ME_TOGGLE_MOVEMODE,
//	ME_TOGGLE_KYUNGGONG,			//*****

//	ME_PAGEDN_QUICKSLOT,
//	ME_PAGEUP_QUICKSLOT,
	ME_SELECT_QUICKSLOT1,
	ME_SELECT_QUICKSLOT2,
	ME_SELECT_QUICKSLOT3,
	ME_SELECT_QUICKSLOT4,

	ME_TOGGLE_PEACEWARMODE,

	ME_TOGGLE_AUTOATTACK,
	ME_TOGGLE_AUTOATTACK2,

	ME_TOGGLE_HELP,
	
	ME_TOGGLE_CAMERAVIEWMODE,
//	ME_CAMERAMODE_BACKVIEW,
//	ME_CAMERAMODE_QUARTERVIEW,
//	ME_CAMERAMODE_LOADVIEW,
//	ME_CAMERAMODE_SAVEVIEW,

	ME_SCREENCAPTURE,

	ME_SHOWALLNAME_ON,
	ME_SHOWALLNAME_OFF,

	ME_CHANGE_WHISPERLIST_UP,
	ME_CHANGE_WHISPERLIST_DOWN,
	
	ME_TOGGLE_BIGMAP,
	ME_MUSSANG_ON,
	ME_TOGGLE_KEY_SETTING_TIP_SHOW,
	ME_TOGGLE_KEY_SETTING_TIP_HIDE,

	ME_TOGGLE_TITANINVENTORYDLG,	//2007. 10. 8. CBH - Ÿ��ź �κ� ����Ű �߰�

	ME_COUNT,					//��ũ�� �� ����
};

enum eMacroPressEvent
{
	MPE_CAMERAMOVE_ZOOMIN,
	MPE_CAMERAMOVE_ZOOMOUT,
	
	MPE_CAMERAMOVE_UP,
	MPE_CAMERAMOVE_DOWN,
	MPE_CAMERAMOVE_RIGHT,
	MPE_CAMERAMOVE_LEFT,
	
	MPE_COUNT,
};

////////
//����Ű
enum eSysKey {

	MSK_NONE	= 1,	//
	MSK_CTRL	= 2,
	MSK_ALT		= 4,
	MSK_SHIFT	= 8,
	MSK_ALL		= MSK_NONE | MSK_CTRL | MSK_ALT | MSK_SHIFT,
};

//////////////
//��ũ�α���ü
struct sMACRO
{
	int		nSysKey;	//����Ű
	WORD	wKey;		//����Ű
	BOOL	bAllMode;	//ä�ø�忡 ������� �Ǿ���ϴ� ��üũ
	BOOL	bUp;		//up�� �̺�Ʈ�� �߻��ؾ� �Ұ�
};


enum eMacroMode {


	MM_CHAT,					//ä�� �켱���
	MM_MACRO,					//����Ű �켱���

//	MM_DEFAULT_CHAT = 0,		//����Ʈ ä�ÿ켱���
//	MM_DEFAULT_GENERAL,			//����Ʈ �Ϲݸ��

//	MM_USERSET_CHAT,			//������ ä�ÿ켱���
//	MM_USERSET_GENERAL,			//������ �Ϲݸ��

	MM_COUNT,
};




class CMacroManager
{

protected:

	sMACRO		m_DefaultKey[MM_COUNT][ME_COUNT];	//����Ʈ��ũ��Ű
	sMACRO		m_MacroKey[MM_COUNT][ME_COUNT];		//������ũ��Ű

	sMACRO		m_DefaultPressKey[MM_COUNT][MPE_COUNT];		//����Ʈ��ũ��������Ű
	sMACRO		m_MacroPressKey[MM_COUNT][MPE_COUNT];		//������ũ��������Ű

	int			m_nMacroMode;					//���õ� ��ũ�� ���
//	int			m_nUserSetMode;					//�������ÿ��� ���õ� ���
	BOOL		m_bPause;
	BOOL		m_bChatMode;
	BOOL		m_bInVisibleCursor;

protected:
	BOOL LoadMacro( LPCTSTR strPath );
	BOOL SaveMacro( LPCTSTR strPath );
	void SetDefaultMacro( int nMacroMode );

public:
	CMacroManager();
	virtual ~CMacroManager();

//	//MAKESINGLETON(CMacroManager);
	BOOL IsVisibleCursor() { return !m_bInVisibleCursor; }

	void Init();
	void KeyboardInput( CKeyboard* keyInfo );
	void KeyboardPressInput( CKeyboard* keyInfo );
	void LoadUserMacro();
	void SaveUserMacro();

	void GetMacro( int nMacroMode, sMACRO* pMacro );		//��ü ��ũ�� ����
	void SetMacro( int nMacroMode, sMACRO* pMacro );		//���� ��ũ�� ����

	sMACRO* GetCurMacroKey( int nMacroEvent )	//Ư�� ��ũ��Ű �ϳ� ����
	{ 
		if( nMacroEvent >= ME_COUNT )
			return NULL;
		
		return &m_DefaultKey[m_nMacroMode][nMacroEvent];	//���Ŀ� �ٲ���.userset�������ÿ�.
	}
	
	void GetDefaultMacro( int nMacroMode, sMACRO* pMacro );

	int GetMacroMode() { return m_nMacroMode; }
	void SetMacroMode( int nMacroMode );

//	int GetUserSetMode() { return m_nUserSetMode; }
//	void SetUserSetMode( int nUserSetMode ) { m_nUserSetMode = nUserSetMode; }

	void SetPause( BOOL bPause ) { m_bPause = bPause; }
	int IsUsableKey( CKeyboard* keyInfo, WORD* wKey, BOOL bUserMode );
	BOOL IsChatMode()	{ return m_bChatMode; }

	void PlayMacro( int nMacroEvent );
	void PlayMacroPress( int nMacroEvent );
/////
};

EXTERNGLOBALTON(CMacroManager)

#endif // !defined(AFX_MACROMANAGER_H__A85EAD4A_B009_45AE_AC28_B00E31856F59__INCLUDED_)
