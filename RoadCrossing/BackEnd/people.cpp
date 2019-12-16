#include "people.h"

const int DEFAULT_X = 49;
const int DEFAULT_Y = 40;
const int mapHeight = 10;

people::people()
{
	mX = DEFAULT_X;
	mY = DEFAULT_Y;
	mState = true;
}

people::people(int x, int y) {
	mX = x;
	mY = y;
	mState = true;
}

void people::draw()
{
	int x = mX;
	int y = mY;
	helper::gotoXY(x, y - 3);
	std::cout << " 0  " << std::endl;
	helper::gotoXY(x, y - 2);
	std::cout << "/|\\" << std::endl;
	helper::gotoXY(x, y - 1);
	std::cout << " |  " << std::endl;
	helper::gotoXY(x, y);
	std::cout << "/ \\" << std::endl;
}

void people::clean()
{
	int x = mX;
	int y = mY;
	helper::gotoXY(x, y - 3);
	std::cout << "    " << std::endl;
	helper::gotoXY(x, y - 2);
	std::cout << "    " << std::endl;
	helper::gotoXY(x, y - 1);
	std::cout << "    " << std::endl;
	helper::gotoXY(x, y);
	std::cout << "    " << std::endl;
}

void people::Up(int height)
{
	clean();
	mY -= height;
}

void people::Left(int width)
{
	if (mX - width > 2)
	{
		clean();
		mX -= width;
	}
}

void people::Right(int width)
{
	if (mX + width <= 49 + 25 * 2 - 1)
	{
		clean();
		mX += width;
	}

}

void people::Down(int height)
{
	if (mY + height <= 40)
	{
		clean();
		mY += height;
	}
}

bool people::isImpact(const std::vector<Vehicle*>& vVehicle)
{
	for (int i = 0; i < vVehicle.size(); i++)
	{

		if (vVehicle[i]->getY() == mY) //check whether they are in the same lane
		{

			if ((mX + 2 >= vVehicle[i]->getX() &&
				mX + 2 <= vVehicle[i]->getX() + vVehicle[i]->getWidth()))
			{
				mState = false;
				vVehicle[i]->makeSound();
				return true;
			}
		}
	}
	return false;
}

bool people::isImpact(const std::vector<Animal*>& vAnimal)
{
	for (int i = 0; i < vAnimal.size(); i++)
	{
		if (vAnimal[i]->getY() == mY) //check whether they are in the same lane
		{
			if ((mX + 2 >= vAnimal[i]->getX() &&
				mX + 2 <= vAnimal[i]->getX() + vAnimal[i]->getWidth()))
			{
				mState = false;
				vAnimal[i]->makeSound();
				return true;
			}
		}
	}
	return false;
}

bool people::isFinish()
{
	if (mY == DEFAULT_Y - 7 * 5) { 
		return true;
	}
	else return false;
}

bool people::isDead()
{
	return !mState;
}


int people::getX() {
	return mX;
}

int people::getY() {
	return mY;
}
