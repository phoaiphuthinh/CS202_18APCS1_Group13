#include "vehicle.h"

#define SCREEN_SIZE_WIDTH 129
#define SCREEN_SIZE_HEIGHT  29

Vehicle::Vehicle() {

}

Vehicle::~Vehicle() {

}

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
	if (mX + w < 0)
		mX += w;
	if (mX - w > SCREEN_SIZE_WIDTH)
		mX -= w;
}
