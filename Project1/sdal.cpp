#include "SDAL.h"
#include <iostream>
#include <stdexcept>

using namespace cop3530;
int main()
{
    SDAL<int> sda_list(10);
    std::cout << "~~~~~~~~~ssll has been created~~~~~~~~~\n";
    std::cout << "~~~~~~~~~testing pushing to the back~~~~~~~~~\n";

    sda_list.push_back(5);
    sda_list.push_back(4);
    sda_list.push_back(3);
    sda_list.push_back(2);
    sda_list.push_back(1);
    sda_list.print(std::cout);
    sda_list.push_back(0);
    sda_list.print(std::cout);

    std::cout << "~~~~~~~~~testing pushing to the front~~~~~~~~~\n";

    sda_list.clear();
    sda_list.push_back(5);
    sda_list.push_back(4);
    sda_list.push_back(3);
    sda_list.push_back(2);
    sda_list.push_back(1);
    sda_list.print(std::cout);
    sda_list.push_back(0);
    sda_list.print(std::cout);

    std::cout << "~~~~~~~~~testing insertion~~~~~~~~~\n";

    sda_list.print(std::cout);
    sda_list.insert(37, 0);
    sda_list.print(std::cout);
    sda_list.insert(37, 2);
    sda_list.insert(37, 4);
    sda_list.insert(37, 6);
    sda_list.insert(37, 8);
    sda_list.print(std::cout);

    try{
        sda_list.insert(37, 20);
    }catch (...){
        std::cout<< "exception caught: insertion at an index that does not exist\n";
    }

    std::cout << "~~~~~~~~~testing popping the front~~~~~~~~~\n";
    sda_list.print(std::cout);
    sda_list.pop_front();
    sda_list.pop_front();
    sda_list.pop_front();
    sda_list.pop_front();
    sda_list.print(std::cout);
    sda_list.clear();
    try{
        sda_list.pop_front();
    }catch (...){
        std::cout<< "exception caught: popping an empty list\n";
    }
    std::cout << "~~~~~~~~~testing popping the back~~~~~~~~~\n";
    int i = 5;
    while(i){
        sda_list.push_back(i);
        --i;
    }
    sda_list.print(std::cout);
    sda_list.pop_back();
    sda_list.pop_back();
    sda_list.pop_back();
    sda_list.print(std::cout);
    sda_list.clear();
    try{
        sda_list.pop_back();
    }catch (...){
        std::cout<< "exception caught: popping an empty list\n";
    }
    std::cout << "~~~~~~~~~testing removal~~~~~~~~~\n";
    i = 5;
    while(i){
        sda_list.push_back(i);
        --i;
    }
    sda_list.print(std::cout);

    sda_list.remove(0);
    sda_list.remove(2);
    sda_list.print(std::cout);
    try{
        sda_list.remove(5);
    }catch (...){
        std::cout<< "exception caught: removing something that's not there \n";
    }
    std::cout << "~~~~~~~~~testing replacing~~~~~~~~~\n";
    sda_list.print(std::cout);
    sda_list.replace(37, 0);
    sda_list.replace(37, 2);
    sda_list.print(std::cout);

    try{
        sda_list.replace(37, 20);
    }catch (...){
        std::cout<< "exception caught: replacing something that's not there \n";
    }
    std::cout << "~~~~~~~~~testing contents~~~~~~~~~\n";

    sda_list.print(std::cout);

    int * array_pointer;
    std::cout << "the contents of the list as an array: ";
    for(int i = 0; i < sda_list.length(); i++){
        array_pointer = sda_list.contents();
        std::cout << array_pointer[i] << " ";
    }
    std::cout << "\n";
    std::cout << "~~~~~~~~~testing item at~~~~~~~~~\n";
    std::cout << "the item at 0: " << sda_list.item_at(0)<<"\n";
    std::cout << "the item at 1: " << sda_list.item_at(1)<<"\n";
    std::cout << "the item at 2: " << sda_list.item_at(2)<<"\n";

    std::cout << "~~~~~~~~~testing peeking~~~~~~~~~\n";
    std::cout << "peek front: " << sda_list.peek_front()<<"\n";
    std::cout << "peek back: " << sda_list.peek_back()<<"\n";

    std::cout << "~~~~~~~~~testing empty/fullness~~~~~~~~~\n";
    std::cout << "is empty? " << sda_list.is_empty()<<"\n";
    sda_list.clear();
    std::cout << "is empty after clearing? " << sda_list.is_empty()<<"\n";

    std::cout << "is full? " << sda_list.is_full()<<"\n";

    std::cout << "~~~~~~~~~testing length~~~~~~~~~\n";
    std::cout << "length of empty list? " << sda_list.length()<<"\n";
    i = 5;
    while(i){
        sda_list.push_back(i);
        --i;
    }
    std::cout << "length of list after pushing 5 times? " << sda_list.length()<<"\n";

    std::cout << "~~~~~~~~~testing allocation to the list~~~~~~~~~\n";

}
