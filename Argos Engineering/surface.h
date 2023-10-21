#pragma once
#include "point.h"
#include "particle.h"
#include <vector>

class surface {
private:
	double scale;
	vector<point> lineOfSurface;
	bool doesSpawnParticles;

public:

	surface(point firstPoint, point lastPoint, double scale, bool doesSpawnParticles = false);
	vector<particle> spawnParticles(int numOfParticles);

	void printLine();


};