#include "offsets.h"

MemManager *m = new MemManager();

namespace offsets {
	DWORD dwLocalPlayer = searchOffset("dwLocalPlayer");
	DWORD m_iTeamNum = searchOffset("m_iTeamNum");
	DWORD dwEntityList = searchOffset("dwEntityList");
	DWORD m_bDormant = searchOffset("m_bDormant");
	DWORD m_iHealth = searchOffset("m_iHealth");
	DWORD m_bSpotted = searchOffset("m_bSpotted");
	DWORD dwForceJump = searchOffset("dwForceJump");
	DWORD m_vecVelocity = searchOffset("m_vecVelocity");
	DWORD m_fFlags = searchOffset("m_fFlags");
	DWORD dwForceAttack = searchOffset("dwForceAttack");
	DWORD m_iCrosshairId = searchOffset("m_iCrosshairId");
}

DWORD searchOffset(string s) {
	fstream readFile("offsets.csgo");

	string temp;
	int pos;
	char tempChar;
	string sAddress;

	while (!readFile.eof()) {
		readFile >> temp;
		pos = temp.find(s);

		if (pos != string::npos) {
			readFile >> tempChar >> sAddress;
			break;
		}
	}

	readFile.close();

	sAddress.erase(sAddress.end() - 1);

	DWORD address = strtol(sAddress.c_str(), 0, 0);

	return address;
}