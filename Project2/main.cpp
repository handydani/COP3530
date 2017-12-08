//
//  main.cpp
//  proj2
//
//  Created by Daniela Isabel Travieso on 12/5/17.
//  Copyright © 2017 Daniela Isabel Travieso. All rights reserved.
//
#include "bstleaf.h"
#include <iostream>
using namespace cop3530;
//template <typename K>
bool compare(int a, int b) { return a < b; }

//template <typename K>
bool equal(int a, int b) { return a == b; }
int main()
{
//    Node<int, char> bst_root;
    bstleaf<int, char, compare, equal> bst;
    bst.insert(1, 'D');
    bst.insert(-2, 'B');
    bst.insert(-3, 'A');
    bst.insert(-1, 'C');
    bst.insert(2, 'E');
    bst.insert(3, 'F');
    /*

            D
           / \
        B      E
      /   \       \
    A       C      F
    */
    bst.print();


//    bst.insert(2, 'B');
//    bst.insert(-2, 'C');
//    bst.insert(3, 'D');
//    std::cout << "insertion of tree successful\n";
//
//    bst.print();
//    std::cout << "printing of tree successful\n";

    return 0;
}
