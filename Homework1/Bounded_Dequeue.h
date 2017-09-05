//
//  bounded_dequeue.h
//  Exercise1
//
//  Created by Daniela Isabel Travieso on 9/3/17.
//  Copyright © 2017 Daniela Isabel Travieso. All rights reserved.
//

#ifndef bounded_dequeue_h
#define bounded_dequeue_h

#include "Dequeue.h"
#include <stdexcept>
template <typename DQ>

class Bounded_Dequeue : public Dequeue<DQ>
{

public:
    Bounded_Dequeue( size_t cap );

    void push_front(DQ element) override;
    void push_back(DQ element) override;
    DQ pop_front(void) override;
    DQ pop_back(void) override;
    DQ peek_front(void) override;
    DQ peek_back(void) override;
    bool is_empty(void) override;
    bool is_full(void) override;
    size_t length(void) override;
    void clear(void) override;
    void print_dequeue(void) override;
    // void print_array(void) override;

private:
    size_t capacity;
    DQ * const data;
    size_t head = 0;
    size_t tail = 0;
    size_t next(size_t i);
    size_t prev(size_t i);
};

//                      _                   _
//   ___ ___  _ __  ___| |_ _ __ _   _  ___| |_ ___  _ __
//  / __/ _ \| '_ \/ __| __| '__| | | |/ __| __/ _ \| '__|
// | (_| (_) | | | \__ \ |_| |  | |_| | (__| || (_) | |
//  \___\___/|_| |_|___/\__|_|   \__,_|\___|\__\___/|_|

template <typename DQ>

Bounded_Dequeue<DQ>::Bounded_Dequeue(size_t cap) : capacity(cap + 1),
                                                   data(new DQ[cap + 1])
{
   for (int i = 0; i < capacity; ++i)
   {
       data[i] = 0;
   }
}


//   __                  _   _
//  / _|_   _ _ __   ___| |_(_) ___  _ __  ___
// | |_| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
// |  _| |_| | | | | (__| |_| | (_) | | | \__ \
// |_|  \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
//
template <typename DQ>
void Bounded_Dequeue<DQ>::push_front(DQ element)
{
    if(!is_full())
    {
        head = prev(head);
        data[head] = element;
    }
    else
    {
         throw std::runtime_error( "Bounded_Queue<E>.enqueue(): full queue" );
    }
}

template <typename DQ>
void Bounded_Dequeue<DQ>::push_back(DQ element)
{
    if(!is_full())
    {
        data[tail] = element;
        tail = next(tail);
    }
    else
    {
        throw std::runtime_error( "Bounded_Queue<E>.enqueue(): full queue" );
    }

}

template <typename DQ>
DQ Bounded_Dequeue<DQ>::pop_front(void)
{
    size_t popped = head;
    if(!is_empty())
    {
        head = next(head);
    }
    else
    {
        throw std::runtime_error( "Bounded_Queue<E>.dequeue(): empty queue" );
    }
    return data[popped];
}

template <typename DQ>
DQ Bounded_Dequeue<DQ>::pop_back(void)
{
    size_t popped = --tail;

    if(!is_empty())
    {
        tail = prev(tail);
    }
    else
    {
        throw std::runtime_error( "Bounded_Queue<E>.dequeue(): empty queue" );
    }
    return data[popped];
}

template <typename DQ>
DQ Bounded_Dequeue<DQ>::peek_front(void)
{
    return data[head];
}

template <typename DQ>
DQ Bounded_Dequeue<DQ>::peek_back(void)
{
    return data[prev(tail)];
}

template <typename DQ>
bool Bounded_Dequeue<DQ>::is_empty(void)
{
    return head == tail;
}

template <typename DQ>
bool Bounded_Dequeue<DQ>::is_full(void)
{
    //check this
    bool fullness = (head == next(tail));
    fullness = fullness || tail == prev(head);
    // if(head > tail)
    // {
    //     fullness = ++tail == head;
    // }
    // else if (head == tail)
    // {
    //     fullness = false;
    // }
    // else
    // {
    //     fullness = prev(head) == tail;
    // }

    return fullness;
}

template <typename DQ>
size_t Bounded_Dequeue<DQ>::length(void)
{
    //test edge cases
    if( head > tail)
    {
        return ((capacity - head) + tail);
    }
    else
    {
        return (tail - head);
    }
}

template <typename DQ>
void Bounded_Dequeue<DQ>::clear(void)
{
    head = tail = 0;
}

template <typename DQ>
size_t Bounded_Dequeue<DQ>::next(size_t i)
{
    if(++i == capacity)
    {
        i = 0;
    }
    return i;
}

template <typename DQ>
size_t Bounded_Dequeue<DQ>::prev(size_t i)
{
    if(--i < 0)
    {
        i = capacity - 1;
    }
    return i;
}
// template <typename DQ>
// void Bounded_Dequeue<DQ>::print_array(void)
// {
//     std::cout << "The array is: " << std:: endl;
//
//     int * ptr = data;
//     int b = sizeof(capacity);
//     for(int i = 0; i< b; ++i)
//     {
//         printf("%u ", *ptr);
//         ++ptr;
//     }
//
//     std::cout << "\nEnd of array" << std::endl;
// }
template <typename DQ>
void Bounded_Dequeue<DQ>::print_dequeue(void)
{
    std::cout << "The dequeue is: " << std:: endl;
    size_t store_H = head;
    size_t store_T = tail;

    while (head != tail)
    {
        std::cout << data[head] << " ";
        head = next(head);
    }
    std::cout << "\nEnd of dequeue" << std::endl;

    // for(int i = 0; i < capacity; ++i)
    // {
    //     if(head == tail)
    //     {
    //
    //         return;
    //     }
    //
    // }

    head = store_H;
    tail = store_T;
}

#endif /* bounded_dequeue_h */
