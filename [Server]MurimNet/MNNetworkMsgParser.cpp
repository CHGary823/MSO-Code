

#include "stdafx.h"
#include "MNNetworkMsgParser.h"
#include "MNDBMsgPArser.h"
#include "BootManager.h"
#include "MurimnetSystem.h"
#include "MNPlayerManager.h"
#include "MNPlayer.h"
#include "PlayRoom.h"
#include "PlayRoomManager.h"
#include "Channel.h"
#include "ChannelManager.h"
#include "MurimNetSystem.h"


void MP_MURIMNETMsgParser(DWORD dwConnectionIndex, char* pMsg, DWORD dwLength)
{
	MSGBASE* pTempMsg = (MSGBASE*)pMsg;
	switch(pTempMsg->Protocol)
	{
	case MP_MURIMNET_CONNECT_SYN:		// Ŭ���̾�Ʈ���� ������
		{
			MSG_DWORD2* pmsg = (MSG_DWORD2*)pMsg;

			/////////
/*
//for test
			if( g_MNSystem.GetPlayRoomManager()->GetPlayRoom(1)->IsStarted() )
				break;	//�ӽ�

			if( !g_MNSystem.GetPlayRoomManager()->GetPlayRoom(1) )
				break;	//�ӽ�
*/
			CMNPlayer* pPlayer = g_MNSystem.GetMNPlayerManager()->AddPlayer(
							pmsg->dwObjectID, dwConnectionIndex, pmsg->dwData1, pmsg->dwData2 );


			/////
			g_Console.LOG( 4, "[%6d]: User Connected", pmsg->dwObjectID );
			/////

			CharacterNumSendAndCharacterInfo( pmsg->dwObjectID );
		}
		break;

	case MP_MURIMNET_RECONNECT_SYN:		// Ŭ���̾�Ʈ���� ������
		{
			MSGBASE* pmsg = (MSGBASE*)pMsg;

//			ASSERT( !g_MNSystem.GetPlayRoomManager()->GetPlayRoom(1)->IsStarted() );
//			ASSERT( g_MNSystem.GetPlayRoomManager()->GetPlayRoom(1) );	//CONFIRM before Delete

			CMNPlayer* pMNPlayer = g_MNSystem.GetMNPlayerManager()->FindPlayer( pmsg->dwObjectID );
			ASSERT( pMNPlayer );
			if( pMNPlayer == NULL ) break;

			CPlayRoom* pPlayRoom = g_MNSystem.GetPlayRoomManager()->GetPlayRoom( pMNPlayer->GetLocationIndex() );
			ASSERT( pPlayRoom );
			if( pPlayRoom == NULL ) break;

			pPlayRoom->PlayerReconnect( pMNPlayer );

			//---LOG
			g_Console.LOG( 4, "[%6d]: User Re-Connected to the Murim Server", pmsg->dwObjectID );			
		}
		break;


	case MP_MURIMNET_PR_TEAMCHANGE_SYN:
		{
			MSG_BYTE* pmsg = (MSG_BYTE*)pMsg;

			//������ ���۵Ǿ����� Ȯ���ϱ�
			
			CMNPlayer* pMNPlayer = g_MNSystem.GetMNPlayerManager()->FindPlayer( pmsg->dwObjectID );
			
			if( pMNPlayer == NULL ) return;

			ASSERT( pMNPlayer->GetLocation() == eLOCATION_PLAYROOM );

			CPlayRoom* pPlayRoom = g_MNSystem.GetPlayRoomManager()->GetPlayRoom( pMNPlayer->GetLocationIndex() );

			if( pPlayRoom->IsStarted() ) break;

			if( pPlayRoom->TeamChange( pMNPlayer, pMNPlayer->GetTeam(), pmsg->bData ) == FALSE )
			{
				MSGBASE msg;
				msg.Category = MP_MURIMNET;
				msg.Protocol = MP_MURIMNET_PR_TEAMCHANGE_NACK;
				
				pMNPlayer->SendMsg( &msg, sizeof(msg) );
			}
		}
		break;
		
	case MP_MURIMNET_DISCONNECT_SYN:
		{
			MSGBASE* pmsg = (MSGBASE*)pMsg;

			//���̽��۵Ǿ����� Ȯ���߰�

			CMNPlayer* pPlayer = g_MNSystem.GetMNPlayerManager()->FindPlayer( pmsg->dwObjectID );
			if( pPlayer == NULL ) break;

			//---playermanager�� ó������
			if( pPlayer->GetLocation() == eLOCATION_PLAYROOM )
			{
				CPlayRoom* pPlayRoom = g_MNSystem.GetPlayRoomManager()->GetPlayRoom( pPlayer->GetLocationIndex() );
				if( pPlayRoom->IsStarted() )		//������ �̹� ���۵Ǿ���.
					break;

				pPlayRoom->PlayerOut( pPlayer );
			}
			else if( pPlayer->GetLocation() == eLOCATION_CHANNEL )
			{
				
			}

			g_MNSystem.GetMNPlayerManager()->DeletePlayer( pPlayer->GetID() );
			
			/////
			g_Console.LOG( 4, "[%6d]: User Disconnected", pPlayer->GetID() );
			/////
			//---

			//ACK
			MSG_DWORD msg;
			msg.Category	= MP_MURIMNET;
			msg.Protocol	= MP_MURIMNET_DISCONNECT_ACK;
			msg.dwData		= pPlayer->GetBackMapNum();
			
			pPlayer->SendMsg( &msg, sizeof(msg) );
			//
		}
		break;

	case MP_MURIMNET_CHNL_MODECHANGE:
		{
			MSG_BYTE* pmsg = (MSG_BYTE*)pMsg;

			CMNPlayer* pMNPlayer = g_MNSystem.GetMNPlayerManager()->FindPlayer( pmsg->dwObjectID );
			ASSERT( pMNPlayer );
			if( pMNPlayer == NULL ) break;

			ASSERT( pMNPlayer->GetLocation() == eLOCATION_CHANNEL );
			if( pMNPlayer->GetLocation() != eLOCATION_CHANNEL ) break;
			//pMNPlayer->SetChannelMode();
			
			g_MNSystem.SelectChannelMode( pMNPlayer, pmsg->bData );
		}
		break;
		
	case MP_MURIMNET_PR_START_SYN:
		{
			//msg to murimserver

			MSGBASE* pmsg = (MSGBASE*)pMsg;

			CMNPlayer* pPlayer = g_MNSystem.GetMNPlayerManager()->FindPlayer( pmsg->dwObjectID );

			ASSERT( pPlayer );
			ASSERT( pPlayer->IsCaptain() );
//			ASSERT( pPlayer->GetLocation()->nKind == eLOCATION_PLAYROOM );

			int nRoomNum = pPlayer->GetLocationIndex();
			CPlayRoom* pRoom = g_MNSystem.GetPlayRoomManager()->GetPlayRoom( nRoomNum );
			
			if( pRoom->IsStarted() ) break;

			static MSG_MNPLAYROOM_INFO MsgPlayRoomInfo;

			MsgPlayRoomInfo.Category	= MP_MURIMNET;
			MsgPlayRoomInfo.Protocol	= MP_MURIMNET_PLAYROOM_INFO_SYN;
			MsgPlayRoomInfo.nIndex		= nRoomNum;
			MsgPlayRoomInfo.nGameKind	= 1;	//eBATTLE_KIND_MURIMFIELD
			MsgPlayRoomInfo.nTotalPlayerNum = pRoom->GetPlayerNum();
			MsgPlayRoomInfo.wMapNum = pRoom->GetMapNum();
			pRoom->GetPlayerInfoList( MsgPlayRoomInfo.PlayerInfo );			

			static SEND_PACKED_TOMAPSERVER_DATA msg;
			msg.Category = MP_PACKEDDATA;
			msg.Protocol = MP_PACKEDDATA_TOMAPSERVER;
			msg.ToMapNum = 98;	//
			msg.wRealDataSize = MsgPlayRoomInfo.GetMsgLength();
			memcpy( msg.Data, &MsgPlayRoomInfo, MsgPlayRoomInfo.GetMsgLength() );
			pPlayer->SendMsg( &msg, msg.GetMsgLength() );
			
			//pRoom->SetStart( TRUE ); //���Ӹ� �����̰� �÷��̾���� ���ۻ��·� �θ� �ȵȴ�. �޼����� �Ȱ���..
		}
		break;

	case MP_MURIMNET_PLAYROOM_INFO_ACK:	//murimserver�κ��� ������ �����ص� ���ٴ� �޼���
		{
			//
			CPlayRoom* pRoom = g_MNSystem.GetPlayRoomManager()->GetPlayRoom( 1 );	//

			MSG_DWORD msg;
			msg.Category	= MP_MURIMNET;
			msg.Protocol	= MP_MURIMNET_PR_START;
			msg.dwData		= 98;	//

			pRoom->SendMsgToAll( &msg, sizeof( msg ) );
			pRoom->PlayStart( TRUE );	//�÷��̾���� ���ۻ��·� �ٲ۴�.
//			g_MNSystem.GetPlayRoomManager()->DeletePlayRoom( 1 ); //��ü ����Ʈ������ player����
		}
		break;

	case MP_MURIMNET_PLAYROOM_INFO_NACK:
		{
			CPlayRoom* pRoom = g_MNSystem.GetPlayRoomManager()->GetPlayRoom( 1 );	//
			pRoom->PlayStart( FALSE );
		}
		break;
		
	case MP_MURIMNET_CHAT_ALL:
		{
			TESTMSGID* pmsg = (TESTMSGID*)pMsg;
			CMNPlayer* pMNPlayer = g_MNSystem.GetMNPlayerManager()->FindPlayer( pmsg->dwObjectID );
			ASSERT( pMNPlayer );
			if( pMNPlayer == NULL ) break;

			switch( pMNPlayer->GetLocation() )
			{
			case eLOCATION_CHANNEL:
				{
					CChannel* pChannel = g_MNSystem.GetChannelManager()->GetChannel( pMNPlayer->GetLocationIndex() );
					if( pChannel )
						pChannel->SendMsgToAll( pmsg, dwLength );
				}
				break;

			case eLOCATION_PLAYROOM:
				{
					CPlayRoom* pPlayRoom = g_MNSystem.GetPlayRoomManager()->GetPlayRoom( pMNPlayer->GetLocationIndex() );
					if( pPlayRoom )
						pPlayRoom->SendMsgToAll( pmsg, dwLength );
				}
				break;
			}
		}
		break;
		
	case MP_MURIMNET_NOTIFYTOMN_PLAYER_LOGOUT:
		{
			MSG_DWORD2* pmsg = (MSG_DWORD2*)pMsg;
			CMNPlayer* pPlayer = g_MNSystem.GetMNPlayerManager()->FindPlayer( pmsg->dwData2 );

			ASSERT( pPlayer );
			if( pPlayer == NULL ) break;
			ASSERT( pPlayer->GetLocation() == eLOCATION_GAME );

			CPlayRoom* pPlayRoom = g_MNSystem.GetPlayRoomManager()->GetPlayRoom( pPlayer->GetLocationIndex() );
			ASSERT( pPlayRoom == g_MNSystem.GetPlayRoomManager()->GetPlayRoom( pmsg->dwData1 ) );

			pPlayRoom->PlayerOut( pPlayer );
			g_MNSystem.GetMNPlayerManager()->DeletePlayer( pPlayer->GetID() );
			/////
			g_Console.LOG( 4, "[%6d]: User Disconnected", pPlayer->GetID() );
			/////
		}
		break;

	case MP_MURIMNET_NOTIFYTOMN_GAMEEND:
		{
			MSG_DWORD2* pmsg = (MSG_DWORD2*)pMsg;
			
			CPlayRoom* pPlayRoom = g_MNSystem.GetPlayRoomManager()->GetPlayRoom( pmsg->dwData1 );

			//dwData2 : �� �¸���( 2�¹��º� ) : �̻��

			ASSERT( pPlayRoom );
			if( pPlayRoom == NULL ) break;
			ASSERT( pPlayRoom->IsStarted() );

			pPlayRoom->PlayStart( FALSE );	//player���� result���·� �ٲ۴�.
		}
		break;
	}
}

void MP_POWERUPMsgParser(DWORD dwConnectionIndex, char* pMsg, DWORD dwLength)
{
	BOOTMNGR->NetworkMsgParse(dwConnectionIndex, pMsg, dwLength);
}

void MP_USERCONNMsgParser(DWORD dwConnectionIndex, char* pMsg, DWORD dwLength)
{
	MSGBASE* pTempMsg = (MSGBASE*)pMsg;

	switch( pTempMsg->Protocol )
	{
	case MP_USERCONN_DISCONNECTED:
		{
			CMNPlayer* pPlayer = g_MNSystem.GetMNPlayerManager()->FindPlayer( pTempMsg->dwObjectID );

			if( pPlayer == NULL ) return;	//agent���� �´�.. --; Ȯ�ο��.

			switch( pPlayer->GetLocation() )
			{
			case eLOCATION_CHANNEL:
				{
					CChannel* pChannel = g_MNSystem.GetChannelManager()->GetChannel( pPlayer->GetLocationIndex() );
					pChannel->PlayerOut( pPlayer );
				}
				break;
			case eLOCATION_PLAYROOM:
				{
					//playroommanager�� ó������
					CPlayRoom* pPlayRoom = g_MNSystem.GetPlayRoomManager()->GetPlayRoom( pPlayer->GetLocationIndex() );
					pPlayRoom->PlayerOut( pPlayer );
				}
				break;
			case eLOCATION_GAME:
				{
				}
				break;
			}

			g_MNSystem.GetMNPlayerManager()->DeletePlayer( pPlayer->GetID() );
			/////
			g_Console.LOG( 4, "[%6d]: User Disconnected", pPlayer->GetID() );
			/////
		}
		break;
	}
	
}



void MP_CHATMsgParser(DWORD dwConnectionIndex, char* pMsg, DWORD dwLength)
{

}