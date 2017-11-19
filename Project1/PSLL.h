//PSLL
#include "List.h"
#include "node.h"
#include <iostream>
// cop3530::PSLL<E>::PSLL(const size_t init_pool = 50) :
// pool_size(init_pool){//constructor stuff}
using namespace cop3530;
// _________________________
// < pool singly linked list >
// -------------------------
//        \   ^__^
//         \  (oo)\_______
//            (__)\       )\/\
//                ||----w |
//                ||     ||
template <typename T>
class PSLL : public List<T>
{
public:
    PSLL(int i);
    ~ PSLL ();

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




private:
    Node <T> * head;
    Node <T> * free_list;
    // Node <T> * last;


};

//TODO check for valid inputs, popping when there's nothing there, etc

//                      _                   _
//   ___ ___  _ __  ___| |_ _ __ _   _  ___| |_ ___  _ __
//  / __/ _ \| '_ \/ __| __| '__| | | |/ __| __/ _ \| '__|
// | (_| (_) | | | \__ \ |_| |  | |_| | (__| || (_) | |
//  \___\___/|_| |_|___/\__|_|   \__,_|\___|\__\___/|_|

template <typename T>
PSLL<T>::PSLL(int i)
{
    head = new Node<T>;
    free_list = new Node<T>;

}
template <typename T>
PSLL<T>::~PSLL()
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
void PSLL<T>::insert(T element, size_t position)
{
    //TODO
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
void PSLL<T>::push_back(T element)
{
    // THIS SHOULD WORK REAX ONLY
    if(!free_list->next){ //if there are no nodes to grab from free_list
        Node <T> * new_node = new Node<T>;
        free_list->next = new_node;
        new_node->next = nullptr;
    }
    if (!length()){
        push_front(element);
        return;
    }

    //grab node from free list
    Node<T> * new_node = free_list->next;
    free_list->next = free_list->next->next;

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
        new_node->next = nullptr;
    }
    //if the list is empty
    else{
        //make the head point to the new node
        head->next = new_node;
    }

    //TODO assuming everything goes well
    new_node->next = nullptr;

}
template <typename T>
void PSLL<T>::push_front(T element)
{
    // THIS SHOULD WORK REAX ONLY
    if(!free_list->next){ //if there are no nodes to grab from free_list
        Node <T> * new_node = new Node<T>;
        free_list->next = new_node;
        new_node->next = nullptr;
    }
    Node <T> * next_node = new Node<T>;
    //grab node from free list

    Node<T> * new_node = free_list->next;
    free_list->next = free_list->next->next;

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
        //after the tail it's null
        new_node->next = nullptr;
    }
    return;
}
template <typename T>
T PSLL<T>::replace( T element, size_t position)
{
    //TODO
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
T PSLL<T>::remove(size_t position)
{
    //TODO
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
T PSLL<T>::pop_back(void)
{
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
    prev_node->next = nullptr;

    //adding to pool
    free_list->next = last_node;

    return popped;

}
template <typename T>
T PSLL<T>::pop_front(void)
{
    //error:
    /*
    Pool Singly Linked List:
The free list: 5->
Pool Singly Linked List:
The free list: 19->
    */

    //
    T popped;
    Node <T> * first_node = head->next;
    popped = first_node->data;

    head->next = head->next->next;

    if(!free_list->next->next){ //if there are no nodes to grab from free_list
        free_list->next->next = first_node;
        first_node->next = nullptr;
    }
    else{
        while(free_list->next != nullptr){
            free_list = free_list->next;
        }
        free_list->next = first_node;
        free_list->next->next = nullptr;
    }

    // // first_node->next = nullptr;
    //
    // free_list->next = first_node;
    // free_list->next->next = nullptr;

    return popped;

}
template <typename T>
T PSLL<T>::item_at(size_t position){

}
template <typename T>
T PSLL<T>::peek_back(void)
{
    //COMPLETE
    T peeked;
    // if(tail){
    //     peeked = tail->data;
    // }
    // else{
    //     peeked = 0;
    // }

    return peeked;
}
template <typename T>
T PSLL<T>::peek_front(void)
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
bool PSLL<T>::is_empty(void)
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
bool PSLL<T>::is_full()
{
    //COMPLETE
    return false;
}
template <typename T>
size_t PSLL<T>::length(void)
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
void PSLL<T>::clear(void)
{
    //TODO
    while(head){
        head->data = 0;
        head = head->next;
    }
    // tail->data = NULL;
    head = new Node<T>;
    // tail = new Node<T>;
}
template <typename T>
void PSLL<T>::contains( T element/*, bool &equals_function()*/)
{
    //TODO


}
// template <typename T>
// bool PSLL<T>::equals_function(T element1/*, T element2*/)
// {
//     //TODO definitely not this
//     // return element1 == element2;
// }
template <typename T>
T * PSLL<T>::contents()
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
void PSLL<T>::print(std::ostream &os)
{

	Node <T> * itr_list = head->next;
    Node <T> * itr_free = free_list->next;


	os << "Pool Singly Linked List: ";
	// loop while itr != null
	while (itr_list)
    {
		os << itr_list->data << "->";
		itr_list = itr_list->next;
    }
    os <<"\n";
    os << "The free list: ";

    while (itr_free)
    {
		os << itr_free->data << "->";
		itr_free = itr_free->next;
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
