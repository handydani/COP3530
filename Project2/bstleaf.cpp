//
//  main.cpp
//  proj2
//
//  Created by Daniela Isabel Travieso on 12/5/17.
//  Copyright © 2017 Daniela Isabel Travieso. All rights reserved.
//
#include "bstleaf.h"
// #include "bstroot.h"
#include <iostream>
using namespace cop3530;
//template <typename K>
bool compare(int a, int b) { return a < b; }

//template <typename K>
bool equal(int a, int b) { return a == b; }
int main()
{
//    Node<int, char> bst_root;
    bstleaf<int, char, compare, equal> bst_leaf;
    std::cout << "~~~~~~~~~bst_leaf has been created~~~~~~~~~\n";
    std::cout << "~~~~~~~~~testing insert~~~~~~~~~\n";

    bst_leaf.insert(1, 'D');
    bst_leaf.insert(-2, 'B');
    bst_leaf.insert(-3, 'A');
    bst_leaf.insert(-1, 'C');
    bst_leaf.insert(2, 'E');
    bst_leaf.insert(3, 'F');
    /*

            D
           / \
        B      E
      /   \       \
    A       C      F
/   \    /   \   /  \


    */
    bst_leaf.print();
    std::cout << "~~~~~~~~~testing remove~~~~~~~~~\n";
    std::cout << "remove 3 and -2\n";

    bst_leaf.remove(3);
    bst_leaf.remove(-2);
    bst_leaf.print();
    std::cout << "remove 1\n";

    bst_leaf.remove(1);
    bst_leaf.print();
    std::cout << "~~~~~~~~~testing lookup~~~~~~~~~\n";

    std::cout << "the value of -3 is " << bst_leaf.lookup(-3)<<"\n";
    std::cout << "the value of -1 is " << bst_leaf.lookup(-1)<<"\n";
    return 0;
}
