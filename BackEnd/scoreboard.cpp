#include "scoreboard.h"

bool Scoreboard::load()
{
	//read from binary file
	/*
	FORMAT FILE
	- 0th: number of scores
	- First line:
	*/
	std::ifstream loadfile("./data/scoreboard.dat", std::ios_base::binary);
	if (loadfile.good())
	{
		int num = 0;
		loadfile.read((char*)&num, sizeof(int)); // read int bytes
		for (int i = 0; i < num; i++)
		{
			Score tmp;
			std::string name;
			int level;
			std::getline(loadfile, name, '\0'); // get player name
			loadfile.read((char*)&level, sizeof(int)); // read int bytes
			tmp.Input(name, level);
			score.push_back(tmp);
		}
		loadfile.close();
		return true;
	}
	loadfile.close();
	return false;
}

bool Scoreboard::save()
{
	std::ofstream savefile("./data/scoreboard.dat", std::ios_base::binary);
	if (savefile.good())
	{
		int size = score.size();
		std::string name;
		int level;
		savefile.write(reinterpret_cast<char*>(&size), sizeof(int)); // write int to binary file
		for (int i = 0; i < size; i++)
		{
			name = score[i].getName();
			level = score[i].getLevel();
			savefile.write(name.c_str(), name.size()); // write string to binary file
			savefile.write("\0", sizeof(char)); // null end string for easier reading
			savefile.write(reinterpret_cast<char*>(&level), sizeof(level)); // write int to binary file
		}
		savefile.close();
		return true;
	}
	savefile.close();
	return false;
}

