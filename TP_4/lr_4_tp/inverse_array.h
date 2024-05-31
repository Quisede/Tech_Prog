#pragma once
template<typename T>

class Array {
private:
	T* array; //������ � ���������� ������������� ����
	size_t size; //����������� �������
public:
	Array(size_t size); //�����������
	~Array();//����������
	void fill_random();
	void fill_random_letter_1();
	void fill_random_letter_2();
	void invert_arr();//�������-������
	void print_array();
};
