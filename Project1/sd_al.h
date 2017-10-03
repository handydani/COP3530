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

    private:
        T * data;
        size_t size = 0;
        size_t head = 0;
        size_t tail = 0;
        // size_t next(size_t i);
        // size_t prev(size_t i);
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

    // if (!array_size){
    //     array_size = 50;
    // }

}
template <typename T>
sd_al<T>::~sd_al()
{
    //TODO find out how to destroy linked list
    // bool finished = false;
    // while(!finished)
    // {
    //     Node<T> * temp = new Node<T>;
    //     temp = head;
    //     temp = temp->next;
    //     delete head;
    // }

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
    if(position == 0)
    {
        push_front(element);
        return;
    }
    else if (position + 1 == length())
    {
        push_back(element);
        return;
    }
    else if (position > length())
    {
        //allocate new array
    }
    else
    {
        for(int i = size; i >= position; --i){
            data[i] = data[i-1];
        }
        data[position] = element;
    }
}
template <typename T>
void sd_al<T>::push_back(T element)
{
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
    for(int i = size; i >= 0; --i){
        data[i] = data[i-1];
    }
    data[0] = element;

}
template <typename T>
T sd_al<T>::replace( T element, size_t position)
{
    T replaced = 0;
    if(position == 0){
        replaced = pop_front();
        push_front(element);
    }
    else if(position + 1 == length()){
        replaced = pop_back();
        push_back(element);
    }
    else if (position + 1 > length()){
        //find next array
    }
    else{
        replaced = remove(position);
        insert(element, position);
    }
    return replaced;
}
template <typename T>
T sd_al<T>::remove(size_t position)
{
    T removed = 0;
    if(position == 0)
    {
        removed = pop_front();
    }
    else if (position + 1 == length())
    {
        removed = pop_back();
    }
    else if (position + 1 > length())
    {
        //find next array
    }
    else
    {
        removed = data[position];
        for (int i = position; i < length(); ++i){
            data[i] = data[i+1];
        }

    }
    return removed;
}
template <typename T>
T sd_al<T>::pop_back(void)
{
    T popped = data[length() - 1];
    data[length() - 1 ] = 0;
    return popped;

}
template <typename T>
T sd_al<T>::pop_front(void)
{
    T popped = data[0];
    data[0] = 0;
    for (int i = 0; i < size; ++i){
        data[i] = data[i+1];
    }
    return popped;
}
template <typename T>
T sd_al<T>::peek_back(void)
{
    //COMPLETE
    // T peeked;
    // if(tail){
    //     peeked = tail->data;
    // }
    // else{
    //     peeked = 0;
    // }
    //
    // return peeked;
}
template <typename T>
T sd_al<T>::peek_front(void)
{
    //COMPLETE
    // T peeked;
    // if(head->next){
    //     peeked = (head->next)->data;
    // }
    // else{
    //     peeked = 0;
    // }
    //
    // return peeked;
}
template <typename T>
bool sd_al<T>::is_empty(void)
{
    //COMPLETE
    // bool answer = false;
    //
    // if(!head->next)
    // {
    //     answer = true;
    // }
    //
    // return answer;
}
template <typename T>
bool sd_al<T>::is_full()
{
    //COMPLETE
    // return false;
}
template <typename T>
size_t sd_al<T>::length(void)
{
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
    //TODO DEBUG
    // while(head){
    //     head->data = NULL;
    //     head = head->next;
    // }
    // tail->data = NULL;
    // head = new Node<T>;
    // tail = new Node<T>;
}
template <typename T>
void sd_al<T>::contains( T element/*, bool &equals_function()*/)
{
    //TODO


}
template <typename T>
T * sd_al<T>::contents()
{
    //TODO FIX
    // T array [length()];
    // T * a;
    // //im sure theres a bug here
    // Node <T> * itr = head->next;
    // T i = 0;
    //
    // while(itr)
    // {
    //     array[i] = itr->data;
    //     itr = itr->next;
    //     ++i;
    // }
    // //
    // return a;

    // int * a = newList.contents();
    // std::cout << a[0] << std::endl;
    // std::cout << a[1] << std::endl;
    // std::cout << a[2] << std::endl;
}

template <typename T>
void sd_al<T>::print()
{
    //COMPLETE
	//temp ptr for itr

	std::cout << "Simple Dynamic Array List: ";
	// loop while itr != null
	for(int i = 0; i < size; ++i){
        if(data[i]){
            std::cout << data[i] << "->";

        }
    }

    std::cout <<"\n";
}
// template <typename T>
// size_t sd_al<T>::next(size_t i)
// {
//     if(++i == size)
//     {
//         //allocate new array
//     }
//     return i;
// }
//
// template <typename T>
// size_t sd_al<T>::prev(size_t i)
// {
//     if(i == 0)
//     {
//         //find previous array
//     }
//     return i;
// }
