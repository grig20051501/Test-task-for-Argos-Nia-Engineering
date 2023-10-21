#pragma once
#include"point.h"
#include<vector>
#include<iostream>

using namespace std;

class particle
{
    //—войства частицы: траектори€ по оси x, траектори€ по оси y , статус столкновени€ с поверхностью

private:
    vector<point> coordinates;
    bool collisionStatus;

public:
    // онструктор частицы. ѕо умолчанию считаетс€, что частица не сталкивалась с поверхностью. x0, y0 - начальные координаты
    particle(point start, bool collisionStatus = false);
    //ѕолчуение траектории движени€ частицы по оси x дл€ дальнейшей обработки
    vector<point> getTrajectory();
    //ѕолучение статуса столкновени€ дл€ дальнейшей обработки
    bool hasCollided();
    //ƒобавление точки траектории частицы
    void addPoint(point p);
    //ƒобавление столкновени€ частицы с поверхностью в точке с координатами x и y. ≈сли столкновение происходило ранее, выводитс€ сообщение об этом
    void addCollision(point p);
    //¬ывод статуса частицы на экран
    void printStatus();
};

