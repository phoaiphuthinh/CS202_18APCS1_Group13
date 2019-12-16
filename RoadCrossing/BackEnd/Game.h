#pragma once

#include "animal.h"
#include "vehicle.h"
#include "TrafficLights.h"
#include "people.h"
#include "car.h"
#include "ufo.h"
#include "duck.h"
#include "moew.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include "../FrontEnd/helper.h"
#include "scoreboard.h"
class Game {
private:
	std::vector<Animal*> animal;
	std::vector<Vehicle*> vehicle;
	std::vector<TrafficLights> trafficLights;
	int level; 
	people player;
	Scoreboard scoreboard;
	std::string name;
public:
	Game();
	~Game();
	void draw();
	bool loadGame(std::string name);
	bool loadScoreboard();
	bool saveScoreboard();
	int getLev();
	Scoreboard getScoreboard();
	void saveGame();
	void updatePeople(char c);
	void update();
	void levelUp();
	void startGame(std::string name);
	bool finish();
	bool isDead();
	bool endGame();
	//List of other methods
};