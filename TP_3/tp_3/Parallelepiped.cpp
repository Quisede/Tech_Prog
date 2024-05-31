#include <iostream>
#include "Figure.h"
#include "Parallelepiped.h"
using namespace std;
Parallelepiped::Parallelepiped() : a(0), b(0), c(0) {}//����������� ��� ����������
Parallelepiped::Parallelepiped(double length, double width, double height) : a(length), b(width), c(height) {}//����������� � �����������
Parallelepiped::Parallelepiped(const Parallelepiped& copy) : a(copy.a), b(copy.b), c(copy.c) {}//����������� �����������
Parallelepiped::~Parallelepiped() { cout << "������� ������ ����������� ���������\n"; }//����������

double Parallelepiped::SurfaceArea() {
	double square = 0;//�������
	square = 2 * (a * c + c * b + a * b);//���������� �������
	return square;//�������� ����������
}