#include "particle.h"
#include "point.h"
#include <iostream>
#include <vector>
using namespace std;
//����� "�������" ( ������� ��������������� � ��������� ������������ )
//�������� ������ ������ �������������� ������� �� ������, ����� ���������� ������ ���������� �������� � ����� ����
//���� ������������ ��� �������� ���������� ������
//partickle2 - �������, ������� ������ ��� ���������� ������ �������� �� ����. � ������ ������������ - ������������ ������������ ��������� ���������� ��������� ����� ����������



    //�������� �������: ���������� �� ��� x, ���������� �� ��� y , ������ ������������ � ������������



    //����������� �������. �� ��������� ���������, ��� ������� �� ������������ � ������������. x0, y0 - ��������� ����������
    particle::particle(point start, bool collisionStatus) {
        this->coordinates.push_back(start);
        this->collisionStatus = collisionStatus;
    }
    //��������� ���������� �������� ������� �� ��� x ��� ���������� ���������
    vector<point> particle::getTrajectory() {
        return this->coordinates;
    }
    //��������� ������� ������������ ��� ���������� ���������
    bool particle::hasCollided() {
        return this->collisionStatus;
    }
    //���������� ����� ���������� �������
    void particle::addPoint(point p) {
        this->coordinates.push_back(p);
    }
    //���������� ������������ ������� � ������������ � ����� � ������������ x � y. ���� ������������ ����������� �����, ��������� ��������� �� ����
    void particle::addCollision(point p) {

        if (this->collisionStatus) {
            cout << "Adding collision error! Particle has already collided!" << endl;
        }
        else
        {
            this->coordinates.push_back(p);
            this->collisionStatus = true;
        }
    }
    //����� ������� ������� �� �����
    void particle::printStatus() {
        if (collisionStatus) {
            cout << "partice has collided with surface in x = " << this->coordinates[this->coordinates.size() - 1].getXCoordinate() << " y = " << this->coordinates[coordinates.size() - 1].getYCoordinate() << endl;
        }
        else
        {
            cout << "particle last coordinates are x = " << this->coordinates[this->coordinates.size() - 1].getXCoordinate() << " and y = " << this->coordinates[coordinates.size() - 1].getYCoordinate() << endl;
        }
    }