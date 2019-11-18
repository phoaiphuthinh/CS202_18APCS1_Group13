#pragma once

#include "animal.h"
#include "vehicle.h"
#include "TrafficLights.h"
#include <vector>

class Game {
private:
	std::vector<Animal*> animal;
	std::vector<Vehicle*> vehicle;
	TrafficLights trafficLights;
	//People : Hiu's work
public:
	Game();
	~Game();
	void draw();
	//List of other methods
};