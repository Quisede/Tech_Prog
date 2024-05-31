#pragma once
#include "Figure.h"

class Parallelepiped : public Figure {
private:
	double a;//сторона а
	double b;//сторона b
	double c;//сторона c
public:
	Parallelepiped();//конструктор без парамтеров
	Parallelepiped(double length, double width, double height);//конструктор с параметрами
	Parallelepiped(const Parallelepiped& copy); //конструктор копирования
	~Parallelepiped(); //деструктор
	double SurfaceArea();
};
