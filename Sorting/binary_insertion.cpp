#include <iostream>
void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
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

    if (item == arr[mid]) return mid + 1;
    if (item > arr[mid]) return binary_search(arr, item, mid+1, high);

    return binary_search(arr, item, low, mid-1);
}
void binary_insertion(int arr[], int n)
{
    std::cout << "Binary Insertion Sort: \n";

    int i, loc, j, k, selected;
    for(int i = 1; i < n; ++i)
        j = i - 1;
        selected = arr[i];
        loc = binary_search(arr, selected, 0, j);
        while(j >= loc)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = selected;
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    // arr[] = {12, 11, 13, 5, 6};
    binary_insertion(arr, n);
    printArray(arr, n);

    return 0;
}
