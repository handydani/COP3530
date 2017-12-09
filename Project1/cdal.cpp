#include "CDAL.h"
#include <iostream>
#include <stdexcept>

using namespace cop3530;
int main()
{
    CDAL<int> cda_list(10);
    std::cout << "~~~~~~~~~cdal has been created~~~~~~~~~\n";
    std::cout << "~~~~~~~~~testing pushing to the back~~~~~~~~~\n";

    cda_list.push_back(5);
    cda_list.push_back(4);
    cda_list.push_back(3);
    cda_list.push_back(2);
    cda_list.push_back(1);
    cda_list.print(std::cout);
    cda_list.push_back(10);
    cda_list.print(std::cout);

    std::cout << "~~~~~~~~~testing pushing to the front~~~~~~~~~\n";

    cda_list.clear();
    cda_list.push_front(5);
    cda_list.push_front(4);
    cda_list.push_front(3);
    cda_list.push_front(2);
    cda_list.push_front(1);
    cda_list.print(std::cout);
    cda_list.push_front(0);
    cda_list.print(std::cout);

    std::cout << "~~~~~~~~~testing insertion~~~~~~~~~\n";

    cda_list.print(std::cout);
    cda_list.insert(37, 0);
    cda_list.print(std::cout);
    cda_list.insert(37, 2);
    cda_list.insert(37, 4);
    cda_list.insert(37, 6);
    cda_list.insert(37, 8);
    cda_list.print(std::cout);

    try{
        cda_list.insert(37, 20);
    }catch (...){
        std::cout<< "exception caught: insertion at an index that does not exist\n";
    }

    std::cout << "~~~~~~~~~testing popping the front~~~~~~~~~\n";
    cda_list.print(std::cout);
    cda_list.pop_front();
    cda_list.pop_front();
    cda_list.pop_front();
    cda_list.pop_front();
    cda_list.print(std::cout);
    cda_list.clear();
    try{
        cda_list.pop_front();
    }catch (...){
        std::cout<< "exception caught: popping an empty list\n";
    }
    std::cout << "~~~~~~~~~testing popping the back~~~~~~~~~\n";
    int i = 5;
    while(i){
        cda_list.push_back(i);
        --i;
    }
    cda_list.print(std::cout);
    cda_list.pop_back();
    cda_list.pop_back();
    cda_list.pop_back();
    cda_list.print(std::cout);
    cda_list.clear();
    try{
        cda_list.pop_back();
    }catch (...){
        std::cout<< "exception caught: popping an empty list\n";
    }
    std::cout << "~~~~~~~~~testing removal~~~~~~~~~\n";
    i = 5;
    while(i){
        cda_list.push_back(i);
        --i;
    }
    cda_list.print(std::cout);

    // cda_list.remove(0);
    cda_list.remove(2);
    cda_list.print(std::cout);
    try{
        cda_list.remove(5);
    }catch (...){
        std::cout<< "exception caught: removing something that's not there \n";
    }
    std::cout << "~~~~~~~~~testing replacing~~~~~~~~~\n";
    cda_list.print(std::cout);
    cda_list.replace(37, 0);
    cda_list.replace(37, 2);
    cda_list.print(std::cout);
    try{
        cda_list.replace(37, 20);
    }catch (...){
        std::cout<< "exception caught: replacing something that's not there \n";
    }
    std::cout << "~~~~~~~~~testing contents~~~~~~~~~\n";

    cda_list.print(std::cout);

    int * array_pointer;
    std::cout << "the contents of the list as an array: ";
    for(int i = 0; i < cda_list.length(); i++){
        array_pointer = cda_list.contents();
        std::cout << array_pointer[i] << " ";
    }
    std::cout << "\n";
    std::cout << "~~~~~~~~~testing item at~~~~~~~~~\n";
    std::cout << "the item at 0: " << cda_list.item_at(0)<<"\n";
    std::cout << "the item at 1: " << cda_list.item_at(1)<<"\n";
    std::cout << "the item at 2: " << cda_list.item_at(2)<<"\n";

    std::cout << "~~~~~~~~~testing peeking~~~~~~~~~\n";
    std::cout << "peek front: " << cda_list.peek_front()<<"\n";
    std::cout << "peek back: " << cda_list.peek_back()<<"\n";

    std::cout << "~~~~~~~~~testing empty/fullness~~~~~~~~~\n";
    std::cout << "is empty? " << cda_list.is_empty()<<"\n";
    cda_list.clear();
    std::cout << "is empty after clearing? " << cda_list.is_empty()<<"\n";

    std::cout << "is full? " << cda_list.is_full()<<"\n";

    std::cout << "~~~~~~~~~testing length~~~~~~~~~\n";
    std::cout << "length of empty list? " << cda_list.length()<<"\n";
    i = 5;
    while(i){
        cda_list.push_back(i);
        --i;
    }
    std::cout << "length of list after pushing 5 times? " << cda_list.length()<<"\n";

    std::cout << "~~~~~~~~~testing pushing of list and dynamic resizing~~~~~~~~~\n";
    cda_list.print(std::cout);
    i = 0;
    while(i != 50){
        cda_list.push_back(i);
        i++;
    }
    cda_list.print(std::cout);
    std::cout << "~~~~~~~~~testing popping of list and dynamic resizing~~~~~~~~~\n";
    cda_list.print(std::cout);

    i = 0;
    while(i != 50){
        cda_list.pop_back();
        i++;
    }
    cda_list.print(std::cout);

}
