  #pragma once
     #include <stdio.h>
     #include "element.h"
     #include <iostream>
     class Queue {
     private:
      Element* start;
      Element* end;
     public:
      Queue();//конструктор без параметров
      explicit Queue(int d);//конструктор с параметрами
      Queue(const Queue& copy);//конструктор копирования
      ~Queue();//деструктор
      //cтандратные методы класса
      void paste(int value);//добавление элемента в очередь
      int get();//извлечение элемента из очереди
      void display(); //вывод очереди на экран
//бинарные операции (перегруженные)
Queue& operator+(int value);//добавление элемента
int operator-();//извлечение элемента из очереди
friend Queue& operator*(Queue& queue, int value);//умножение
элемента на число
      Queue& operator=(const Queue& other);//присвоение
      bool  operator==(const  Queue&  other_queue);//проверка  на
равенство (поэлементное)
      bool  operator!=(const  Queue&  other_queue);//проверка  на
неравенство
friend std :: istream& operator>>(std :: istream& in, Queue&
queue);//перегрузка ввода в поток
friend std :: ostream& operator<<(std :: ostream& out, Queue& queue);//перегрузка вывода в поток
};