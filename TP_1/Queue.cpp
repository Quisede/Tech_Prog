//реализация методов базового класса queue
     #include "Queue.h"
     #include <iostream>
Queue :: Queue() : start(nullptr), end(nullptr), size(0) {} //конструктор класса
//деструктор класса (будет проходить по всем узлам, пока не освободит всю память, выделенную под них
     Queue :: ~Queue(){
         while (start != nullptr){
             queue_struct* tmp = start;
start = start -> next; //указатель смещается на следующий узел очереди
delete tmp; }
     }
     void Queue::paste(int value) {
         queue_struct* new_struct = new queue_struct(value);
         if (end == nullptr) {
             start = end = new_struct;
         } else {
             end->next = new_struct;
             end = new_struct;
}
size++; }
     int Queue :: get(){
         //если очередь пустая, то выводим сообщение
         if(start == nullptr){
             std :: cout << "Очередь пустая" << std :: endl;
return -1; }
         int value;
             if (start == end) {
                 value = start->data;
                 delete start;
                 start = end = nullptr;
                 size--;
             } else {
                 queue_struct* tmp = start;
                 while (tmp->next != end) {
                     tmp = tmp->next;
                 }
                 value = end->data;

            delete end;
            end = tmp;
            end->next = nullptr;
            size--;
}
        return value;
    }
Queue* Queue :: copy_queue(){
    Queue* copy_of_queue = new Queue();
    queue_struct* tmp = start;
    while(tmp != nullptr){
        copy_of_queue -> paste(tmp -> data);
        tmp = tmp -> next;
    }
    return copy_of_queue;
}
void Queue :: merge(Queue *q){
    //если очередь пустая
    if(q == nullptr){
return; }
    queue_struct* tmp = q -> start;
    while(tmp != nullptr){
        paste(tmp -> data);
        tmp = tmp -> next;
    }
}
void Queue :: display(){
    if(start == nullptr){
        std :: cout << "Очередь пустая" << std :: endl;
return; }

queue_struct* tmp = start;
    while(tmp != nullptr){
        std :: cout << tmp -> data << " ";
        tmp = tmp -> next;
    }
    std::cout << std::endl;
}
