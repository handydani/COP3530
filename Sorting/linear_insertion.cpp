#include <iostream>
void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}
void linear_insertion(int arr[], int n)
{
    std::cout << "Linear Insertion Sort: \n";
    int key = 0;
    int i, j = 0;
   for( i = 1; i < n; ++i){
       key = arr[i];
       j = i-1;
       while( j >= 0 && arr[j] > key){
           arr[j+1] = arr[j];
           j--;
       }
       arr[j+1] = key;
   }
}
int binary_search(int arr[], int item, int low, int high)
{
    if (high <= low){
        if(item > arr[low])
            return low + 1;
        else
            return low;
    }
    int mid = (low + high)/2;

    //if the item is the same as the mid point
    if (item == arr[mid]) return mid + 1;
    //if the item is greater than the mid point, search right
    if (item > arr[mid]) return binary_insertion(a, item, mid+1, high);

    return binary_insertion(arr, item, low, mid-1);
}
void binary_insertion(int arr[], int n)
{
    std::cout << "Binary Insertion Sort: \n";


}
int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr, n);
    printArray(arr, n);

    // arr[] = {12, 11, 13, 5, 6};
    binary_insertion(arr, n);
    printArray(arr, n);

    return 0;
}
