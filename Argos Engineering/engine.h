#pragma once
#include "point.h"
#include "particle.h"
#include "surface.h"
#include <vector>

class engine {
private:

	vector<particle> particles;
	vector<surface> surfaces;

	//Служебный метод, проверяющий, пересекаются ли прямые, заданные двумя точками
	bool areLinesIntersecting(point p1, point p2, point p3, point p4);

public:

	//Служебный метод обращения к единственной генерирующей поверхности
	surface findSpawningSurface();

	//Создание материальной поверхности по двум точкам, заданным масштабом ( по умолчанию 1) и возможностью генерации новых частиц
	void spawnSurface(point firstPoint, point lastPoint, double scale = 1, bool doesSpawnParticles = false);

	//Создание заданного числа частиц с заданными скоростями по осям ( по умолчанию случайными ) с генерирующей поверхности
	//Генерирующая поверхность существует в единственном виде
	void spawnParticles(int numOfParticles, double xVelocity = -1, double yVelocity = -1);

	//Движение всех существующих частиц в течение времени t
	void moveParticles(int time);

	//Вычсисление средней траектории движения частиц в теченние времени t
	void calculate(int time);

	//Тестовый метод для вывода траектории движения каждой частицы
	void printPathOfParticles();

	//Поиск ближайшей точки в массиве points к координатам x, y
	point findClosestPoint(double x, double y, vector<point> points);

	
};