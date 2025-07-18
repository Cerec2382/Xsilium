// Magic.h: interface for the CMagic class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAGIC_H__CD611900_EF3A_11D2_9B6C_00001C7030A6__INCLUDED_)
#define AFX_MAGIC_H__CD611900_EF3A_11D2_9B6C_00001C7030A6__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <windows.h>

#define DEF_MAGICTYPE_DAMAGE_SPOT			1
#define DEF_MAGICTYPE_HPUP_SPOT				2
#define DEF_MAGICTYPE_DAMAGE_AREA			3
#define DEF_MAGICTYPE_SPDOWN_SPOT			4
#define DEF_MAGICTYPE_SPDOWN_AREA			5
#define DEF_MAGICTYPE_SPUP_SPOT				6
#define DEF_MAGICTYPE_SPUP_AREA				7
#define DEF_MAGICTYPE_TELEPORT				8
#define DEF_MAGICTYPE_SUMMON				9 
#define DEF_MAGICTYPE_CREATE				10
#define DEF_MAGICTYPE_PROTECT				11	
#define DEF_MAGICTYPE_HOLDOBJECT			12
#define DEF_MAGICTYPE_INVISIBILITY			13
#define DEF_MAGICTYPE_CREATE_DYNAMIC		14
#define DEF_MAGICTYPE_POSSESSION			15 
#define DEF_MAGICTYPE_CONFUSE				16 
#define DEF_MAGICTYPE_POISON				17 
#define DEF_MAGICTYPE_BERSERK				18
#define DEF_MAGICTYPE_DAMAGE_LINEAR			19
#define DEF_MAGICTYPE_POLYMORPH				20
#define DEF_MAGICTYPE_DAMAGE_AREA_NOSPOT	21
#define DEF_MAGICTYPE_TREMOR				22 // �AR� L�LsR� �r�z 
#define DEF_MAGICTYPE_ICE					23 // l󸮴°� 
#define DEF_MAGICTYPE_DAMAGE_SPOT_SPDOWN    25
#define DEF_MAGICTYPE_ICE_LINEAR			26
#define DEF_MAGICTYPE_DAMAGE_AREA_NOSPOT_SPDOWN 27
#define DEF_MAGICTYPE_DAMAGE_AREA_ARMOR_BREAK   28
#define DEF_MAGICTYPE_CANCELLATION			29
#define DEF_MAGICTYPE_DAMAGE_LINEAR_SPDOWN 30
#define DEF_MAGICTYPE_INHIBITION           31
#define DEF_MAGICTYPE_RESURRECTION          32 // Ressurect
#define DEF_MAGICTYPE_SCAN                  33

#define DEF_MAXMAGICEFFECTS			100

class CMagic  
{									 
public:
	CMagic();
	virtual ~CMagic();

	char m_cName[31];

	short m_sType;
	DWORD m_dwDelayTime, m_dwLastTime;
	short m_sValue1, m_sValue2, m_sValue3, m_sValue4, m_sValue5, m_sValue6;
	short m_sValue7, m_sValue8, m_sValue9, m_sValue10, m_sValue11, m_sValue12;
	short m_sIntLimit;
	int   m_iGoldCost;
	
	char  m_cCategory; // ���� ����: �Ϲ� ���� 0, ���ݸ��� 1, ��� ���� 2 
	int   m_iAttribute; // ���� �Ӽ�:  �� 1 �ϴ� 2 �� 3 �� 4  
};

#endif // !defined(AFX_MAGIC_H__CD611900_EF3A_11D2_9B6C_00001C7030A6__INCLUDED_)
