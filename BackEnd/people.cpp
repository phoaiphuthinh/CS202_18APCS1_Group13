#include "people.h"

const int DEFAULT_X = 15;
const int DEFAULT_Y = 15;

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
	// N/A mapHeight
	/*	if (mY == mapHeight) return true;
		else return false;*/
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
