#include "SSLL.h"
#include <iostream>
#include <stdexcept>

using namespace cop3530;
int main()
{
    SSLL<int> ssl_list(0);
    std::cout << "~~~~~~~~~ssll has been created~~~~~~~~~\n";
    std::cout << "~~~~~~~~~testing pushing to the front~~~~~~~~~\n";

    ssl_list.push_front(5);
    ssl_list.push_front(4);
    ssl_list.push_front(3);
    ssl_list.push_front(2);
    ssl_list.push_front(1);
    ssl_list.print(std::cout);
    ssl_list.push_front(0);
    ssl_list.print(std::cout);

    std::cout << "~~~~~~~~~testing pushing to the back~~~~~~~~~\n";

    ssl_list.clear();
    ssl_list.push_back(5);
    ssl_list.push_back(4);
    ssl_list.push_back(3);
    ssl_list.push_back(2);
    ssl_list.push_back(1);
    ssl_list.print(std::cout);
    ssl_list.push_back(0);
    ssl_list.print(std::cout);

    std::cout << "~~~~~~~~~testing insertion~~~~~~~~~\n";

    ssl_list.print(std::cout);
    ssl_list.insert(37, 0);
    ssl_list.print(std::cout);
    ssl_list.insert(37, 2);
    ssl_list.insert(37, 4);
    ssl_list.insert(37, 6);
    ssl_list.insert(37, 8);
    ssl_list.print(std::cout);

    try{
        ssl_list.insert(37, 20);
    }catch (...){
        std::cout<< "exception caught: insertion at an index that does not exist\n";
    }

    std::cout << "~~~~~~~~~testing popping the front~~~~~~~~~\n";
    ssl_list.print(std::cout);
    ssl_list.pop_front();
    ssl_list.pop_front();
    ssl_list.pop_front();
    ssl_list.pop_front();
    ssl_list.print(std::cout);
    ssl_list.clear();
    try{
        ssl_list.pop_front();
    }catch (...){
        std::cout<< "exception caught: popping an empty list\n";
    }
    std::cout << "~~~~~~~~~testing popping the back~~~~~~~~~\n";
    int i = 5;
    while(i){
        ssl_list.push_back(i);
        --i;
    }
    ssl_list.print(std::cout);
    ssl_list.pop_back();
    ssl_list.pop_back();
    ssl_list.pop_back();
    ssl_list.print(std::cout);
    ssl_list.clear();
    try{
        ssl_list.pop_back();
    }catch (...){
        std::cout<< "exception caught: popping an empty list\n";
    }
    std::cout << "~~~~~~~~~testing removal~~~~~~~~~\n";
    i = 5;
    while(i){
        ssl_list.push_back(i);
        --i;
    }
    ssl_list.print(std::cout);

    ssl_list.remove(0);
    ssl_list.remove(2);
    ssl_list.print(std::cout);
    try{
        ssl_list.remove(5);
    }catch (...){
        std::cout<< "exception caught: removing something that's not there \n";
    }
    std::cout << "~~~~~~~~~testing replacing~~~~~~~~~\n";
    ssl_list.print(std::cout);
    ssl_list.replace(37, 0);
    ssl_list.replace(37, 2);
    ssl_list.print(std::cout);

    try{
        ssl_list.replace(37, 20);
    }catch (...){
        std::cout<< "exception caught: replacing something that's not there \n";
    }
    std::cout << "~~~~~~~~~testing contents~~~~~~~~~\n";

    ssl_list.print(std::cout);

    int * array_pointer;
    std::cout << "the contents of the list as an array: ";
    for(int i = 0; i < ssl_list.length(); i++){
        array_pointer = ssl_list.contents();
        std::cout << array_pointer[i] << " ";
    }
    std::cout << "\n";
    std::cout << "~~~~~~~~~testing item at~~~~~~~~~\n";
    std::cout << "the item at 0: " << ssl_list.item_at(0)<<"\n";
    std::cout << "the item at 1: " << ssl_list.item_at(1)<<"\n";
    std::cout << "the item at 2: " << ssl_list.item_at(2)<<"\n";

    std::cout << "~~~~~~~~~testing peeking~~~~~~~~~\n";
    std::cout << "peek front: " << ssl_list.peek_front()<<"\n";
    std::cout << "peek back: " << ssl_list.peek_back()<<"\n";

    std::cout << "~~~~~~~~~testing empty/fullness~~~~~~~~~\n";
    std::cout << "is empty? " << ssl_list.is_empty()<<"\n";
    ssl_list.clear();
    std::cout << "is empty after clearing? " << ssl_list.is_empty()<<"\n";

    std::cout << "is full? " << ssl_list.is_full()<<"\n";

    std::cout << "~~~~~~~~~testing length~~~~~~~~~\n";
    std::cout << "length of empty list? " << ssl_list.length()<<"\n";
    i = 5;
    while(i){
        ssl_list.push_back(i);
        --i;
    }
    std::cout << "length of list after pushing 5 times? " << ssl_list.length()<<"\n";

}
