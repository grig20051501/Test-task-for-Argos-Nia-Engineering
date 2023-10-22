#include "particle.h"
#include "point.h"
#include <iostream>
#include <vector>
using namespace std;

particle::particle(point start, double xVelocity, double yVelocity, bool collisionStatus) {
    this->path.push_back(start);
    this->xVelocity = xVelocity;
    this->yVelocity = yVelocity;
    this->collisionStatus = collisionStatus;
}

vector<point> particle::getPath() {
    return this->path;
}

bool particle::hasCollided() {
    return this->collisionStatus;
}

void particle::addPoint(point p) {
    this->path.push_back(p);
}

void particle::addCollision(point p) {

    if (this->collisionStatus) {
        cout << "Adding collision error! Particle has already collided!" << endl;
    }
    else
    {
        this->path.push_back(p);
        this->collisionStatus = true;
    }
}

void particle::printStatus() {
    if (collisionStatus) {
        cout << "partice has collided with surface in x = " << this->path[this->path.size() - 1].getXCoordinate() << " y = " << this->path[path.size() - 1].getYCoordinate() << endl;
    }
    else
    {
        cout << "particle last coordinates are x = " << this->path[this->path.size() - 1].getXCoordinate() << " and y = " << this->path[path.size() - 1].getYCoordinate() << endl;
        cout << "particle's velocity by x axis is: " << this->xVelocity << " and by y axis is: " << this->yVelocity << endl;
    }
}

void particle::changeXVelocity(double newXVelocity) {
	this->xVelocity = newXVelocity;
}

void particle::changeYVelocity(double newYVelocity) {
	this->yVelocity = newYVelocity;
}

void particle::move() {
    if (!this->collisionStatus) {
        point lastPoint = this->path[this->path.size() - 1];
        point newPoint = point(lastPoint.getXCoordinate() + this->xVelocity, lastPoint.getYCoordinate() + this->yVelocity);
        this->path.push_back(newPoint);
    }
}