//cd_al
#include "adt_ll.h"
#include <iostream>
#include "node_cdal.h"
#include <stdexcept>

using namespace cop3530;
// _______________________________
// < chained dynamic array list >
// -------------------------------
//        \   ^__^
//         \  (oo)\_______
//            (__)\       )\/\
//                ||----w |
//                ||     ||
template <typename T>
class cd_al : public adt_ll<T>
{
    public:
        cd_al(int i);
        ~ cd_al ();

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
        size_t node_ctr();
        void create_node(void);

    private:
        Node_CDAL <T> * head;
        size_t tail;

};

//                      _                   _
//   ___ ___  _ __  ___| |_ _ __ _   _  ___| |_ ___  _ __
//  / __/ _ \| '_ \/ __| __| '__| | | |/ __| __/ _ \| '__|
// | (_| (_) | | | \__ \ |_| |  | |_| | (__| || (_) | |
//  \___\___/|_| |_|___/\__|_|   \__,_|\___|\__\___/|_|

template <typename T>
cd_al<T>::cd_al(int i)
{
    head = new Node_CDAL<T>;
    head->next = NULL;
    tail = 0;
}
template <typename T>
cd_al<T>::~cd_al()
{
    //TODO find out how to destroy linked list
    // bool finished = false;
    // while(!finished)
    // {
    //     Node_CDAL<T> * temp = new Node<T>;
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
void cd_al<T>::insert(T element, size_t position)
{
    //COMPLETE
    // if(position == 0)
    // {
    //     push_front(element);
    //     return;
    // }
    // else if (position + 1 == length())
    // {
    //     push_back(element);
    //     return;
    // }
    // else if (position > length())
    // {
    //     std::domain_error d("The position requested does not exist");
    //     throw d;
    // }
    // else
    // {
    //     Node<T> * itr = new Node<T>;
    //     Node<T> * prev = new Node<T>;
    //
    //     itr = head;
    //     while(position + 1){
    //         prev = itr;
    //         itr = itr->next;
    //         --position;
    //     }
    //     Node<T> * new_node = new Node<T>;
    //     // new_node = itr;
    //     prev->next = new_node;
    //     new_node->data = element;
    //     new_node->next = itr;
    // }
}
template <typename T>
void cd_al<T>::push_back(T element)
{
    //tail must be less than 50
    //item must be pushed to the first node, next nodes, and the last node,
    if (tail < 50){
        //you don't have to create a new node
        Node_CDAL <T> * itr = head;
        Node_CDAL <T> * prev_node = new Node_CDAL<T>;

        while(itr){
            prev_node = itr;
            itr = itr->next;
        }

        (prev_node->data)[tail] = element;
    }
    else{
        Node_CDAL <T> * new_node = new Node_CDAL<T>;
        Node_CDAL <T> * prev_node = new Node_CDAL<T>;
        Node_CDAL <T> * itr = new Node_CDAL<T>;
        //set itr to represent the head
        itr = head;

        //cycle through the list until you reach the end, O(n)
        while(itr){
            //make prev_node represent the last node
            prev_node = itr;
            itr = itr->next;
        }

        //write data to the new node
        tail = 0;
        (new_node->data)[tail] = element;

        //if the list isn't empty
        if(prev_node){
            //make the last node point to the new node
            prev_node->next = new_node;
        }
        //if the list is empty
        else{
            //make the head point to the new node
            head->next = new_node;
        }
        new_node->next = nullptr;
    }

    //TODO check for cases in which pushing to the back fails
    ++tail;
}
template <typename T>
void cd_al<T>::push_front(T element)
{
    //there is more than one node
    //the tail is = to 50
    /*
        00: copy contents as normal and shift down
        01: create new node and copy contents to an array and shift down
        10: copy contents to an array and shift down
        11: create new node and copy contents to an array and shift down
    */
    if(tail < 50)
    {
        //create new node, copy contents and shift down
    }
    else if(node_ctr() > 1 && tail < 50)
    {
//
//  _                 _                         _
// | |__   ___   ___ | | ___ __ ___   __ _ _ __| | __
// | '_ \ / _ \ / _ \| |/ / '_ ` _ \ / _` | '__| |/ /
// | |_) | (_) | (_) |   <| | | | | | (_| | |  |   <
// |_.__/ \___/ \___/|_|\_\_| |_| |_|\__,_|_|  |_|\_\
//

        //find last node, copy contents to an array and shift down
        Node_CDAL <T> * new_node = new Node_CDAL<T>;
        Node_CDAL <T> * prev_node = new Node_CDAL<T>;
        Node_CDAL <T> * itr = head;

        //cycle through the list until you reach the end, O(n)
        while(itr){
            //make prev_node represent the last node
            prev_node = itr;
            itr = itr->next;
        }

        //if the list isn't empty
        if(prev_node){
            //make the last node point to the new node
            prev_node->next = new_node;
        }
        //if the list is empty
        else{
            //make the head point to the new node
            head->next = new_node;
        }
        new_node->next = nullptr;

        T * content_array = new T[length()];
        for(int i = 0; i < length(); ++i){
            content_array[i] = (new_node->data)[i];
        }
        new_node->data[0] = element;
        for(int i = 1; i < length(); ++i){
            (new_node->data)[i] = content_array[i-1];
        }

    }
    else
    {
        //shift data of head down
        //copy contents to an array
        T * content_array = new T[length()];
        for(int i = 0; i < length(); ++i){
            content_array[i] = (head->data)[i];
        }
        head->data[0] = element;
        for(int i = 1; i < length(); ++i){
            (head->data)[i] = content_array[i-1];
        }
    }
    return;
    //if tail == 49
        // allocate new array and new node

    // create array of size n + 1
    // copy contents
    //COMPLETE
    // Node <T> * new_node = new Node<T>;
    // Node <T> * next_node = new Node<T>;
    //
    // //write data to the new node
    // new_node->data = element;
    //
    // //If there exists something which head points to
    // if(head->next){
    //     //the first node is saved to next node
    //     next_node = head->next;
    //     //the next pointer of the new node now points to the prev first node
    //     new_node->next = next_node;
    //     //head now points to the new node
    //     head->next = new_node;
    // }
    // //if the list is empty
    // else{
    //     //head now points to the new node
    //     head->next = new_node;
    //     //the tail becomes the new node
    //     tail = new_node;
    //     //after the tail it's null
    //     tail->next = nullptr;
    // }
    // return;
}
template <typename T>
T cd_al<T>::replace( T element, size_t position)
{
    //COMPLETE
    // T replaced;
    // if(position == 0){
    //     replaced = pop_front();
    //     push_front(element);
    // }
    // else if(position + 1 == length()){
    //     replaced = pop_back();
    //     push_back(element);
    // }
    // else if (position + 1 > length()){
    //     std::domain_error d("The position requested does not exist");
    //     throw d;
    // }
    // else{
    //
    //     replaced = remove(position);
    //
    //     Node<T> * itr = new Node<T>;
    //     Node<T> * prev = new Node<T>;
    //
    //     itr = head;
    //     while(position + 1){
    //         prev = itr;
    //         itr = itr->next;
    //         --position;
    //     }
    //     Node<T> * new_node = new Node<T>;
    //     // new_node = itr;
    //     prev->next = new_node;
    //     new_node->data = element;
    //     new_node->next = itr;
    // }
    // return replaced;
}
template <typename T>
T cd_al<T>::remove(size_t position)
{
    //COMPLETE
    // T removed;
    // if(position == 0)
    // {
    //     removed = pop_front();
    // }
    // else if (position + 1 == length())
    // {
    //     removed = pop_back();
    // }
    // else if (position + 1 > length())
    // {
    //     std::domain_error d("The position requested does not exist");
    //     throw d;
    // }
    // else
    // {
    //     Node<T> * itr = new Node<T>;
    //     Node<T> * prev = new Node<T>;
    //
    //     itr = head->next;
    //     prev = head;
    //     while(position){
    //         itr = itr->next;
    //         prev = prev->next;
    //         --position;
    //     }
    //
    //     removed = itr->data;
    //     prev->next = itr->next;
    //     itr->next = nullptr;
    //     itr->data = NULL;
    //     delete itr;
    // }
    // return removed;
}
template <typename T>
T cd_al<T>::pop_back(void)
{
    //COMPLETE
    // T popped;
    // Node <T> * last_node = new Node<T>;
    // Node <T> * prev_node = new Node<T>;
    //
    // //traverse the list leaving prev one behind last
    // last_node = head;
    // while(last_node->next){
    //     prev_node = last_node;
    //     last_node = last_node->next;
    // }
    // //popped now contains the data to be deleted
    // popped = last_node->data;
    //
    // //tail is the previous which now points to null
    // tail = prev_node;
    // tail->next = nullptr;
    //
    // //zeroing out the data
    // last_node->data = NULL;
    // last_node->next = nullptr;
    // //deleting
    // delete last_node;
    //
    // return popped;

}
template <typename T>
T cd_al<T>::pop_front(void)
{
    //COMPLETE
    // T popped;
    // Node <T> * first_node = new Node<T>;
    //
    // first_node = head->next;
    // popped = first_node->data;
    //
    // head->next = first_node->next;
    //
    // return popped;

}
template <typename T>
T cd_al<T>::peek_back(void)
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
T cd_al<T>::peek_front(void)
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
bool cd_al<T>::is_empty(void)
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
bool cd_al<T>::is_full()
{
    //COMPLETE
    // return false;
}
template <typename T>
size_t cd_al<T>::length(void)
{
    size_t length = 0;
    Node_CDAL <T> * itr = head;

    while(itr){
        for (int i = 0; i < 50; ++i){
            length++;
        }
        itr = itr->next;
    }
    return length;

}
template <typename T>
void cd_al<T>::clear(void)
{

    Node_CDAL <T> * itr = head;

    while(itr){
        delete[] itr->data;
        itr = itr->next;
    }

    head = new Node_CDAL<T>;
    head->next = nullptr;


    return;
}
template <typename T>
void cd_al<T>::contains( T element/*, bool &equals_function()*/)
{
    //TODO


}
template <typename T>
bool equals_function(T element1/*, T element2*/)
{
    //TODO definitely not this
    // return element1 == element2;
}
template <typename T>
T * cd_al<T>::contents()
{
    //COMPLETE
    // T array [length()];
    // Node <T> * itr = head->next;
    //
    // for (int i = 0; i < length(); i++){
    //     array[i] = itr->data;
    //     itr = itr->next;
    // }
    //
    // return array;
}

template <typename T>
void cd_al<T>::print()
{
	Node_CDAL <T> * itr = head;

	std::cout << "Chained Dynamic Array List\n";
    unsigned int node_ctr = 1;
    while(itr){
        std::cout << "Node " << node_ctr<<": ";
        for (int i = 0; i < 50; ++i){
            std::cout << (itr->data)[i] << "->";
        }
        std::cout << "\n";
        itr = itr->next;
        node_ctr++;
    }

    std::cout <<"\n";
}
//HELPER functions
template <typename T>
size_t cd_al<T>::node_ctr(void)
{
    size_t ctr = 0;
    Node_CDAL <T> * itr = head;

    while(itr){
        ctr++;
        itr = itr->next;
    }
    return ctr;

}
template <typename T>
void cd_al<T>::create_node(void)
{
    Node_CDAL <T> * new_node = new Node_CDAL<T>;
    Node_CDAL <T> * prev_node = new Node_CDAL<T>;
    Node_CDAL <T> * curr_node = new Node_CDAL<T>;
    //set curr_node to represent the head
    curr_node = head;

    //cycle through the list until you reach the end, O(n)
    while(curr_node){
        //make prev_node represent the last node
        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    // //write data to the new node
    // tail = 0;
    // (new_node->data)[tail] = element;

    //if the list isn't empty
    if(prev_node){
        //make the last node point to the new node
        prev_node->next = new_node;
    }
    //if the list is empty
    else{
        //make the head point to the new node
        head->next = new_node;
    }
    new_node->next = nullptr;

    tail = 0;
}
