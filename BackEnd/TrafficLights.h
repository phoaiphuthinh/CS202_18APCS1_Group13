#pragma once

class TrafficLights {
private:
	int state; //red or blue
	int time; //time remaining
public:
	TrafficLights();
	TrafficLights(int time);
	int getState();
	int getTime();
	void change(int newTime = 30);
};