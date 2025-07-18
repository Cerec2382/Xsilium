#if !defined(AFX_ACCOUNT_H__57BA71C0_B929_11D2_B143_00001C7030A6__INCLUDED_)
#define AFX_ACCOUNT_H__57BA71C0_B929_11D2_B143_00001C7030A6__INCLUDED_


#include <windows.h>

class CAccount  								 
{
public:
	CAccount(char * cDataName, char * m_cWorldName, int iClient);
	virtual ~CAccount();

	char cAccountName[11];		// 5h
	char cPassword[11];			// 10h
	int iAccountValid, iClientH;
	int m_iAccntYear, m_iAccntMonth, m_iAccntDay;
	int m_iPassYear, m_iPassMonth, m_iPassDay;
	char cWorldName[30];
	char cEmail[52];
	char cCharName[11];
	int dAccountID;
	
	// Ex WL
	char cAccountType;
	DWORD dwLogInTime;
	char m_cOnGameServer[11];
	int  m_iLevel;
	bool InGame;
};

class CCharacter  								 
{
public:
	CCharacter(char * cDataName, int m_iTracker);
	virtual ~CCharacter();
	char cCharacterName[11];	// 18h
	int iTracker;
};


#endif // !defined(AFX_MSG_H__57BA71C0_B929_11D2_B143_00001C7030A6__INCLUDED_)