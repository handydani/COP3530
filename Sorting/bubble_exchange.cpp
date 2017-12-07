#include <iostream>
void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}
void bubble_exchange(int arr[], int n)
{
    int i, j;
       bool swapped;
       for (i = 0; i < n-1; i++) // this represents the number of passes
       {
         swapped = false;
         for (j = 0; j < n-i-1; j++) // the right part represents the sorted part of the list
         {
            if (arr[j] > arr[j+1]) // if the curr is greater than the right one
            {
               swap(&arr[j], &arr[j+1]); //swap 
               swapped = true;
            }
         }

         // once you've iterated through the entire list without making any swaps, you have arrived at a sorted list so you break
         if (swapped == false)
            break;
       }
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    // arr[] = {12, 11, 13, 5, 6};
    bubble_exchange(arr, n);
    printArray(arr, n);

    return 0;
}
