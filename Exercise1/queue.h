#ifndef Header_h
#define Header_h
#include <iostream>
#include <string>

class Queue
{
    //FIFO
  int container[5] = {0,0,0,0,0};
  public:
    Queue();
    void enqueue(int element)
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

    int dequeue()
    {
        int dequeued = container[0];

        for (int i = 0; i < 4; ++i)
        {
            container[i] = container[i+1];
        }
        container[4] = 0;
        return dequeued;
    }
    bool isEmpty()
    {
        if (container[0] == 0)
        {
            return true;
        }
    }
    bool isFull()
    {
        if (container[4] != 0)
        {
            return true;
        }
    }
    void print()
    {
        std::cout << "\nthe queue contains: " << std::endl;
        for(int i = 0; i < 5; ++i)
        {
            std::cout << container[i] << " ";
        }
        std::cout << "\n";
    }

};
Queue::Queue(){

}

#endif /* Header_h */
