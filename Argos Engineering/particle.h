#pragma once
#include"point.h"
#include<vector>
#include<iostream>

using namespace std;

class particle
{
    //—войства частицы: траектори€ движени€, скорости движкени€ по ос€м, статус столкновени€ с поверхностью

private:
    vector<point> path;
    bool collisionStatus;
	double xVelocity;
	double yVelocity;

public:

    // онструктор частицы. ѕо умолчанию считаетс€, что частица не сталкивалась с поверхностью. start - начальна€ точка в траектории движени€
	//xVelocity, yVelocity - скорости движени€ частицы по ос€м соответственно
    particle(point start, double xVelocity, double yVelocity, bool collisionStatus = false);

    //ѕолчуение траектории движени€ частицы дл€ дальнейшей обработки
    vector<point> getPath();

    //ѕолучение статуса столкновени€ дл€ дальнейшей обработки
    bool hasCollided();

    //ƒобавление точки траектории частицы
    void addPoint(point p);

    //ƒобавление столкновени€ частицы с поверхностью в точке p. ≈сли столкновение происходило ранее, выводитс€ сообщение об этом
    void addCollision(point p);

    //¬ывод статуса частицы на экран
    void printStatus();

	//»зменение скорости движени€ частицы по оси x
	void changeXVelocity(double newXVelocity);

	//»зменение скорости движени€ частицы по оси y
	void changeYVelocity(double newYVelocity);

    //ѕолучение скорости движени€ частицы по оси x
    double getXVelocity();

    //ѕолучение скорочти движени€ частицы по оси y
    double getYVelocity();
};

