#include "particle.h"
#include <iostream>
#include <vector>
using namespace std;
//Класс "частица" ( частицы рассматриваются в двумерном пространстве )
//Движение частиц считаю целесообразным вынести из класса, чтобы координаты частиц изменялись отдельно в явном виде
//Ниже представлено два варианта реализации класса
//partickle2 - частица, которая хранит всю траекторию своего движения по осям. В случае столкновения - координатами столкновения считаются координаты последней точки траектории



    //Свойства частицы: траектория по оси x, траектория по оси y , статус столкновения с поверхностью



    //Конструктор частицы. По умолчанию считается, что частица не сталкивалась с поверхностью. x0, y0 - начальные координаты
    particle::particle(int x0, int y0, bool collisionStatus) {
        this->xCoordinates.push_back(x0);
        this->yCoordinates.push_back(y0);
        this->collisionStatus = collisionStatus;
    }
    //Полчуение траектории движения частицы по оси x для дальнейшей обработки
    vector<int> particle::get_x_trajectory() {
        return this->xCoordinates;
    }
    //Полчуение траектории движения частицы по оси y для дальнейшей обработки
    vector<int> particle::get_y_Trajectory() {
        return this->yCoordinates;
    }
    //Получение статуса столкновения для дальнейшей обработки
    bool particle::hasCollided() {
        return this->collisionStatus;
    }
    //Добавление точки траектории частицы
    void particle::addPoint(int x, int y) {
        this->xCoordinates.push_back(x);
        this->yCoordinates.push_back(y);
    }
    //Добавление столкновения частицы с поверхностью в точке с координатами x и y. Если столкновение происходило ранее, выводится сообщение об этом
    void particle::addCollision(int x, int y) {

        if (this->collisionStatus) {
            cout << "Adding collision error! Particle has already collided!" << endl;
        }
        else
        {
            this->xCoordinates.push_back(x);
            this->yCoordinates.push_back(y);
            this->collisionStatus = true;
        }
    }
    //Вывод статуса частицы на экран
    void particle::printStatus() {
        if (collisionStatus) {
            cout << "partice has collided with surface in x = " << this->xCoordinates[this->xCoordinates.size() - 1] << " y = " << this->yCoordinates[yCoordinates.size() - 1] << endl;
        }
        else
        {
            cout << "particle last coordinates are x = " << this->xCoordinates[this->xCoordinates.size() - 1] << " and y = " << this->yCoordinates[yCoordinates.size() - 1] << endl;
        }
    }