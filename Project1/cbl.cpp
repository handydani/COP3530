#include "CBL.h"
#include <iostream>
#include <stdexcept>

using namespace cop3530;
int main()
{
    CBL<int> cb_list(10);
    std::cout << "~~~~~~~~~cbl has been created~~~~~~~~~\n";
    std::cout << "~~~~~~~~~testing pushing to the front~~~~~~~~~\n";

    cb_list.push_front(5);
    cb_list.push_front(4);
    cb_list.push_front(3);
    cb_list.push_front(2);
    cb_list.push_front(1);
    cb_list.print(std::cout);
    cb_list.push_front(0);
    cb_list.print(std::cout);

    std::cout << "~~~~~~~~~testing pushing to the back~~~~~~~~~\n";

    cb_list.clear();
    cb_list.push_back(5);
    cb_list.push_back(4);
    cb_list.push_back(3);
    cb_list.push_back(2);
    cb_list.push_back(1);
    cb_list.print(std::cout);
    cb_list.push_back(0);
    cb_list.print(std::cout);

    std::cout << "~~~~~~~~~testing insertion~~~~~~~~~\n";

    cb_list.print(std::cout);
    cb_list.insert(37, 0);
    cb_list.print(std::cout);
    cb_list.insert(37, 2);
    cb_list.insert(37, 4);
    cb_list.insert(37, 6);
    cb_list.insert(37, 8);
    cb_list.print(std::cout);

    try{
        cb_list.insert(37, 20);
    }catch (...){
        std::cout<< "exception caught: insertion at an index that does not exist\n";
    }

    std::cout << "~~~~~~~~~testing popping the front~~~~~~~~~\n";
    cb_list.print(std::cout);
    cb_list.pop_front();
    cb_list.pop_front();
    cb_list.pop_front();
    cb_list.pop_front();
    cb_list.print(std::cout);
    cb_list.clear();
    try{
        cb_list.pop_front();
    }catch (...){
        std::cout<< "exception caught: popping an empty list\n";
    }
    std::cout << "~~~~~~~~~testing popping the back~~~~~~~~~\n";
    int i = 5;
    while(i){
        cb_list.push_back(i);
        --i;
    }
    cb_list.print(std::cout);
    cb_list.pop_back();
    cb_list.pop_back();
    cb_list.pop_back();
    cb_list.print(std::cout);
    cb_list.clear();
    try{
        cb_list.pop_back();
    }catch (...){
        std::cout<< "exception caught: popping an empty list\n";
    }
    std::cout << "~~~~~~~~~testing removal~~~~~~~~~\n";
    i = 5;
    while(i){
        cb_list.push_back(i);
        --i;
    }
    cb_list.print(std::cout);

    cb_list.remove(0);
    cb_list.remove(2);
    cb_list.print(std::cout);
    try{
        cb_list.remove(5);
    }catch (...){
        std::cout<< "exception caught: removing something that's not there \n";
    }
    std::cout << "~~~~~~~~~testing replacing~~~~~~~~~\n";
    cb_list.print(std::cout);
    cb_list.replace(37, 0);
    cb_list.replace(37, 2);
    cb_list.print(std::cout);

    try{
        cb_list.replace(37, 20);
    }catch (...){
        std::cout<< "exception caught: replacing something that's not there \n";
    }
    std::cout << "~~~~~~~~~testing contents~~~~~~~~~\n";

    cb_list.print(std::cout);

    int * array_pointer;
    std::cout << "the contents of the list as an array: ";
    for(int i = 0; i < cb_list.length(); i++){
        array_pointer = cb_list.contents();
        std::cout << array_pointer[i] << " ";
    }
    std::cout << "\n";
    std::cout << "~~~~~~~~~testing item at~~~~~~~~~\n";
    std::cout << "the item at 0: " << cb_list.item_at(0)<<"\n";
    std::cout << "the item at 1: " << cb_list.item_at(1)<<"\n";
    std::cout << "the item at 2: " << cb_list.item_at(2)<<"\n";

    std::cout << "~~~~~~~~~testing peeking~~~~~~~~~\n";
    std::cout << "peek front: " << cb_list.peek_front()<<"\n";
    std::cout << "peek back: " << cb_list.peek_back()<<"\n";

    std::cout << "~~~~~~~~~testing empty/fullness~~~~~~~~~\n";
    std::cout << "is empty? " << cb_list.is_empty()<<"\n";
    cb_list.clear();
    std::cout << "is empty after clearing? " << cb_list.is_empty()<<"\n";

    std::cout << "is full? " << cb_list.is_full()<<"\n";

    std::cout << "~~~~~~~~~testing length~~~~~~~~~\n";
    std::cout << "length of empty list? " << cb_list.length()<<"\n";
    i = 5;
    while(i){
        cb_list.push_back(i);
        --i;
    }
    std::cout << "length of list after pushing 5 times? " << cb_list.length()<<"\n";

}
