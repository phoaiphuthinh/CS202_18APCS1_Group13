#pragma comment(lib, "winmm.lib")
#include <thread>
#include "BackEnd/Game.h"
#include "FrontEnd/SplashScreen.h"
bool isRunning = false;
Game game;
char MOVING;

void exitGame(std::thread* t) {
	isRunning = false;
	t->join();
}

void playGame() {
	//cerr << "Play\n";
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
		Sleep(2000);
	}
}

int main() {
	//Lack of screen and menu :3
	//PlayGame
	std::thread t(playGame);
	
	game.startGame();
	isRunning = true;
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
		//cerr << isRunning;
	}

	return 0;
}