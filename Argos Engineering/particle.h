#pragma once
#include"point.h"
#include<vector>
#include<iostream>

using namespace std;

class particle
{
    //�������� �������: ���������� ��������, �������� ��������� �� ����, ������ ������������ � ������������

private:
    vector<point> path;
    bool collisionStatus;
	double xVelocity;
	double yVelocity;

public:

    //����������� �������. �� ��������� ���������, ��� ������� �� ������������ � ������������. start - ��������� ����� � ���������� ��������
	//xVelocity, yVelocity - �������� �������� ������� �� ���� ��������������
    particle(point start, double xVelocity, double yVelocity, bool collisionStatus = false);

    //��������� ���������� �������� ������� ��� ���������� ���������
    vector<point> getPath();

    //��������� ������� ������������ ��� ���������� ���������
    bool hasCollided();

    //���������� ����� ���������� �������
    void addPoint(point p);

    //���������� ������������ ������� � ������������ � ����� p. ���� ������������ ����������� �����, ��������� ��������� �� ����
    void addCollision(point p);

    //����� ������� ������� �� �����
    void printStatus();

	//��������� �������� �������� ������� �� ��� x
	void changeXVelocity(double newXVelocity);

	//��������� �������� �������� ������� �� ��� y
	void changeYVelocity(double newYVelocity);

    //��������� �������� �������� ������� �� ��� x
    double getXVelocity();

    //��������� �������� �������� ������� �� ��� y
    double getYVelocity();
};

