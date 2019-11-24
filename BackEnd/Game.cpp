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
}

void Game::draw() {
	system("cls");
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
	for (auto x : animal)
		x->draw();
	for (auto x : vehicle)
		x->draw();
	player.draw();
}

void Game::saveGame(std::string name) {
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
	f.open("./data/" + name + ".dat");
	f << level << "\n";
	f << player.getX() << " " << player.getY() << "\n";

	f << vehicle.size() << "\n";
	for (auto x : vehicle)
		f << x->getX() << " " << x->getY() << " "<< x->getSign() << " ";
	f << "\n" << animal.size() << "\n";
	for (auto x : animal)
		f << x->getX() << " " << x->getY() << " " << x->getSign() << " ";
	f << "\n" << trafficLights.size() << "\n";
	for (auto x : trafficLights)
		f << x.getState() << " " << x.getTime() << " ";
	f.close();
}

bool Game::loadGame(std::string name) {
	std::ifstream f;
	f.open("./data/" + name + ".dat");
	if (!f.is_open())
		return false;
	Game::~Game();
	f >> level;
	int x, y;
	f >> x >> y;
	player = people(x, y);
	int n;
	f >> n;
	vehicle.assign(n, nullptr);
	for (int i = 0; i < n; i++) {
		int type;
		f >> x >> y >> type;
		if (type == 1)
			vehicle[i] = new car(x, y);
		else
			vehicle[i] = new ufo(x, y);
	}
	f >> n;
	animal.assign(n, nullptr);
	for (int i = 0; i < n; i++) {
		int type;
		f >> x >> y >> type;
		if (type == 1)
			animal[i] = new Duck(x, y);
		else
			animal[i] = new Moew(x, y);
	}
	f >> n;
	for (int i = 0; i < n; i++) {
		f >> x >> y;
		trafficLights.push_back(TrafficLights(x, y));
	}
	f.close();
	return true;
}

void Game::updatePeople(char c) {
	switch (c)
	{
	case 'W':
		player.Up(HEIGHT);
		break;
	case 'A':
		player.Left(WIDTH);
		break;
	case 'S':
		player.Down(HEIGHT);
	case 'D':
		player.Right(WIDTH);
		break;
	default:
		break;
	}
}

void Game::update() {
	for (auto x : animal)
		x->move(x->getSign());
	for (auto x : vehicle)
		x->move(x->getSign());
}

void Game::levelUp() {
	srand(time(NULL));
	level++;
	Game::~Game();
	player = people();
	int n = min(2 + level + rand() % 2, 9);
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
			vehicle[2 * i] = new car(10 + (rand() % 3 + 1) + vehicle[2*(i-1)]->getX(), 12); // lane 1
			vehicle[2 * i + 1] = new ufo(10 + (rand() % 3 + 1) + vehicle[2*(i - 1)+1]->getX(), 19); //lane 2
			animal[2 * i] = new Duck(10 + (rand() % 3 + 1) + animal[2*(i - 1)]->getX(), 26); //lane 3
			animal[2 * i + 1] = new Moew(10 + (rand() % 3 + 1) + animal[2*(i - 1)+1]->getX(), 33); //lane 4
		}
	}
	if (level > 6) {
		trafficLights.push_back(TrafficLights());
		if (level > 10)
			trafficLights.push_back(TrafficLights());
	}
}

void Game::startGame() {
	level = 0;
	levelUp();
}

bool Game::finish() {
	return false;
}

bool Game::isDead() {
	return player.isDead();
}

bool Game::endGame() {
	return player.isImpact(vehicle) || player.isImpact(animal);
}