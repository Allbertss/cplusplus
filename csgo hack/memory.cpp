#include "memory.h"

HANDLE MemManager::hProc;

MemManager::MemManager()
{
	this->hProc = NULL;
	this->pID = NULL;
	try {
		if (!attachProc("csgo.exe")) {
			throw 1; 
		}

		this->cDll = getModule(pID, "client_panorama.dll");
		this->eDll = getModule(pID, "engine.dll");
	}

	catch (...) {
		//PlaySound(TEXT("Sounds\\snare.wav"), NULL, SND_SYNC);
		MessageBoxA(NULL, "First open CS:GO", "Tortilla - Error occurred", MB_ICONSTOP | MB_OK);
	}
}

MemManager::~MemManager() {
	CloseHandle(this->hProc);
}
