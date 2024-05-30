#include "second.h"
     #include <iostream>
     using namespace std;
     //конструкторы
     Queue::Queue() : start(nullptr), end(nullptr) {}
     Queue::Queue(int d) {
      start = end = new Element(d);
     }
     Queue::Queue(const Queue& copy) {
      //проверка что очередь не пустая
      if (copy.start == nullptr) {
       start = end = nullptr;
return; }
//Новый элемент очереди, копируем данные из первого элемента Element* newElement = new Element(); newElement->setData(copy.start->getData());
start = end = newElement;
      //копируем оставшиеся элементы
      Element* tmp = copy.start->getNext();
      while (tmp != nullptr) {
       Element* newElement = new Element();
       newElement->setData(tmp->getData());
       end->setNext(newElement);
       end = newElement;
       tmp = tmp->getNext();
      }
}
//деструкторы
Queue::~Queue() {
 while (start != nullptr) {
  Element* temp = start;
  start = start->getNext();
  delete temp;
} }
//стандартная функция
void Queue::paste(int value) {
 Element* newElement = new Element(value);
 if (end == nullptr) {
  start = end = newElement;
 }
 else {
  end->setNext(newElement);
  end = newElement;
} }
int Queue::get() {
 if (start == nullptr) {
  cout << "Очередь пустая\n";
  return -1;//так как очередь пустая
 }
int value;
 if (start == end) {
  value = start->getData();
  delete start;
  start = end = nullptr;
}
else {
Element* tmp = start;

  while (tmp->getNext() != end) {
   tmp = tmp->getNext();
}
  value = end->getData();
  delete end;
  end = tmp;
  end->setNext(nullptr);
}
 return value;
}
/*
value = end -> getData();
Element* tmp = end;
if(end == start){
end = start = nullptr;
}
else{
end = start -> getNext();
}
delete tmp;
return value;
}
*/
void Queue::display() {
 if (start == nullptr) {
  std::cout << "Очередь пустая" << std::endl;
  return;
 }
 Element* tmp = start;
 while (tmp != nullptr) {
  std::cout << tmp->getData() << " ";
  tmp = tmp->getNext();
 }

 std::cout << std::endl;
}
//бинарные операции(перегрузка)
//операция добавления
Queue& Queue :: operator+(int value) {
 cout << "Используется перегрузка\n";
 paste(value);
 return *this;
}
int Queue :: operator-() {
 cout << "Используется перегрузка\n";
 if (start == nullptr) {
  cout << "Очередь пустая\n";
  return -1;//так как очередь пустая
 }
 else
  return get();
}
//операция умножения элементов очереди на число
Queue& operator*(Queue& queue, int value) {
 cout << "Используется перегрузка\n";
 if (queue.start == nullptr) {
  std::cout << "Очередь пустая" << std::endl;
 }
 Element* tmp = queue.start;
 while (tmp != nullptr) {
  tmp->setData(tmp->getData() * value);
  tmp = tmp->getNext();
 }
 return queue;
}

//операция присваивания
Queue& ::Queue :: operator=(const Queue& other) {
 if (this != &other) {
  //очищаем текущее содержимое очереди
  while (start != nullptr) {
   Element* tmp = start;
   start = start->getNext();
   delete tmp;
}
  //копирование
  if (other.start != nullptr) {
   Element* tmp = other.start;
   start = end = new Element(tmp->getData());
   tmp = tmp->getNext();
   while (tmp != nullptr) {
    Element* newElement = new Element(tmp->getData());
    end->setNext(newElement);
    end = newElement;
    tmp = tmp->getNext();
} }
  else {
   start = end = nullptr;
} }
 return *this;
}
//проверка на равенство ==
bool :: Queue :: operator==(const Queue& other_queue){
cout << "Выполняется проверка на равенство двух очередей\n"; Element* tmp_current = start;
Element* tmp_other_queue = other_queue.start;
if (other_queue.start == nullptr)

return false;
      //проходимся поэлементно по очередям
while (tmp_current != nullptr && tmp_other_queue != nullptr) {
       if (tmp_current->getData() != tmp_other_queue->getData())
        return false;
       tmp_current = tmp_current->getNext();
       tmp_other_queue = tmp_other_queue->getNext();
      }
return (tmp_current == nullptr && tmp_other_queue == nullptr);
}
//проверка на неравенство !=
bool :: Queue ::operator!=(const Queue& other_queue) {
cout << "Выполняется проверка на неравенство двух очередей\n";
      Element* tmp_current = start;
      Element* tmp_other_queue = other_queue.start;
      if (other_queue.start == nullptr)
       return false;
      //проходимся поэлементно по очередям
while (tmp_current != nullptr && tmp_other_queue != nullptr) {
       if (tmp_current->getData() == tmp_other_queue->getData())
        return false;
       tmp_current = tmp_current->getNext();
       tmp_other_queue = tmp_other_queue->getNext();
      }

return (tmp_current == nullptr && tmp_other_queue == nullptr);
}
     //перегрузка ввода в поток
     std::istream& operator>>(std::istream& in, Queue& queue) {
int value;
std::cout << "Введите элементы очереди (для завершения введите отрицательное число):\n";
      while (true) {
       in >> value;
       if (value < 0)
        break;
       queue.paste(value);
}
return in; }
     //перегрузка вывода в поток
     std::ostream& operator<<(std::ostream& out, Queue& queue) {
      queue.display();
return out; }