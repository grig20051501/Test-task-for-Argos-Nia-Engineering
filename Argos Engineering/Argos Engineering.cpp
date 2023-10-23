#include <iostream>
#include "particle.h"
#include "point.h"
#include "surface.h"
#include "engine.h"

using namespace std;

int main()
{
	point first(0, 2);
	point last(6, 6);

	point a(4, 0);
	point b(4, 10);
	engine eng;	

	//cout << eng.areLinesIntersecting(first, last, a, b);

	eng.spawnSurface(point(0,0), point(0,5), 1, true);
	eng.spawnSurface(point(4, 0), point(4,10), 1, false);
	eng.spawnParticles(10);
	eng.moveParticles(5);
	eng.calculate(5);

	/*point a(4, 4), b(5, 3);
	cout << (a < b);*/
}