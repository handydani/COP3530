#include "SSLL.h"
#include <iostream>
#include <stdexcept>
#include "SDAL.h"
#include "CDAL.h"
#include "PSLL.h"
#include "CBL.h"
using namespace cop3530;
int main()
{

    std::cout <<"Hello World" <<std::endl;
    SSLL<int> newList(0);

    newList.insert(3, 0);
    newList.insert(2, 1);
    newList.push_back(1);
    newList.print(std::cout);

    std::cout << newList.peek_back() << "\n";
    std::cout << newList.peek_front() << "\n";
    std::cout << newList.is_empty() << "\n";
    std::cout << newList.length() << "\n";
    std::cout << newList.pop_front() << "\n";
    newList.push_back(5);
    newList.print(std::cout);
    std::cout << newList.remove(1) << "\n";
    newList.print(std::cout);
    std::cout << newList.length() << "\n";

    std::cout << newList.pop_back() << "\n";
    std::cout << newList.pop_back() << "\n";
    std::cout << newList.length() << "\n";

    newList.print(std::cout);
    newList.push_back(1);
    newList.push_back(2);
    newList.push_back(3);
    newList.push_back(4);
    newList.push_back(5);
    newList.print(std::cout);
    newList.insert(37, 0);
    newList.print(std::cout);

    newList.insert(37, 2);
    newList.print(std::cout);

    newList.insert(37, 4);
    newList.print(std::cout);

    newList.insert(37, 6);
    newList.print(std::cout);

    newList.insert(37, 8);
    newList.print(std::cout);

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
    newList.print(std::cout);

    // this printsstd::cout the contents of the list as an array
    int * array_pointer;
    for(int i = 0; i < newList.length(); i++){
        array_pointer = newList.contents();
        std::cout << array_pointer[i] << " ";
    }
    std::cout << "\n ";


    newList.clear();
    newList.print(std::cout);
    std::cout << "This is now a simple dynamic array list"<<std::endl;
    SDAL<int> newSDALList(10);
    newSDALList.push_back(1);
    newSDALList.push_back(2);
    newSDALList.push_back(3);
    newSDALList.push_back(4);
    newSDALList.push_front(5);
    newSDALList.print(std::cout);

    newSDALList.insert(6, 5);
    newSDALList.insert(12, 0);
    newSDALList.insert(2, 1);

    newSDALList.print(std::cout);
    std::cout << newSDALList.pop_back() << std::endl;
    newSDALList.print(std::cout);

    std::cout << newSDALList.pop_front() << std::endl;
    newSDALList.print(std::cout);

    std::cout << "testing remove list"<<std::endl;

    std::cout << newSDALList.remove(1) << std::endl;
    newSDALList.print(std::cout);

    std::cout << newSDALList.remove(0) << std::endl;
    newSDALList.print(std::cout);

    std::cout << newSDALList.remove(3) << std::endl;
    newSDALList.print(std::cout);

    std::cout << "testing replace list"<<std::endl;

    std::cout << newSDALList.replace(37, 0) << std::endl;
    newSDALList.print(std::cout);

    std::cout << newSDALList.replace(38, 1) << std::endl;
    newSDALList.print(std::cout);

    std::cout << newSDALList.replace(39, 2) << std::endl;
    newSDALList.print(std::cout);
    std::cout << newSDALList.replace(40, 3) << std::endl;

    newSDALList.print(std::cout);

    std::cout << "------testing allocation of list------"<<std::endl;

    newSDALList.push_back(40);
    newSDALList.push_back(41);
    newSDALList.push_back(42);
    newSDALList.push_back(43);
    newSDALList.push_back(44);
    newSDALList.push_back(45);
    newSDALList.print(std::cout);

    std::cout << "The length of the list is " << newSDALList.length() << std::endl;

    newSDALList.push_back(46);
    std::cout << "The length of the list is " << newSDALList.length() << std::endl;
    newSDALList.print(std::cout);

    newSDALList.push_back(47);

    newSDALList.print(std::cout);
    std::cout << "The length of the list is " << newSDALList.length() << std::endl;


    std::cout << "------testing deallocation of list------"<<std::endl;

    SDAL<int> deallSDALList(100);
    deallSDALList.push_back(40);
    deallSDALList.push_back(41);
    deallSDALList.push_back(42);
    deallSDALList.push_back(43);
    deallSDALList.push_back(44);
    deallSDALList.push_back(45);
    deallSDALList.print(std::cout);

    std::cout << "The length of the list is " << deallSDALList.length() << std::endl;
    deallSDALList.pop_back();
    deallSDALList.print(std::cout);

    std::cout << "------testing clearing of list------"<<std::endl;

    deallSDALList.clear();
    deallSDALList.print(std::cout);
    // std::cout << "------testing deletion of list------"<<std::endl;
    // lol this wont work
    // deallSDALList.~SDAL<int>();


    std::cout << "This is now a chained dynamic array list"<<std::endl;
    CDAL<int> CDALList(0);

    CDALList.print(std::cout);
    std::cout << "------testing pushing back of list and dynamic resizing------"<<std::endl;

    int i = 0;
    while(i != 50){
        CDALList.push_back(i);
        i++;
    }
    CDALList.print(std::cout);
    std::cout << CDALList.length()<<"\n";
    std::cout << CDALList.node_ctr()<<"\n";

    i = 50;
    while(i != 100){
        CDALList.push_back(i);
        i++;
    }
    CDALList.print(std::cout);


    i = 100;

    while(i != 150){
        CDALList.push_back(i);
        i++;
    }
    CDALList.print(std::cout);
    std::cout << CDALList.length()<<"\n";
    std::cout << CDALList.node_ctr()<<"\n";

    std::cout << "------testing clearing of list------"<<std::endl;

    CDALList.clear();
    CDALList.print(std::cout);


    std::cout << "------testing pushing to the front of the list------"<<std::endl;
    CDAL<int> NewCDALList(0);

    NewCDALList.push_back(1);
    NewCDALList.push_back(1);
    NewCDALList.push_back(1);
    NewCDALList.push_back(1);
    NewCDALList.push_back(1);
    NewCDALList.print(std::cout);
    NewCDALList.push_front(2);

    NewCDALList.push_front(3);

    NewCDALList.push_front(4);

    NewCDALList.push_front(5);
    NewCDALList.print(std::cout);
    NewCDALList.push_front(3);
    NewCDALList.push_front(3);
    NewCDALList.push_front(3);
    NewCDALList.push_front(3);
    NewCDALList.print(std::cout);

    i = 0;
    while(i != 86){
        NewCDALList.push_back(i);
        i++;
    }
    NewCDALList.push_front(5);
    NewCDALList.push_front(5);
    NewCDALList.print(std::cout);


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
    NewCDALList.print(std::cout);
    NewCDALList.pop_back();
    NewCDALList.print(std::cout);

    while(i != 75){
        NewCDALList.push_back(i);
        i++;
    }
    NewCDALList.print(std::cout);

    NewCDALList.pop_back();
    NewCDALList.print(std::cout);


    std::cout << "------testing popping the front of the list------"<<std::endl;
    NewCDALList.print(std::cout);
    NewCDALList.pop_front();
    NewCDALList.print(std::cout);

    i = 0;
    while(i != 21){
        NewCDALList.pop_front();
        i++;
    }
    NewCDALList.print(std::cout);
    NewCDALList.pop_front();
    NewCDALList.print(std::cout);
    NewCDALList.pop_front();
    NewCDALList.print(std::cout);

    NewCDALList.push_back(37);
    NewCDALList.push_back(37);
    NewCDALList.push_back(37);
    NewCDALList.print(std::cout);

    std::cout << "------testing insertion of the list------"<<std::endl;
    NewCDALList.insert(37, 4);
    NewCDALList.print(std::cout);
    NewCDALList.insert(37, 0);
    NewCDALList.print(std::cout);
    NewCDALList.insert(100, 53);
    NewCDALList.print(std::cout);
    i = 0;
    while(i != 45){
        NewCDALList.push_back(i);
        i++;
    }
    NewCDALList.print(std::cout);
    NewCDALList.insert(74, 20);
    NewCDALList.print(std::cout);
    NewCDALList.insert(74, 100);
    NewCDALList.print(std::cout);
    NewCDALList.insert(100, 0);
    NewCDALList.print(std::cout);
    std::cout << "------testing removal of the list------"<<std::endl;
    NewCDALList.remove(0);
    NewCDALList.print(std::cout);
    std::cout <<"the length is " << NewCDALList.length()<<"\n";
    NewCDALList.remove(NewCDALList.length()-1);
    NewCDALList.print(std::cout);
    std::cout <<"the length is " << NewCDALList.length()<<"\n";

    NewCDALList.remove(5);
    NewCDALList.print(std::cout);
    std::cout <<"the length is " << NewCDALList.length()<<"\n";
    std::cout << "------testing replacement of the list------"<<std::endl;

    NewCDALList.replace(100, 0);
    NewCDALList.print(std::cout);

    NewCDALList.replace(100, 25);
    NewCDALList.print(std::cout);

    NewCDALList.replace(100, NewCDALList.length()-1);
    NewCDALList.print(std::cout);

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
    NewCDALList.print(std::cout);
    NewCDALList.clear();
    NewCDALList.print(std::cout);


    std::cout << "This is now a Pool Singly Linked Lists\n";

    PSLL<int> PSLList(0);
    PSLList.print(std::cout);
    i = 1;
    while(i != 20){
        PSLList.push_front(i);
        ++i;
    }
    PSLList.print(std::cout);

    std::cout << "~~~~~~~~~testing pushing to the front~~~~~~~~~\n";
    PSLList.push_front(37);
    PSLList.print(std::cout);
    std::cout << "~~~~~~~~~testing pushing to the back~~~~~~~~~\n";

    PSLList.push_back(37);
    PSLList.print(std::cout);
    std::cout << "~~~~~~~~~testing popping the back~~~~~~~~~\n";
    PSLList.pop_back();
    PSLList.print(std::cout);
    PSLList.clear();
    PSLList.print(std::cout);

    PSLList.push_back(5);
    PSLList.print(std::cout);
    std::cout << "~~~~~~~~~testing popping the front~~~~~~~~~\n";

    //
    // PSLList.pop_front();
    // PSLList.print(std::cout);
    // i = 1;
    // while(i != 20){
    //     PSLList.push_front(i);
    //     ++i;
    // }
    // PSLList.print(std::cout);
    //
    // PSLList.pop_front();
    // PSLList.print(std::cout);
    // PSLList.pop_front();
    // PSLList.print(std::cout);

    std::cout << "~~~~~~~~~Now testing CBL~~~~~~~~~\n";
    CBL<int> CBLList(10);
    CBLList.push_back(1);
    CBLList.push_back(2);
    CBLList.push_back(3);
    CBLList.push_back(4);
    CBLList.print(std::cout);

    // CBLList.insert(6, 5);
    // CBLList.insert(12, 0);
    // CBLList.insert(2, 1);

    // CBLList.print(std::cout);
    std::cout << CBLList.pop_back() << std::endl;
    CBLList.print(std::cout);

    // std::cout << CBLList.pop_front() << std::endl;
    // CBLList.print(std::cout);

    // std::cout << "testing remove list"<<std::endl;
    //
    // std::cout << CBLList.remove(1) << std::endl;
    // CBLList.print(std::cout);
    //
    // std::cout << CBLList.remove(0) << std::endl;
    // CBLList.print(std::cout);
    //
    // std::cout << CBLList.remove(3) << std::endl;
    // CBLList.print(std::cout);
    //
    // std::cout << "testing replace list"<<std::endl;

    // std::cout << CBLList.replace(37, 0) << std::endl;
    // CBLList.print(std::cout);
    //
    // std::cout << CBLList.replace(38, 1) << std::endl;
    // CBLList.print(std::cout);
    //
    // std::cout << CBLList.replace(39, 2) << std::endl;
    // CBLList.print(std::cout);
    // std::cout << CBLList.replace(40, 3) << std::endl;
    //
    // CBLList.print(std::cout);

    std::cout << "------testing allocation of list------"<<std::endl;

    CBLList.push_back(40);
    CBLList.push_back(41);
    CBLList.push_back(42);
    CBLList.push_back(43);
    CBLList.push_back(44);
    CBLList.push_back(45);
    CBLList.print(std::cout);

    std::cout << "The length of the list is " << CBLList.length() << std::endl;

    CBLList.push_back(46);
    std::cout << "The length of the list is " << CBLList.length() << std::endl;
    CBLList.print(std::cout);

    CBLList.push_back(47);

    CBLList.print(std::cout);
    std::cout << "The length of the list is " << CBLList.length() << std::endl;


    // std::cout << "------testing deallocation of list------"<<std::endl;
    //
    // SDAL<int> deallSDALList(100);
    // deallSDALList.push_back(40);
    // deallSDALList.push_back(41);
    // deallSDALList.push_back(42);
    // deallSDALList.push_back(43);
    // deallSDALList.push_back(44);
    // deallSDALList.push_back(45);
    // deallSDALList.print(std::cout);
    //
    // std::cout << "The length of the list is " << deallSDALList.length() << std::endl;
    // deallSDALList.pop_back();
    // deallSDALList.print(std::cout);
    //
    // std::cout << "------testing clearing of list------"<<std::endl;
    //
    // deallSDALList.clear();
    // deallSDALList.print(std::cout);
    // // std::cout << "------testing deletion of list------"<<std::endl;
    // // lol this wont work
    // // deallSDALList.~SDAL<int>();
    //

    return 0;


}
