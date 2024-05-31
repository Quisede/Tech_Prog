#include <math.h>
#include <iostream>
#include "Figure.h"
#include "Ball.h"
using namespace std;

Ball::Ball() : radius(0) {} //конструктор без параметров
Ball::Ball(double r) : radius(r) {} //конструктор c параметрами
Ball::Ball(const Ball& copy) : radius(copy.radius) {}  //конструктор копирования
Ball::~Ball() { cout << "Очистка памяти произведена корректно\n"; }; //десруктор

double Ball::SurfaceArea() {
	double square = 0;//площадь
	square = 4 * 3.14 * radius * radius;//вычисление площади
	return square;//передаем результат
}