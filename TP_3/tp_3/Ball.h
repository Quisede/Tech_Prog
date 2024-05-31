#pragma once
#include "Figure.h"

class Ball : public Figure {
private:
	double radius;//радиус
public:
	Ball();//конструктор без парамтеров
	Ball(double r);//конструктор с параметрами
	Ball(const Ball& copy);//конструктор копирования
	~Ball();//деструктор
	double SurfaceArea();
};