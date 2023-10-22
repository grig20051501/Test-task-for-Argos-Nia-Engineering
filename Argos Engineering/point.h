#pragma once

//Точка в плоскости. Характеризуется двумя координатами
class point {
private:
	double xCoordinate;
	double yCoordinate;
public:

	//Конструктор точки. Принимает две координаты - x и y
	point(double x, double y);

	point();

	//Получение координаты точки по оси x
	double getXCoordinate();

	//Получение координаты точки по оси y
	double getYCoordinate();

	//Изменение координаты точки по оси x
	void changeXCoordinate(double newX);

	//Изменение координаты точки по оси y
	void changeYCoordinate(double newY);
};