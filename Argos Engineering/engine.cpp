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

bool engine::areLinesIntersecting(point p1, point p2, point p3, point p4) {
	double x1 = p1.getXCoordinate(), y1 = p1.getYCoordinate();
	double x2 = p2.getXCoordinate(), y2 = p2.getYCoordinate();
	double x3 = p3.getXCoordinate(), y3 = p3.getYCoordinate();
	double x4 = p4.getXCoordinate(), y4 = p4.getYCoordinate();

	double den = (y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1);

	if (den == 0) {
		return false;  // Прямые параллельны или совпадают
	}

	double ua = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / den;
	double ub = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / den;

	if (ua >= 0 && ua <= 1 && ub >= 0 && ub <= 1) {
		return true;   // Прямые пересекаются внутри отрезков
	}

	return false;   // Прямые не пересекаются
}

void engine::moveParticles(int time) {

	for (int j = 0; j < time; j++) {
		for (int i = 0; i < this->particles.size(); i++) {

				point lastPartCoords = this->particles[i].getPath()[this->particles[i].getPath().size() - 1];
				point part1 = point(lastPartCoords.getXCoordinate(), lastPartCoords.getYCoordinate());
				point part2 = point(lastPartCoords.getXCoordinate() + this->particles[i].getXVelocity(), lastPartCoords.getYCoordinate() + this->particles[i].getYVelocity());

				for (int k = 0; k < this->surfaces.size(); k++) {
					//проверка на пересечение с материальной поверхностью

					point p1 = this->surfaces[k].getPoints()[0];
					point p2 = this->surfaces[k].getPoints()[this->surfaces[k].getPoints().size() - 1];

					if (this->areLinesIntersecting(part1, part2, p1, p2) && !this->surfaces[k].canSpawn() && !this->particles[i].hasCollided()) {
						point a = this->findClosestPoint(part2.getXCoordinate(), part2.getYCoordinate(), this->surfaces[k].getPoints());
						this->particles[i].addCollision(a);
						cout << "Particle # " << i << " has collided in x = " << a.getXCoordinate() << " y = " << a.getYCoordinate() << endl;
					}
				}

				if (!this->particles[i].hasCollided()) {
					this->particles[i].addPoint(part2);
				}
				else {
					point lastPointOfPath = this->particles[i].getPath()[this->particles[i].getPath().size() - 1];
					this->particles[i].addPoint(lastPointOfPath);
				}
			}
		}
	cout << endl;
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
	}

	cout << "Average path of particle is: " << endl;
	for (point p : averagePath) {
		cout << "x =  " << p.getXCoordinate() << ", y = " << p.getYCoordinate() << endl;
	}
}
