#pragma once
#include "point.h"
#include "particle.h"
#include <vector>

//Поверхность из условия, фактически - отрезок прямой. Может создавать новые частицы
class surface {
private:

	//Свойства прямой: масштаб ( расстояние между точками отрезка по оси x ), массив всех точек отрезка, возможность создавать новые частицы
	double scale;
	vector<point> lineOfSurface;
	bool doesSpawnParticles;

public:

	//Конструктор поверхности. Принимает первую точку отрезка, последнюю точку отрезка, расстояние между точками и возможность создавать частицы
	//Внутри высчитывается массив точек отрезка 
	surface(point firstPoint, point lastPoint, double scale, bool doesSpawnParticles = false);

	//Создание заданного количества частиц ( если возможно ) в случайных точках поверхности с заданными скоростями движения по осям ( по умолчанию случайными )
	vector<particle> spawnParticles(int numOfParticles, double xVelocity = -1, double yVelocity = -1);

	//Вывод массива точек отрезка
	void printLine();


};