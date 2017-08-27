#include <iostream>
#include "stack.h"
int main ()
{
    Stack* stackclass = new Stack();

    stackclass->push(3);
    stackclass->push(4);
    stackclass->print();
    std::cout << "\n popped: " << stackclass->pop() << std::endl;
    stackclass->print();
    std::cout << "\n popped: " << stackclass->pop() << std::endl;
    stackclass->print();

    if ( !stackclass->isEmpty())
    {
        std::cout << "\n popped: " << stackclass->pop() << std::endl;
        stackclass->print();
    }
    stackclass->push(1);
    stackclass->push(2);
    stackclass->push(3);
    stackclass->push(4);
    stackclass->push(5);
    stackclass->print();
    stackclass->pop();
    stackclass->pop();
    stackclass->print();

    if ( !stackclass->isFull())
    {
        std::cout << "\n pushed: 6 " << std::endl;
        stackclass->push(6);
    }

    //check if element they are pushing is 0
    return 0;
}
