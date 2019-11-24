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
	gotoXY(x, y-3);
	std::cout << " 0  " << std::endl;
	gotoXY(x, y-2);
	std::cout << "/|\\" << std::endl;
	gotoXY(x, y-1);
	std::cout << " |  " << std::endl;
	gotoXY(x, y);
	std::cout << "/ \\" << std::endl;
}

void people::Up(int height)
{
	mY += height;
}

void people::Left(int width)
{
	mX += width;
}

void people::Right(int width)
{
	mX -= width;
}

void people::Down(int height)
{
	mY -= height;
}

bool people::isImpact(const std::vector<Vehicle*>& vVehicle)
{
	for (int i = 0; i < vVehicle.size(); i++)
	{
		if (vVehicle[i]->getY() == mY) //check whether they are in the same lane
		{
			if ((mX >= vVehicle[i]->getX() &&
				mX <= vVehicle[i]->getX() + vVehicle[i]->getWidth())
				|| (mX + width >= vVehicle[i]->getX() &&
					mX + width <= vVehicle[i]->getX() + vVehicle[i]->getWidth()))
				return false;
		}
	}
	return true;
}

bool people::isImpact(const std::vector<Animal*>& vAnimal)
{
	for (int i = 0; i < vAnimal.size(); i++)
	{
		if (vAnimal[i]->getY() == mY) //check whether they are in the same lane
		{
			if ((mX >= vAnimal[i]->getX() &&
				mX <= vAnimal[i]->getX() + vAnimal[i]->getWidth())
				|| (mX + width >= vAnimal[i]->getX() &&
					mX + width <= vAnimal[i]->getX() + vAnimal[i]->getWidth()))
				mState = false;
			return true;
		}
	}
	return false;
}

bool people::isFinish()
{
	 
		if (mY == mapHeight) return true;
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
