#include <iostream>
#include "../Exercise1/stack.h"
#include <stack>
#include <stdexcept>
int* makeTT(int* scores_start, int* scores_end);
int main()
{

    int myArr[] = {50, 10, 40, 20, 30};
    int * start = &(myArr[0]);
    int * last = &(myArr[4]);

    int * result = makeTT(start, last);

    for(int i = 0; i < 6; ++i){
        std::cout << *result << " ";
        result++;
    }
    std::cout << "\n";
    return 0;
}
int * makeTT(int * scores_start, int * scores_end)
{
    int * ptrToTT;
    int * begin = scores_start;
    int * end = scores_end;
    std::stack<int> stack;
    // scores_end++ = NULL;
    int length = 0;

    //calculate the length and push to the stack
    while (scores_start <= scores_end)
    {
        length++;
        stack.push(*scores_start);
        scores_start++;
    }

    //populate myArr with the values between scores start and end
    int myArr[length];
    for(int i = 0; i < length; ++i){
        myArr[i] = *begin;
        ++begin;
    }

    // calculate halved array length
    int add = 0;
    if (length % 2 == 0 )
        add = 0;
    else
        add = 1;

    //newArr now contains the winners
    int newArr[length/2 + add];
    int index = 0;
    for(int i = 0; i < length; i += 2){
        try{
            if (myArr[i] > myArr[i+1]){
                newArr[index] = myArr[i];
            }
            else{
                newArr[index] = myArr[i+1];
            }

        }
        catch(...){
            newArr[index] = myArr[i];
        }
        index++;
    }

    begin = &newArr[0];
    end = &newArr[index];


    while(!stack.empty()){
        std::cout << stack.top()<< " ";
        stack.pop();
    }
    std::cout <<"\n";

    makeTT(begin, end);

    int TT[stack.size()];
    for(int i = 0; i < stack.size(); ++i){
        TT[i] = stack.top();
        stack.pop();
    }
    ptrToTT = &TT[0];

    return ptrToTT;
}
