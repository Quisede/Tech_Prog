 #include "Queue1protected.hpp"
     #include <iostream>
Queue3::Queue3() : Queue() {}
Queue3::~Queue3() {}
int Queue3::max_value() {
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
void Queue3 :: paste(int value){
    Queue :: paste(value);
}
int Queue3 :: get(){
    return Queue :: get();
}
void Queue3 :: merge(Queue *q){
    Queue :: merge(q);
}
void Queue3::print_result() {

int res = max_value();
std::cout << "Максимальное значение в очереди: " << res << std::endl;
}