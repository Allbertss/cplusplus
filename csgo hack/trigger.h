#pragma once
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

#include "offsets.h"
#include "player.h"
#include "entity.h"

using namespace std;

class Trigger {
public:
	Trigger(unsigned int MAX_PLAYERS, bool ZERO_DELAY);
	~Trigger();

	void shoot(unsigned int delayBefore, unsigned int delayAfter);
	bool logic();
	void trigger();

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
	bool ZERO_DELAY;
};