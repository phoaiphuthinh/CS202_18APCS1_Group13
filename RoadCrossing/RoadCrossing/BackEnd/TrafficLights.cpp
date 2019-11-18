#include "TrafficLights.h"

TrafficLights::TrafficLights() {
	state = 0;
	time = 30; //default time 
}

TrafficLights::TrafficLights(int time) {
	state = 0;
	this->time = time;
}

int TrafficLights::getState() {
	return state;
}

int TrafficLights::getTime() {
	return time;
}

void TrafficLights::change(int newTime) {
	time--;
	if (time == 0) {
		time = newTime;
		state = 1 - state;
	}
}