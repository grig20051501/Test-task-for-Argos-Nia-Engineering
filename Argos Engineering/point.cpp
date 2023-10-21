#include "point.h"

point::point(int x, int y) {
	this->xCoordinate = x;
	this->yCoordinate = y;
};

int point::getXCoordinate() {
	return this->xCoordinate;
};

int point::getYCoordinate() {
	return this->yCoordinate;
};

void point::changeXCoordinate(int newX) {
	this->xCoordinate = newX;
};

void point::changeYCoordinate(int newY) {
	this->yCoordinate = newY;
};


