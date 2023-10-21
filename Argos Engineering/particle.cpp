#include "particle.h"
#include <iostream>
#include <vector>
using namespace std;
//����� "�������" ( ������� ��������������� � ��������� ������������ )
//�������� ������ ������ �������������� ������� �� ������, ����� ���������� ������ ���������� �������� � ����� ����
//���� ������������ ��� �������� ���������� ������
//partickle2 - �������, ������� ������ ��� ���������� ������ �������� �� ����. � ������ ������������ - ������������ ������������ ��������� ���������� ��������� ����� ����������



    //�������� �������: ���������� �� ��� x, ���������� �� ��� y , ������ ������������ � ������������



    //����������� �������. �� ��������� ���������, ��� ������� �� ������������ � ������������. x0, y0 - ��������� ����������
    particle::particle(int x0, int y0, bool collisionStatus) {
        this->xCoordinates.push_back(x0);
        this->yCoordinates.push_back(y0);
        this->collisionStatus = collisionStatus;
    }
    //��������� ���������� �������� ������� �� ��� x ��� ���������� ���������
    vector<int> particle::get_x_trajectory() {
        return this->xCoordinates;
    }
    //��������� ���������� �������� ������� �� ��� y ��� ���������� ���������
    vector<int> particle::get_y_Trajectory() {
        return this->yCoordinates;
    }
    //��������� ������� ������������ ��� ���������� ���������
    bool particle::hasCollided() {
        return this->collisionStatus;
    }
    //���������� ����� ���������� �������
    void particle::addPoint(int x, int y) {
        this->xCoordinates.push_back(x);
        this->yCoordinates.push_back(y);
    }
    //���������� ������������ ������� � ������������ � ����� � ������������ x � y. ���� ������������ ����������� �����, ��������� ��������� �� ����
    void particle::addCollision(int x, int y) {

        if (this->collisionStatus) {
            cout << "Adding collision error! Particle has already collided!" << endl;
        }
        else
        {
            this->xCoordinates.push_back(x);
            this->yCoordinates.push_back(y);
            this->collisionStatus = true;
        }
    }
    //����� ������� ������� �� �����
    void particle::printStatus() {
        if (collisionStatus) {
            cout << "partice has collided with surface in x = " << this->xCoordinates[this->xCoordinates.size() - 1] << " y = " << this->yCoordinates[yCoordinates.size() - 1] << endl;
        }
        else
        {
            cout << "particle last coordinates are x = " << this->xCoordinates[this->xCoordinates.size() - 1] << " and y = " << this->yCoordinates[yCoordinates.size() - 1] << endl;
        }
    }