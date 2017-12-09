#include "PSLL.h"
#include <iostream>
#include <stdexcept>

using namespace cop3530;
int main()
{
    PSLL<int> pss_list(10);
    std::cout << "~~~~~~~~~psll has been created~~~~~~~~~\n";
    std::cout << "~~~~~~~~~testing pushing to the back~~~~~~~~~\n";

    pss_list.push_back(5);
    pss_list.push_back(4);
    pss_list.push_back(3);
    pss_list.push_back(2);
    pss_list.push_back(1);
    pss_list.print(std::cout);
    pss_list.push_back(0);
    pss_list.print(std::cout);

    std::cout << "~~~~~~~~~testing pushing to the front~~~~~~~~~\n";

    pss_list.clear();
    pss_list.push_front(5);
    pss_list.push_front(4);
    pss_list.push_front(3);
    pss_list.push_front(2);
    pss_list.push_front(1);
    pss_list.print(std::cout);
    pss_list.push_front(0);
    pss_list.print(std::cout);

    std::cout << "~~~~~~~~~testing insertion~~~~~~~~~\n";

    pss_list.print(std::cout);
    pss_list.insert(37, 0);
    pss_list.print(std::cout);
    pss_list.insert(37, 2);
    pss_list.insert(37, 4);
    pss_list.insert(37, 6);
    pss_list.insert(37, 8);
    pss_list.print(std::cout);

    try{
        pss_list.insert(37, 20);
    }catch (...){
        std::cout<< "exception caught: insertion at an index that does not exist\n";
    }

    std::cout << "~~~~~~~~~testing popping the front~~~~~~~~~\n";
    pss_list.print(std::cout);
    std::cout << "popping the front causes a seg fault\n";
    // pss_list.pop_front();
    // pss_list.pop_front();
    // pss_list.pop_front();
    // pss_list.pop_front();
    // pss_list.print(std::cout);
    // pss_list.clear();
    // try{
    //     pss_list.pop_front();
    // }catch (...){
    //     std::cout<< "exception caught: popping an empty list\n";
    // }
    std::cout << "~~~~~~~~~testing popping the back~~~~~~~~~\n";
    int i = 5;
    while(i){
        pss_list.push_back(i);
        --i;
    }
    pss_list.print(std::cout);
    pss_list.pop_back();
    pss_list.pop_back();
    pss_list.pop_back();
    pss_list.print(std::cout);
    pss_list.clear();
    try{
        pss_list.pop_back();
    }catch (...){
        std::cout<< "exception caught: popping an empty list\n";
    }
    std::cout << "~~~~~~~~~testing removal~~~~~~~~~\n";
    i = 5;
    while(i){
        pss_list.push_back(i);
        --i;
    }
    pss_list.print(std::cout);

    // pss_list.remove(0);
    pss_list.remove(2);
    pss_list.print(std::cout);
    try{
        pss_list.remove(5);
    }catch (...){
        std::cout<< "exception caught: removing something that's not there \n";
    }
    std::cout << "~~~~~~~~~testing replacing~~~~~~~~~\n";
    pss_list.print(std::cout);
    std::cout << "replacing causes a seg fault\n";

    try{
        pss_list.replace(37, 20);
    }catch (...){
        std::cout<< "exception caught: replacing something that's not there \n";
    }
    std::cout << "~~~~~~~~~testing contents~~~~~~~~~\n";

    pss_list.print(std::cout);

    int * array_pointer;
    std::cout << "the contents of the list as an array: ";
    for(int i = 0; i < pss_list.length(); i++){
        array_pointer = pss_list.contents();
        std::cout << array_pointer[i] << " ";
    }
    std::cout << "\n";
    std::cout << "contents is messed up as you can see\n";

    std::cout << "~~~~~~~~~testing item at~~~~~~~~~\n";
    std::cout << "the item at 0: " << pss_list.item_at(0)<<"\n";
    std::cout << "the item at 1: " << pss_list.item_at(1)<<"\n";
    std::cout << "the item at 2: " << pss_list.item_at(2)<<"\n";
    std::cout << "item_at is messed up as you can see\n";

    std::cout << "~~~~~~~~~testing peeking~~~~~~~~~\n";
    std::cout << "peek front: " << pss_list.peek_front()<<"\n";
    std::cout << "peek back: " << pss_list.peek_back()<<"\n";

    std::cout << "~~~~~~~~~testing empty/fullness~~~~~~~~~\n";
    std::cout << "is empty? " << pss_list.is_empty()<<"\n";
    pss_list.clear();
    std::cout << "is empty after clearing? " << pss_list.is_empty()<<"\n";

    std::cout << "is full? " << pss_list.is_full()<<"\n";

    std::cout << "~~~~~~~~~testing length~~~~~~~~~\n";
    std::cout << "length of empty list? " << pss_list.length()<<"\n";
    i = 5;
    while(i){
        pss_list.push_back(i);
        --i;
    }
    std::cout << "length of list after pushing 5 times? " << pss_list.length()<<"\n";


}
