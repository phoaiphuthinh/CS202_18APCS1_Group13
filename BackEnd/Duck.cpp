#include "duck.h"

Duck::Duck() {
	sound = "boloxi";
}

Duck::Duck(int x, int y) : Animal(x,y) {
	sound = "boloxi";
}

void Duck::draw(int x, int y) {
	//Front-end, this part is Dat's responsibility

}

int Duck::getSign() {
	return 1;
}