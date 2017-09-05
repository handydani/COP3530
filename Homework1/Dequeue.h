//
//  dequeue.h
//  Exercise1
//
//  Created by Daniela Isabel Travieso on 9/1/17.
//  Copyright © 2017 Daniela Isabel Travieso. All rights reserved.
//

#ifndef dequeue_h
#define dequeue_h

template <typename DQ>
class Dequeue
{

public:
    virtual ~Dequeue() {};
    virtual void push_front(DQ element) = 0;
    virtual void push_back(DQ element) = 0;
    virtual DQ pop_front(void) = 0;
    virtual DQ pop_back(void) = 0;
    virtual DQ peek_front(void) = 0;
    virtual DQ peek_back(void) = 0;
    virtual bool is_empty(void) = 0;
    virtual bool is_full() = 0;
    virtual size_t length(void) = 0;
    virtual void clear(void) = 0;
    virtual void print_dequeue(void) = 0;
    // virtual void print_array(void) = 0;


};

#endif /* dequeue_h */
