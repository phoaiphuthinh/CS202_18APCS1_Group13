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

