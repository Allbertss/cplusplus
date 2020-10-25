#pragma once
#include <iostream>

#include "offsets.h"
#include "definitions.h"

using namespace std;

class Player {
public:
	Player();
	~Player();

	DWORD getLocalPlayer();
	unsigned int getTeam(); // 1 - spectator, 2 - t, 3 ct
	unsigned int getFlags();
	unsigned int getCrosshair();
	bool isMoving();

	// junk
	void junk0();
	void junk1();
	void junk2();
	void junk3();
	void junk4();
	// end of junk
private:

public:

private:

};

struct vec3 {
	float x;
	float y;
	float z;
};

extern Player *pLocal;