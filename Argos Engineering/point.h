#pragma once

class point {
private:
	double xCoordinate;
	double yCoordinate;
public:
	point(double x, double y);
	double getXCoordinate();
	double getYCoordinate();
	void changeXCoordinate(double newX);
	void changeYCoordinate(double newY);
};