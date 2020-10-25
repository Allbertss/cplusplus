#pragma once
#include <iostream>
#include "offsets.h"

using namespace std;

class Entity {
public:
	Entity();
	~Entity();

	unsigned int getEntity(int i);
	unsigned int getTeam(int i);
	unsigned int getHealth(int i);
	bool isDormant(int i);

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

extern Entity *pEntity;