#pragma once
#include "point.h"
#include "particle.h"
#include "surface.h"
#include <vector>

class engine {
private:

	vector<particle> particles;
	vector<surface> surfaces;

	//��������� �����, �����������, ������������ �� ������, �������� ����� �������
	bool areLinesIntersecting(point p1, point p2, point p3, point p4);

public:

	//��������� ����� ��������� � ������������ ������������ �����������
	surface findSpawningSurface();

	//�������� ������������ ����������� �� ���� ������, �������� ��������� ( �� ��������� 1) � ������������ ��������� ����� ������
	void spawnSurface(point firstPoint, point lastPoint, double scale = 1, bool doesSpawnParticles = false);

	//�������� ��������� ����� ������ � ��������� ���������� �� ���� ( �� ��������� ���������� ) � ������������ �����������
	//������������ ����������� ���������� � ������������ ����
	void spawnParticles(int numOfParticles, double xVelocity = -1, double yVelocity = -1);

	//�������� ���� ������������ ������ � ������� ������� t
	void moveParticles(int time);

	//����������� ������� ���������� �������� ������ � �������� ������� t
	void calculate(int time);

	//�������� ����� ��� ������ ���������� �������� ������ �������
	void printPathOfParticles();

	//����� ��������� ����� � ������� points � ����������� x, y
	point findClosestPoint(double x, double y, vector<point> points);

	
};