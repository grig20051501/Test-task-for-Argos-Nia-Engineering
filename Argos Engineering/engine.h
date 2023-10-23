#pragma once
#include "point.h"
#include "particle.h"
#include "surface.h"
#include <vector>

class engine {
private:

	vector<particle> particles;
	vector<surface> surfaces;

public:

	//—лужебный метод обращени€ к единственной генерирующей поверхности
	surface findSpawningSurface();

	//—оздание материальной поверхности по двум точкам, заданным масштабом ( по умолчанию 1) и возможностью генерации новых частиц
	void spawnSurface(point firstPoint, point lastPoint, double scale = 1, bool doesSpawnParticles = false);

	//—оздание заданного числа частиц с заданными скорост€ми по ос€м ( по умолчанию случайными ) с генерирующей поверхности
	//√енерирующа€ поверхность существует в единственном виде
	void spawnParticles(int numOfParticles, double xVelocity = -1, double yVelocity = -1);

	//ƒвижение всех существующих частиц в течение времени t
	void moveParticles(int time);

	//¬ычсисление средней траектории движени€ частиц в теченние времени t
	void calculate(int time);

	//“естовый метод дл€ вывода траектории движени€ каждой частицы
	void printPathOfParticles();

	//ѕоиск ближайшей точки в массиве points к координатам x, y
	point findClosestPoint(double x, double y, vector<point> points);
};