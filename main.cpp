#pragma comment(lib, "winmm.lib")
#include <thread>
#include "BackEnd/Game.h"
#include "FrontEnd/SplashScreen.h"
bool isRunning = false;
Game game;
char MOVING;

void exitGame(std::thread* t) {
	isRunning = false;
	t->detach();
}

void playGame() {
	//cerr << "Play\n";
	while (true) {
		if (isRunning) {
			if (!game.isDead())
				game.updatePeople(MOVING);
			MOVING = ' ';
			game.update();
			game.draw();
			if (game.endGame()) {
				isRunning = false;
			}
			if (game.finish()) {
				isRunning = false;
				game.levelUp();
				game.draw();
			}
			Sleep(100);
		}
	}
}

int main() {
	int command = SplashScreen();
	if (command == 3)
		return 0;
	isRunning = true;
	if (command == 2) {
		//Ask what name -> BOLOXI
		std::string name = "boloxi";
		game.loadGame(name);
		game.draw();
		isRunning = false;
	}
	else
		game.startGame();
	std::thread t(playGame);
	while (true) {
		int temp = toupper(_getch());
		
		if (temp == 27) {
			exitGame(&t);
			break;
		}

		if (!game.isDead()) {
			if (temp == 'P')
				isRunning = false;
			else if (temp == 'L') {
				isRunning = false;
				//Ask what name -> boloxi
				std::string name = "boloxi";
				game.saveGame(name);
			} else {
				MOVING = temp;
				isRunning = true;
			}
		} else {
			if (temp == 'Y') {
				game.startGame();
				isRunning = true;
			}
			else {
				exitGame(&t);
				break;
			}
		}
	}
	return 0;
}

/*
int main() {
	game.startGame();
	while (true) {
		game.update();
		game.draw();
		Sleep(100);
	}
	return 0;
}
*/