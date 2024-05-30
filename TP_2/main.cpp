 #include <stdio.h>
     #include <iostream>
     #include "first.h"
     #include "element.h"
     #include "second.h"
     using namespace std;
     int main() {
      setlocale(LC_ALL, "Russian");
      Date data;
      Date result;
      Queue queue;
Queue queue2;//вторая очередь
int choice_1;
int choice_2;
int choice_3;
int choice_4;
int value_day;
int value_month;
int value_year;
int value;
int count = 0;
do {
 cout << "Выберите задание:\n";
 cout << "1) Задание 1 - Унарная операция\n";
 cout << "2) Задание 2 - Бинарная операция\n";
 cout << "3) Завершение программы\n";
 cin >> choice_1;
 system("cls");
 switch (choice_1) {
 case 1:
  cout << "Введите день:\n";
  do {
   cin >> value_day;
   if (value_day < 1 || value_day > 31) {
    cout << "Неверное значение, попробуйте ещё раз:\n";
   }
  } while (value_day < 1 || value_day > 31);
  system("cls");
  cout << "Введите месяц:\n";
  do {
cin >> value_month;
 if (value_month < 1 || value_month > 12) {
          cout << "Неверное значение, попробуйте ещё раз:\n";
         }
        } while (value_month < 1 || value_month > 12);
        system("cls");
        cout << "Введите год:\n";
        do {
         cin >> value_year;
         if (value_year < 0 || value_year > 3000) {
          cout << "Неверное значение, попробуйте ещё раз:\n";
         }
        } while (value_year < 0 || value_year > 3000);
        system("cls");
        data.setDay(value_day);
        data.setMonth(value_month);
        data.setYear(value_year);
        do {
         cout  <<  "Выберите  операцию:\n1)Префикс++\n2)Префикс--
\n3)Постфикс++\n4)Постфикс--\n5)Вывести   на   экран\n6)Выход   в
главное меню\n\n\n";
         cin >> choice_2;
         system("cls");
         switch (choice_2) {
         case 1:
          result = ++data;
          cout << "Возвращаемое значение\n";
          cout << "День:\n" << result.getDay() << endl;
          cout << "Месяц:\n" << result.getMonth() << endl;
          cout << "Год:\n" << result.getYear() << endl;
          system("pause");
          break;
case 2:
result = --data;
 cout << "Возвращаемое значение\n";
 cout << "День:\n" << result.getDay() << endl;
 cout << "Месяц:\n" << result.getMonth() << endl;
 cout << "Год:\n" << result.getYear() << endl;
 system("pause");
 break;
case 3:
 result = data++;
 cout << "Возвращаемое значение\n";
 cout << "День:\n" << result.getDay() << endl;
 cout << "Месяц:\n" << result.getMonth() << endl;
 cout << "Год:\n" << result.getYear() << endl;
 system("pause");
 break;
case 4:
 result = data--;
 cout << "Возвращаемое значение\n";
 cout << "День:\n" << result.getDay() << endl;
 cout << "Месяц:\n" << result.getMonth() << endl;
 cout << "Год:\n" << result.getYear() << endl;
 system("pause");
 break;
case 5:
 cout << "День:\n" << data.getDay() << endl;
 cout << "Месяц:\n" << data.getMonth() << endl;
 cout << "Год:\n" << data.getYear() << endl;
 system("pause");
 break;
case 6:
 cout << "Выход в меню\n" << endl;
 break;
default:
 cout << "Некорректный вывод. Попробуйте снова\n";
 break;
}
  system("cls");
 } while (choice_2 != 6);
 break;
case 2: do {
  if (count == 0) {
   cout << "Cоздаем очередь\n";
   choice_3 = 1;
   count++;
}
else {
   cout << "1)Первая очередь\n";
   cout << "2)Вторая очередь\n";
   cout << "3)Выйти\n";
   cin >> choice_3;
   if (choice_3 == 3) {
    system("cls");
    break;
   }
   system("cls");
   if (choice_3 != 1 && choice_3 != 2 && choice_3 != 3) {
    cout << "Введено неверное значение\n";
break; }
}
do {
cout << "Выберите операцию:\n\nСТАНДАРТНЫЕ:\n1)Добавление\n2)Извлечение\n3)Вывод очереди на экран\n\nПЕРЕГРУЖЕННЫЕ\n4)Добавление\n5)Извлечение\n6)Умножение на число\n7)Присвоение\n8)Проверка на равенство ==\n9)Проверка на неравенство !=\n10)Перегрузка ввода\n11)Перегрузка вывода\n12)Вернуться назад в меню\n\n\n";
cin >> choice_2; system("cls"); switch (choice_2){
    case 1:
 cout << "Введите значение для добавления:\n";
 cin >> value;
 if (choice_3 == 1)
  queue.paste(value);
 else if (choice_3 == 2)
  queue2.paste(value);
 system("cls");
 break;
case 2:
 if (choice_3 == 1)
 std::cout << "Извлечено значение: " << queue.get() <<  std::endl;
 else if (choice_3 == 2)
std::cout << "Извлечено значение: " << queue2.get() <<std::endl;
break;
          case 3:
           std::cout << "Очередь: ";
           if (choice_3 == 1)
            queue.display();
           else if (choice_3 == 2)
            queue2.display();
           system("pause");
           break;
          case 4:
           cout << "Введите значение для добавления:\n";
           cin >> value;
           if (choice_3 == 1)
            queue + value;
           else if (choice_3 == 2)
            queue2 + value;
           system("cls");
           break;
          case 5:
           if (choice_3 == 1)
           cout << "Извлечено значение: " << -queue << std::endl; else if (choice_3 == 2)
cout << "Извлечено значение: " << -queue2 << std::endl; break;
case 6:
 cout << "Введите число для умножения:\n";
 cin >> value;
 if (choice_3 == 1)
  queue* value;
 else if (choice_3 == 2)
  queue2* value;
 break;
case 7:
cout << "Выполняется операци присвоения\n";
cout << "Какое присвоение выполнить?\n";
cout << "1)Присвоить значения второй очереди первой\n"; cout << "1)Присвоить значения первой очереди второй\n"; cin >> choice_4;
if (choice_4 == 1)
  queue = queue2;
 if (choice_4 == 2)
  queue2 = queue;
 else
  cout << "Неверный ответ\nОшибкa\n";
 system("cls");
 break;
case 8:
 if (queue == queue2)
  cout << "Очереди равны\n";
 else
  cout << "Очереди не равны\n";
 break;
case 9:
 if (queue != queue2)
  cout << "Очереди не равны\n";
 else
 cout << "Очереди равны\n";
    break;
   case 10:
    cout << "Использование перегрузки ввода\n";
    if (choice_3 == 1)
     std :: cin >> queue;
    else if (choice_3 == 2)
     std :: cin >> queue2;
    system("cls");
    break;
   case 11:
    cout << "Использование перегрузки вывода\n";
    if (choice_3 == 1)
     std::cout << queue;
    else if (choice_3 == 2)
     std::cout << queue2;
    system("pause");
    system("cls");
    break;
   case 12:
    cout << "Возврат назад в меню\n";
    system("pause");
    system("cls");
    break;
   default:
    cout << "Некорректный вывод. Попробуйте снова\n";
    break;
   }
  } while (choice_2 != 12);
 } while (choice_3 != 3);
case 3:
 cout << "Программа завершена\n";
 break;
default:
cout << "Некорректный вывод. Попробуйте снова\n";
break; }
 } while (choice_1 != 3);
return 0; }


