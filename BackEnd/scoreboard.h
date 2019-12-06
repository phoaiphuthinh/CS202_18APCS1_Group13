#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "score.h"
#include <fstream>
#include <iomanip>
#include <algorithm>
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
	bool isExisted(Score other)
	{
		for (int i=0; i<score.size(); i++)
		{
			if (score[i].getName() == other.getName()) {
				//&& score[i].getLevel() == other.getLevel())
				score[i].update(other.getLevel());
				return true;
			}
		}
		return false;
	}
};