#pragma once

class point {
private:
	int xCoordinate;
	int yCoordinate;
public:
	point(int x, int y);
	int getXCoordinate();
	int getYCoordinate();
	void changeXCoordinate(int newX);
	void changeYCoordinate(int newY);
};