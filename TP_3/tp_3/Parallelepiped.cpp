#include <iostream>
#include "Figure.h"
#include "Parallelepiped.h"
using namespace std;
Parallelepiped::Parallelepiped() : a(0), b(0), c(0) {}//конструктор без параметров
Parallelepiped::Parallelepiped(double length, double width, double height) : a(length), b(width), c(height) {}//конструктор с параметрами
Parallelepiped::Parallelepiped(const Parallelepiped& copy) : a(copy.a), b(copy.b), c(copy.c) {}//конструктор копирования
Parallelepiped::~Parallelepiped() { cout << "Очистка памяти произведена корректно\n"; }//деструктор

double Parallelepiped::SurfaceArea() {
	double square = 0;//площадь
	square = 2 * (a * c + c * b + a * b);//вычисление площади
	return square;//передача результата
}