//CBL
#include "List.h"
#include <iostream>
#include "node.h"
#include <stdexcept>
namespace cop3530
{
// ___________________________
// < central buffer list >
// ---------------------------
//        \   ^__^
//         \  (oo)\_______
//            (__)\       )\/\
//                ||----w |
//                ||     ||

template <typename T>
class CBL : public List<T>
{
    public:
        CBL(size_t array_size);
        ~ CBL ();

        void insert( T element, size_t position) override;
        void push_back(T element) override;
        void push_front(T element) override;
        T replace( T element, size_t position) override;
        T remove(size_t position) override;
        T pop_back(void) override;
        T pop_front(void) override;
        T item_at(size_t position) override;
        T peek_back(void) override;
        T peek_front(void) override;
        bool is_empty(void) override;
        bool is_full() override;
        size_t length(void) override;
        void clear(void) override;
        void contains( T element /*equals_function*/) override;
        void print(std::ostream &os) override;
        T * contents() override;
        //my helper functions
        void deallocate_array(void);
        void allocate_array(void);
        size_t prev(size_t i);
        size_t next(size_t i);
    private:
        T * data;
        size_t head;
        size_t tail;
        // size_t capacity;
        size_t size;
};

//                      _                   _
//   ___ ___  _ __  ___| |_ _ __ _   _  ___| |_ ___  _ __
//  / __/ _ \| '_ \/ __| __| '__| | | |/ __| __/ _ \| '__|
// | (_| (_) | | | \__ \ |_| |  | |_| | (__| || (_) | |
//  \___\___/|_| |_|___/\__|_|   \__,_|\___|\__\___/|_|

template <typename T>
CBL<T>::CBL(size_t array_size): data (new (std::nothrow) T[array_size])
{
    if (data == nullptr) {
        array_size = 50;
        data = new T[array_size];
    }
    size = array_size;
    for(int i = 0; i < array_size; ++i){
        data[i] = 0;
    }
    tail = 0;
    head = 0;
}
template <typename T>
CBL<T>::~CBL()
{
    delete[] data;
}

//   __                  _   _
//  / _|_   _ _ __   ___| |_(_) ___  _ __  ___
// | |_| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
// |  _| |_| | | | | (__| |_| | (_) | | | \__ \
// |_|  \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
//

template <typename T>
void CBL<T>::insert(T element, size_t position)
{
    if(position == 0)
    {
        push_front(element);
        return;
    }
    else if (position == length())
    {
        push_back(element);
        return;
    }
    // else if (position < length())
    // {
    //     for(int i = size; i >= position; --i){
    //         data[i] = data[i-1];
    //     }
    //     data[position] = element;
    // }
    // else if (position > length() && position < size)
    // {
    //     std::cout <<"You cannot insert where there are no nodes to fit in between\n";
    // }
    // else if (position > size)
    // {
    //     allocate_array();
    //     std::cout <<"You cannot insert at this position but I have created a new list 150% the size of the original so you can continue pushing to it" <<std::endl;
    // }
    // else
    // {
    //     std::cout << "what are you doing";
    //     //TODO DELETE LATER
    // }

}
template <typename T>
void CBL<T>::push_back(T element)
{
    if(!is_full())
    {
        data[tail] = element;
        tail = next(tail);
    }
    else
    {
        allocate_array();
        push_back(element);
    }

}
template <typename T>
void CBL<T>::push_front(T element)
{
    if(!is_full())
    {
        head = prev(head);
        data[head] = element;
    }
    else
    {
        allocate_array();
        push_front(element);
    }
}
template <typename T>
T CBL<T>::replace(T element, size_t position)
{
    //TODO error checking

    T replaced = 0;

    if(data[position])
    {
        replaced = data[position];
        data[position] = element;
    }
    else
    {
        throw std::runtime_error("trying to replace something that doesn't exist");
    }

    return replaced;
}
template <typename T>
T CBL<T>::remove(size_t position)
{
    T removed = 0;
    // if(position == 0) //pop the front
    // {
    //     removed = pop_front();
    // }
    // else if (position == length() - 1) //pop the last element
    // {
    //     removed = pop_back();
    // }
    // else if (position >= length()) //trying to remove a node thats not there
    // {
    //     std::cout << "You can't remove a node at a position that doesn't exist" << "\n";
    // }
    // else if (position < length() - 1) //valid removal of interior node
    // {
    //     removed = data[position];
    //     for (int i = position; i < length(); ++i){
    //         data[i] = data[i+1];
    //     }
    // }
    //
    // if ((size >= 100) && (length() < (size)/2)) //downsize the array if its too big
    // {
    //     deallocate_array();
    // }
    //
    return removed;
}
template <typename T>
T CBL<T>::pop_back(void)
{
    size_t popped = --tail;
    if(!is_empty())
    {
        tail = prev(tail);
    }
    else throw std::runtime_error( "empty list" );

    if ((size >= 100) && (length() < (size)/2)) //downsize the array if its too big
    {
        deallocate_array();
    }
    return data[popped];
}
template <typename T>
T CBL<T>::pop_front(void)
{
    size_t popped = head;
    if(!is_empty())
    {
        head = next(head);
    }
    else throw std::runtime_error( "empty list," );

    if ((size >= 100) && (length() < (size)/2)) //downsize the array if its too big
    {
        deallocate_array();
    }
    return data[popped];
}
template <typename T>
T CBL<T>::item_at(size_t position)
{
    return data[position];
}

template <typename T>
T CBL<T>::peek_back(void)
{
    return data[length()-1];
}
template <typename T>
T CBL<T>::peek_front(void)
{
    return data[0];
}
template <typename T>
bool CBL<T>::is_empty(void)
{
    return head == tail;
}
template <typename T>
bool CBL<T>::is_full()
{
    return (head == next(tail));
}
template <typename T>
size_t CBL<T>::length(void)
{
    if(head > tail)
    {
        return ((size - head) + tail);
    }
    else
    {
        return (tail - head);
    }
}
template <typename T>
void CBL<T>::clear(void)
{
    // head = tail;
    // tail = head;
    // for(int i = 0; i < size; ++i)
    //     data[i] = 0;
}
template <typename T>
void CBL<T>::contains( T element/*, bool &equals_function()*/)
{
    //TODO
    return;

}
template <typename T>
T * CBL<T>::contents()
{
    T * ptr = &data[0];
    return ptr;
}

template <typename T>
void CBL<T>::print(std::ostream &os)
{
    if(!length()){
        os << "<empty list>\n";
        return;
    }
	// loop while itr != null
    os << "[";
    if(head < tail){
        for(int i = head; i < tail; ++i){
                os << data[i] << ",";
        }
    }
    else{
        for(int i = head; i < size; ++i){
                os << data[i] << ",";
        }
        for(int i = 0; i < tail; ++i){
                os << data[i] << ",";
        }
    }

    os <<"]\n";
}

// _____________
// < helper fxns >
// -------------
//        \   ^__^
//         \  (oo)\_______
//            (__)\       )\/\
//                ||----w |
//                ||     ||

template <typename T>
void CBL<T>::allocate_array(void)
{
    T temp[size]; //temp array for storing variables
    size_t prev_size = size; //store the original size
    for(int i = 0 ; i < prev_size; ++i){ //copy the contents of data to temp
        temp[i] = data[i];
        data[i] = 0;
    }
    size = 1.5 * prev_size;//will this work?
    data = new T[size]; //reinitialize the data variable to 150% the size of the original

    for(int i = 0 ; i < prev_size; ++i){ //copy temp back to data
        data[i] = temp[i];
    }
    for(int i = prev_size; i < size; ++i){ //initialize the rest of the array w 0
        data[i] = 0;
    }
}

template <typename T>
void CBL<T>::deallocate_array(void)
{
    T temp[size]; //temp array for storing variables
    size_t prev_size = size; //store the original size


    for(int i = 0 ; i < prev_size; ++i){ //copy the contents of data to temp
        temp[i] = data[i];
        data[i] = 0;
    }

    size = 0.75 * prev_size;//will this work?
    data = (new T[size]); //reinitialize the data variable to 150% the size of the original

    for(int i = 0 ; i < prev_size; ++i){ //copy temp back to data
        data[i] = temp[i];
    }
    //this might b redundant
    for(int i = prev_size; i < size; ++i){ //initialize the rest of the array w 0
        data[i] = 0;
    }

}




template <typename T>
size_t CBL<T>::next(size_t i)
{
    if(++i == size)
    {
        i = 0;
    }
    return i;
}

template <typename T>
size_t CBL<T>::prev(size_t i)
{
    if(--i <= 0)
    {

        i = size - 1;
    }
    return i;
}
}
