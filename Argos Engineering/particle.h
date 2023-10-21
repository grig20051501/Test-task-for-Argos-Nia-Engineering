#pragma once
#include"point.h"
#include<vector>
#include<iostream>

using namespace std;

class particle
{
    //�������� �������: ���������� �� ��� x, ���������� �� ��� y , ������ ������������ � ������������

private:
    vector<point> coordinates;
    bool collisionStatus;

public:

    //����������� �������. �� ��������� ���������, ��� ������� �� ������������ � ������������. start - ��������� ����� � ���������� ��������
    particle(point start, bool collisionStatus = false);

    //��������� ���������� �������� ������� ��� ���������� ���������
    vector<point> getTrajectory();

    //��������� ������� ������������ ��� ���������� ���������
    bool hasCollided();

    //���������� ����� ���������� �������
    void addPoint(point p);

    //���������� ������������ ������� � ������������ � ����� p. ���� ������������ ����������� �����, ��������� ��������� �� ����
    void addCollision(point p);

    //����� ������� ������� �� �����
    void printStatus();
};

