#include <iostream>
#include "../Exercise1/stack.h"
#include <stack>
#include <cmath>
#include <stdexcept>
/*
                                                Grease is the word
                                                It's got groove it's got meaning
                                                Grease is the time, is the place, is the motion
                                                Grease is the way we are feeling

                                                                - Frankie Valli
*/

int* makeTT(int* scores_start, int* scores_end);

template <typename T>
class Node
{
    public:
        Node();
        Node <T> * left;
        Node <T> * right;
        T data;
};
template <typename T>
Node<T>::Node(){
    left = 0;
    right = 0;
    data = 0;
}
int main()
{

    int myArr[] = {50, 10, 40, 20, 30};
    int * start = &(myArr[0]);
    int * last = &(myArr[4]);

    makeTT(start, last);

    // for(int i = 0; i < 6; ++i){
    //     std::cout << *result << " ";
    //     result++;
    // }
    // std::cout << "\n";
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

    int counter = 0;
    while(!stack.empty()){
        ++counter;
        std::cout << stack.top()<< " ";
        stack.pop();
    }
    std::cout <<"\n";

    if(counter == 1){
        int TT[stack.size()];
        for(int i = 0; i < stack.size(); ++i){
            TT[i] = stack.top();
            stack.pop();
        }
        ptrToTT = &TT[0];

    }
    else{
        makeTT(begin, end);
    }
    return ptrToTT;

}
int * makeTT(int * scores_start, int * scores_end)
{
    unsigned int size = 0, height = 0, length = 0;

    //length of whats given, levels of final tree, and the size of the array
    length = scores_end - scores_start;
    height = ceil(log2(length)) + 1;
    size = pow(2, height);

    //final array and initial array;
    int fin_array[size];
    int in_array[length];

    for(int i = 0; int * element = scores_start; element <= scores_end; ++i; ++element)
    {
        in_array[i] = *element;
    }

    int * left = scores_start;
    int * right = scores_start++;
    unsigned int currheight = height;
    size_t pwindex = 0;
    unsigned int ctr = 0;
    unsigned int bound = length;

    while(currheight != 0)
    {
        while(bound && (left || right))// check
        {
            pwindex = currheight + ctr;
            if (*left > *right){
                fin_array[pwindex] = *left;

            }
            else if(*left < *right){
                fin_array[pwindex] = *right;
            }
            else{

            }
            left += 2;
            right += 2;
            
            ctr++;
        }
        currheight--;

    }


}
