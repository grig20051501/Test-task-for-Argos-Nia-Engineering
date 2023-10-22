#pragma once
#include "point.h"
#include "particle.h"
#include <vector>

//����������� �� �������, ���������� - ������� ������. ����� ��������� ����� �������
class surface {
private:

	//�������� ������: ������� ( ���������� ����� ������� ������� �� ��� x ), ������ ���� ����� �������, ����������� ��������� ����� �������
	double scale;
	vector<point> lineOfSurface;
	bool doesSpawnParticles;

public:

	//����������� �����������. ��������� ������ ����� �������, ��������� ����� �������, ���������� ����� ������� � ����������� ��������� �������
	//������ ������������� ������ ����� ������� 
	surface(point firstPoint, point lastPoint, double scale, bool doesSpawnParticles = false);

	//�������� ��������� ���������� ������ ( ���� �������� ) � ��������� ������ ����������� � ��������� ���������� �������� �� ���� ( �� ��������� ���������� )
	vector<particle> spawnParticles(int numOfParticles, double xVelocity = -1, double yVelocity = -1);

	//����� ������� ����� �������
	void printLine();


};