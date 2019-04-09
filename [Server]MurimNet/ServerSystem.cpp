// ServerSystem.cpp: implementation of the CServerSystem class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ServerSystem.h"
#include "ServerTable.h"

#include "Console.h"
#include "Network.h"
#include "DataBase.h"
#include "CommonNetworkMsgParser.h"
#include "MNNetworkMsgParser.h"
#include "BootManager.h"

#include "MurimNetSystem.h"
#include "MHTimeManager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CServerSystem * g_pServerSystem = NULL;


CServerSystem::CServerSystem()
{
	CoInitialize(NULL);
}

CServerSystem::~CServerSystem()
{
	CoUninitialize();
}


void CServerSystem::Start(WORD ServerNum)
{
	//////////////////////////////////////////////////////////////////////////
	// �ܼ� �ʱ�ȭ
	// ��ư ����.�ܺ��Է¿� ��ư�� 28�� �غ�Ǿ��ִ�.�Ѱ��� ������� ���� ��� pCustomButton �ʵ带 NULL�� ä���.
	MENU_CUSTOM_INFO cbutton[3];					// �ܺ� �Է��� ���� ��ư�� 2�� �����Ѵ�.
	cbutton[0].cbMenuCommand = ButtonProc1;		// ��ư�� ���������� �ݹ��Լ��� ����
	strcpy( cbutton[0].szMenuName, "Button1" );	// ��ư�� ĸ���� �����Ѵ�.
	cbutton[1].cbMenuCommand = ButtonProc2;
	strcpy( cbutton[1].szMenuName, "Button2" );
	cbutton[2].cbMenuCommand = ButtonProc3;
	strcpy( cbutton[2].szMenuName, "Button3" );

	if( !g_Console.Init( 3, cbutton, OnCommand ) )
		MessageBox( NULL, "Console �ʱ�ȭ ����", 0, 0 );

	char TitleText[255];
	sprintf( TitleText, "MURIM NET SERVER", ServerNum );
	SetWindowText( GetActiveWindow(), TitleText );
	
	//////////////////////////////////////////////////////////////////////////
	// ���� ���ҽ� �ε�

	SetNetworkParser();



	// servertable usertable �ʱ�ȭ ---------------------

	g_pServerTable = new CServerTable;
	g_pServerTable->Init( 500 );

	CUSTOM_EVENT ev[2];
	ev[0].dwPeriodicTime = 5;
	ev[0].pEventFunc = GameProcess;
	ev[1].dwPeriodicTime = 0;
	ev[1].pEventFunc = ProcessDBMessage;
//	ev[2].dwPeriodicTime = 1000*60*5;
//	ev[2].pEventFunc = _5minGameProcess;
	
	DESC_NETWORK desc;
	desc.OnAcceptServer = OnAcceptServer;
	desc.OnDisconnectServer = OnDisconnectServer;
	desc.OnAcceptUser = OnAcceptUser;
	desc.OnDisconnectUser = OnDisconnectUser;
	desc.OnRecvFromServerTCP = ReceivedMsgFromServer;
	desc.OnRecvFromUserTCP = ReceivedMsgFromUser;
//	desc.dwCustomDefineEventNum = 3;
	desc.dwCustomDefineEventNum = 2;
	desc.pEvent = ev;

	desc.dwMainMsgQueMaxBufferSize = 5120000;
	desc.dwMaxServerNum = 50;
	desc.dwMaxUserNum = 4000;
	desc.dwServerBufferSizePerConnection = 256000;
	desc.dwServerMaxTransferSize = 65000;
	desc.dwUserBufferSizePerConnection = 65000;
	desc.dwUserMaxTransferSize = 8192;
	desc.dwConnectNumAtSameTime = 100;
	desc.dwFlag = NULL;

	g_Network.Init(&desc);
	
	BOOTMNGR->AddSelfBootList(MAP_SERVER, ServerNum, g_pServerTable);
	if(!BOOTMNGR->StartServer(&g_Network, g_pServerTable->GetSelfServer()))
	{
		ASSERT(0);
	}
	if(!BOOTMNGR->ConnectToMS(&g_Network, g_pServerTable))
	{
		ASSERT(0);
	}

	//////////////////////////////////////////////////////////////////////////
	// DB ����
	DWORD maxthread = 2;
	DWORD maxqueryinsametime = 1024;
	
	if(g_DB.Init(maxthread,maxqueryinsametime) == FALSE)
	{
		MessageBox(NULL,"DataBase �ʱ�ȭ ����",0,0);//pjslocal
		exit(0);
	}

/////
	g_MNSystem.Init();



	g_Console.LOG(4, "-----------   MAP SERVER START  -----------------");
	g_Console.LOG(4, "-----------   MURIM NET SERVER  -----------------");
	// �� �κ��� �������� �޽��� ����.CONSOLE�� ����ϵ� ������ �޽��� ������� ¥�� ������ε� �̺�Ʈ�� ����ؾ���
	// �ϹǷ� ������ �޽��� ���� �ۼ��� �ϰ� ���� �ʴٸ� �� �޼ҵ带 ����Ѵ�.�� ��� ���� �޽��� ������ ������ ����� 
	// �����Ѵ�.�� �޼ҵ�� I4DyuchiCONSOLE ���̾�α��� x��ư�� ���������� �������� �ʴ´�.�� �޼ҵ尡 �����Ѵٸ� ��
	// �α׷��� �����ϴ� ���̴�.
	g_Console.WaitMessage();

}

void CServerSystem::End()
{
	g_DB.Release();
	g_Network.Release();
	g_Console.Release();

	if(g_pServerTable)
	{
		delete g_pServerTable;
		g_pServerTable = NULL;
	}

	g_MNSystem.Release();

	CoFreeUnusedLibraries();
}


void CServerSystem::Process()
{
	MHTIMEMGR_OBJ->Process();
}



void CServerSystem::SetNetworkParser()
{
	int i = 0;
	for( i = 0 ; i < MP_MAX ; ++i )		g_pUserMsgParser[i]		= NULL;
	for( i = 0 ; i < MP_MAX ; ++i )		g_pServerMsgParser[i]	= NULL;
	
//---ServerMsg Parser
	g_pServerMsgParser[MP_POWERUP]	= MP_POWERUPMsgParser;
	g_pServerMsgParser[MP_MURIMNET] = MP_MURIMNETMsgParser;
	g_pServerMsgParser[MP_USERCONN] = MP_USERCONNMsgParser;
	g_pServerMsgParser[MP_CHAT]		= MP_CHATMsgParser;

}




void CServerSystem::ReleaseAuthKey(DWORD key)
{

}



/////////////////////
//---global functions

void GameProcess()
{
	g_pServerSystem->Process();
}

void OnAcceptServer(DWORD dwConnectionIndex)
{
	g_Console.LOG( 4, "MURIM NET SERVER Connected : Connection-index %d", dwConnectionIndex );
}

void OnDisconnectServer(DWORD dwConnectionIndex)
{
	g_Console.LOG(4, "Serve Disconnected : Connection-index %d", dwConnectionIndex);

	// �������� ����
	SERVERINFO * delInfo = g_pServerTable->RemoveServer(dwConnectionIndex);
	if(!delInfo)
	{
		ASSERT(0);
	}
	delete delInfo;


	// taiyo
	// ������Ʈ�� �׾��ٸ�, ���� ��Ʈ�� ���� �ִ� ������ �����.
//	g_pUserTable->SetPositionHead();
//	CObject * info = NULL;
//	while(info = g_pUserTable->GetData())
//	{
//		if(info->GetObjectKind() == eObjectKind_Player)
//		{
//			CPlayer * ply = (CPlayer *)info;
//			if(ply->GetAgentNum() == dwConnectionIndex)
//			{
//				// ����ȯ����Ʈ�� �׻� 0���� �������ش�.
//				SaveMapChangePointUpdate(ply->GetID(), 0);
//				g_pServerSystem->RemovePlayer(ply->GetID());
//			}
				
//		}
//	}
/*
	char strr[255];
	
	SERVERINFO* serverinfo = g_pServerTable->FindServerForConnectionIndex(dwConnectionIndex);

	if(serverinfo)
		if(serverinfo->wPortForServer>MAPSERVER_PORT && serverinfo->wPortForServer < MAXSERVER_PORT)
		{
			MapUserUnRegistLoginMapInfo(serverinfo->wPortForServer);
		}

	wsprintf(strr, "%d �� connectionIndex ���� ���� ����", dwConnectionIndex);//pjslocal
	g_Console.LOG(4, strr);
	
	SERVERINFO * delInfo = g_pServerTable->RemoveServer(dwConnectionIndex);
	if(!delInfo)
	{
		ASSERT(0);
	}
	delete delInfo;
*/
}

void OnAcceptUser(DWORD dwConnectionIndex)
{

}

void OnDisconnectUser(DWORD dwConnectionIndex)
{

}

void ProcessDBMessage()
{
	g_DB.ProcessingDBMessage();
}

void ReceivedMsgFromServer(DWORD dwConnectionIndex,char* pMsg,DWORD dwLength)
{
	MSGROOT* pTempMsg = reinterpret_cast<MSGROOT*>(pMsg);

	if( g_pServerMsgParser[pTempMsg->Category] )	//�ӽ�
		g_pServerMsgParser[pTempMsg->Category](dwConnectionIndex, pMsg, dwLength);
}

void ReceivedMsgFromUser(DWORD dwConnectionIndex,char* pMsg,DWORD dwLength)
{
	MSGROOT* pTempMsg = reinterpret_cast<MSGROOT*>(pMsg);

	if( g_pUserMsgParser[pTempMsg->Category] )	//�ӽ�
		g_pUserMsgParser[pTempMsg->Category](dwConnectionIndex, pMsg, dwLength);
}



void OnConnectServerSuccess(DWORD dwConnectionIndex, void* pVoid)
{
	SERVERINFO* info = (SERVERINFO*)pVoid;
	info->dwConnectionIndex = dwConnectionIndex;
	if(info->wServerKind == MONITOR_SERVER)
	{
		BOOTMNGR->NotifyBootUpToMS(&g_Network);
		g_Console.LOG(4, "Connected to the MS : %s, %d, (%d)", info->szIPForServer, info->wPortForServer, dwConnectionIndex);
	}
	else
	{
		BOOTMNGR->SendConnectSynMsg(&g_Network, dwConnectionIndex, g_pServerTable);
		g_Console.LOG(4, "Connected to the Server : %s, %d, (%d)", info->szIPForServer, info->wPortForServer, dwConnectionIndex);
	}
	/*/// ������� taiyo
	if(!dwConnectionIndex) return;

	info->dwConnectionIndex = dwConnectionIndex;					// �̰� ����� �����ϳ�? üũ
	MSG_WORD msg;
	msg.Category = MP_SERVER;
	msg.Protocol = MP_SERVER_PWRUP;
	msg.wData = g_pServerTable->GetSelfServer()->wPortForServer;
	g_Network.Send2Server(dwConnectionIndex, (char*)&msg, sizeof(msg));
	//*/

	//PACKDATA���� ����ϴ� ����
	if(g_pServerTable->GetMaxServerConnectionIndex() < dwConnectionIndex)
			g_pServerTable->SetMaxServerConnectionIndex(dwConnectionIndex);
/*
	SERVERINFO* info = (SERVERINFO*)pVoid;
	info->dwConnectionIndex = dwConnectionIndex;
	if(info->wServerKind == MONITOR_SERVER)
	{
		BOOTMNGR->NotifyBootUpToMS(&g_Network);
		g_Console.LOG(4, "MS ���� ���� : %s, %d, (%d)", info->szIPForServer, info->wPortForServer, dwConnectionIndex);
	}
	else
	{
		BOOTMNGR->SendConnectSynMsg(&g_Network, dwConnectionIndex, g_pServerTable);
		g_Console.LOG(4, "���� ���� ���� : %s, %d, (%d)", info->szIPForServer, info->wPortForServer, dwConnectionIndex);
	}
*/
}

void OnConnectServerFail(void* pVoid)
{
	SERVERINFO* info = (SERVERINFO*)pVoid;
	if(info->wServerKind == MONITOR_SERVER)
	{
		BOOTMNGR->AddBootListINI(MAP_SERVER, 99, g_pServerTable);
		BOOTMNGR->BactchConnectToMap(&g_Network, g_pServerTable);
		g_Console.LOG(4, "Failed to Connect to the MS : %s, %d", info->szIPForServer, info->wPortForServer);
	}
	else
	{
		g_Console.LOG(4, "Failed to Connect to the Server : %s, %d", info->szIPForServer, info->wPortForServer);
		BOOTMNGR->RemoveBootList(g_pServerTable, info->wPortForServer);
	}	

}

/////////////////////////////
//--- console interface function
void ButtonProc1()
{
}

void ButtonProc2()
{
}

void ButtonProc3()
{
}

void OnCommand( char* szCommand )
{
}

