#ifndef Queue_h
     #define Queue_h
     class Queue {
     public:
struct queue_struct {
int data; //поле для хранения значения элемента очереди
private:
queue_struct *next;//указатель на следующий элемент
    queue_struct(int d): data(d), next(nullptr) {}
};
queue_struct *start; //указатель на первый элемент очереди
         queue_struct  *end;  //указатель  на  последний  элемент очереди
         int size; //размер очереди
     public:
         Queue(); //конструктор
         ~Queue(); //деструктор
         void paste(int value); //добавление элемента в очередь
         int get(); //извлечение элемента из очереди
         Queue *copy_queue(); //создание копии очереди
         void merge(Queue *q); //слияние очередей
         void display(); //вывод очереди на экран
         //геттеры
         queue_struct* get_start() { return start; }
         queue_struct* get_end() { return end; }
};
     #endif /* Queue_h */