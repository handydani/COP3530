//SSLL
#include "List.h"
#include <iostream>
#include "node.h"
#include <stdexcept>
namespace cop3530 {
// ___________________________
// < simple singly linked list >
// ---------------------------
//        \   ^__^
//         \  (oo)\_______
//            (__)\       )\/\
//                ||----w |
//                ||     ||

template <typename T>
class SSLL : public List<T>
{
    public:
        SSLL(int i);
        SSLL(const SSLL&); //copy contructor
        SSLL& operator =(const SSLL&); //copy assignment operator
        //move constructor
        //move assignment operator
        ~ SSLL (); //destructor

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
        void contains( T element/*,  &f()*/) override;
        void print(std::ostream &os) override;
        T * contents() override;
        // void f();


    private:
        Node <T> * head;
        Node <T> * tail;


};

//                      _                   _
//   ___ ___  _ __  ___| |_ _ __ _   _  ___| |_ ___  _ __
//  / __/ _ \| '_ \/ __| __| '__| | | |/ __| __/ _ \| '__|
// | (_| (_) | | | \__ \ |_| |  | |_| | (__| || (_) | |
//  \___\___/|_| |_|___/\__|_|   \__,_|\___|\__\___/|_|

template <typename T>
SSLL<T>::SSLL(int i)
{
    head = new Node<T>;
    tail = new Node<T>;
}
template <typename T>
SSLL<T>::SSLL(const SSLL&orig) :
head(orig.head), tail(orig.tail)
{

}
template <typename T>
SSLL<T>& SSLL<T>::operator =(const SSLL&rhs)
{
    // head = head.rhs;
    // tail = tail.rhs;
    return *this;
}
template <typename T>
SSLL<T>::~SSLL()
{
    //TODO find out how to destroy linked list
    Node<T> * temp = new Node<T>;
    Node<T> * next = new Node<T>;
    temp = head;

    while (temp)
   {
       next = temp->next;
       free(temp);
       temp = next;
   }
}

//   __                  _   _
//  / _|_   _ _ __   ___| |_(_) ___  _ __  ___
// | |_| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
// |  _| |_| | | | | (__| |_| | (_) | | | \__ \
// |_|  \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
//

template <typename T>
void SSLL<T>::insert(T element, size_t position)
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
void SSLL<T>::push_back(T element)
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
void SSLL<T>::push_front(T element)
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
T SSLL<T>::replace( T element, size_t position)
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
T SSLL<T>::remove(size_t position)
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
        itr->data = 0;
        delete itr;
    }
    return removed;
}
template <typename T>
T SSLL<T>::pop_back(void)
{
    //COMPLETE
    if(!length()){

        std::domain_error d("The position requested does not exist");
        throw d;

    }

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
    last_node->data = 0;
    last_node->next = nullptr;
    //deleting
    delete last_node;

    return popped;

}
template <typename T>
T SSLL<T>::pop_front(void)
{
    //COMPLETE
    if(!length()){
        std::domain_error d("The position requested does not exist");
        throw d;
    }

    T popped;
    Node <T> * first_node = new Node<T>;

    first_node = head->next;
    popped = first_node->data;

    head->next = first_node->next;

    return popped;

}
template <typename T>
T SSLL<T>::item_at(size_t position)
{
	//iterate through list until you get to a position
	//TODO throw error if it's not there
    if(!position) return head->data;

	Node <T> * itr = head->next;
	T item = 0;
	while (itr->next)
    {
		itr = itr->next;
		--position;
		if(position == 0){ //0 or negative 1
			item = itr->data;
			break;
		}
    }

    return item;

}
template <typename T>
T SSLL<T>::peek_back(void)
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
T SSLL<T>::peek_front(void)
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
bool SSLL<T>::is_empty(void)
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
bool SSLL<T>::is_full()
{
    //COMPLETE
    return false;
}
template <typename T>
size_t SSLL<T>::length(void)
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
void SSLL<T>::clear(void)
{
    //COMPLETE
    while(head){
        head->data = 0;
        head = head->next;
    }
    tail->data = 0;
    head = new Node<T>;
    tail = new Node<T>;
}
template <typename T>
void SSLL<T>::contains( T element/*, bool &equals_function()*/)
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
T * SSLL<T>::contents()
{
    //COMPLETE
    T * array = new T[length()];
    Node <T> * itr = head->next;

    for (int i = 0; i < length(); i++){
        array[i] = itr->data;
        itr = itr->next;
    }

    return &array[0];
}

template <typename T>
void SSLL<T>::print(std::ostream &os)
{
    //COMPLETE
	//temp ptr for itr
	Node <T> * itr = head->next;
    if(!head->next){
        os << "<empty list>\n";
        return;
    }
    os << "[";
	// loop while itr != null
	while (itr)
    {
		os << itr->data;
		itr = itr->next;
        if(itr)
            os << ",";
    }
    os << "]\n";
}

// template <typename DataT>
// class SSLL_Iter
// {
// public:
//   // type aliases required for C++ iterator compatibility
//   using value_type = DataT;
//   using reference = DataT&;
//   using pointer = DataT*;
//   using difference_type = std::ptrdiff_t;
//   using iterator_category = std::forward_iterator_tag;
//
//   // type aliases for prettier code
//   using self_type = SSLL_Iter;
//   using self_reference = SSLL_Iter&;
//
// private:
//   Node* here;
//
// public:
//   explicit SSLL_Iter( Node* start = nullptr ) : here( start ) {}
//   SSLL_Iter( const SSLL_Iter& src ) : here( src.here ) {}
//
//   reference operator*() const {}
//   pointer operator->() const {}
//
//   self_reference operator=( SSLL_Iter<DataT> const& src ) {}
//
//   self_reference operator++() {} // preincrement
//
//   self_type operator++(int) {} // postincrement
//
//   bool operator==( SSLL_Iter<DataT> const& rhs ) const {}
//   bool operator!=( SSLL_Iter<DataT> const& rhs) const {}
//   }
// }; // end SSLL_Iter


}
