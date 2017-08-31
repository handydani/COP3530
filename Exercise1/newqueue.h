#include <iostream>
// Template class <Q element>
class newQueue
{
    int * head;
    int * tail;
    int * next;
    int counter;
    int container[6] = {0,0,0,0,0,0};
    public:
        newQueue();
        void enqueue(int var);
        int dequeue();
        bool isEmpty();
        bool isFull();
        void print();

};
newQueue::newQueue()
{
    head = &container[0];
    tail = head;
    next = ++tail;
    counter = 0;

}
void newQueue::enqueue(int var)
{
    if(isFull())
    {
        std::cout << "error: queue is full";
    }
    else
    {
        
        //this wont work I think
        // int emptySpot = *tail;
        // container[emptySpot] = var;
        // ++tail;
    }
}
int newQueue::dequeue()
{
    if(isEmpty)
    {
        std::cout << "error: queue is empty";
    }
    else
    {
        //dequeue what head is pointing to
        int last = *head;
        //idk lol
        ++head;
        //
    }
}
bool newQueue::isEmpty()
{
    if (head == tail)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool newQueue::isFull()
{
    int * next = head;
    next += 5;
    if(next == tail)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void newQueue::print()
{

}
