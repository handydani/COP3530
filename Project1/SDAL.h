//SDAL
#include "List.h"
#include <iostream>
#include "node.h"
#include <stdexcept>
using namespace cop3530;
// ___________________________
// < simple dynamic array list >
// ---------------------------
//        \   ^__^
//         \  (oo)\_______
//            (__)\       )\/\
//                ||----w |
//                ||     ||

template <typename T>
class SDAL : public List<T>
{
    public:
        SDAL(size_t array_size);
        ~ SDAL ();

        void insert( T element, size_t position) override;
        void push_back(T element) override;
        void push_front(T element) override;
        T replace( T element, size_t position) override;
        T remove(size_t position) override;
        T pop_back(void) override;
        T pop_front(void) override;
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

    private:
        T * data;
        size_t size = 0;
        size_t tail;
};




//TODO UPDATE WITH TAIL INSTEAD OF USING 0'S AS AN INDICATOR





//                      _                   _
//   ___ ___  _ __  ___| |_ _ __ _   _  ___| |_ ___  _ __
//  / __/ _ \| '_ \/ __| __| '__| | | |/ __| __/ _ \| '__|
// | (_| (_) | | | \__ \ |_| |  | |_| | (__| || (_) | |
//  \___\___/|_| |_|___/\__|_|   \__,_|\___|\__\___/|_|

template <typename T>
SDAL<T>::SDAL(size_t array_size): data (new (std::nothrow) T[array_size])
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
}
template <typename T>
SDAL<T>::~SDAL()
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
void SDAL<T>::insert(T element, size_t position)
{
    //TODO check logic it seems like there's a lot of redundancies with the if statements
    //maybe consider a helper function to check isValid?
    //check to make sure inputs aren't 0
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
    else if (position < length())
    {
        for(int i = size; i >= position; --i){
            data[i] = data[i-1];
        }
        data[position] = element;
    }
    else if (position > length() && position < size)
    {
        std::cout <<"You cannot insert where there are no nodes to fit in between\n";
    }
    else if (position > size)
    {
        allocate_array();
        std::cout <<"You cannot insert at this position but I have created a new list 150% the size of the original so you can continue pushing to it" <<std::endl;
    }
    else
    {
        std::cout << "what are you doing";
        //TODO DELETE LATER
    }

}
template <typename T>
void SDAL<T>::push_back(T element)
{
    //check to make sure inputs aren't 0
    if (length() + 1 == size)
    {
        allocate_array();
    }
    for(int i = 0; i < size; ++i){
        if(data[i] == 0){
            data[i] = element;
            return;
        }
    }
}
template <typename T>
void SDAL<T>::push_front(T element)
{
    //check to make sure inputs aren't 0
    if (length() + 1 == size)
    {
        allocate_array();
    }
    for(int i = size; i >= 0; --i){
        data[i] = data[i-1];
    }
    data[0] = element;
}
template <typename T>
T SDAL<T>::replace(T element, size_t position)
{
    T replaced = 0;
    if(position == 0)
    {
        replaced = pop_front();
        push_front(element);
    }
    else if(position + 1 == length())
    {
        replaced = pop_back();
        push_back(element);
    }
    else if (position >= length())
    {
        std::cout << "there's nothing to replace\n";
    }
    else if(position < length())
    {
        replaced = remove(position);
        insert(element, position);
    }
    return replaced;
}
template <typename T>
T SDAL<T>::remove(size_t position)
{
    T removed = 0;
    if(position == 0) //pop the front
    {
        removed = pop_front();
    }
    else if (position == length() - 1) //pop the last element
    {
        removed = pop_back();
    }
    else if (position >= length()) //trying to remove a node thats not there
    {
        std::cout << "You can't remove a node at a position that doesn't exist" << "\n";
    }
    else if (position < length() - 1) //valid removal of interior node
    {
        removed = data[position];
        for (int i = position; i < length(); ++i){
            data[i] = data[i+1];
        }
    }

    if ((size >= 100) && (length() < (size)/2)) //downsize the array if its too big
    {
        deallocate_array();
    }

    return removed;
}
template <typename T>
T SDAL<T>::pop_back(void)
{
    T popped = data[length() - 1];
    data[length() - 1 ] = 0;
    if ((size >= 100) && (length() < (size)/2)) //downsize the array if its too big
    {
        deallocate_array();
    }
    std::cout << popped <<std::endl;
    return popped;

}
template <typename T>
T SDAL<T>::pop_front(void)
{
    T popped = data[0];
    data[0] = 0;
    for (int i = 0; i < size; ++i){
        data[i] = data[i+1];
    }

    if ((size >= 100) && (length() < (size)/2)) //downsize the array if its too big
    {
        deallocate_array();
    }

    return popped;
}
template <typename T>
T SDAL<T>::peek_back(void)
{
    return data[length()-1];
}
template <typename T>
T SDAL<T>::peek_front(void)
{
    return data[0];
}
template <typename T>
bool SDAL<T>::is_empty(void)
{
    bool emptiness = false;
    if(length() == 0)
        emptiness = true;
    return emptiness;
}
template <typename T>
bool SDAL<T>::is_full()
{
    bool fullness = false;
    if(size == length())
        fullness = true;
    return fullness;
}
template <typename T>
size_t SDAL<T>::length(void)
{
    //TODO fix this! what about nodes of 0

    size_t counter = 0;
    for(int i = 0; i < size; ++i){
        if(data[i] == 0){
            return counter;
        }
        ++counter;
    }
    return counter;
}
template <typename T>
void SDAL<T>::clear(void)
{
    for(int i = 0; i < size; ++i)
        data[i] = 0;
}
template <typename T>
void SDAL<T>::contains( T element/*, bool &equals_function()*/)
{
    //TODO
    return;

}
template <typename T>
T * SDAL<T>::contents()
{
    T * ptr = &data[0];
    return ptr;
}

template <typename T>
void SDAL<T>::print(std::ostream &os)
{
    os << "Simple Dynamic Array List: ";
	// loop while itr != null
	for(int i = 0; i < size; ++i){
            os << data[i] << "->";
    }

    os <<"\n";
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
void SDAL<T>::allocate_array(void)
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
void SDAL<T>::deallocate_array(void)
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
