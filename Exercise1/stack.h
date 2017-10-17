#ifndef Header_h
#define Header_h
#include <iostream>
#include <string>

class Stack
{
    //LIFO
  int container[5] = {0,0,0,0,0};
  public:
    Stack();
    void push(int element)
    {
        for(int i = 0; i < 5; ++i)
        {
            if (container[i] == 0)
            {
                container[i] = element;
                return;
            }
        }
    }

    int pop()
    {
        int popped = 0;
        for(int i = 4; i >= 0; --i)
        {
            if (container[i] != 0)
            {
                popped = container[i];
                container[i] = 0;
                return popped;
            }
        }
        return popped;
    }
    bool isEmpty()
    {
        if (container[0] == 0)
        {
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if (container[4] != 0)
        {
            return true;
        }
        return false;
    }
    unsigned int size()
    {
        unsigned int ctr = 0;
        for(int i = 0; i < 5; ++i){
            if(container[i] != 0){
                ++ctr;
            }
        }
        
        return ctr;
    }
    void print()
    {
        std::cout << "\nthe stack contains: " << std::endl;
        for(int i = 0; i < 5; ++i)
        {
            std::cout << container[i] << " ";
        }
        std::cout << "\n";
    }

};
Stack::Stack(){

    int a = 1;
}

#endif /* Header_h */
