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
//TODO check for redundancies with contents() function and creating a new node
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
    // COMPLETE
    if(position == 0)
    {
        push_front(element);
        return;
    }
    else if (position > length())
    {
        std::domain_error d("The position requested does not exist");
        throw d;
    }
    else
    {
        if(tail == 50)
        {
            //new node is needed
            // tail = 50
            // new node must be added
            // copy element and contents to array[0->length()]
            // copy array contents back to the nodes

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
            tail = 0;
        }

        T * content_array = new T[node_ctr() * 50];
        Node_CDAL <T> * itr = head;

        //while loop to iterate through each node and a for loop to iterate through each array
        unsigned int ca_index_start = 0;
        unsigned int ca_index_end = 50; //these variables are updated so that the content array will be accessed at the right points

        while(itr){
            for(int i = ca_index_start, j = 0; j < 50; ++i, ++j){ // i = [0, 49], j = [0, 49]; i = [50, 99], j = [0,49]
                content_array[i] = (itr->data)[j];
            }
            ca_index_start = ca_index_end;
            ca_index_end += 50;
            itr = itr->next;
        }
        //at this point content_array should contain all of the contents

        for(int i = length() + 1; i >= position; --i){
            content_array[i] = content_array[i-1];
        }

        content_array[position] = element;
        //reset variables
        itr = head;
        ca_index_start = 0;
        ca_index_end = 50;

        //copying content array back to the nodes with the element
        while(itr){
            for(int i = 0, j = ca_index_start; i < 50; ++i, ++j){
                (itr->data)[i] = content_array[j];
            }
            ca_index_start = ca_index_end;
            ca_index_end += 50;
            itr = itr->next;
        }

        ++tail;
        return;
    }
}
template <typename T>
void cd_al<T>::push_back(T element)
{
    //tail must be less than 50
    //item must be pushed to the first node, next nodes, and the last node,
    if (tail < 50){
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
    if(tail == 50)
    {
        // tail = 50
        // new node must be added
        // copy element and contents to array[0->length()]
        // copy array contents back to the nodes
        // tail = 1

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
        tail = 0;
    }


    T * content_array = new T[node_ctr() * 50];
    Node_CDAL <T> * itr = head;
    content_array[0] = element; //adding element to content_array

    //while loop to iterate through each node and a for loop to iterate through each array
    unsigned int ca_index_start = 1;
    unsigned int ca_index_end = 50; //these variables are updated so that the content array will be accessed at the right points

    while(itr){
        for(int i = ca_index_start, j = 0; j < 50; ++i, ++j){ // i = [1, 50], j = [0, 49]; i = [51, 99], j = [0,49]
            content_array[i] = (itr->data)[j];
        }
        ca_index_start = ca_index_end + 1;
        ca_index_end += 50;
        itr = itr->next;
    }
    //at this point content_array should contain all of the contents

    //reset variables
    itr = head;
    ca_index_start = 0;
    ca_index_end = 50;

    //copying content array back to the nodes with the element
    while(itr){
        for(int i = 0, j = ca_index_start; i < 50; ++i, ++j){
            (itr->data)[i] = content_array[j];
        }
        ca_index_start = ca_index_end;
        ca_index_end += 50;
        itr = itr->next;
    }

    ++tail; //TODO check for cases in which pushing to the front fails?
    return;
}
template <typename T>
T cd_al<T>::replace( T element, size_t position)
{
    T replaced;
    if (position + 1 > length()){
        std::domain_error d("The position requested does not exist");
        throw d;
    }
    else{

        T * content_array = new T[node_ctr() * 50];
        Node_CDAL <T> * itr = head;

        //while loop to iterate through each node and a for loop to iterate through each array
        unsigned int ca_index_start = 0;
        unsigned int ca_index_end = 50; //these variables are updated so that the content array will be accessed at the right points

        while(itr){
            for(int i = ca_index_start, j = 0; j < 50; ++i, ++j){ // i = [0, 49], j = [0, 49]; i = [50, 99], j = [0,49]
                content_array[i] = (itr->data)[j];
            }
            ca_index_start = ca_index_end;
            ca_index_end += 50;
            itr = itr->next;
        }
        //at this point content_array should contain all of the contents
        replaced = content_array[position];
        content_array[position] = element;
        //copy back
        //reset variables
        itr = head;
        ca_index_start = 0;
        ca_index_end = 50;

        //copying content array back to the nodes with the element
        while(itr){
            for(int i = 0, j = ca_index_start; i < 50; ++i, ++j){
                (itr->data)[i] = content_array[j];
            }
            ca_index_start = ca_index_end;
            ca_index_end += 50;
            itr = itr->next;
        }

    }
    return replaced;
}
template <typename T>
T cd_al<T>::remove(size_t position)
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
        std::domain_error d("The position requested does not exist");
        throw d;
    }
    else
    {
        T * content_array = new T[node_ctr() * 50];
        Node_CDAL <T> * itr = head;

        //while loop to iterate through each node and a for loop to iterate through each array
        unsigned int ca_index_start = 0;
        unsigned int ca_index_end = 50; //these variables are updated so that the content array will be accessed at the right points

        while(itr){
            for(int i = ca_index_start, j = 0; j < 50; ++i, ++j){ // i = [0, 49], j = [0, 49]; i = [50, 99], j = [0,49]
                content_array[i] = (itr->data)[j];
            }
            ca_index_start = ca_index_end;
            ca_index_end += 50;
            itr = itr->next;
        }
        //at this point content_array should contain all of the contents
        removed = content_array[position];
        for(int i = position; i < length(); ++i){ //do you have to use length -1?
            content_array[i] = content_array[i+1];
        }

        //reset variables
        itr = head;
        ca_index_start = 0;
        ca_index_end = 50;

        //copying content array back to the nodes with the element
        while(itr){
            for(int i = 0, j = ca_index_start; i < 50; ++i, ++j){
                (itr->data)[i] = content_array[j];
            }
            ca_index_start = ca_index_end;
            ca_index_end += 50;
            itr = itr->next;
        }

        if(tail > 1)
            --tail;
        else{
            tail = 50;
            Node_CDAL <T> * last_node = head;
            Node_CDAL <T> * prev_node = new Node_CDAL<T>;

            //traverse the list leaving prev one behind last
            last_node = head;
            while(last_node->next){
                prev_node = last_node;
                last_node = last_node->next;
            }
            prev_node->next = nullptr;

            //zeroing out the data
            last_node->data = NULL;
            last_node->next = nullptr;
            //deleting
            delete last_node;
        }
    }
    return removed;
}
template <typename T>
T cd_al<T>::pop_back(void)
{
    //TODO throw error if trying to pop an empty list
    T popped;
    Node_CDAL <T> * itr = head;
    while(itr->next){
        itr = itr->next;
    }
    popped = (itr->data)[tail - 1];
    (itr->data)[tail - 1] = 0;
    if(tail > 1)
        --tail;
    else{
        tail = 50;
        Node_CDAL <T> * last_node = head;
        Node_CDAL <T> * prev_node = new Node_CDAL<T>;

        //traverse the list leaving prev one behind last
        last_node = head;
        while(last_node->next){
            prev_node = last_node;
            last_node = last_node->next;
        }
        prev_node->next = nullptr;

        //zeroing out the data
        last_node->data = NULL;
        last_node->next = nullptr;
        //deleting
        delete last_node;
    }

    return popped;

}
template <typename T>
T cd_al<T>::pop_front(void)
{
    T popped = (head->data)[0];

    T * content_array = new T[node_ctr() * 50];
    Node_CDAL <T> * itr = head;

    //while loop to iterate through each node and a for loop to iterate through each array
    unsigned int ca_index_start = 0;
    unsigned int ca_index_end = 50; //these variables are updated so that the content array will be accessed at the right points

    while(itr){
        for(int i = ca_index_start, j = 0; j < 50; ++i, ++j){ // i = [0, 49], j = [0, 49]; i = [51, 99], j = [0,49]
            content_array[i] = (itr->data)[j];
        }
        ca_index_start = ca_index_end;
        ca_index_end += 50;
        itr = itr->next;
    }
    //at this point content_array should contain all of the contents

    //reset variables
    itr = head;
    ca_index_start = 1;
    ca_index_end = 50;

    //copying content array back to the nodes with the element
    while(itr){
        for(int i = 0, j = ca_index_start; i < 50; ++i, ++j){ //i = [0, 49], j = [1, 50]; i = [0, 49], j = [51, 100]
            (itr->data)[i] = content_array[j];
        }
        ca_index_start = ca_index_end + 1;
        ca_index_end += 50;
        itr = itr->next;
    }

    if(tail > 1)
        --tail;
    else{
        tail = 50;
        Node_CDAL <T> * last_node = head;
        Node_CDAL <T> * prev_node = new Node_CDAL<T>;

        //traverse the list leaving prev one behind last
        last_node = head;
        while(last_node->next){
            prev_node = last_node;
            last_node = last_node->next;
        }
        prev_node->next = nullptr;

        //zeroing out the data
        last_node->data = NULL;
        last_node->next = nullptr;
        //deleting
        delete last_node;

    }

    return popped;

}
template <typename T>
T cd_al<T>::peek_back(void)
{
    Node_CDAL <T> * itr = head;
    T peeked = 0;

    while(itr->next){
        itr = itr->next;
    }
    peeked = (itr->data)[tail - 1];

    return peeked;
}
template <typename T>
T cd_al<T>::peek_front(void)
{
    T peeked = (head->data)[0];
    return peeked;
}
template <typename T>
bool cd_al<T>::is_empty(void)
{
    return ((tail == 0) && (node_ctr() == 1));
}
template <typename T>
bool cd_al<T>::is_full()
{
    return (tail == 50);
}
template <typename T>
size_t cd_al<T>::length(void)
{
    size_t length = 0;
    Node_CDAL <T> * itr = head;

    while(itr->next){
        for (int i = 0; i < 50; ++i){
            length++;
        }
        itr = itr->next;
    }
    int i = tail;
    while(i){
        length++;
        i--;
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
    tail = 0;

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
    T * content_array = new T[node_ctr() * 50];
    Node_CDAL <T> * itr = head;

    //while loop to iterate through each node and a for loop to iterate through each array
    unsigned int ca_index_start = 0;
    unsigned int ca_index_end = 50; //these variables are updated so that the content array will be accessed at the right points

    while(itr){
        for(int i = ca_index_start, j = 0; j < 50; ++i, ++j){ // i = [0, 49], j = [0, 49]; i = [50, 99], j = [0,49]
            content_array[i] = (itr->data)[j];
        }
        ca_index_start = ca_index_end;
        ca_index_end += 50;
        itr = itr->next;
    }

    return &content_array[0];
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
// _____________
// < helper fxns >
// -------------
//        \   ^__^
//         \  (oo)\_______
//            (__)\       )\/\
//                ||----w |
//                ||     ||
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
