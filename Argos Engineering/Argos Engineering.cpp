#include <iostream>
#include "particle.h"
#include "point.h"
#include "surface.h"
#include "engine.h"

using namespace std;

int main()
{
	point first(0, 0);
	point last(10, 10);

	engine eng;
	eng.spawnSurface(first, last, 1, true);
	eng.spawnParticles(100);
	eng.moveParticles(7);
	eng.printPathOfParticles();
	eng.calculate(7);
}