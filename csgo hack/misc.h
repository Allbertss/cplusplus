#pragma once
#include <iostream>

#include "entity.h"
#include "player.h"

using namespace std;

class Misc {
public:
	Misc(unsigned int MAX_PLAYERS, unsigned int LAN_MODE);
	~Misc();

	void radar();
	void bhop();

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
	unsigned int MAX_PLAYERS;
	unsigned int LAN_MODE;

	bool radarToggle = false;
	bool bhopToggle = false;
};