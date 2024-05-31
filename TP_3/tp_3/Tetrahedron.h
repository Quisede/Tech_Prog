#pragma once
#include "Figure.h"

class Tetrahedron : public Figure {
private:
	double a;//сторона а
public:
	Tetrahedron();//конструктор без парамтеров
	Tetrahedron(double side);//конструктор с параметрами
	Tetrahedron(const Tetrahedron& copy);//конструктор копирования
	~Tetrahedron();//деструктор
	double SurfaceArea();
};