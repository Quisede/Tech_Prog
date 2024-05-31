#pragma once
template<typename T>

class Array {
private:
	T* array; //массив с элементами определенного типа
	size_t size; //размерность массива
public:
	Array(size_t size); //конструктор
	~Array();//деструктор
	void fill_random();
	void fill_random_letter_1();
	void fill_random_letter_2();
	void invert_arr();//функция-шаблон
	void print_array();
};
