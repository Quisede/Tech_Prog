#include <math.h>
#include <iostream>
#include "Figure.h"
#include "Ball.h"
using namespace std;

Ball::Ball() : radius(0) {} //����������� ��� ����������
Ball::Ball(double r) : radius(r) {} //����������� c �����������
Ball::Ball(const Ball& copy) : radius(copy.radius) {}  //����������� �����������
Ball::~Ball() { cout << "������� ������ ����������� ���������\n"; }; //���������

double Ball::SurfaceArea() {
	double square = 0;//�������
	square = 4 * 3.14 * radius * radius;//���������� �������
	return square;//�������� ���������
}