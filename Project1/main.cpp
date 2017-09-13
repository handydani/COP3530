#include "ss_ll.h"
#include <iostream>
#include <stdexcept>
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

    return 0;
}
