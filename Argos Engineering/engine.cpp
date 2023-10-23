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
	
	for (int i = 0; i < spawnedParticles.size(); i ++) {
		this->particles.push_back(spawnedParticles[i]);
	}
}

point engine::findClosestPoint(double x, double y, vector<point> points) {
	int num = 0;
	int minDistance = 99999;

	for (int i = 0; i < points.size(); i++) {
		double newDistance = sqrt((x - points[i].getXCoordinate()) * (x - points[i].getXCoordinate()) + (y - points[i].getYCoordinate()) * (y - points[i].getYCoordinate()));
		if (minDistance > newDistance) {
			minDistance = newDistance;
			num = i;
		}
	}
	return points[num];
}

void engine::moveParticles(int time) {

	for (int j = 0; j < time; j++) {
		for (int i = 0; i < this->particles.size(); i++) {
			if (!this->particles[i].hasCollided()) {

				point lastPartCoords = this->particles[i].getPath()[this->particles[i].getPath().size() - 1];
				double xPart = lastPartCoords.getXCoordinate() + this->particles[i].getXVelocity();
				double yPart = lastPartCoords.getYCoordinate() + this->particles[i].getYVelocity();

				for (int k = 0; k < this->surfaces.size(); k++) {
					//проверка на пересечение с материальной поверхностью
					double x1 = this->surfaces[k].getPoints()[0].getXCoordinate();
					double y1 = this->surfaces[k].getPoints()[0].getYCoordinate();
					double x2 = this->surfaces[k].getPoints()[this->surfaces[k].getPoints().size() - 1].getXCoordinate();
					double y2 = this->surfaces[k].getPoints()[this->surfaces[k].getPoints().size() - 1].getYCoordinate();

					if ((xPart >= min(x1, x2) && xPart <= max(x1, x2)) && (yPart >= min(y1, y2) && yPart <= max(y1, y2))) {
						point a = this->findClosestPoint(xPart, yPart, this->surfaces[k].getPoints());
						this->particles[i].addCollision(a);
						cout << "Particle # " << i << " has collided in x = " << a.getXCoordinate() << " y = " << a.getYCoordinate() << endl;
					}
				}

				if (!this->particles[i].hasCollided()) {
					this->particles[i].addPoint(point(xPart, yPart));
				}
			}
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
		if (counter != 0) {
			averagePath.push_back(point(x / counter, y / counter));
		}
		else {
			averagePath.push_back(point(x, y));
		}
	}

	cout << "Average path of particle is: " << endl;
	for (point p : averagePath) {
		cout << "x =  " << p.getXCoordinate() << ", y = " << p.getYCoordinate() << endl;
	}
}
