#include <iostream>
#include "particle.h"
#include "point.h"
#include "surface.h"
#include "engine.h"

using namespace std;

int main()
{
	point first(0, 0);
	point last(2, 2);

	engine eng;	
	eng.spawnSurface(first, last, 1, true);
	eng.spawnSurface(point(3, 0), point(8,5), 1, false);
	eng.spawnParticles(1);
	eng.moveParticles(3);
	eng.printPathOfParticles();
	eng.calculate(3);

	/*point a(4, 4), b(5, 3);
	cout << (a < b);*/
}