#include "engine.h"

void engine::spawnSurface(point firstPoint, point lastPoint, double scale, bool doesSpawnParticles)
{
	this->surfaces.push_back(surface(firstPoint, lastPoint, scale, doesSpawnParticles));
}

//Если будет время - доделать рандомное создание спавнера в случае его отсутствия
surface engine::findSpawningSurface() {
	for (surface surf : this->surfaces) {
		if (surf.canSpawn()) {
			return surf;
		}
	}
}

void engine::spawnParticles(int numOfParticles, double xVelocity, double yVelocity) {

	surface spawner = this->findSpawningSurface();

	vector<particle> spawnedParticles = spawner.spawnParticles(numOfParticles, xVelocity, yVelocity);
	
	for (particle part : spawnedParticles) {
		this->particles.push_back(part);
	}
}

void engine::moveParticles(int time) {

	for (int j = 0; j < time; j++) {
		for (int i = 0; i < this->particles.size(); i++) {
			this->particles[i].move();
		}
	}
}

void engine::printPathOfParticles() {
	int i = 0;
	for (particle part : this->particles) {
		vector<point> path = part.getPath();
		cout << "particle n: " << i << endl;
		i++;
		for (point p : path) {
			cout << "x = " << p.getXCoordinate() << " y = " << p.getYCoordinate() << endl;
		}
	}
}

void engine::calculate(int time) {
	vector<point> averagePath;

	for (int i = 0; i <= time; i++) {
		int counter = 0;
		double x = 0;
		double y = 0;

		for (particle part : this->particles) {
			if (part.getPath().size() - 1 >= i) {
				x += part.getPath()[i].getXCoordinate();
				y += part.getPath()[i].getYCoordinate();
				counter++;
			}
		}
		//cout << "CALCULATING " << " X: " << x << " Y: " << y << " COUNTER: " << counter << endl;
		averagePath.push_back(point(x / counter, y / counter));
	}

	cout << "Average path of particle is: " << endl;
	for (point p : averagePath) {
		cout << "x =  " << p.getXCoordinate() << ", y = " << p.getYCoordinate() << endl;
	}
}
