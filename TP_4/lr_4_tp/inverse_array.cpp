#include "inverse_array.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <string>
#include <type_traits>
using namespace std;


//конструктор
template<typename T>
Array<T>::Array(size_t size) {
	this->size = size;
	array = new T[size];
}

//деструктор
template<typename T>
Array<T>::~Array() {
	delete[] array;
}

//функция заполнения рандомными значениями (числовые)
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
		uniform_int_distribution<> uid('a', 'z'); // Диапазон ASCII кодов для маленьких букв английского алфавита

		for (int i = 0; i < size; i++)
			array[i] = uid(gen);
	}
}

template<typename T>
void Array<T>::fill_random_letter_1() {
	const char* ar[] = { "а", "б", "в", "г", "д", "е", "ё", "ж", "з", "и", "й", "к", "л", "м", "н", "о", "п", "р", "с",
		"т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ъ", "ы", "ь", "э", "ю", "я" };

	for (int i = 0; i < size; i++) {
		std::string letter = ar[rand() % 33]; // Получаем случайную букву из массива
		array[i] = static_cast<T>(letter[0]); // Преобразуем строку в символ типа T и присваиваем элементу массива
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
		array[i] = ar[rand() % 3]; // Выбираем случайную строку из массива ar
	}
}

//фукнция шаблон
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
