//ss_ll
#include "adt_ll.h"
#include <iostream>
#include "node.h"
#include <stdexcept>
using namespace cop3530;
// ___________________________
// < simple singly linked list >
// ---------------------------
//        \   ^__^
//         \  (oo)\_______
//            (__)\       )\/\
//                ||----w |
//                ||     ||

template <typename T>
class ss_ll : public adt_ll<T>
{
    public:
        ss_ll(int i);
        ~ ss_ll ();

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
        Node <T> * head;
        Node <T> * tail;
        // Node <T> * first;
        // Node <T> * last;


};

//                      _                   _
//   ___ ___  _ __  ___| |_ _ __ _   _  ___| |_ ___  _ __
//  / __/ _ \| '_ \/ __| __| '__| | | |/ __| __/ _ \| '__|
// | (_| (_) | | | \__ \ |_| |  | |_| | (__| || (_) | |
//  \___\___/|_| |_|___/\__|_|   \__,_|\___|\__\___/|_|

template <typename T>
ss_ll<T>::ss_ll(int i)
{
    head = new Node<T>;
    tail = new Node<T>;
}
template <typename T>
ss_ll<T>::~ss_ll()
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
void ss_ll<T>::insert(T element, size_t position)
{
    //COMPLETE
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
        std::domain_error d("The position requested does not exist");
        throw d;
    }
    else
    {
        Node<T> * itr = new Node<T>;
        Node<T> * prev = new Node<T>;

        itr = head;
        while(position + 1){
            prev = itr;
            itr = itr->next;
            --position;
        }
        Node<T> * new_node = new Node<T>;
        // new_node = itr;
        prev->next = new_node;
        new_node->data = element;
        new_node->next = itr;
    }
}
template <typename T>
void ss_ll<T>::push_back(T element)
{
    //COMPLETE
    if (!length()){
        push_front(element);
        return;
    }

    Node <T> * new_node = new Node<T>;
    Node <T> * old_node = new Node<T>;
    Node <T> * itr = new Node<T>;
    //set itr to represent the head
    itr = head;

    //cycle through the list until you reach the end, O(n)
    while(itr){
        //make old_node represent the last node
        old_node = itr;
        itr = itr->next;
    }

    //write data to the new node
    new_node->data = element;

    //if the list isn't empty
    if(old_node){
        //make the last node point to the new node
        old_node->next = new_node;
    }
    //if the list is empty
    else{
        //make the head point to the new node
        head->next = new_node;
    }
    //set tail equal to the new last node
    tail = new_node;
    //make tail point to null
    tail->next = nullptr;
}
template <typename T>
void ss_ll<T>::push_front(T element)
{
    //COMPLETE
    Node <T> * new_node = new Node<T>;
    Node <T> * next_node = new Node<T>;

    //write data to the new node
    new_node->data = element;

    //If there exists something which head points to
    if(head->next){
        //the first node is saved to next node
        next_node = head->next;
        //the next pointer of the new node now points to the prev first node
        new_node->next = next_node;
        //head now points to the new node
        head->next = new_node;
    }
    //if the list is empty
    else{
        //head now points to the new node
        head->next = new_node;
        //the tail becomes the new node
        tail = new_node;
        //after the tail it's null
        tail->next = nullptr;
    }
    return;
}
template <typename T>
T ss_ll<T>::replace( T element, size_t position)
{
    //COMPLETE
    T replaced;
    if(position == 0){
        replaced = pop_front();
        push_front(element);
    }
    else if(position + 1 == length()){
        replaced = pop_back();
        push_back(element);
    }
    else if (position + 1 > length()){
        std::domain_error d("The position requested does not exist");
        throw d;
    }
    else{

        replaced = remove(position);

        Node<T> * itr = new Node<T>;
        Node<T> * prev = new Node<T>;

        itr = head;
        while(position + 1){
            prev = itr;
            itr = itr->next;
            --position;
        }
        Node<T> * new_node = new Node<T>;
        // new_node = itr;
        prev->next = new_node;
        new_node->data = element;
        new_node->next = itr;
    }
    return replaced;
}
template <typename T>
T ss_ll<T>::remove(size_t position)
{
    //COMPLETE
    T removed;
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
        std::domain_error d("The position requested does not exist");
        throw d;
    }
    else
    {
        Node<T> * itr = new Node<T>;
        Node<T> * prev = new Node<T>;

        itr = head->next;
        prev = head;
        while(position){
            itr = itr->next;
            prev = prev->next;
            --position;
        }

        removed = itr->data;
        prev->next = itr->next;
        itr->next = nullptr;
        itr->data = NULL;
        delete itr;
    }
    return removed;
}
template <typename T>
T ss_ll<T>::pop_back(void)
{
    //COMPLETE
    T popped;
    Node <T> * last_node = new Node<T>;
    Node <T> * prev_node = new Node<T>;

    //traverse the list leaving prev one behind last
    last_node = head;
    while(last_node->next){
        prev_node = last_node;
        last_node = last_node->next;
    }
    //popped now contains the data to be deleted
    popped = last_node->data;

    //tail is the previous which now points to null
    tail = prev_node;
    tail->next = nullptr;

    //zeroing out the data
    last_node->data = NULL;
    last_node->next = nullptr;
    //deleting
    delete last_node;

    return popped;

}
template <typename T>
T ss_ll<T>::pop_front(void)
{
    //COMPLETE
    T popped;
    Node <T> * first_node = new Node<T>;

    first_node = head->next;
    popped = first_node->data;

    head->next = first_node->next;

    return popped;

}
template <typename T>
T ss_ll<T>::peek_back(void)
{
    //COMPLETE
    T peeked;
    if(tail){
        peeked = tail->data;
    }
    else{
        peeked = 0;
    }

    return peeked;
}
template <typename T>
T ss_ll<T>::peek_front(void)
{
    //COMPLETE
    T peeked;
    if(head->next){
        peeked = (head->next)->data;
    }
    else{
        peeked = 0;
    }

    return peeked;
}
template <typename T>
bool ss_ll<T>::is_empty(void)
{
    //COMPLETE
    bool answer = false;

    if(!head->next)
    {
        answer = true;
    }

    return answer;
}
template <typename T>
bool ss_ll<T>::is_full()
{
    //COMPLETE
    return false;
}
template <typename T>
size_t ss_ll<T>::length(void)
{
    //COMPLETE
    size_t length = 0;
    Node <T> * itr = new Node<T>;
    itr = head->next;
    while(itr){
        ++length;
        itr = itr->next;
    }
    return length;
}
template <typename T>
void ss_ll<T>::clear(void)
{
    //TODO DEBUG
    while(head){
        head->data = NULL;
        head = head->next;
    }
    tail->data = NULL;
    head = new Node<T>;
    tail = new Node<T>;
}
template <typename T>
void ss_ll<T>::contains( T element/*, bool &equals_function()*/)
{
    //TODO


}
template <typename T>
bool equals_function(T element1, T element2)
{
    //TODO definitely not this
    return element1 == element2;
}
template <typename T>
T * ss_ll<T>::contents()
{
    //TODO FIX
    T array [length()];
    T * a;
    //im sure theres a bug here
    Node <T> * itr = head->next;
    T i = 0;

    while(itr)
    {
        array[i] = itr->data;
        itr = itr->next;
        ++i;
    }
    //
    return a;

    // int * a = newList.contents();
    // std::cout << a[0] << std::endl;
    // std::cout << a[1] << std::endl;
    // std::cout << a[2] << std::endl;
}

template <typename T>
void ss_ll<T>::print()
{
    //COMPLETE
	//temp ptr for itr
	Node <T> * itr = head->next;

	std::cout << "Simple Singly Linked List: ";
	// loop while itr != null
	while (itr)
    {
		std::cout << itr->data << "->";
		itr = itr->next;
    }
    std::cout <<"\n";
}
