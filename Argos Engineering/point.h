#pragma once

//����� � ���������. ��������������� ����� ������������
class point {
private:
	double xCoordinate;
	double yCoordinate;
public:

	//����������� �����. ��������� ��� ���������� - x � y
	point(double x, double y);

	point();

	//��������� ���������� ����� �� ��� x
	double getXCoordinate();

	//��������� ���������� ����� �� ��� y
	double getYCoordinate();

	//��������� ���������� ����� �� ��� x
	void changeXCoordinate(double newX);

	//��������� ���������� ����� �� ��� y
	void changeYCoordinate(double newY);
};