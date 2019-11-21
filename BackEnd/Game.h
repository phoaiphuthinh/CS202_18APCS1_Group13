#pragma once

#include "animal.h"
#include "vehicle.h"
#include "TrafficLights.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class Game {
private:
	std::vector<Animal*> animal;
	std::vector<Vehicle*> vehicle;
	std::vector<TrafficLights> trafficLights;
	int level; 
	//People : Hiu's work
public:
	Game();
	~Game();
	void draw();
	std::vector<Animal*> getAnimal();
	std::vector<Vehicle*> getVehicle();
	void resetGame();
	void startGame();
	void loadGame(std::string name);
	void saveGame(std::string name);
	void updatePeople(char c);
	void update();

	//List of other methods
};