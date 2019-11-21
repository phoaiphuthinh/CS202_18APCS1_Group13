#include "vehicle.h"

#define SCREEN_SIZE_WEIGHT = 129;
#define SCREEN_SIZE_HEIGHT = 29;

int Vehicle::getX()
{
	return mX;
}

int Vehicle::getY()
{
	return mY;
}

int Vehicle::getWidth()
{
	return w;
}

void Vehicle::move(int sign) //left or right
{
	mX += sign * w / 2;
	mY += sign * h / 2;
	if (mX - w / 2 > SCREEN_SIZE_WEIGHT || mX + w / 2 < 0 || mY - h / 2 > SCREEN_SIZE_HEIGHT || mY + h / 2 < 0)
		destroy = true;
	else
		draw();
}
