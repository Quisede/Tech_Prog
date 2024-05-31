#include "stack.h"
#include "stack_node.h"
#include "stack_node.cpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <type_traits>
#include <stdexcept>
using namespace std;

//�����������
template <typename T>
Stack<T>::Stack(int size_of_stack) {
	top = nullptr;
	stack_size = size_of_stack;
}

//���������� ���������� ����������
template <typename T>
void Stack<T>::fill_random() {
	mt19937 gen(time(NULL));
	T random_value;
	char* random_string;
	for (int i = 0; i < stack_size; i++) {
		if (std::is_same<T, int>::value) {
			uniform_int_distribution<int> uid(0, 100);
			random_value = uid(gen);
		}
		else if (std::is_same<T, double>::value) {
			uniform_real_distribution<double> urd(0., 30.);
			random_value = urd(gen);
		}
		else if (std::is_same<T, float>::value) {
			uniform_real_distribution<float> urd(0.f, 30.f);
			random_value = urd(gen);
		}
		else if (std::is_same<T, char>::value) {
			 random_value = 'A' + rand() % 26;
		}
		else if (std::is_same<T, string>::value) {
			char* temp = new char[6];
			for (int j = 0; j < 5; ++j) {
				temp[j] = 'A' + rand() % 26;
			}
			temp[5] = '\0';
			random_string = temp;
		}
		Node<T>* NewNode = new Node<T>(random_value);
		NewNode->next = top;
		top = NewNode;
		cout << " " << NewNode->data;
	}
	cout << endl;
}

//�������� ������� �����
template <typename T>
void Stack<T>::delete_top() {
	if (top == nullptr)
		throw std::runtime_error("������! ���� ������");
	//cout << tmp->data;
	top = top->next;
	stack_size--;
	//cout << "������ ������� �����\n";
	//cout << tmp_value -> data; //���������� ��������� ��������
}

//����������
template <typename T>
Stack<T>::~Stack() {
	cout << "������ ����������\n";
	while (top != nullptr) {
		delete_top();
	}
}

//������ �����
template <typename T>
void Stack<T>::print_stack() {
	Node<T>* current = top; // �������� � ������� �����

	cout << "����: ";

	// �������� �� ���� ��������� �����
	while (current != nullptr) {
		cout << current->data << " "; // ������� �������� ��������
		current = current->next; // ��������� � ���������� ��������
	}

	cout << endl;
}

//������������� �������� =
template <typename T>
Stack<T>& Stack<T>::operator=(Stack<T>& copy_stack) {
	if (this != &copy_stack) {
		// ������� ������� ����
		while (top != nullptr) {
			delete_top();
		}

		// ������� ��������� ���� ��� �����������
		Stack<T> temp_stack(0);

		// �������� �������� �� ����� copy_stack �� ��������� ���� � �������� �������
		Node<T>* copy_node = copy_stack.top;
		while (copy_node != nullptr) {
			Node<T>* new_node = new Node<T>(copy_node->data);
			new_node->next = top;
			top = new_node;
			copy_node = copy_node->next;
		}

		stack_size = copy_stack.stack_size;
	}
	return *this;
}

//������������� �������� +
template <typename T>
Stack<T>& Stack<T>::operator+(Stack<T>& other_stack) {
	if (this != &other_stack) {
		Node<T>* current = top;
		Node<T>* other = other_stack.top;
		while (current != nullptr && other != nullptr) {
			current->data += other->data;
			current = current->next;
			other = other->next;
		}
	}
	return *this;
}


//������������� �������� -
template <typename T>
Stack<T>& Stack<T>::operator-(Stack<T>& other_stack) {
	if (this != &other_stack) {
		Node<T>* current = top;
		Node<T>* other = other_stack.top;
		while (current != nullptr && other != nullptr) {
			current->data -= other->data;
			current = current->next;
			other = other->next;
		}
	}
	return *this;
}

//������������� �������� ==
template <typename T>
bool Stack<T>::operator==(Stack<T>& other_stack) {
	if (this != &other_stack) {
		if (stack_size != other_stack.stack_size) {
			cout << "����� �� �����\n";
			return false;
		}
		else {
			Node<T>* current = top;
			Node<T>* other = other_stack.top;
			while (current != nullptr && other != nullptr) {
				if (current->data != other->data) {
					cout << "����� �� �����\n";
					return false;
				}
				current = current->next;
				other = other->next;
			}
			cout << "����� �����\n";
			return true;
		}
	}
	else {
		cout << "������\n";
		return false;
	}
}
template <typename T>
void Stack<T>::invert_stack() {
	if (top == nullptr || top->next == nullptr) {
		// ���� ���� ��� �������� ������ ���� �������, ������� ������������� �� �����
		return;
	}

	Node<T>* prev = nullptr;
	Node<T>* current = top;
	Node<T>* next = nullptr;

	// ���������� �������� �����, ����� ������ �� ��������� ��������
	while (current != nullptr) {
		next = current->next; // ��������� ������ �� ��������� �������
		current->next = prev; // ������ ������ �������� �������� �� ����������

		// ��������� � ��������� ��������, ���������� ���������� �������
		prev = current;
		current = next;
	}

	// ����� ������� ������� - ���� ��� �����
	top = prev;
}