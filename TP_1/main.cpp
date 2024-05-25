 #include <iostream>
     #include "Queue.h"
     #include "Queue1public.h"
     #include "Queue1private.hpp"
     #include "Queue1protected.hpp"
     int main(){
         setlocale(LC_ALL, "Russian");
         Queue queue;
         Queue1 queue_public;
         Queue2 queue_private;
         Queue3 queue_protected;
         //реализация меню
         int choice;
         int value;
         Queue* copy = nullptr;
         do{
значения\n";
std::cout << "Выберите операцию:\n";
std::cout << "1 - Добавление элемента в очередь\n";
std::cout << "2 - Извлечение элемента из очереди\n";
std::cout << "3 - Вывод очереди на экран\n";
std::cout   <<   "4   -   Вычисление   максимального
std::cout << "5 - Создание копии очереди\n";
std::cout << "6 - Слияние оригинальной очереди с копией и вывод результата\n";
             std::cout << "7 - Выход из программы\n";
             std::cin >> choice;
switch (choice) {
добавления: ";
case 1:
std::cout << "Введите значение для
    std::cin >> value;
    queue.paste(value);
    break;
case 2:
std::cout << "Извлечено значение: "
<< queue.get() << std::endl;
                             break;
очереди.\n";
после слияния: ";
    case 3:
        std::cout << "Очередь: ";
        queue.display();
        break;
    case 4:
queue_public.merge(&queue);
queue_public.print_result();
queue_private.merge(&queue);
queue_private.print_result();
queue_protected.merge(&queue);
queue_protected.print_result();
break;
    case 5:
        copy = queue.copy_queue();
        std::cout    <<    "Создана    копия
        break;
    case 6:
queue.merge(copy);
std::cout << "Оригинальная очередь
        queue.display();
        break;
    case 7:

завершена.\n";
Попробуйте снова.\n";
                     }
    break;
default:
    std::cout  <<  "Некорректный  выбор.
4.
    } while (choice != 7);
return 0; }