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
			loadfile.ignore('\0', 1000); // get player name
			std::getline(loadfile, name, '\0'); // get player name
			loadfile.read((char*)&level, sizeof(int)); // read int bytes
			tmp.Input(name, level);
			if (!isExisted(tmp))
				score.push_back(tmp);
		}
		sort();
		score.resize(std::min(10, num));
		loadfile.close();
		return true;
	}
	loadfile.close();
	return false;
}

bool Scoreboard::save()
{
	score.resize(std::min(10,(int)score.size()));
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

void Scoreboard::sort()
{
	for (int k = 0; k < score.size(); k++)
	{
		for (int i = 0; i < score.size() - 1; i++) {
			if (score[i].getLevel() < score[i + 1].getLevel())
			{
				Score temp = score[i];
				score[i] = score[i + 1];
				score[i + 1] = temp;
			}
		}
	}
}

void Scoreboard::draw()
{
	system("cls");
	cout << setfill('-') << setw(55) << "";
	cout << setfill(' ') << "\n";
	cout << "| " << setw(15) << left << "RANKING";
	cout << "| " << setw(25) << left << "NAME";
	cout << "| " << setw(10) << left << "LEVEL";
	cout << "| " << setfill('-') << setw(55) << "\n";
	cout << setfill(' ') << "\n";
	for (int i = 0; i < score.size(); i++) {
		cout << "| " << setw(15) << left << i + 1;
		cout << "| " << setw(25) << left << score[i].getName();
		cout << "| " << setw(10) << left << score[i].getLevel();
		cout << "|\n";
		cout << setfill('-') << setw(55) << "";
		cout << setfill(' ') << "\n";
	}
}

