#include "vehicle.h"
#include "animal.h"
#include <vector>
class people {
	int mX, mY;
	const int width = 5;
	bool mState;
public:
	people();
	void Up(int height);

	void Left(int width);

	void Right(int width);
	void Down(int height);

	bool isImpact(const std::vector<Vehicle*>& vVehicle);

	bool isImpact(const std::vector<Animal*>& vAnimal);

	bool isFinish();
	bool isDead();
}