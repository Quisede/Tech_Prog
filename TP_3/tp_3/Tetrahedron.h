#pragma once
#include "Figure.h"

class Tetrahedron : public Figure {
private:
	double a;//������� �
public:
	Tetrahedron();//����������� ��� ����������
	Tetrahedron(double side);//����������� � �����������
	Tetrahedron(const Tetrahedron& copy);//����������� �����������
	~Tetrahedron();//����������
	double SurfaceArea();
};