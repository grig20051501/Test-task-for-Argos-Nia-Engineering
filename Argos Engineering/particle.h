#pragma once
#include<vector>
#include<iostream>

using namespace std;

class particle
{
    //—войства частицы: траектори€ по оси x, траектори€ по оси y , статус столкновени€ с поверхностью

private:
    vector<int> xCoordinates;
    vector<int> yCoordinates;
    bool collisionStatus;

public:
    // онструктор частицы. ѕо умолчанию считаетс€, что частица не сталкивалась с поверхностью. x0, y0 - начальные координаты
    particle(int x0, int y0, bool collisionStatus = false);
    //ѕолчуение траектории движени€ частицы по оси x дл€ дальнейшей обработки
    vector<int> get_x_trajectory();
    //ѕолчуение траектории движени€ частицы по оси y дл€ дальнейшей обработки
    vector<int> get_y_Trajectory();
    //ѕолучение статуса столкновени€ дл€ дальнейшей обработки
    bool hasCollided();
    //ƒобавление точки траектории частицы
    void addPoint(int x, int y);
    //ƒобавление столкновени€ частицы с поверхностью в точке с координатами x и y. ≈сли столкновение происходило ранее, выводитс€ сообщение об этом
    void addCollision(int x, int y);
    //¬ывод статуса частицы на экран
    void printStatus();
};

