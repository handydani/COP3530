#include "ss_ll.h"
#include <iostream>
#include <stdexcept>
#include "sd_al.h"
#include "cd_al.h"
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
    // lol this wont work
    // deallSDALList.~sd_al<int>();


    std::cout << "This is now a chained dynamic array list"<<std::endl;
    cd_al<int> CDALList(0);

    CDALList.print();
    std::cout << "------testing pushing back of list and dynamic resizing------"<<std::endl;

    int i = 0;
    while(i != 50){
        CDALList.push_back(i);
        i++;
    }
    CDALList.print();
    std::cout << CDALList.length()<<"\n";
    std::cout << CDALList.node_ctr()<<"\n";

    i = 50;
    while(i != 100){
        CDALList.push_back(i);
        i++;
    }
    CDALList.print();


    i = 100;
    while(i != 150){
        CDALList.push_back(i);
        i++;
    }
    CDALList.print();
    std::cout << CDALList.length()<<"\n";
    std::cout << CDALList.node_ctr()<<"\n";

    std::cout << "------testing clearing of list------"<<std::endl;

    CDALList.clear();
    CDALList.print();


    std::cout << "------testing pushing to the front of the list------"<<std::endl;
    cd_al<int> NewCDALList(0);

    NewCDALList.push_back(1);
    NewCDALList.push_back(1);
    NewCDALList.push_back(1);
    NewCDALList.push_back(1);
    NewCDALList.push_back(1);
    NewCDALList.print();
    NewCDALList.push_front(2);

    NewCDALList.push_front(3);

    NewCDALList.push_front(4);

    NewCDALList.push_front(5);
    NewCDALList.print();
    NewCDALList.push_front(3);
    NewCDALList.push_front(3);
    NewCDALList.push_front(3);
    NewCDALList.push_front(3);
    NewCDALList.print();

    i = 0;
    while(i != 86){
        NewCDALList.push_back(i);
        i++;
    }
    NewCDALList.push_front(5);
    NewCDALList.push_front(5);
    NewCDALList.print();


    std::cout << "------testing the length of the list------"<<std::endl;

    std::cout << "The length is: "<< NewCDALList.length() <<"\n";
    NewCDALList.clear();
    std::cout << "The length is: "<< NewCDALList.length() << "\n";

    std::cout << "------testing popping the back of the list------"<<std::endl;
    i = 0;
    while(i != 38){
        NewCDALList.push_back(i);
        i++;
    }
    NewCDALList.print();
    NewCDALList.pop_back();
    NewCDALList.print();

    while(i != 75){
        NewCDALList.push_back(i);
        i++;
    }
    NewCDALList.print();

    NewCDALList.pop_back();
    NewCDALList.print();


    std::cout << "------testing popping the front of the list------"<<std::endl;
    NewCDALList.print();
    NewCDALList.pop_front();
    NewCDALList.print();

    i = 0;
    while(i != 21){
        NewCDALList.pop_front();
        i++;
    }
    NewCDALList.print();
    NewCDALList.pop_front();
    NewCDALList.print();
    NewCDALList.pop_front();
    NewCDALList.print();

    NewCDALList.push_back(37);
    NewCDALList.push_back(37);
    NewCDALList.push_back(37);
    NewCDALList.print();

    std::cout << "------testing insertion of the list------"<<std::endl;
    NewCDALList.insert(37, 4);
    NewCDALList.print();
    NewCDALList.insert(37, 0);
    NewCDALList.print();
    NewCDALList.insert(100, 53);
    NewCDALList.print();
    i = 0;
    while(i != 45){
        NewCDALList.push_back(i);
        i++;
    }
    NewCDALList.print();
    NewCDALList.insert(74, 20);
    NewCDALList.print();
    NewCDALList.insert(74, 100);
    NewCDALList.print();
    NewCDALList.insert(100, 0);
    NewCDALList.print();
    std::cout << "------testing removal of the list------"<<std::endl;
    NewCDALList.remove(0);
    NewCDALList.print();
    std::cout <<"the length is " << NewCDALList.length()<<"\n";
    NewCDALList.remove(NewCDALList.length()-1);
    NewCDALList.print();
    std::cout <<"the length is " << NewCDALList.length()<<"\n";

    NewCDALList.remove(5);
    NewCDALList.print();
    std::cout <<"the length is " << NewCDALList.length()<<"\n";
    std::cout << "------testing replacement of the list------"<<std::endl;

    NewCDALList.replace(100, 0);
    NewCDALList.print();

    NewCDALList.replace(100, 25);
    NewCDALList.print();

    NewCDALList.replace(100, NewCDALList.length()-1);
    NewCDALList.print();

    std::cout << "------testing peeking of the list------"<<std::endl;

    std::cout << "the back of the list is: "<< NewCDALList.peek_back()<<"\n";
    std::cout << "the front of the list is: "<< NewCDALList.peek_front()<<"\n";

    std::cout << "------testing emptiness of the list------"<<std::endl;

    std::cout << "Is the list empty? "<< NewCDALList.is_empty()<<"\n";
    NewCDALList.clear();
    std::cout << "Is the list empty? "<< NewCDALList.is_empty()<<"\n";

    std::cout << "------testing fullness of list------"<<std::endl;

    std::cout << "Is the list full? "<< NewCDALList.is_full()<<"\n";
    i = 0;
    while(i != 50){
        NewCDALList.push_back(50-i);
        i++;
    }
    std::cout << "Is the list full? "<< NewCDALList.is_full()<<"\n";

    std::cout << "------testing contents of list------"<<std::endl;

    int * array_pointer_CDAL = NewCDALList.contents();

    for(int i = 0; i < NewCDALList.length(); ++i){
        std::cout << array_pointer_CDAL[i]<<"->";
    }
    std::cout <<"\n";


    std::cout << "------testing pushing 0------"<<std::endl;
    NewCDALList.clear();
    i = 0;
    while(i != 50){
        NewCDALList.push_back(0);
        i++;
    }
    std::cout <<"the length is "<< NewCDALList.length();
    std::cout <<"\n";
    NewCDALList.print();
    NewCDALList.clear();
    NewCDALList.print();
    return 0;
}
