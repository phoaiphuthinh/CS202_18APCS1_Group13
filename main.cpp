#pragma comment(lib, "winmm.lib")
#include <thread>
#include <mutex>
#include "BackEnd/Game.h"
#include "FrontEnd/SplashScreen.h"
bool isRunning = false;
bool isBreak = false;
Game game;
char MOVING;
std::mutex mtx;

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
		if (isBreak)
			break;
	}
}

int main() {
	int count=0;
	while (true) {
		game.loadScoreboard();
		int command = SplashScreen(count);
		count++;
		if (command == 4)
			break;
		if (command == 3) {
			//Print scoreboard
			game.getScoreboard().draw();
			std::cin.ignore();

		}
		else {
			isRunning = true;
			isBreak = false;
			std::string name;
			if (command == 2)
			{
				system("cls");
				name = yourname();
				game.loadGame(name);
				game.draw();
				isRunning = false;
			}
			else {
				//std::mutex mtx;
				system("cls");
				//mtx.lock();
				gotoXY(117, 25);
				textcolor(13);
				std::cout << "What is your name: ";
				gotoXY(137, 25);
				getline(std::cin, name);
				textcolor(10);
				//mtx.unlock();
				game.startGame(name);
			}
			std::thread t(playGame);

			while (true) {
				int temp = toupper(_getch());

				if (temp == 27) {
					if (game.isDead())
						game.saveScoreboard();
					isRunning = false;
					isBreak = true;
					exitGame(&t);
					Sleep(500);
					break;
				}

				if (!game.isDead()) {
					if (temp == 'P')
						isRunning = false;
					else if (temp == 'L') {
						isRunning = false;
						game.saveGame();
					}
					else {
						MOVING = temp;
						isRunning = true;
					}
				}
				else {
					game.saveScoreboard();
					if (temp == 'Y') {
						game.startGame(name);
						isRunning = true;
					}
					else {
						isRunning = false;
						isBreak = true;
						exitGame(&t);
						Sleep(500);
						break;
					}
				}
			}
			if (t.joinable())
				t.join();
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