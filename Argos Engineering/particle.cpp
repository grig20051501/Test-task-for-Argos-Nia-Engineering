#include "particle.h"
#include "point.h"
#include <iostream>
#include <vector>
using namespace std;
//Класс "частица" ( частицы рассматриваются в двумерном пространстве )
//Движение частиц считаю целесообразным вынести из класса, чтобы координаты частиц изменялись отдельно в явном виде
//Ниже представлено два варианта реализации класса
//partickle2 - частица, которая хранит всю траекторию своего движения по осям. В случае столкновения - координатами столкновения считаются координаты последней точки траектории



    //Свойства частицы: траектория по оси x, траектория по оси y , статус столкновения с поверхностью



    //Конструктор частицы. По умолчанию считается, что частица не сталкивалась с поверхностью. x0, y0 - начальные координаты
    particle::particle(point start, bool collisionStatus) {
        this->coordinates.push_back(start);
        this->collisionStatus = collisionStatus;
    }
    //Полчуение траектории движения частицы по оси x для дальнейшей обработки
    vector<point> particle::getTrajectory() {
        return this->coordinates;
    }
    //Получение статуса столкновения для дальнейшей обработки
    bool particle::hasCollided() {
        return this->collisionStatus;
    }
    //Добавление точки траектории частицы
    void particle::addPoint(point p) {
        this->coordinates.push_back(p);
    }
    //Добавление столкновения частицы с поверхностью в точке с координатами x и y. Если столкновение происходило ранее, выводится сообщение об этом
    void particle::addCollision(point p) {

        if (this->collisionStatus) {
            cout << "Adding collision error! Particle has already collided!" << endl;
        }
        else
        {
            this->coordinates.push_back(p);
            this->collisionStatus = true;
        }
    }
    //Вывод статуса частицы на экран
    void particle::printStatus() {
        if (collisionStatus) {
            cout << "partice has collided with surface in x = " << this->coordinates[this->coordinates.size() - 1].getXCoordinate() << " y = " << this->coordinates[coordinates.size() - 1].getYCoordinate() << endl;
        }
        else
        {
            cout << "particle last coordinates are x = " << this->coordinates[this->coordinates.size() - 1].getXCoordinate() << " and y = " << this->coordinates[coordinates.size() - 1].getYCoordinate() << endl;
        }
    }