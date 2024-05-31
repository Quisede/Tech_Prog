#include <math.h>
#include <iostream>
#include "Figure.h"
#include "Tetrahedron.h"
using namespace std;

//конструктор без параметров
Tetrahedron::Tetrahedron() : a(0) {}
Tetrahedron::Tetrahedron(double side) : a(side) {}
Tetrahedron::Tetrahedron(const Tetrahedron& copy) : a(copy.a) {}
Tetrahedron::~Tetrahedron() { cout << "Очистка памяти произведена корректно\n"; }
double Tetrahedron::SurfaceArea() {
	double square = 0;
	square = a * a * sqrt(3);
	return square;
}