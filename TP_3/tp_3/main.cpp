#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Figure.h"
#include "Parallelepiped.h"
#include "Tetrahedron.h"
#include "Ball.h"
using namespace std;

//��������� �������
void save_in_file(const string& filename, Figure* arr[], const int count_figure);
void show_result(const string& filename);
void load_from_file(const string& filename, Figure* arr[], int count_figure);

int main(){
	setlocale(LC_ALL, "rus");

	Figure* arr[10]; //������ ������ �� ����������� �����
	int count_figure = 0; //������� �����

	//���������� ��� ������� � �������������
	int choice_1;
	double a;
	double b;
	double c;
	string filename;

	//�������������� � ������������� (����)
	do {
		cout << "����\n\n1)������� ������ ���������������\n2)������� ������ ���������\n3)������� ������ ����\n4)��������� ������ � ����\n5)������ ����������� �� �����\n6)��������� ������ �� �����\n7)��������� ���������\n";
		cin >> choice_1;
		system("cls");
		switch (choice_1) {
		case 1: {
			cout << "������� �����\n";
			cin >> a;
			cout << "������� ������\n";
			cin >> b;
			cout << "������� ������\n";
			cin >> c;
			arr[count_figure] = new Parallelepiped(a, b, c);
			cout << "���������\n" << arr[count_figure]->SurfaceArea() << endl;
			count_figure++;
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			cout << "������� �����\n";
			cin >> a;
			arr[count_figure] = new Tetrahedron(a);
			cout << "���������\n" << arr[count_figure]->SurfaceArea() << endl;
			count_figure++;
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			cout << "������� ������\n";
			cin >> a;
			arr[count_figure] = new Ball(a);
			cout << "���������\n" << arr[count_figure]->SurfaceArea() << endl;
			count_figure++;
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			cout << "������� ��� ����� ��� ����������\n";
			cin >> filename;
			save_in_file(filename, arr, count_figure);
			system("pause");
			system("cls");
			break;
		}
		case 5: {
			cout << "������� ��� ����� ��� ������\n";
			cin >> filename;
			show_result(filename);
			system("pause");
			system("cls");
			break;
		}
		case 6: {
			cout << "������� ��� �����\n";
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
			cout << "������������ ��������. ���������� �����\n";
		}
	} while (choice_1 != 7);
	
}

//������� ��� ���������� ������ � ����
void save_in_file(const string& filename, Figure* arr[], const int count_figure) {
	ofstream file(filename);
	if (file.is_open()) {
		for (int i = 0; i < count_figure; i++) {
			file << arr[i]->SurfaceArea() << endl;
		}
		file.close();
		cout << "������ ������� ���������\n";
	}
	else {
		cout << "������ ��� ����������\n";
	}
}
//������� ������ ����������� ������ �� �����
void show_result(const string& filename) {
	ifstream file(filename);
	double res;
	if (file.is_open()) {
		cout << "����������� ���������� ����������:\n";
		while (file >> res) {
			cout << res << endl;
		}
		file.close();
	}
	else {
		cout << "������ ��� ������ �����\n";
	}
}
//��������� ������ �� ������ �� �����
void load_from_file(const string& filename, Figure* arr[], int count_figure) {
	int count = 1;
	ifstream file(filename);
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			istringstream iss(line);//��������� ������ �� ��������
			string FigureType;
			iss >> FigureType;
			cout << count++ << ":";
			cout << FigureType << endl;
			if (FigureType == "Parallelepiped") {
				double a, b, c;
				iss >> a >> b >> c;
				cout << "�������:" << a << b << c << endl;
				arr[count_figure] = new Parallelepiped(a, b, c);
				cout << "�������:" << arr[count_figure]->SurfaceArea() << endl;
				count_figure++;
				cout << "\n\n";
			}
			else if (FigureType == "Tetrahedron") {
				double a;
				iss >> a;
				cout << "�������:" << a << endl;
				arr[count_figure] = new Tetrahedron(a);
				cout << "�������:" << arr[count_figure]->SurfaceArea() << endl;
				count_figure++;
				cout << "\n\n";
			}
			else if (FigureType == "Ball") {
				double r;
				iss >> r;
				cout << "������:" << r << endl;
				arr[count_figure] = new Ball(r);
				cout << "�������:" << arr[count_figure]->SurfaceArea() << endl;
				count_figure++;
				cout << "\n\n";
			}
			else {
				cout << "������ ��� ���������� ����\n";
				system("pause");
			}
		}
		file.close();
		cout << "������ ������� ���������\n";
	}
	else {
		cout << "������ ��� �������� �����\n";
	}
}
