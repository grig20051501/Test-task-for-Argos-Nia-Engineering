#pragma once
#include "point.h"
#include "particle.h"
#include <vector>

//ѕоверхность из услови€, фактически - отрезок пр€мой. ћожет создавать новые частицы
class surface {
private:

	//—войства пр€мой: масштаб ( рассто€ние между точками отрезка по оси x ), массив всех точек отрезка, возможность создавать новые частицы
	double scale;
	vector<point> lineOfSurface;
	bool doesSpawnParticles;

public:

	// онструктор поверхности. ѕринимает первую точку отрезка, последнюю точку отрезка, рассто€ние между точками и возможность создавать частицы
	//¬нутри высчитываетс€ массив точек отрезка 
	surface(point firstPoint, point lastPoint, double scale, bool doesSpawnParticles = false);

	//—оздание заданного количества частиц ( если возможно ) в случайных точках поверхности
	vector<particle> spawnParticles(int numOfParticles);

	//¬ывод массива точек отрезка
	void printLine();


};