#pragma comment(lib, "winmm.lib")
#include <thread>
#include "BackEnd/Game.h"
#include "FrontEnd/SplashScreen.h"
static bool isRunning = false;
static Game game;
char MOVING;

void exitGame(std::thread* t) {
	isRunning = false;
	t->join();
}

void playGame() {
	while (isRunning) {
		if (!game.isDead()) 
			game.updatePeople(MOVING);
		MOVING = ' ';
		game.update();
		game.draw();
		if (game.endGame()) {

		}
		if (game.finish()) {
			isRunning = false;
			game.levelUp();
		}
	}
}

int main() {
	//Lack of screen and menu :3
	//PlayGame
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
			else {
				MOVING = temp;
				isRunning = true;
			}
		} else {
			if (temp == 'Y') {
				game.startGame();
				isRunning = true;
			}
			else
				exitGame(&t);
		}
	}

	return 0;
}