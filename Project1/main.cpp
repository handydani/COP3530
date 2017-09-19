#include "ss_ll.h"
#include <iostream>
#include <stdexcept>
using namespace cop3530;
int main()
{

    std::cout <<"Hello World" <<std::endl;
    // ss_ll<int> newList(0);

    newList.insert(3, 0);
    newList.insert(2, 1);
    newList.push_back(1);
    newList.print();

    std::cout << newList.peek_back() << "\n";
    std::cout << newList.peek_front() << "\n";
    std::cout << newList.is_empty() << "\n";
    std::cout << newList.length() << "\n";
    std::cout << newList.pop_front() << "\n";
    newList.push_back(5);
    newList.print();
    std::cout << newList.remove(1) << "\n";
    newList.print();
    std::cout << newList.length() << "\n";

    std::cout << newList.pop_back() << "\n";
    std::cout << newList.pop_back() << "\n";
    std::cout << newList.length() << "\n";

    newList.print();
    newList.push_back(1);
    newList.push_back(2);
    newList.push_back(3);
    newList.push_back(4);
    newList.push_back(5);
    newList.print();
    newList.insert(37, 0);
    newList.print();

    newList.insert(37, 2);
    newList.print();

    newList.insert(37, 4);
    newList.print();

    newList.insert(37, 6);
    newList.print();

    newList.insert(37, 8);
    newList.print();

    newList.replace(74, 0);
    newList.replace(74, 2);
    newList.replace(74, 4);
    newList.replace(74, 6);
    newList.replace(74, 8);
    newList.replace(74, 9);
    try{
        newList.replace(74, 10);
        std::cout<< "checkpoint\n";
    }catch (...){
        std::cout<< "exception caught\n";

    }





    return 0;
}
