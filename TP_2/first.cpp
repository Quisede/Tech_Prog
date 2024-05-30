 #include "first.h"
     #include <iostream>
     using namespace std;
     //конструктор без параметров
Date::Date() : day(new int(1)), month(new int(1)), year(new int(2024)) {}
     //конструктор c параметрами
     Date::Date(int d, int m, int y) : day(new int(d)), month(new
int(m)), year(new int(y)) {}
     //конструктор копирования
     Date::Date(const  Date&  copy)  :  day(new  int(*copy.day)),
month(new int(*copy.month)), year(new int(*copy.year)) {}
     //деструктор
     Date :: ~Date() {
     delete day;
     delete month;
     delete year;
     }
     //описание геттеров и сеттеров
     int Date::getDay() const {
     return *day;
     }
     int Date::getMonth() const {
     return *month;
     }
     int Date::getYear() const {
     return *year;
}
     void Date::setDay(int d) {
     *day = d;
     }
     void Date::setMonth(int m) {
     *month = m;
     }
     void Date::setYear(int y) {
     *year = y;
     }
     //описание методов
//префиксный ++
Date& Date :: operator++() {
cout << "Используется префиксный ++\n";
int answer;
cout << "Введите 1 - если хотите увеличить день\nВведите 2 - если хотите увеличить месяц\nВведите 3 - если хотите увеличить год\n" << endl;
     cin >> answer;
     system("cls");
switch (answer) {
case 1:
if (*day == 31 && *month == 12) { // Проверяем, является ли последний день года
     // Если последний день года, устанавливаем день в 1, а также увеличиваем месяц и год
     *day = 1;
     *month = 1;
     (*year)++;
     }

     else if (*day == 31 && (*month == 1 || *month == 3 || *month
== 5 || *month == 7 || *month == 8 || *month == 10)) {
// Если последний день месяца с 31 днем (январь, март, май, и т.д.), устанавливаем день в 1, а также увеличиваем месяц
     *day = 1;
     (*month)++;
     }
     else if (*day == 30 && (*month == 4 || *month == 6 || *month
== 9 || *month == 11)) {
// Если последний день месяца с 30 днями (апрель, июнь,сентябрь, ноябрь), устанавливаем день в 1, а также увеличиваем месяц
     *day = 1;
     (*month)++;
     }
     else
     (*day)++;
     break;
     case 2:
     if (*month == 12) {
     *month = 1;
     (*year)++;
     }
     else
     (*month)++;
     break;
     case 3:
     (*year)++;
     break;
     }
     return *this;
     }
     //префиксный —
     Date& Date :: operator--() {
     cout << "Используется префиксный —\n";

int answer;
cout << "Введите 1 - если хотите уменьшить день\nВведите 2 - если хотите уменьшить месяц\nВведите 3 - если хотите уменьшить год\n" << endl;
     cin >> answer;
     system("cls");
switch (answer) {
case 1:
if (*day == 1 && *month == 1) {
*day = 31;
*month = 12;
(*year)--;
}
else if (*day == 1 && (*month == 2 || *month == 4 || *month
== 6 || *month == 8 || *month == 9 || *month == 11)) {
     *day = 31;
(*month)--;
}
else if (*day == 1 && (*month == 5 || *month == 7 || *month
== 10 || *month == 12)) {
     *day = 30;
     (*month)--;
     }
     else
     (*day)--;
     break;
     case 2:
     if (*month == 1) {
     *month = 12;
     (*year)--;
     }
     else
     (*month)--;
     break;
     case 3:

(*year)--;
     break;
     }
     return *this;
     }
     //постфиксный ++(ВОЗВРАЩАЕТ ЗНАЧЕНИЕ ДО ++)
     Date& operator++(Date& date, int) {
     cout << "Используется постфиксный++\n";
     Date tmp (date);
     ++date;
     cout << "Возвращаемое значение\n";
     cout << "День:\n" << tmp.getDay() << endl;
     cout << "Месяц:\n" << tmp.getMonth() << endl;
     cout << "Год:\n" << tmp.getYear() << endl;
     return tmp;
     }
     //постфиксный — (ВОЗВРАЩАЕТ ЗНАЧЕНИЕ ДО —)
     Date& Date :: operator--(int) {
     cout << "Используется постфиксный —\n";
     Date tmp = *this;
--(*this);
cout << "Возвращаемое значение\n";
cout << "День:\n" << tmp.getDay() << endl;
cout << "Месяц:\n" << tmp.getMonth() << endl; cout << "Год:\n" << tmp.getYear() << endl; return tmp;
}