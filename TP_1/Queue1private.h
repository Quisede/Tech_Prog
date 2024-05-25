 #ifndef Queue1private_hpp
     #define Queue1private_hpp
     #include "Queue.h"
     #include <stdio.h>
     class Queue2 : private Queue {
     public:
         Queue2();
         ~Queue2();
         int max_value();
         void paste(int value);
         int get();
         Queue *copy_queue();
         void merge(Queue *q);
         void display();
         void print_result();
};
#endif /* Queue1private_hpp */