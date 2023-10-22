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
	surface(point firstPoint, point lastPoint, double scale, bool doesSpawnParticles);

	//�������� ��������� ���������� ������ ( ���� �������� ) � ��������� ������ ����������� � ��������� ���������� �������� �� ���� ( �� ��������� ���������� )
	vector<particle> spawnParticles(int numOfParticles, double xVelocity, double yVelocity);

	//����� ������� ����� �������
	void printLine();

	//��������� ����������� ����������� ��������� ����� �������
	bool canSpawn();


};