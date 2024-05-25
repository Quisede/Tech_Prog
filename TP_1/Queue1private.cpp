#include "Queue1private.hpp"
#include <iostream>
Queue2::Queue2() : Queue() {}
Queue2::~Queue2() {}
int Queue2::max_value() {
    if (get_start() == nullptr) {
        std::cerr << "Queue is empty." << std::endl;
return -1; }
    int maxVal = get_start()->data;
    queue_struct* tmp = get_start()->next;
    while (tmp != nullptr) {
        if (tmp->data > maxVal) {
            maxVal = tmp->data;
        }
        tmp = tmp->next;
    }
    return maxVal;
}
void Queue2 :: paste(int value){
    Queue :: paste(value);
}
int Queue2 :: get(){
    return Queue :: get();
}
     void Queue2 :: merge(Queue *q){
         Queue :: merge(q);
}
void Queue2::print_result() {
int res = max_value();
std::cout << "Максимальное значение в очереди: " << res
<< std::endl;
     }