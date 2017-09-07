//
//  Project 1
//
//  Created by Daniela Isabel Travieso on 9/7/17.
//  Copyright © 2017 Daniela Isabel Travieso. All rights reserved.
//

#ifndef adt_ll_h
#define adt_ll_h

template <typename T>
class adt_ll
{

public:
    virtual ~adt_ll() {};
    virtual void insert( T element, size_t position) = 0;
    virtual void push_back(T element) = 0;
    virtual void push_front(T element) = 0;
    virtual void replace( T element, size_t position) = 0;
    virtual void remove(size_t position) = 0;
    virtual T pop_back(void) = 0;
    virtual T pop_front(void) = 0;
    virtual T peek_back(void) = 0;
    virtual T peek_front(void) = 0;
    virtual bool is_empty(void) = 0;
    virtual bool is_full() = 0;
    virtual size_t length(void) = 0;
    virtual void clear(void) = 0;
    virtual void contains( T element, /*equals_function*/) = 0;
    virtual void print(ostream) = 0;
    virtual void contents() = 0;

};

#endif /* adt_ll_h */
