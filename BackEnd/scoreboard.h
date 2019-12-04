#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "score.h"
#include <fstream>
#include <iomanip>
using std::cout;
using std::setw;
using std::left;
using std::setfill;

class Scoreboard {
private:
	std::vector<Score> score;
	friend class Game;
public:
	bool load();
	bool save();
	void sort();
	void draw();
};