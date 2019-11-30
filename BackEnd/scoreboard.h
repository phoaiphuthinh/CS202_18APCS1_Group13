#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "score.h"
#include <fstream>

class Scoreboard {
private:
	std::vector<Score> score;
	friend class Game;
public:
	bool load();
	bool save();
};