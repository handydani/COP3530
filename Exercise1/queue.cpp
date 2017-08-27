#include <iostream>
#include "queue.h"

int main()
{
    Queue* queueclass = new Queue();

    queueclass->enqueue(1);
    queueclass->enqueue(2);
    queueclass->enqueue(3);
    queueclass->enqueue(4);
    queueclass->enqueue(5);
    queueclass->print();

    std::cout << "the dequeued element is: " << queueclass->dequeue();
    queueclass->print();
    queueclass->dequeue();
    queueclass->dequeue();
    queueclass->print();


    return 0;
}
