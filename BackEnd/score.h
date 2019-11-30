#pragma once
#include <string>

class Score {
private:
	std::string name;
	int level;
public:
	void Input(std::string name_, int level_ );
	std::string getName();
	int getLevel()
	{
		return level;
	}
};