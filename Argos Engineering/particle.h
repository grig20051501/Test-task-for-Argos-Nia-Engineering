#pragma once
#include<vector>
#include<iostream>

using namespace std;

class particle
{
    //�������� �������: ���������� �� ��� x, ���������� �� ��� y , ������ ������������ � ������������

private:
    vector<int> xCoordinates;
    vector<int> yCoordinates;
    bool collisionStatus;

public:
    //����������� �������. �� ��������� ���������, ��� ������� �� ������������ � ������������. x0, y0 - ��������� ����������
    particle(int x0, int y0, bool collisionStatus = false);
    //��������� ���������� �������� ������� �� ��� x ��� ���������� ���������
    vector<int> get_x_trajectory();
    //��������� ���������� �������� ������� �� ��� y ��� ���������� ���������
    vector<int> get_y_Trajectory();
    //��������� ������� ������������ ��� ���������� ���������
    bool hasCollided();
    //���������� ����� ���������� �������
    void addPoint(int x, int y);
    //���������� ������������ ������� � ������������ � ����� � ������������ x � y. ���� ������������ ����������� �����, ��������� ��������� �� ����
    void addCollision(int x, int y);
    //����� ������� ������� �� �����
    void printStatus();
};

