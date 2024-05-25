//header файл дочернего класса
#ifndef Queue1public_h
#define Queue1public_h
#include "Queue.h"
class Queue1 : public Queue {
public:
    Queue1();
    ~Queue1();
    int max_value();
    void print_result();
};
#endif /* Queue1public_h */