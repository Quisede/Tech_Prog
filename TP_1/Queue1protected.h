#ifndef Queue1protected_hpp
     #define Queue1protected_hpp
     #include "Queue.h"
     #include <stdio.h>
     class Queue3 : protected Queue {
     public:
         Queue3();
         ~Queue3();
         int max_value();
         void paste(int value);
         int get();
         Queue *copy_queue();
         void merge(Queue *q);
         void display();
         void print_result();
};
     #endif /* Queue1protected_hpp */