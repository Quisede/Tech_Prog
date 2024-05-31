#pragma once
#include "stack_node.h"

template <class T>

class Stack {
private:
	Node<T>* top;//вершина стека
	size_t stack_size;//вводит пользозватель
public:
	Stack(int size_of_stack);//конструктор
	~Stack();//деструктор

	//методы
	void fill_random();
	//void fill_random_char_2();
	void delete_top();
	void print_stack();
	void invert_stack();

	//перегрузки
	Stack& operator=(Stack<T>& copy_stack);//оператор присваивания двух стектов друг другу
	Stack& operator+(Stack<T>& other_stack);//оператор сложения
	Stack& operator-(Stack<T>& other_stack);//опеатор вычитания
	bool operator==(Stack<T>& other_stack);//опеатор вычитания
};