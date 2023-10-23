#include "surface.h"
#include <time.h>

surface::surface(point firstPoint, point lastPoint, double scale, bool doesSpawnParticles) {

	this->scale = scale;
	this->doesSpawnParticles = doesSpawnParticles;

	//Вычисление точек отрезка по каноническому уравнению прямой
	double x = min(firstPoint.getXCoordinate(), lastPoint.getXCoordinate());
	double xa = min(firstPoint.getXCoordinate(), lastPoint.getXCoordinate());
	double xb = max(firstPoint.getXCoordinate(), lastPoint.getXCoordinate());
	double ya = min(firstPoint.getYCoordinate(), lastPoint.getYCoordinate());
	double y = min(firstPoint.getYCoordinate(), lastPoint.getYCoordinate());
	double yb = max(firstPoint.getYCoordinate(), lastPoint.getYCoordinate());

	

	if (xa == xb) {
		for (int i = ya; i <= yb; i++) {
			this->lineOfSurface.push_back(point(xa, i));
		}
	}
	else if (ya == yb) {
		for (int i = xa; i <= xb; i++) {
			this->lineOfSurface.push_back(point(i, ya));
		}
	}
	else {
		this->lineOfSurface.push_back(firstPoint);
		while (x != xb && y != yb) {

			x += this->scale;
			y = (x - xa) * (yb - ya) / (xb - xa) + ya;
			this->lineOfSurface.push_back(point(x, y));
		}
	}
};

void surface::printLine() {
	for (point p : this->lineOfSurface) {
		cout << p.getXCoordinate() << " " << p.getYCoordinate() << endl;
	}
}

vector<point> surface::getPoints() {
	return this->lineOfSurface;
}

vector<particle> surface::spawnParticles(int numOfParticles, double xVelocity, double yVelocity) {

	srand(time(0));
	vector<particle> particles;

	bool isXVelocityRandom = false;
	bool isYVelocityRandom = false;

	if (xVelocity == -1) {
		isXVelocityRandom = true;
	}

	if (yVelocity == -1) {
		isYVelocityRandom = true;
	}

	for(int i = 0 ; i < numOfParticles; i++) {

		if (isXVelocityRandom) {
			xVelocity = rand() % 9;
		}

		if (isYVelocityRandom) {
			yVelocity = rand() % 9;
		}

		point spawnPoint = this->lineOfSurface[rand() % this->lineOfSurface.size()];

		particles.push_back(particle(spawnPoint, xVelocity, yVelocity, false));
		cout << "Particle # " << i << " was spawned at x = " << spawnPoint.getXCoordinate() << " y = " << spawnPoint.getYCoordinate() << endl;
	}
	cout << endl;
	return particles;
}

bool surface::canSpawn() {
	return this->doesSpawnParticles;
}
