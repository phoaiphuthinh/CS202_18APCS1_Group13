#include "Game.h"

const int WIDTH = 20;
const int HEIGHT = 5;

Game::Game() {
}

Game::~Game() {
	//Destroy animal
	for (auto x : animal)
		delete x;
	//Destroy vehicles
	for (auto x : vehicle)
		delete x;
	animal.clear();
	vehicle.clear();
	trafficLights.clear();
	Score tmp;
}

void Game::draw() {
	//system("cls");
	clearMap();
	std::cout << "  ";
	for (int i = 0; i < 42; i++)
	{
		gotoXY(1, 1 + i);
		std::cout << "|";
	}
	for (int i = 0; i < 100; i++)
	{
		gotoXY(2 + i, 0);
		std::cout << "_";
		gotoXY(2 + i, 7);
		std::cout << "_";
		gotoXY(2 + i, 14);
		std::cout << "_";
		gotoXY(2 + i, 21);
		std::cout << "_";
		gotoXY(2 + i, 28);
		std::cout << "_";
		gotoXY(2 + i, 35);
		std::cout << "_";
		gotoXY(2 + i, 42);
		std::cout << "_";
	}
	for (int i = 0; i < 42; i++)
	{
		gotoXY(102, 1 + i);
		std::cout << "|";
	}


	/*for (int i = 0; i < 20; i++)
	{
		gotoXY(110, 1 + i);
		textcolor(9);
		std::cout << "|";
		gotoXY(140, 1 + i);
		std::cout << "|";

		textcolor(10);
	}*/

	DrawRect(110, 0, 45, 30,0,0);
	textcolor(46);
	gotoXY(125, 3);
	std::cout << "INSTRUCTIONS";
	textcolor(11);
	gotoXY(117, 7);
	std::cout << "PRESS L TO SAVE GAME";
	gotoXY(117, 9);
	std::cout << "PRESS Y TO RESTART GAME WHEN DIE";
	gotoXY(117, 11);
	std::cout << "PRESS P TO PAUSE GAME";
	textcolor(10);

	textcolor(12);
	gotoXY(117, 14);
	std::cout << "PRESS A TO MOVE TO THE LEFT";
	gotoXY(117, 16);
	std::cout << "PRESS D TO MOVE TO THE RIGHT";
	gotoXY(117, 18);
	std::cout << "PRESS W TO MOVE UPWARD";
	gotoXY(117, 20);
	std::cout << "PRESS S TO MOVE DOWNWARD";
	textcolor(10);

	textcolor(13);
	gotoXY(117, 23);
	int lev = getlevel();
	std::cout << "LEVEL " << lev;
	textcolor(10);

	/*for (int i = 0; i < 30; i++)
	{
		gotoXY(i+111, 0);
		textcolor(9);
		std::cout << "_";

		gotoXY(i + 111, 6);
		std::cout << "_"; 

		textcolor(10);
		
	}*/

	for (auto x : animal)
		x->draw();
	for (auto x : vehicle)
		x->draw();

	if (trafficLights.size() != 0)
	{
		int t = trafficLights[0].getTime();
		gotoXY(105, 17);
		std::cout << t << "  ";
		char a = 220;

		if (trafficLights[0].getState() == 1) // xanh
		{
			textcolor(10);
			gotoXY(105, 18);
			std::cout << a;
		}
		else if (trafficLights[0].getState() == 0)  // do
		{
			gotoXY(105, 18);
			textcolor(12);
			std::cout << a;
		}

		if (trafficLights.size() > 1)
		{
			t = trafficLights[1].getTime();
			gotoXY(105, 11);
			textcolor(10);
			std::cout << t << "  ";
			if (trafficLights[1].getState() == 1) // xanh
			{
				textcolor(10);
				gotoXY(105, 12);
				std::cout << a;
			}
			else if (trafficLights[1].getState() == 0)  // do
			{
				gotoXY(105, 12);
				textcolor(12);
				std::cout << a;
			}
		}

		gotoXY(105, 19);
		textcolor(15);
		std::cout << a;
		textcolor(10);

	}
	player.draw();
}

void Game::saveGame() {
	/*
			FORMAT FILE
			- 0th: level
			- First line: coordinate of people : x , y
			- Second line: number of vehicles (n)
			- Third line: n coordinates of n vehicles (xi, yi, sign)
			- Forth line: number of animal (m)
			- Fiveth line: m coordinates of m animal (xi, yi, sign)
			- Sixth line: number of trafficlight (k)
			- Seventh line: state and time remaining of k traffic lights

		At first, save data in text file. If it works perfectly, store in binary file.
	*/
	std::ofstream f;
	f.open("./data/" + this->name + ".dat", std::ios::out | std::ios::binary);
	f.write((char*)&level, sizeof(int));
	int x = player.getX();
	f.write((char*)&x, sizeof(int));
	x = player.getY();
	f.write((char*)&x, sizeof(int));
	x = (int)vehicle.size();
	f.write((char*)&x, sizeof(int));
	for (auto v : vehicle) {
		x = v->getX();
		f.write((char*)&x, sizeof(int));
		x = v->getY();
		f.write((char*)&x, sizeof(int));
		x = v->getSign();
		f.write((char*)&x, sizeof(int));
	}
	x = (int)animal.size();
	f.write((char*)&x, sizeof(int));
	for (auto v : animal) {
		x = v->getX();
		f.write((char*)&x, sizeof(int));
		x = v->getY();
		f.write((char*)&x, sizeof(int));
		x = v->getSign();
		f.write((char*)&x, sizeof(int));
	}
	x = (int)trafficLights.size();
	f.write((char*)&x, sizeof(int));
	for (auto v : trafficLights) {
		x = v.getState();
		f.write((char*)&x, sizeof(int));
		x = v.getTime();
		f.write((char*)&x, sizeof(int));
	}
	f.close();
}

bool Game::loadGame(std::string name) {
	std::ifstream f;
	f.open("./data/" + name + ".dat", std::ios::in | std::ios::binary);
	if (!f.is_open())
		return false;

	PlaySound(TEXT("./sources/background.wav"), NULL, SND_ASYNC | SND_LOOP);

	Game::~Game();
	this->name = name;
	f.read((char*)&level, sizeof(int));
	int x, y;
	f.read((char*)&x, sizeof(int));
	f.read((char*)&y, sizeof(int));
	player = people(x, y);
	int n;
	f.read((char*)&n, sizeof(int));
	vehicle.assign(n, nullptr);
	for (int i = 0; i < n; i++) {
		int type;
		f.read((char*)&x, sizeof(int));
		f.read((char*)&y, sizeof(int));
		f.read((char*)&type, sizeof(int));
		if (type == 1)
			vehicle[i] = new car(x, y);
		else
			vehicle[i] = new ufo(x, y);
	}
	f.read((char*)&n, sizeof(int));
	animal.assign(n, nullptr);
	for (int i = 0; i < n; i++) {
		int type;
		f.read((char*)&x, sizeof(int));
		f.read((char*)&y, sizeof(int));
		f.read((char*)&type, sizeof(int));
		if (type == 1)
			animal[i] = new Duck(x, y);
		else
			animal[i] = new Moew(x, y);
	}
	f.read((char*)&n, sizeof(int));
	for (int i = 0; i < n; i++) {
		f.read((char*)&x, sizeof(int));
		f.read((char*)&y, sizeof(int));
		trafficLights.push_back(TrafficLights(x, y));
	}
	f.close();
	return true;
}

bool Game::loadScoreboard()
{
	return scoreboard.load();
}

bool Game::saveScoreboard()
{
	loadScoreboard();
	Score tmp;
	tmp.Input(name, level);
	if (!scoreboard.isExisted(tmp)) scoreboard.score.push_back(tmp);
	scoreboard.sort();
	return scoreboard.save();
}

Scoreboard Game::getScoreboard()
{
	return scoreboard;
}

void Game::updatePeople(char c) {
	switch (c)
	{
	case 'W':
		player.Up(7);
		break;
	case 'A':
		player.Left(4);
		break;
	case 'S':
		player.Down(7);
		break;
	case 'D':
		player.Right(4);
		break;
	default:
		break;
	}
}

void Game::update() {
	for (auto &x : trafficLights)
		x.change(max(10, 30 - level * 2 - rand() % 5));
	for (auto x : vehicle) {
		if (trafficLights.size() == 0)
			x->move(x->getSign());
		else if (trafficLights.size() == 1) {
			if (x->getSign() == 1)
				x->move(1);
			else if (trafficLights[0].getState() == 1)
				x->move(-1);
		}
		else {
			if (x->getSign() == 1) {
				if (trafficLights[1].getState())
					x->move(1);
			}
			else {
				if (trafficLights[0].getState())
					x->move(-1);
			}
		}
	}
	for (auto x : animal)
		x->move(x->getSign());
}

void Game::levelUp() {
	PlaySound(TEXT("./sources/levelup.wav"), NULL, SND_SYNC);
	PlaySound(TEXT("./sources/background.wav"), NULL, SND_ASYNC | SND_LOOP);
	srand(time(NULL));
	level++;
	std::string tmp = this->name;
	Game::~Game();
	this->name = tmp;
	player = people();
	int n = min(level + rand() % 2, 5);
	vehicle.assign(2 * n, nullptr);
	animal.assign(2 * n, nullptr);
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			vehicle[2 * i] = new car(rand() % 20 + 2, 12); // lane 1
			vehicle[2 * i + 1] = new ufo(rand() % 20 + 2, 19); //lane 2
			animal[2 * i] = new Duck(rand() % 20 + 2, 26); //lane 3
			animal[2 * i + 1] = new Moew(rand() % 20 + 2, 33); //lane 4
		}
		else {
			vehicle[2 * i] = new car(20 + (rand() % 3 + 1) + vehicle[2 * (i - 1)]->getX(), 12); // lane 1
			vehicle[2 * i + 1] = new ufo(15 + (rand() % 3 + 1) + vehicle[2 * (i - 1) + 1]->getX(), 19); //lane 2
			animal[2 * i] = new Duck(10 + (rand() % 3 + 1) + animal[2 * (i - 1)]->getX(), 26); //lane 3
			animal[2 * i + 1] = new Moew(10 + (rand() % 3 + 1) + animal[2 * (i - 1) + 1]->getX(), 33); //lane 4
		}
	}
	if (level > 1) {
		trafficLights.push_back(TrafficLights());
		if (level > 3)
			trafficLights.push_back(TrafficLights());
	}
}

void Game::startGame(std::string name) {
	level = 0;
	levelUp();
	this->name = name;
}

bool Game::finish() {
	return player.isFinish();
}

bool Game::isDead() {
	return player.isDead();
}

bool Game::endGame() {
	return player.isImpact(vehicle) || player.isImpact(animal);
}

int Game::getlevel()
{
	return level;
}
