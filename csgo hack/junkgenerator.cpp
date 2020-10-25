// 2016

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

int getRandomNumber(int from, int to);
void write(string fileName, int n);
string getRandomString(int n);

char letters[] = "abcdefghijklmnopqrstuvwxyz";

int main() {
	srand(time(NULL));

	string fileName[1000];
	int n;
	int lines;

	cout << "Enter file name: ";
	cin >> fileName[0];

	cout << "Enter how many lines in one file: ";
	cin >> lines;

	cout << "Enter how many files: ";
	cin >> n;

	for (int i = 1; i < n; i++) {
		fileName[i] += fileName[0] + to_string(i) + ".txt";
	}

	fileName[0] += ".txt";

	for (int i = 0; i < n; i++) {
		write(fileName[i], lines);
	}

	return 0;
}

void write(string fileName, int n) {
	ofstream writeFile(fileName);

	for (int i = 0; i < n; i++) {
		string variable = getRandomString(getRandomNumber(8, 12));
		writeFile << "float " << variable << " = " << getRandomNumber(1400000000, 10000000) << ";\n" <<
			variable << " = " << getRandomNumber(1400000000, 10000000) << ";" << endl <<
			"if (" << variable << " == " << getRandomNumber(1400000000, 10000000) << ") {\n" <<
			variable << " = " << getRandomNumber(1400000000, 10000000) << ";\n" <<
			variable << " = " << getRandomNumber(1400000000, 10000000) << ";\n" <<
			variable << " = " << getRandomNumber(1400000000, 10000000) << ";\n" <<
			variable << " = " << getRandomNumber(1400000000, 10000000) << ";\n}" << endl << endl;

		variable = "";
	}

	writeFile.close();
}

string getRandomString(int n) {
	string temp = "";

	for (int i = 0; i < n; i++) {
		temp += letters[rand() % 26];
	}

	return temp;
}

int getRandomNumber(int from, int to) {
	return rand() % from + to;
}
