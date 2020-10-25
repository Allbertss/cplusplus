#include <iostream>
#include <iomanip>

#include "definitions.h"
#include "misc.h"
#include "trigger.h"

using namespace std;

// Functions
void menu();

// Global variables
unsigned int MAX_PLAYERS;
unsigned int LAN_MODE;
bool ZERO_DELAY;

int main() {
	menu();

	Misc misc(MAX_PLAYERS, LAN_MODE);
	Trigger trigger(MAX_PLAYERS, ZERO_DELAY);

	for (;;) {
		misc.radar();
		misc.bhop();
		trigger.trigger();

		if (GetAsyncKeyState(KEY_EXIT))
			return 0;

		Sleep(1);
	}

	return 0;
}

void menu() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 14);
	cout << "Tortilla ";
	SetConsoleTextAttribute(hConsole, 3);
	cout << "loaded";
	SetConsoleTextAttribute(hConsole, 14);
	cout << "!\n\n";
	SetConsoleTextAttribute(hConsole, 3);
	cout << "Play ";
	SetConsoleTextAttribute(hConsole, 14);
	cout << "mm ";
	SetConsoleTextAttribute(hConsole, 3);
	cout << "or ";
	SetConsoleTextAttribute(hConsole, 14);
	cout << "casual";
	SetConsoleTextAttribute(hConsole, 3);
	cout << ": ";
	SetConsoleTextAttribute(hConsole, 14);
	string temp;
	cin >> temp;

	if (temp == "mm")
		MAX_PLAYERS = 10;
	else
		MAX_PLAYERS = 64;

	char temp2;
	SetConsoleTextAttribute(hConsole, 14);
	cout << "\nLAN ";
	SetConsoleTextAttribute(hConsole, 3);
	cout << "mode: ";
	SetConsoleTextAttribute(hConsole, 14);
	cin >> temp2;
	
	if (temp2 == 'y')
		LAN_MODE = 1;
	else 
		LAN_MODE = 0;

	char temp3;
	SetConsoleTextAttribute(hConsole, 14);
	cout << "\nTrigger ";
	SetConsoleTextAttribute(hConsole, 3);
	cout << "zero delay: ";
	SetConsoleTextAttribute(hConsole, 14);
	cin >> temp3;
	
	if (temp3 == 'y')
		ZERO_DELAY = 1;
	else 
		ZERO_DELAY = 0;
}