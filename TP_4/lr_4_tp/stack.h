#pragma once
#include "stack_node.h"

template <class T>

class Stack {
private:
	Node<T>* top;//������� �����
	size_t stack_size;//������ �������������
public:
	Stack(int size_of_stack);//�����������
	~Stack();//����������

	//������
	void fill_random();
	//void fill_random_char_2();
	void delete_top();
	void print_stack();
	void invert_stack();

	//����������
	Stack& operator=(Stack<T>& copy_stack);//�������� ������������ ���� ������� ���� �����
	Stack& operator+(Stack<T>& other_stack);//�������� ��������
	Stack& operator-(Stack<T>& other_stack);//������� ���������
	bool operator==(Stack<T>& other_stack);//������� ���������
};