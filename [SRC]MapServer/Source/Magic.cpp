// Magic.cpp: implementation of the CMagic class.
//
//////////////////////////////////////////////////////////////////////

#include "../Header/Magic.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMagic::CMagic()
{
	ZeroMemory(m_cName, sizeof(m_cName));
	m_iAttribute = 0;
}

CMagic::~CMagic()
{										    

}
