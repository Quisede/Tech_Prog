#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Figure.h"
#include "Parallelepiped.h"
#include "Tetrahedron.h"
#include "Ball.h"
using namespace std;

//прототипы функций
void save_in_file(const string& filename, Figure* arr[], const int count_figure);
void show_result(const string& filename);
void load_from_file(const string& filename, Figure* arr[], int count_figure);

int main(){
	setlocale(LC_ALL, "rus");

	Figure* arr[10]; //массив ссылок на абстрактный класс
	int count_figure = 0; //счетчик фигур

	//переменные для диалога с пользователем
	int choice_1;
	double a;
	double b;
	double c;
	string filename;

	//взаимодействие с пользователем (меню)
	do {
		cout << "МЕНЮ\n\n1)Введите данные параллелепипеда\n2)Введите данные тетраэдра\n3)Введите данные шара\n4)Сохранить данные в файл\n5)Чтение результатов из файла\n6)Выгрузить данные из файла\n7)Завершить программу\n";
		cin >> choice_1;
		system("cls");
		switch (choice_1) {
		case 1: {
			cout << "Введите длину\n";
			cin >> a;
			cout << "Введите ширину\n";
			cin >> b;
			cout << "Введите высоту\n";
			cin >> c;
			arr[count_figure] = new Parallelepiped(a, b, c);
			cout << "Результат\n" << arr[count_figure]->SurfaceArea() << endl;
			count_figure++;
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			cout << "Введите длину\n";
			cin >> a;
			arr[count_figure] = new Tetrahedron(a);
			cout << "Результат\n" << arr[count_figure]->SurfaceArea() << endl;
			count_figure++;
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			cout << "Введите радиус\n";
			cin >> a;
			arr[count_figure] = new Ball(a);
			cout << "Результат\n" << arr[count_figure]->SurfaceArea() << endl;
			count_figure++;
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			cout << "Введите имя файла для сохранения\n";
			cin >> filename;
			save_in_file(filename, arr, count_figure);
			system("pause");
			system("cls");
			break;
		}
		case 5: {
			cout << "Введите имя файла для чтения\n";
			cin >> filename;
			show_result(filename);
			system("pause");
			system("cls");
			break;
		}
		case 6: {
			cout << "Введите имя файла\n";
			cin >> filename;
			system("cls");
			load_from_file(filename, arr, count_figure);
			system("pause");
			system("cls");
			break;
		}
		case 7: {
			for (int i = 0; i < count_figure; i++) {
				delete arr[i];

				return 0;
			}
		}
		default:
			cout << "Некорректная операция. Попробуйте снова\n";
		}
	} while (choice_1 != 7);
	
}

//функция для сохранения данных в файл
void save_in_file(const string& filename, Figure* arr[], const int count_figure) {
	ofstream file(filename);
	if (file.is_open()) {
		for (int i = 0; i < count_figure; i++) {
			file << arr[i]->SurfaceArea() << endl;
		}
		file.close();
		cout << "Данные успешно сохранены\n";
	}
	else {
		cout << "Ошибка при сохранении\n";
	}
}
//функция чтения сохраненных данных из файла
void show_result(const string& filename) {
	ifstream file(filename);
	double res;
	if (file.is_open()) {
		cout << "Сохраненные результаты вычислений:\n";
		while (file >> res) {
			cout << res << endl;
		}
		file.close();
	}
	else {
		cout << "Ошибка при чтении файла\n";
	}
}
//построить фигуру по данным из файла
void load_from_file(const string& filename, Figure* arr[], int count_figure) {
	int count = 1;
	ifstream file(filename);
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			istringstream iss(line);//разделяем строку по пробелам
			string FigureType;
			iss >> FigureType;
			cout << count++ << ":";
			cout << FigureType << endl;
			if (FigureType == "Parallelepiped") {
				double a, b, c;
				iss >> a >> b >> c;
				cout << "Стороны:" << a << b << c << endl;
				arr[count_figure] = new Parallelepiped(a, b, c);
				cout << "Площадь:" << arr[count_figure]->SurfaceArea() << endl;
				count_figure++;
				cout << "\n\n";
			}
			else if (FigureType == "Tetrahedron") {
				double a;
				iss >> a;
				cout << "Стороны:" << a << endl;
				arr[count_figure] = new Tetrahedron(a);
				cout << "Площадь:" << arr[count_figure]->SurfaceArea() << endl;
				count_figure++;
				cout << "\n\n";
			}
			else if (FigureType == "Ball") {
				double r;
				iss >> r;
				cout << "Радиус:" << r << endl;
				arr[count_figure] = new Ball(r);
				cout << "Площадь:" << arr[count_figure]->SurfaceArea() << endl;
				count_figure++;
				cout << "\n\n";
			}
			else {
				cout << "Ошибка при считывании типа\n";
				system("pause");
			}
		}
		file.close();
		cout << "Данные успешно загружены\n";
	}
	else {
		cout << "ОШИБКА ПРИ ОТКРЫТИИ ФАЙЛА\n";
	}
}
