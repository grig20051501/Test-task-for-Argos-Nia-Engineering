#include "surface.h"
#include <time.h>

surface::surface(point firstPoint, point lastPoint, double scale, bool doesSpawnParticles) {

	this->scale = scale;
	this->doesSpawnParticles = doesSpawnParticles;

	double x = min(firstPoint.getXCoordinate(), lastPoint.getXCoordinate());
	double xa = min(firstPoint.getXCoordinate(), lastPoint.getXCoordinate());
	double xb = max(firstPoint.getXCoordinate(), lastPoint.getXCoordinate());
	double ya = min(firstPoint.getYCoordinate(), lastPoint.getYCoordinate());
	double y = min(firstPoint.getYCoordinate(), lastPoint.getYCoordinate());
	double yb = max(firstPoint.getYCoordinate(), lastPoint.getYCoordinate());

	this->lineOfSurface.push_back(firstPoint);

	while (x != xb && y != yb) {

		x += this->scale;
		y = (x - xa) * (yb - ya) / (xb - xa) + ya;
		this->lineOfSurface.push_back(point(x, y));	
	}
};

void surface::printLine() {
	for (point p : this->lineOfSurface) {
		cout << p.getXCoordinate() << " " << p.getYCoordinate() << endl;
	}
}

//ÂÀÆÍÎ: ÑÄÅËÀÒÜ ÏÐÎÂÅÐÊÓ ÂÎÇÌÎÆÍÎÑÒÈ ÑÎÇÄÀÍÈß ×ÀÑÒÈÖ
vector<particle> surface::spawnParticles(int numOfParticles) {
	int scale = this->lineOfSurface.size() / numOfParticles;
	vector<particle> particles;
	srand(time(0));

	for(int i = 0 ; i < numOfParticles; i++) {
		particles.push_back(particle(point(this->lineOfSurface[rand() % this->lineOfSurface.size()])));
	}
	return particles;
}
