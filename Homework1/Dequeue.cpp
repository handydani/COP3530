//
//  main.cpp
//  Exercise1
//
//  Created by Daniela Isabel Travieso on 9/3/17.
//  Copyright © 2017 Daniela Isabel Travieso. All rights reserved.
//
/*

                        "I got, I got, I got, I got
                        Loyalty, got royalty inside my DNA
                        Cocaine quarter piece, got war and peace inside my DNA
                        I got power, poison, pain and joy inside my DNA
                        I got hustle though, ambition, flow, inside my DNA
                        I was born like this, since one like this
                        Immaculate conception
                        I transform like this, perform like this
                        Was Yeshua's new weapon"
                                                    - Kendrick Lamar, DAMN.

*/

#include <iostream>
#include <stdexcept>
#include "Bounded_Dequeue.h"
#include "Dequeue.h"

int main()
{

//  _            _   _
// | |_ ___  ___| |_(_)_ __   __ _
// | __/ _ \/ __| __| | '_ \ / _` |
// | ||  __/\__ \ |_| | | | | (_| |
//  \__\___||___/\__|_|_| |_|\__, |
//                           |___/

    bool success = false;



    std::cout << "~* Testing size 0 dequeue *~" <<std::endl;
    Bounded_Dequeue<int> My_Dequeue0(0);

    success = My_Dequeue0.length() == 0;
    std::cout << std::boolalpha << "Did it pass the length test? "<< success << std::endl;
    success = My_Dequeue0.is_empty(); //this feels more like a philosophical question,
                                      //is it empty if there's nothing able to be in there to begin with?
    std::cout << std::boolalpha << "Did it pass the empty test? "<< success << std::endl;
    success = !My_Dequeue0.is_full();
    std::cout << std::boolalpha << "Did it pass the full test? "<< success << std::endl;

    My_Dequeue0.print_dequeue();




    std::cout << "\n~* Testing size 1 dequeue *~" <<std::endl;
    Bounded_Dequeue<int> My_Dequeue1(1);

    success = My_Dequeue1.length() == 0;
    std::cout << std::boolalpha << "Did it pass the length test? "<< success << std::endl;
    success = My_Dequeue1.is_empty();
    std::cout << std::boolalpha << "Did it pass the empty test? "<< success << std::endl;
    success = !My_Dequeue1.is_full();
    std::cout << std::boolalpha << "Did it pass the full test? "<< success << std::endl;

    My_Dequeue1.push_back(1);
    My_Dequeue1.print_dequeue();


    std::cout << "\n~* Testing size 2 dequeue *~" <<std::endl;
    Bounded_Dequeue<int> My_Dequeue2(2);

    success = My_Dequeue2.length() == 0;
    std::cout << std::boolalpha << "Did it pass the length test? "<< success << std::endl;
    success = My_Dequeue2.is_empty();
    std::cout << std::boolalpha << "Did it pass the empty test? "<< success << std::endl;
    success = !My_Dequeue2.is_full();
    std::cout << std::boolalpha << "Did it pass the full test? "<< success << std::endl;

    My_Dequeue2.push_back(1);
    My_Dequeue2.push_back(2);

    My_Dequeue2.print_dequeue();

    // success = success && !My_Dequeue0.empty();
    // success = success && !My_Dequeue0.empty();
    // success = success && !My_Dequeue0.empty();


    //

    //
    // std::cout << "\n~* Testing size 5 dequeue *~" <<std::endl;
    // Bounded_Dequeue<int> My_Dequeue5(5);
    //
    // std::cout << "\n~* Testing size 6 dequeue *~" <<std::endl;
    // Bounded_Dequeue<int> My_Dequeue6(6);
    //
    //
    // My_Dequeue.push_back(25);
    // My_Dequeue.push_front(37);
    //

    return 0;


}