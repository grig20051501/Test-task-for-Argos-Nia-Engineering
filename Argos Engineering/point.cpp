#include "point.h"

point::point(double x, double y) {
	this->xCoordinate = x;
	this->yCoordinate = y;
};

double point::getXCoordinate() {
	return this->xCoordinate;
};

double point::getYCoordinate() {
	return this->yCoordinate;
};

void point::changeXCoordinate(double newX) {
	this->xCoordinate = newX;
};

void point::changeYCoordinate(double newY) {
	this->yCoordinate = newY;
};


