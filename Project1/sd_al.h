//sd_al
#include "adt_ll.h"
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
class sd_al : public adt_ll<T>
{
    public:
        sd_al(size_t array_size);
        ~ sd_al ();

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
        void print() override;
        T * contents() override;
        //my helper functions
        void deallocate_array(void);
        void allocate_array(void);

    private:
        T * data;
        size_t size = 0;
};

//                      _                   _
//   ___ ___  _ __  ___| |_ _ __ _   _  ___| |_ ___  _ __
//  / __/ _ \| '_ \/ __| __| '__| | | |/ __| __/ _ \| '__|
// | (_| (_) | | | \__ \ |_| |  | |_| | (__| || (_) | |
//  \___\___/|_| |_|___/\__|_|   \__,_|\___|\__\___/|_|

template <typename T>
sd_al<T>::sd_al(size_t array_size): data (new (std::nothrow) T[array_size])
{
    if (data == nullptr) {
        array_size = 50;
        data = new T[array_size];
    }
    size = array_size;
    for(int i = 0; i < array_size; ++i){
        data[i] = 0;
    }
}
template <typename T>
sd_al<T>::~sd_al()
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
void sd_al<T>::insert(T element, size_t position)
{
    //WORKS, NEEDS ERROR CHECKING
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
void sd_al<T>::push_back(T element)
{
    //WORKS, NEEDS ERROR CHECKING
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
void sd_al<T>::push_front(T element)
{
    //WORKS, NEEDS ERROR CHECKING
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
T sd_al<T>::replace(T element, size_t position)
{
    //WORKS, NEEDS ERROR CHECKING

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
T sd_al<T>::remove(size_t position)
{

//WORKS, NEEDS ERROR CHECKING

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
T sd_al<T>::pop_back(void)
{
    //WORKS, NEEDS ERROR CHECKING
    //
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
T sd_al<T>::pop_front(void)
{
    //WORKS, NEEDS ERROR CHECKING
    //
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
T sd_al<T>::peek_back(void)
{
    return data[length()-1];
}
template <typename T>
T sd_al<T>::peek_front(void)
{
    return data[0];
}
template <typename T>
bool sd_al<T>::is_empty(void)
{
    bool emptiness = false;
    if(length() == 0)
        emptiness = true;
    return emptiness;
}
template <typename T>
bool sd_al<T>::is_full()
{
    bool fullness = false;
    if(size == length())
        fullness = true;
    return fullness;
}
template <typename T>
size_t sd_al<T>::length(void)
{
    //IT WORK

    size_t counter = 0;
    for(int i = 0; i < size; ++i){
        if(data[i] == 0){
            return counter;
        }
        ++counter;
    }
}
template <typename T>
void sd_al<T>::clear(void)
{
    for(int i = 0; i < size; ++i)
        data[i] = 0;
}
template <typename T>
void sd_al<T>::contains( T element/*, bool &equals_function()*/)
{
    //TODO


}
template <typename T>
T * sd_al<T>::contents()
{
    T * ptr = &data[0];
    return ptr;
}

template <typename T>
void sd_al<T>::print()
{
    //COMPLETE
	std::cout << "Simple Dynamic Array List: ";
	// loop while itr != null
	for(int i = 0; i < size; ++i){
            std::cout << data[i] << "->";
    }

    std::cout <<"\n";
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
void sd_al<T>::allocate_array(void)
{
    // TODO use contents() once that fxn is complete
    //TESTING
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
void sd_al<T>::deallocate_array(void)
{
    // TODO use contents() once that fxn is complete
    //TESTING

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
