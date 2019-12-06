#include "score.h"
void Score::Input(std::string name_, int level_)
{
	name = name_;
	level = level_;
}

std::string Score::getName()
{
	return name;
}

void Score::update(int newLevel) {
	if (newLevel > level)
		level = newLevel;
}
