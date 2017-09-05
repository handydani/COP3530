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
    int index = 0;
    int array[1001];
    bool result = true;
    int car = 0;

    std::cin >> end;

    //checks for when reaching the end
    while (end != 0)
    {
        /*
        reseting variables and creating the stack
        */
        length = end;
        std::stack<int> s;
        result = true;
        car = 0;
        index = 0;

        for(int i = 0; i < length; ++i)
        {
            //inputs car
            std::cin >> car;

            //while there is something in the stack and while the topmost element is less than the input
            while(s.size() && s.top() < car){
                //push to the array (the right street)
                array[index] = s.top();
                //remove from stack
                s.pop();
                //increment array
                ++index;

                //this allows for the elements to continue iterating until all
                //valid items are in the right street
            }
            //keep pushing until you reach valid stack of items
            s.push(car);

        }
        //while there is something in the stack
        while(s.size())
        {
            //pop the stack and append it to the array
            array[index] = s.top();
            s.pop();
            index++;
        }

        //checking if the array is correct
        for(int i=0; i < length; ++i)
        {
            if(array[i] > i+1)
            {
                result=false;
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

        std::cin >> end;
    }

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
