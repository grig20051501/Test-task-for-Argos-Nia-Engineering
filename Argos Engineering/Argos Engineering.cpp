#include <iostream>
#include "particle.h"
#include "point.h"
#include "surface.h"
#include "engine.h"

using namespace std;

void printOptions() {
	cout << "Type 'surface' if you would like to spawn a surface, which particles stick to" << endl;
	cout << "Type 'particles' if ypu would like to spawn particles from spawning surface" << endl;
	cout << "Type 'move' if you would like to move particles" << endl;
	cout << "Type 'path' if you would like to enable\/disable printing path of every particle" << endl;
	cout << "Type 'calculate' if you would like to calculate average path of particles and end session" << endl;
}


int main()
{
	engine eng;
	bool doShowPath = false;
	int time = 0;
	int t = 0;
	double x1, x2, y1, y2;
	cout << "This programs works in 2 dimensions" << endl;
	cout << "Enter ccordinates of first and last points surface, which spawns particles in format x1, y1, x2, y2" << endl;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << "Enter scale of simulation (1 is recommeded)" << endl;
	double scale;
	cin >> scale;

	while (true) {
		
		eng.spawnSurface(point(x1, y1), point(x2, y2), scale, true);
		printOptions();

		string command;
		cin >> command;

		if (command == "surface") {
			cout << "Enter ccordinates of first and last points surface, which DOES NOT spawn particles in format x1, y1, x2, y2" << endl;
			cin >> x1 >> y1 >> x2 >> y2;
			eng.spawnSurface(point(x1, y1), point(x2, y2), 1);
			cout << "Succesful" << endl;
		}
		else if (command == "particles") {
			cout << "Enter number of particles to spawn" << endl;
			int num;
			cin >> num;
			cout << "Enter particles velocities by axis in format vx, vy (type -1 if random)" << endl;
			double vx, vy;
			cin >> vx;
			if (vx != -1) {
				cin >> vy;
				eng.spawnParticles(num, vx, vy);
			}
			else {
				eng.spawnParticles(num);
			}
			cout << "Succesful" << endl;
		}
		else if (command == "move") {
			cout << "Enter time of movement (number of points in trajectory of particles)" << endl;
			cin >> t;
			eng.moveParticles(t);
			if (doShowPath) {
				eng.printPathOfParticles();
			}
			time += t;
			cout << "Succesful" << endl;
		}
		else if (command == "path") {
			doShowPath = !doShowPath;
			cout << "Succesful" << endl;
		}
		else if (command == "calculate") {
			if (time != 0) {
				eng.calculate(time);
				return 0;
			}
			else { cout << "Nothing to calculate" << endl; }
		}
		else { cout << "Unknown command" << endl; }
	}
}