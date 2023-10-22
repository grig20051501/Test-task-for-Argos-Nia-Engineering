#include <iostream>
#include "particle.h"
#include "point.h"
#include "surface.h"

using namespace std;

int main()
{
	surface sur(point(0, 0), point(10, 10), 1, true);
	sur.printLine();

	vector<particle> spawnedParticles = sur.spawnParticles(20);

	for (particle part : spawnedParticles) {
		part.printStatus();
	}

	/*particle part(point(0, 0), 1, 2, true);
	for (int i = 0; i < 10; i++) {
		part.move();
	}
	vector<point> path = part.getPath();
	for (point p : path) {
		cout << p.getXCoordinate() << " " << p.getYCoordinate() << endl;
	}*/
}