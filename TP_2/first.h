  #pragma once
     #include <stdio.h>
     #include <iostream>
     class Date {
     private:
     int *day;
     int *month;
     int *year;
     public:
     Date();//конструктор без параметров
     Date(int d, int m, int y);//конструктор с параметрами
     Date(const Date& copy);//конструктор копирования
     ~Date();//деконструктор
//перегрузка операторов
Date& operator++(); //префикс инкремент
Date& operator--(); //префикс декремент
friend Date& operator++ (Date&, int); //дружественная ф-я постфикс инкремент
     Date& operator--(int); //постфикс декремент
     //сеттеры и геттеры для элементов класса
     void setDay(int d);
     void setMonth(int m);
     void setYear(int y);
     int getDay() const;
int getMonth() const;
     int getYear() const;
};