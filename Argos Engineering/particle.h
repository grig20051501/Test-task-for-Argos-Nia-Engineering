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
    //����������� �������. �� ��������� ���������, ��� ������� �� ������������ � ������������. x0, y0 - ��������� ����������
    particle(point start, bool collisionStatus = false);
    //��������� ���������� �������� ������� �� ��� x ��� ���������� ���������
    vector<point> getTrajectory();
    //��������� ������� ������������ ��� ���������� ���������
    bool hasCollided();
    //���������� ����� ���������� �������
    void addPoint(point p);
    //���������� ������������ ������� � ������������ � ����� � ������������ x � y. ���� ������������ ����������� �����, ��������� ��������� �� ����
    void addCollision(point p);
    //����� ������� ������� �� �����
    void printStatus();
};

