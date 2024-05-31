#pragma once
#include "Figure.h"

class Ball : public Figure {
private:
	double radius;//������
public:
	Ball();//����������� ��� ����������
	Ball(double r);//����������� � �����������
	Ball(const Ball& copy);//����������� �����������
	~Ball();//����������
	double SurfaceArea();
};