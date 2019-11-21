#include "Game.h"

Game::Game() {

}

Game::~Game() {
	//Destroy animal
	for (auto x : animal)
		delete x;
	//Destroy vehicles
	for (auto x : vehicle)
		delete x;
}

void Game::draw() {
	//Ponk long xien
}

std::vector<Animal*> Game::getAnimal() {
	return animal;
}

std::vector<Vehicle*> Game::getVehicle() {
	return vehicle;
}

void Game::saveGame(std::string name) {
	/*
			FORMAT FILE
			- First line: coordinate of people : x , y
			- Second line: number of animal (n)
			- Third line: n coordinates of n animal (xi, yi)
			- Forth line: number of vehicles (m)
			- Fiveth line: m coordinates of m vehicles (xi, yi)
			- Sixth line: number of trafficlight (k)
			- Seventh line: state and time remaining of k traffic lights 
			
		At first, save data in text file. If it works perfectly, store in binary file.
	*/
	std::ofstream f;
	f.open(name);
	//get x, y

	std::cout << vehicle.size() << "\n";
	for (int i = 0; i < (int)vehicle.size(); i++) {
		// vehicle[i]->getX() getY()

	}
}