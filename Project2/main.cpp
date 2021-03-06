//
//  main.cpp
//  proj2
//
//  Created by Daniela Isabel Travieso on 12/5/17.
//  Copyright © 2017 Daniela Isabel Travieso. All rights reserved.
//
#include "bstleaf.h"
#include "bstroot.h"
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

    bst_leaf.remove(3);
    bst_leaf.remove(-2);
    bst_leaf.print();
    bst_leaf.remove(1);
    bst_leaf.print();
    std::cout << "~~~~~~~~~testing lookup~~~~~~~~~\n";

    std::cout << "the value of -3 is " << bst_leaf.lookup(-3)<<"\n";
    std::cout << "the value of -1 is " << bst_leaf.lookup(-1)<<"\n";
    // std::cout << "the value of -5 is " << bst_leaf.lookup(-5)<<"\n";

    // bst.lookup(0);

//     bstroot<int, char, compare, equal> bst_root;
//
//     std::cout << "~~~~~~~~~bst_root has been created~~~~~~~~~\n";
//     bst_root.insert(1, 'D');
//     bst_root.insert(-2, 'B');
//     bst_root.insert(-3, 'A');
//     bst_root.insert(-1, 'C');
//     bst_root.insert(2, 'E');
//     bst_root.insert(3, 'F');
//     /*
//
//             D
//            / \
//         B      E
//       /   \       \
//     A       C      F
// /   \    /   \   /  \
//
//
//     */
//     bst_root.print();
//     std::cout << "~~~~~~~~~testing remove~~~~~~~~~\n";
//
//     bst_root.remove(3);
//     bst_root.remove(-2);
//     bst_root.print();
//     bst_root.remove(1);
//     bst_root.print();
//     std::cout << "~~~~~~~~~testing lookup~~~~~~~~~\n";
//
//     std::cout << "the value of -3 is " << bst_root.lookup(-3)<<"\n";
//     std::cout << "the value of -1 is " << bst_root.lookup(-1)<<"\n";
//
//     std::cout << "~~~~~~~~~bst_rand has been created~~~~~~~~~\n";

    return 0;
}
