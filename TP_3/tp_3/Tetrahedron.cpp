#include <math.h>
#include <iostream>
#include "Figure.h"
#include "Tetrahedron.h"
using namespace std;

//����������� ��� ����������
Tetrahedron::Tetrahedron() : a(0) {}
Tetrahedron::Tetrahedron(double side) : a(side) {}
Tetrahedron::Tetrahedron(const Tetrahedron& copy) : a(copy.a) {}
Tetrahedron::~Tetrahedron() { cout << "������� ������ ����������� ���������\n"; }
double Tetrahedron::SurfaceArea() {
	double square = 0;
	square = a * a * sqrt(3);
	return square;
}