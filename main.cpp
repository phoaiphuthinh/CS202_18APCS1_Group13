#pragma comment(lib, "winmm.lib")
#include <thread>
#include "BackEnd/duck.h"
static bool isRunning;

void exitGame(std::thread* t) {
	isRunning = false;
	t->join();
}

void playGame() {
	while (isRunning) {

	}
}

int main() {
	
	Duck d;
	d.makeSound();
	system("pause");
	return 0;
}