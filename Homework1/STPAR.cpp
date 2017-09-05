//
//  STPAR.cpp
//  Homework1
//
//  Created by Daniela Isabel Travieso on 9/3/17.
//  Copyright © 2017 Daniela Isabel Travieso. All rights reserved.
//
/*

                                        And what about this feeling that I'm never good enough?
                                        Will it wash out in the water, or is it always in the blood?
                                        ...
                                        Could I change it if I wanted, could I rise above the flood?
                                        Will it wash out in the water, or is it always in the blood?
                                                            - John Mayer, The Search for Everything

*/
#include <stack>
#include <iostream>

int main()
{
    int length = 0;
    int end = 0;

    do
    {

        //checks for when reaching the end
        if(end == 0)
        {
            break;
        }
        else
        {
            length = end;
            continue;
        }


        //algorithm begins

        //create an array, a correct array to compare to, a stack, and boolean for final result
        int array[length];
        int compare[length];
        std::stack<int> s;
        bool result = false;
        int car = 0;

        //populate the array with the car and the correct array with a correct value
        for(int i = 1; i <= length; ++i)
        {
            std::cin >> car;
            array[i] = car;
            compare[i] = i;
        }

        //this is where the algorithm would go if I had one

        //checking if correct
        for(int i = 1; i <= length; ++i)
        {
            if(compare[i] != i)
            {
                result = true;
                break;
            }
        }
        if (result)
        {
            std::cout << "yes" << std::endl;
        }
        else
        {
            std::cout << "no" << std::endl;
        }

    } while (end != 0);

    return 0;
}

  /*
  AVAILABLE COMMANDS:
    s.empty();
    s.size();
    s.top(); //get the element without removing it
    s.pop(); //remove the element
    s.push(someElement); //add the element
  */
