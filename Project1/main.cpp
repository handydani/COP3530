#include "ss_ll.h"
#include <iostream>
#include <stdexcept>
#include "sd_al.h"
#include "node.h"
using namespace cop3530;
int main()
{

    std::cout <<"Hello World" <<std::endl;
    ss_ll<int> newList(0);

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
    newList.replace(37, 0);
    newList.print();

    // this prints the contents of the list as an array
    int * array_pointer;
    for(int i = 0; i < newList.length(); i++){
        array_pointer = newList.contents();
        std::cout << array_pointer[i] << " ";
    }
    std::cout << "\n ";


    newList.clear();
    newList.print();
    std::cout << "This is now a simple dynamic array list"<<std::endl;
    sd_al<int> newSDALList(10);
    newSDALList.push_back(1);
    newSDALList.push_back(2);
    newSDALList.push_back(3);
    newSDALList.push_back(4);
    newSDALList.push_front(5);
    newSDALList.print();

    newSDALList.insert(6, 5);
    newSDALList.insert(12, 0);
    newSDALList.insert(2, 1);

    newSDALList.print();
    std::cout << newSDALList.pop_back() << std::endl;
    newSDALList.print();

    std::cout << newSDALList.pop_front() << std::endl;
    newSDALList.print();

    std::cout << "testing remove list"<<std::endl;

    std::cout << newSDALList.remove(1) << std::endl;
    newSDALList.print();

    std::cout << newSDALList.remove(0) << std::endl;
    newSDALList.print();

    std::cout << newSDALList.remove(3) << std::endl;
    newSDALList.print();

    std::cout << "testing replace list"<<std::endl;

    std::cout << newSDALList.replace(37, 0) << std::endl;
    newSDALList.print();

    std::cout << newSDALList.replace(38, 1) << std::endl;
    newSDALList.print();

    std::cout << newSDALList.replace(39, 2) << std::endl;
    newSDALList.print();
    std::cout << newSDALList.replace(40, 3) << std::endl;

    newSDALList.print();

    std::cout << "------testing allocation of list------"<<std::endl;

    newSDALList.push_back(40);
    newSDALList.push_back(41);
    newSDALList.push_back(42);
    newSDALList.push_back(43);
    newSDALList.push_back(44);
    newSDALList.push_back(45);
    newSDALList.print();

    std::cout << "The length of the list is " << newSDALList.length() << std::endl;

    newSDALList.push_back(46);
    std::cout << "The length of the list is " << newSDALList.length() << std::endl;
    newSDALList.print();

    newSDALList.push_back(47);

    newSDALList.print();
    std::cout << "The length of the list is " << newSDALList.length() << std::endl;


    std::cout << "------testing deallocation of list------"<<std::endl;

    sd_al<int> deallSDALList(100);
    deallSDALList.push_back(40);
    deallSDALList.push_back(41);
    deallSDALList.push_back(42);
    deallSDALList.push_back(43);
    deallSDALList.push_back(44);
    deallSDALList.push_back(45);
    deallSDALList.print();

    std::cout << "The length of the list is " << deallSDALList.length() << std::endl;
    deallSDALList.pop_back();
    deallSDALList.print();

    std::cout << "------testing clearing of list------"<<std::endl;

    deallSDALList.clear();
    deallSDALList.print();
    // std::cout << "------testing deletion of list------"<<std::endl;
    // lol
    // deallSDALList.~sd_al<int>();

    

    return 0;
}
