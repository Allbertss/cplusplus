#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <Windows.h>

struct Line {
	std::string currentState;
	char currentSymbol;
	char newSymbol;
	char direction;
	std::string newState;
};

struct State {
	std::vector<Line> lines;
};

class Machine {
	std::string _tape;
	std::vector<Line> _code;
	std::unordered_map<std::string, State> _states;
	std::string _currentState = "0";
	unsigned int _head;
	unsigned int _state;
	std::string _fileName;
	bool _toggle = false;
	DWORD _keyCode = 0x0;

	void setSymbol(char symbol);
	void moveHead(char direction);
	void changeState(std::string state);
	char readTape(unsigned int index) const;
	void read();
	void write();
	void sortToStates();
public:
	Machine(std::string fileName, DWORD keyCode);
	~Machine();

	void operator()();
	void printTape();
};