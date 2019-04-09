#ifndef _MNDBMSGPARSER_H
#define _MNDBMSGPARSER_H



//////////////////////////////////////////////////////////////////////////
// DB�� ���� �޽����� ������ ������ ID ����
enum   DBMESSAGEIDFUNC 
{
	eCharacterInfoQuery,
	MaxQuery,
};

#define STORED_CHARACTER_SELECT				"MP_CHARACTER_SelectByCharacterIDX"		// ������ ĳ������ ����

enum CHSelectInfo	// ĳ�������� ������ ��
{
	eCS_ObjectID = 0, eCS_UserID, eCS_PartyID,eCS_Gender, eCS_Gengoal, eCS_Life, eCS_Shield, eCS_Energe, eCS_Dex, eCS_Sta, eCS_Simmak, eCS_Fame, 
	eCS_Karma, eCS_Name, eCS_Repute, eCS_Stage, eCS_Grade, eCS_Expoint, eCS_GradeUpPoint, eCS_Money, 
	eCS_QuickPace, eCS_Vitality, eCS_Map, eCS_FaceType, eCS_HeadType, eCS_Hat, eCS_Weapon, eCS_Dress, eCS_Shoes, 
	eCS_Ring1, eCS_Ring2, eCS_Cape, eCS_Necklace, eCS_Armlet, eCS_Belt, eCS_MunpaIDX, eCS_MunpaPositon, eCS_MunpaName,   
	eCS_Ability1, eCS_Ability2, eCS_Ability3, eCS_Ability4, eCS_Ability5,
	eCS_Ability6, eCS_Ability7, eCS_MapChangePoint, eCS_LoginPoint ,
};

void CharacterNumSendAndCharacterInfo(DWORD CharacterIDX);
void RCharacterNumSendAndCharacterInfo(LPQUERY pData, LPDBMESSAGE pMessage);


#endif