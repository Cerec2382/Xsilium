// Map.h: interface for the CMap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAP_H__12609160_8060_11D2_A8E6_00001C7030A6__INCLUDED_)
#define AFX_MAP_H__12609160_8060_11D2_A8E6_00001C7030A6__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <windows.h>
#include <winbase.h>
#include "../Header/OccupyFlag.h"
#include "../Header/Tile.h"
#include "../Header/StrategicPoint.h"


#define DEF_OWNERTYPE_PLAYER			1
#define DEF_OWNERTYPE_NPC				2
#define DEF_OWNERTYPE_PLAYER_INDIRECT	3

// for Client Data
#define DEF_MAPDATASIZEX		40
#define DEF_MAPDATASIZEY		35
//#define DEF_MAPDATASIZEX		45
//#define DEF_MAPDATASIZEY		40

#define DEF_MAXTELEPORTLOC		200
#define DEF_MAXWAYPOINTCFG		200
#define DEF_MAXMGAR				50
#define DEF_MAXNMR				50
#define DEF_MAXSPOTMOBGENERATOR	100
#define DEF_MAXFISHPOINT		200
#define DEF_MAXMINERALPOINT		200
#define DEF_MAXOCCUPYFLAG		20001 //3001
#define	DEF_MAXINITIALPOINT		20

#include <windows.h>
#include "Game.h"
#include "StrTok.h"
#include "TeleportLoc.h"
#include "../General/GlobalDef.h"

#define DEF_MAPTYPE_NORMAL				0
#define DEF_MAPTYPE_NOPENALTY_NOREWARD	1
#define DEF_MAXENERGYSPHERES			10

#define DEF_MAXSTRATEGICPOINTS			200
#define DEF_MAXSECTORS					60
#define DEF_MAXSTRIKEPOINTS				20

#define DEF_MAXITEMEVENTS				50
#define DEF_MAXDYNAMICGATE			10
#define MAX_HELDENIANTOWER              800
#define DEF_MAXHELDENIANDOOR            800
#define DEF_TIMETODELETE		300000

class CMap  
{
public:
	BOOL bGetBigMoveable(short, short, short, char);// v2.172
	BOOL bGetMoveableArea(short, short, short);
    class CClearMap  * m_pClearMap;
	void BorrarFlag();
	//heldenian
	int cMapName;
	char m_cHeldenianModeMap;
    BOOL m_bIsHeldenianMap;
	short m_sHeldenianWinningZoneY, m_sHeldenianWinningZoneX;
	
    struct{
          int dX;
		  int dY;
		  char cDir;
	}m_stHeldenianGateDoor[DEF_MAXHELDENIANDOOR];
	
	struct{
	short sTypeID;
    int dX;
	int dY;
	char cSide;
	}m_stHeldenianTower[MAX_HELDENIANTOWER];
	void SetBigOwner(short sOwner, char cOwnerClass, short pX, short pY, char cArea);
	void ClearBigOwner(short sOwnerH, char cOwnerType, short pX, short pY, char cArea);
	BOOL bApocalypseGate();
	BOOL bApocalypseGateTeleporter(short dX, short dY, char * cMapName, short * tX, short * tY);
	BOOL bCheckFlySpaceAvailable(short sX, short sY, char cDir, short sOwner);
	void RestoreStrikePoints();
	BOOL bRemoveCrusadeStructureInfo(short sX, short sY);
	BOOL bAddCrusadeStructureInfo(char cType, short sX, short sY, char cSide);
	int iGetAttribute(int dX, int dY, int iBitMask);
	void _SetupNoAttackArea();
	void ClearTempSectorInfo();
	void ClearSectorInfo();
	int iRegisterOccupyFlag(int dX, int dY, int iSide, int iEKNum, int iDOI);
	int  iCheckItem(short sX, short sY);
	void SetTempMoveAllowedFlag(int dX, int dY, BOOL bFlag);
	int iAnalyze(char cType, int *pX, int *pY, int * pV1, int *pV2, int * pV3);
	BOOL bGetIsWater(short dX, short dY);
	BOOL bGetIsFarm(short dX, short dY);	//v2.19 2002-12-16 농사 스킬 관련
	BOOL bAddCropsTotalSum();				//v2.19 2002-12-16 농사 스킬 관련
	BOOL bRemoveCropsTotalSum();			//v2.19 2002-12-16 농사 스킬 관련
	void GetDeadOwner(short * pOwner, char * pOwnerClass, short sX, short sY);
	BOOL bGetIsMoveAllowedTile(short dX, short dY);
	void SetNamingValueEmpty(int iValue);
	int iGetEmptyNamingValue();
	BOOL bGetDynamicObject(short sX, short sY, short * pType, DWORD * pRegisterTime, int * pIndex = NULL);
	void SetDynamicObject(WORD wID, short sType, short sX, short sY, DWORD dwRegisterTime);
	BOOL bGetIsTeleport(short dX, short dY);
	BOOL bSearchTeleportDest(int sX, int sY, char * pMapName, int * pDx, int * pDy, char * pDir);
	BOOL bInit(char * pName);
	BOOL bIsValidLoc(short sX, short sY);
	class CItem * pGetItem(short sX, short sY, short * pRemainItemSprite, short * pRemainItemSpriteFrame, char * pRemainItemColor);
	void pGetItem2(short sX, short sY, short * pRemainItemSprite, short * pRemainItemSpriteFrame, char * pRemainItemColor, DWORD dwTime);
	BOOL bSetItem(short sX, short sY, class CItem * pItem);
	void ClearDeadOwner(short sX, short sY);
	void ClearOwner(int iDebugCode, short sOwnerH, char cOwnerType, short sX, short sY);
	BOOL bGetMoveable(short dX, short dY, short * pDOtype = NULL/*, class CItem * pTopItem = NULL*/); // v2.172
	void GetOwner(short * pOwner, char * pOwnerClass, short sX, short sY);
	void SetOwner(short sOwner, char cOwnerClass, short sX, short sY);
	void SetDeadOwner(short sOwner, char cOwnerClass, short sX, short sY);
	CMap(class CMapServer * pGame);
	virtual ~CMap();

	class CTile * m_pTile;
	class CMapServer * m_pGame;
	char  m_cName[11];
	char  m_cLocationName[11];
	short m_sSizeX, m_sSizeY, m_sTileDataSize;
	class CTeleportLoc * m_pTeleportLoc[DEF_MAXTELEPORTLOC];
	
	//short m_sInitialPointX, m_sInitialPointY;
	POINT m_pInitialPoint[DEF_MAXINITIALPOINT];

	BOOL  m_bNamingValueUsingStatus[1000]; // 0~999
	BOOL  m_bRandomMobGenerator;
	char  m_cRandomMobGeneratorLevel;
	int   m_iTotalActiveObject;
	int   m_iTotalAliveObject;
	int   m_iMaximumObject;

	char  m_cType;				// 맵의 형식. 0이면 보통. 1이면 공격행위가 범죄가 아니다.

	BOOL  m_bIsFixedDayMode;	// 항상 주간모드인지: 건물 내부 등 
	BOOL  m_bIsFixedSnowMode;	// 항상 눈내리는 모드인지 (icebound,X-Mas)

	struct {		    
		BOOL bDefined;
		char cType;				// 1:RANDOMAREA   2:RANDOMWAYPOINT
		
		char cWaypoint[10];     // RANDOMWAYPOINT 등
		RECT rcRect;			// RANDOMAREA발생의 경우 
		
		int  iTotalActiveMob;
		int  iMobType;
		int  iMaxMobs;
		int  iCurMobs;
		
	} m_stSpotMobGenerator[DEF_MAXSPOTMOBGENERATOR];

	POINT m_WaypointList[DEF_MAXWAYPOINTCFG];
	RECT  m_rcMobGenAvoidRect[DEF_MAXMGAR];
	RECT  m_rcNoAttackRect[DEF_MAXNMR];

	POINT m_FishPointList[DEF_MAXFISHPOINT];
	int   m_iTotalFishPoint, m_iMaxFish, m_iCurFish;

	BOOL  m_bMineralGenerator;
	char  m_cMineralGeneratorLevel;
	POINT m_MineralPointList[DEF_MAXMINERALPOINT];
	int   m_iTotalMineralPoint, m_iMaxMineral, m_iCurMineral;

	char  m_cWhetherStatus;		// 기상 상태. 0이면 없음. 1~3 비 4~6 눈 7~9 폭풍 
	DWORD m_dwWhetherLastTime, m_dwWhetherStartTime;  // 날씨 지속, 시작 시간 

	int   m_iLevelLimit;
	int   m_iUpperLevelLimit;	// 상위 렙 제한 

	class COccupyFlag * m_pOccupyFlag[DEF_MAXOCCUPYFLAG];
	int   m_iTotalOccupyFlags;
	
	class CStrategicPoint * m_pStrategicPointList[DEF_MAXSTRATEGICPOINTS];
	BOOL  m_bIsAttackEnabled;

	BOOL  m_bIsFightZone;

	struct {
		char cType;
		int sX, sY;

	} m_stEnergySphereCreationList[DEF_MAXENERGYSPHERES];

	int m_iTotalEnergySphereCreationPoint;
	
	struct {
		char cResult;
		int aresdenX, aresdenY, elvineX, elvineY;
	} m_stEnergySphereGoalList[DEF_MAXENERGYSPHERES];

	int m_iTotalEnergySphereGoalPoint;

	BOOL m_bIsEnergySphereGoalEnabled;
	int m_iCurEnergySphereGoalPointIndex; 

	struct {
		int iPlayerActivity;
		int iNeutralActivity;
		int iAresdenActivity;
		int iElvineActivity;
		int iMonsterActivity;

	} m_stSectorInfo[DEF_MAXSECTORS][DEF_MAXSECTORS], m_stTempSectorInfo[DEF_MAXSECTORS][DEF_MAXSECTORS];

	int m_iMaxNx, m_iMaxNy, m_iMaxAx, m_iMaxAy, m_iMaxEx, m_iMaxEy, m_iMaxMx, m_iMaxMy, m_iMaxPx, m_iMaxPy;
	
	struct {
		char cRelatedMapName[11];
		int iMapIndex;
		int dX, dY;
		int iHP, iInitHP;

		int iEffectX[5];
		int iEffectY[5];
	
	} m_stStrikePoint[DEF_MAXSTRIKEPOINTS];
	int m_iTotalStrikePoints;

	BOOL m_bIsDisabled;

	struct {
		char cType;
		char cSide;
		short sX, sY;
	} m_stCrusadeStructureInfo[DEF_MAXCRUSADESTRUCTURES];
	int m_iTotalCrusadeStructures;
	int m_iTotalAgriculture;

	struct {
		char cItemName[21];
		int iAmount;
		int iTotalNum;
		int iMonth;
		int iDay;
		int iType;
		char *cMob[5];

		int iCurNum;
		int	iNumMob;
	} m_stItemEventList[DEF_MAXITEMEVENTS];
	int m_iTotalItemEvents;

	BOOL m_bIsEnergySphereAutoCreation;

	short sMobEventAmount ;
	
	//////////////// APOCALYPSE //////////////////
	BOOL	m_bIsCitizenLimit;
	int		m_iApocalypseBossMobNpcID, m_iApocalypseMobGenType;
	RECT  m_rcApocalypseBossMobRect;
	short	m_cDynamicGateType;
	short m_sDynamicGateX1;
	short m_sDynamicGateX2;
	short m_sDynamicGateY1;
	short m_sDynamicGateY2;
	int		m_iTotalDynamicGate;
	short	m_sDynamicGateTgtX;
	short	m_sDynamicGateTgtY;
	BOOL  m_bIsRecallImpossible;
	BOOL  m_bIsApocalypseMap;
	BOOL  m_bIsBossInMap;
	BOOL  m_bIsGateMap;
	BOOL	m_bIsGateAvailable;
	BOOL  m_bIsApocalypseMobSpawn;
	BOOL	m_bIsInferniaAGate, m_bIsInferniaBGate, m_bIsProcellaGate;
	char	m_cDynamicGateDestMap[11];
	int   m_iMaximumObjectDefault;
	//////////////////////////////////////////////
	int TotalChars;

	
private:
	BOOL _bDecodeMapDataFileContents();
};

#endif // !defined(AFX_MAP_H__12609160_8060_11D2_A8E6_00001C7030A6__INCLUDED_)
