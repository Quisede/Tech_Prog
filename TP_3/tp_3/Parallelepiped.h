#pragma once
#include "Figure.h"

class Parallelepiped : public Figure {
private:
	double a;//������� �
	double b;//������� b
	double c;//������� c
public:
	Parallelepiped();//����������� ��� ����������
	Parallelepiped(double length, double width, double height);//����������� � �����������
	Parallelepiped(const Parallelepiped& copy); //����������� �����������
	~Parallelepiped(); //����������
	double SurfaceArea();
};
