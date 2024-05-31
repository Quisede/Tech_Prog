#include "inverse_array.h"
#include "inverse_array.cpp"
#include "stack_node.h"
#include "stack_node.cpp"
#include "stack.h"
#include "stack.cpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int choice_1;
	int choice_2;
	int choice_3;
	int choice_4;
	int choice_5;
	int choice_6;
	int choice_7;
	int size_of_stack_1;
	int size_of_stack_2;
	int count = 0;
	Stack<int>Stack_1(0);
	Stack<int>Stack_2(0);
	
	do {
		system("cls");
		cout << "Выберите задание\n";
		cout << "1) Инверсия массива\n";
		cout << "2) Параметризованный стек\n";
		cout << "3) Завершение программы\n";
		cin >> choice_1;

		system("cls");

		srand(time(0));

		switch (choice_1) {
		case 1:
			cout << "Выберите тип данных с которым хотите работать:\n1)int\n2)double\n3)float\n4)char\n5)char*\n";
			cin >> choice_2;
			system("cls");
			switch (choice_2) {
			case 1: {
				//int
				size_t arr_size = rand() % 30;
				cout << "Размер массива - " << arr_size << endl;
				Array<int> intArray(arr_size);
				intArray.fill_random();
				intArray.print_array();
				cout << endl;
				intArray.invert_arr();
				intArray.print_array();
				cout << endl;
				break;
			}
			case 2: {
				//double
				cout << "\n";
				size_t arr_size_2 = rand() % 30;
				cout << "Размер массива - " << arr_size_2 << endl;
				Array<double> doubleArray(arr_size_2);
				doubleArray.fill_random();
				doubleArray.print_array();
				cout << endl;
				doubleArray.invert_arr();
				doubleArray.print_array();
				cout << endl;
				break;
			}
			case 3: {
				//float
				cout << "\n";
				size_t arr_size_3 = rand() % 30;
				cout << "Размер массива - " << arr_size_3 << endl;
				Array<float> floatArray(arr_size_3);
				floatArray.fill_random();
				floatArray.print_array();
				cout << endl;
				floatArray.invert_arr();
				floatArray.print_array();
				cout << endl;
				break;
			}
			case 4: {
				//char
				cout << "\n";
				size_t arr_size_4 = rand() % 30;
				cout << "Размер массива - " << arr_size_4 << endl;
				Array<char> charArray(arr_size_4);
				charArray.fill_random_letter_1();
				charArray.print_array();
				cout << endl;
				charArray.invert_arr();
				charArray.print_array();
				cout << endl;
				break;
			}
			case 5: {
				//char*
				cout << "\n";
				size_t arr_size_4 = rand() % 30;
				cout << "Размер массива - " << arr_size_4 << endl;
				Array<std::string> charArray(arr_size_4);
				charArray.fill_random_letter_2();
				charArray.print_array();
				cout << endl;
				charArray.invert_arr();
				charArray.print_array();
				cout << endl;
				break;
			}
			}
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 2:
				cout << "Выберите тип данных с которым хотите работать:\n1)int\n2)double\n3)float\n";
				cin >> choice_4;
				system("cls");
				switch (choice_4) {
				case 1:{
					count = 0;
					//выбрали тип int, создаем два стека
					cout << "Создание стеков\n";

					//создаем стек 1
					cout << "Введите размер стека\n";
					cin >> size_of_stack_1;
					system("cls");
					Stack<int>Stack_1(size_of_stack_1);
					//заполняем его рандомными значениями
					Stack_1.fill_random();
					count++;
					system("pause");
					system("cls");

					//создаем стек 2
					cout << "Введите размер стека\n";
					cin >> size_of_stack_2;
					system("cls");
					Stack<int>Stack_2(size_of_stack_2);
					//заполняем его рандомными значениями
					Stack_2.fill_random();
					count++;
					system("pause");
					system("cls");

					if (count == 2) {
						do {
							//после заполнения переходим к действиям
							system("cls");
							cout << "Действия:\n1)Присваивание (=)\n2)Сложение (+)\n3)Вычитание (-)\n4)Сравнение(==)\n5)Печать стеков\n6)Выход\n";
							cin >> choice_6;
							system("cls");


							switch (choice_6) {
							case 1:
								//перегрузка присваивания
								cout << "Присвоить:\n1)Стек 1 = Стек 2\n2)Стек 2 = Стек 1\n";
								cin >> choice_7;
								switch (choice_7) {
								case 1:
									Stack_1 = Stack_2;
									Stack_1.invert_stack();
									break;
								case 2:
									Stack_2 = Stack_1;
									Stack_2.invert_stack();
									break;
								default:
									cout << "Некорректный выбор\n";
									break;
								}
								break;
							case 2:
								//перегрузка сложения
								cout << "Сложить:\n1)Стек 1 + Стек 2\n2)Стек 2 + Стек 1\n";
								cin >> choice_7;
								switch (choice_7) {
								case 1:
									Stack_1 + Stack_2;
									break;
								case 2:
									Stack_2 + Stack_1;
									break;
								default:
									cout << "Некорректный выбор\n";
									break;
								}
								break;
							case 3:
								//перегрузка вычитания
								cout << "Сложить:\n1)Стек 1 - Стек 2\n2)Стек 2 - Стек 1\n";
								cin >> choice_7;
								switch (choice_7) {
								case 1:
									Stack_1 - Stack_2;
									break;
								case 2:
									Stack_2 - Stack_1;
									break;
								default:
									cout << "Некорректный выбор\n";
									break;
								}
								break;
							case 4:
								//перегрузка сравнения
								Stack_1 == Stack_2;
								system("pause");
								break;
							case 5:
								Stack_1.print_stack();
								Stack_2.print_stack();
								system("pause");
								break;
							}
						} while (choice_6 != 6);
					}
					break;
				}
				case 2:{
					count = 0;
					//выбрали тип double, создаем два стека
					cout << "Создание стеков\n";

					//создаем стек 1
					cout << "Введите размер стека\n";
					cin >> size_of_stack_1;
					system("cls");
					Stack<double>Stack_1(size_of_stack_1);
					//заполняем его рандомными значениями
					Stack_1.fill_random();
					count++;
					system("pause");
					system("cls");

					//создаем стек 2
					cout << "Введите размер стека\n";
					cin >> size_of_stack_2;
					system("cls");
					Stack<double>Stack_2(size_of_stack_2);
					//заполняем его рандомными значениями
					Stack_2.fill_random();
					count++;
					system("pause");
					system("cls");

					if (count == 2) {
						do {
							//после заполнения переходим к действиям
							system("cls");
							cout << "Действия:\n1)Присваивание (=)\n2)Сложение (+)\n3)Вычитание (-)\n4)Сравнение(==)\n5)Печать стеков\n6)Выход\n";
							cin >> choice_6;
							system("cls");


							switch (choice_6) {
							case 1:
								//перегрузка присваивания
								cout << "Присвоить:\n1)Стек 1 = Стек 2\n2)Стек 2 = Стек 1\n";
								cin >> choice_7;
								switch (choice_7) {
								case 1:
									Stack_1 = Stack_2;
									Stack_1.invert_stack();
									break;
								case 2:
									Stack_2 = Stack_1;
									Stack_2.invert_stack();
									break;
								default:
									cout << "Некорректный выбор\n";
									break;
								}
								break;
							case 2:
								//перегрузка сложения
								cout << "Сложить:\n1)Стек 1 + Стек 2\n2)Стек 2 + Стек 1\n";
								cin >> choice_7;
								switch (choice_7) {
								case 1:
									Stack_1 + Stack_2;
									break;
								case 2:
									Stack_2 + Stack_1;
									break;
								default:
									cout << "Некорректный выбор\n";
									break;
								}
								break;
							case 3:
								//перегрузка вычитания
								cout << "Сложить:\n1)Стек 1 - Стек 2\n2)Стек 2 - Стек 1\n";
								cin >> choice_7;
								switch (choice_7) {
								case 1:
									Stack_1 - Stack_2;
									break;
								case 2:
									Stack_2 - Stack_1;
									break;
								default:
									cout << "Некорректный выбор\n";
									break;
								}
								break;
							case 4:
								//перегрузка сравнения
								Stack_1 == Stack_2;
								system("pause");
								break;
							case 5:
								Stack_1.print_stack();
								Stack_2.print_stack();
								system("pause");
								break;
							}
						} while (choice_6 != 6);
					}
					break;
				}
				case 3: {
					count = 0;
					//выбрали тип float, создаем два стека
					cout << "Создание стеков\n";

					//создаем стек 1
					cout << "Введите размер стека\n";
					cin >> size_of_stack_1;
					system("cls");
					Stack<float>Stack_1(size_of_stack_1);
					//заполняем его рандомными значениями
					Stack_1.fill_random();
					count++;
					system("pause");
					system("cls");

					//создаем стек 2
					cout << "Введите размер стека\n";
					cin >> size_of_stack_2;
					system("cls");
					Stack<float>Stack_2(size_of_stack_2);
					//заполняем его рандомными значениями
					Stack_2.fill_random();
					count++;
					system("pause");
					system("cls");

					if (count == 2) {
						do {
							//после заполнения переходим к действиям
							system("cls");
							cout << "Действия:\n1)Присваивание (=)\n2)Сложение (+)\n3)Вычитание (-)\n4)Сравнение(==)\n5)Печать стеков\n6)Выход\n";
							cin >> choice_6;
							system("cls");


							switch (choice_6) {
							case 1:
								//перегрузка присваивания
								cout << "Присвоить:\n1)Стек 1 = Стек 2\n2)Стек 2 = Стек 1\n";
								cin >> choice_7;
								switch (choice_7) {
								case 1:
									Stack_1 = Stack_2;
									Stack_1.invert_stack();
									break;
								case 2:
									Stack_2 = Stack_1;
									Stack_2.invert_stack();
									break;
								default:
									cout << "Некорректный выбор\n";
									break;
								}
								break;
							case 2:
								//перегрузка сложения
								cout << "Сложить:\n1)Стек 1 + Стек 2\n2)Стек 2 + Стек 1\n";
								cin >> choice_7;
								switch (choice_7) {
								case 1:
									Stack_1 + Stack_2;
									break;
								case 2:
									Stack_2 + Stack_1;
									break;
								default:
									cout << "Некорректный выбор\n";
									break;
								}
								break;
							case 3:
								//перегрузка вычитания
								cout << "Сложить:\n1)Стек 1 - Стек 2\n2)Стек 2 - Стек 1\n";
								cin >> choice_7;
								switch (choice_7) {
								case 1:
									Stack_1 - Stack_2;
									break;
								case 2:
									Stack_2 - Stack_1;
									break;
								default:
									cout << "Некорректный выбор\n";
									break;
								}
								break;
							case 4:
								//перегрузка сравнения
								Stack_1 == Stack_2;
								system("pause");
								break;
							case 5:
								Stack_1.print_stack();
								Stack_2.print_stack();
								system("pause");
								break;
							}
						} while (choice_6 != 6);
					}
					break;
				}
				}
		}
	} while (choice_1 != 3);
}
