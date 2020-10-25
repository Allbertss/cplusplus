#include <thread>

#include "machine.h"

int main() {
	std::string fileNames[4];

	std::cout << "Enter 1 file name: ";
	std::cin >> fileNames[0];

	std::cout << "Enter 2 file name: ";
	std::cin >> fileNames[1];

	std::cout << "Enter 3 file name: ";
	std::cin >> fileNames[2];

	std::cout << "Enter 4 file name: ";
	std::cin >> fileNames[3];

	system("cls");

	Machine m1(fileNames[0], 0x31);
	Machine m2(fileNames[1], 0x32);
	Machine m3(fileNames[2], 0x33);
	Machine m4(fileNames[3], 0x34);

	std::thread t4(m4);
	std::thread t3(m3);
	std::thread t2(m2);
	std::thread t1(m1);

	t4.join();
	t3.join();
	t2.join();
	t1.join();

	std::cout << "Done.\n";

	return 0;
}
