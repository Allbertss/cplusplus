#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>

#include "memory.h"

using namespace std;

extern MemManager *m;

DWORD searchOffset(string s);

namespace offsets {
	extern DWORD dwLocalPlayer;
	extern DWORD m_iTeamNum;
	extern DWORD dwEntityList;
	extern DWORD m_bDormant;
	extern DWORD m_iHealth;
	extern DWORD m_bSpotted;
	extern DWORD dwForceJump;
	extern DWORD m_vecVelocity;
	extern DWORD m_fFlags;
	extern DWORD dwForceAttack;
	extern DWORD m_iCrosshairId;
}