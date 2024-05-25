#include <iostream>
#include "Queue1public.h"
Queue1::Queue1() : Queue() {}
Queue1::~Queue1() {}
int Queue1::max_value() {
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
void Queue1::print_result() {
int res = max_value();
std::cout << " Максимальное значение в очереди: " << res
<< std::endl;
     }