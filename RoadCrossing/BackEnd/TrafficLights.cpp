#include "TrafficLights.h"

TrafficLights::TrafficLights() {
	state = 1;
	time = 10; //default time 
}

TrafficLights::TrafficLights(int state, int time) {
	this->state = state;
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
		state = 1 - state;
		time = (state ? newTime / 2 : newTime);
	}
}