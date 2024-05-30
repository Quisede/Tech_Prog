#pragma once
class Element {
private: int data;//значение элемента очереди
      Element* next;//указатель на следующий элементpublic:
Element() : data(0), next(nullptr) {} explicit Element(int d) : data(d), next(nullptr) {}
//сеттеры и геттеры void setData(int d) { data = d; }
void setNext(Element* ptr) { next = ptr; } int getData() { return data; }
      Element* getNext() { return next; }};