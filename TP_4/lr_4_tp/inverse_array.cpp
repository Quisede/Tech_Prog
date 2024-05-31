#include "inverse_array.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <string>
#include <type_traits>
using namespace std;


//�����������
template<typename T>
Array<T>::Array(size_t size) {
	this->size = size;
	array = new T[size];
}

//����������
template<typename T>
Array<T>::~Array() {
	delete[] array;
}

//������� ���������� ���������� ���������� (��������)
template<typename T>
void Array<T>::fill_random() {
	mt19937 gen(time(NULL));

	if (sizeof(array) == sizeof(int)) {
		uniform_int_distribution<> uid(0, 30);
		for (int i = 0; i < size; i++)
			array[i] = uid(gen);
	}
	else if (sizeof(array) == sizeof(double)) {
		uniform_real_distribution<>urd(0., 30.);
		for (int i = 0; i < size; i++)
			array[i] = urd(gen);
	}
	else if (sizeof(T) == sizeof(float)) {
		uniform_real_distribution<float> urd(0.f, 30.f);
		for (int i = 0; i < size; i++)
			array[i] = urd(gen);
	}
	else if (std::is_same<T, char>::value) {
		uniform_int_distribution<> uid('a', 'z'); // �������� ASCII ����� ��� ��������� ���� ����������� ��������

		for (int i = 0; i < size; i++)
			array[i] = uid(gen);
	}
}

template<typename T>
void Array<T>::fill_random_letter_1() {
	const char* ar[] = { "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�",
		"�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�" };

	for (int i = 0; i < size; i++) {
		std::string letter = ar[rand() % 33]; // �������� ��������� ����� �� �������
		array[i] = static_cast<T>(letter[0]); // ����������� ������ � ������ ���� T � ����������� �������� �������
	}
}

template<typename T>
void Array<T>::fill_random_letter_2() {
	const char* ar[] = {
		"hello",
		"world",
		"!!!!!"
	};

	srand(time(nullptr));

	for (int i = 0; i < size; i++) {
		array[i] = ar[rand() % 3]; // �������� ��������� ������ �� ������� ar
	}
}

//������� ������
template<typename T>
void Array<T>::invert_arr(){
	for (int i = 0; i < size / 2; i++) {
		T tmp = array[i];
		array[i] = array[size - i - 1];
		array[size - i - 1] = tmp;
	}
}

template<typename T>
void Array<T>::print_array() {
	for (int i = 0; i < size; i++)
		cout << array[i] << ",";
}
