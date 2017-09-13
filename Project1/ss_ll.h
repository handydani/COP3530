//ss_ll
#include "adt_ll.h"
#include <iostream>
#include "node.h"
#include <stdexcept>

// ___________________________
// < simple singly linked list >
// ---------------------------
//        \   ^__^
//         \  (oo)\_______
//            (__)\       )\/\
//                ||----w |
//                ||     ||

template <typename T>
class ss_ll : public cop3530::adt_ll<T>
{
    public:
        ss_ll(int i);
        ~ ss_ll ();

        void insert( T element, size_t position) override;
        void push_back(T element) override;
        void push_front(T element) override;
        void replace( T element, size_t position) override;
        void remove(size_t position) override;
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
        int* contents() override;


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
    //TODO debug
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
    else if (position > length())
    {
        std::domain_error d("The position requested does not exist");
        throw d;
    }
    else
    {
        Node<T> * itr = new Node<T>;

        itr = head;
        while(position){
            itr = itr->next;
            --position;
        }
        Node<T> * new_node = new Node<T>;

        new_node = itr;
        new_node->data = itr->data;
        new_node->next = itr->next;
    }
}
template <typename T>
void ss_ll<T>::push_back(T element)
{
    //TODO debug
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
    //TODO debug
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
void ss_ll<T>::replace( T element, size_t position)
{
    //in order to do this one like it's insert you
    //have to finish remove, pop back, and pop front
}
template <typename T>
void ss_ll<T>::remove(size_t position)
{

}
template <typename T>
T ss_ll<T>::pop_back(void)
{
    return 1;

}
template <typename T>
T ss_ll<T>::pop_front(void)
{
    //COMPLETE TODO debugging
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
    // while(head){
    //     delete head->data;
    //     head = head->next;
    // }
    // head = new Node<T>;
    // tail = new Node<T>;
}
template <typename T>
void ss_ll<T>::contains( T element /*equals_function*/)
{

}
template <typename T>
int* ss_ll<T>::contents()
{
    //TODO FIX
    // T array [2];
    int * a;
    // //im sure theres a bug here
    // Node <T> * itr = head->next;
    // int i = 0;
    //
    // while(itr)
    // {
    //     array[i] = itr->data;
    //     itr = itr->next;
    //     ++i;
    // }
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

//
//
// int LinkedList::get(std::size_t i) {
// 	Node *curr = first;
// 	std::size_t count = 0;
// 	// move through our linked list,
// 	// counting each time as we do it.
// 	while(curr && count != i) {
// 		curr = curr->next;
// 		++count;
// 	}
//
// 	// if curr is null OR count is not
// 	//  equal to i.
// 	if (!curr || count != i) {
// 		throw std::out_of_range(
// 			"index out of range"
// 		);
// 	}
// 	// If we get here, then curr IS index i.
// 	// therefore, we can return curr's data.
// 	return curr->data;
// }
//
// int LinkedList::get(std::size_t i) {
// 	if (!first) {
// 		throw std::out_of_range("invalid index");
// 	}
// 	Node *curr = first;
// 	std::size_t count = 0;
// 	while(count < i && curr->next) {
// 		++count;
// 		curr=curr->next;
// 	}
// 	if (count != i) {
// 		throw std::out_of_range("invalid index");
// 	}
// 	return curr->data;
// }
