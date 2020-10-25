#include <thread>

#include "machine.h"

Machine::Machine(std::string fileName, DWORD keyCode) : _fileName(fileName), _keyCode(keyCode) {
	_head = 0;
	_state = 0;

	read();
	sortToStates();
}

Machine::~Machine() {
	write();
}

void Machine::setSymbol(char symbol) {
	_tape[_head] = symbol;
}

void Machine::moveHead(char direction) {
	if (direction == 'R') {
		if (_head != _tape.length())
			_head++;
	} else if (direction == 'L') {
		if (_head != 0)
			_head--;
	} else
		std::cout << "Error: bad direction.\n";
}

void Machine::changeState(std::string state) {
	_currentState = state;
}

char Machine::readTape(unsigned int index) const {
	return _tape[index];
}

void Machine::read() {
	std::ifstream readFile(_fileName);

	readFile >> _tape;
	readFile >> _head;

	while (!readFile.eof()) {
		Line temp;
		readFile >> temp.currentState >> temp.currentSymbol >> temp.newSymbol >> temp.direction >> temp.newState;
		_code.push_back(temp);
	}

	readFile.close();
}

void Machine::write() {
	std::string fileName = _fileName.substr(0, _fileName.size() - 4) + "_done.txt";
	std::ofstream writeFile(fileName);

	writeFile << _tape;

	writeFile.close();
}

void Machine::sortToStates() {
	for (auto c : _code)
		_states[c.currentState].lines.push_back(c);
}

void Machine::printTape() {
	if (_toggle)
		std::cout << "Tape " << _fileName.substr(0, _fileName.size() - 4) << ": " << _tape << "\n";
}

void Machine::operator()() {
	for (;;) {
		if (GetAsyncKeyState(_keyCode) & 1)
			_toggle = !_toggle;

		if (!_toggle)
			continue;

		char tp = readTape(_head);

		for (auto l : _states[_currentState].lines)
			if (tp == l.currentSymbol) {
				setSymbol(l.newSymbol);
				changeState(l.newState);
				moveHead(l.direction);
				printTape();
			}

		std::unordered_map<std::string, State>::const_iterator it = _states.find(_currentState);
		if (it == _states.end())
			break;

		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}