#include <iostream>
void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}
void shell_insertion(int arr[], int n)
{
    std::cout << "Shell Insertion Sort: \n";
    int i, j, gap, temp;
	//we start with a bigger gap
	gap = n/2;
	while(gap > 0)
    {
		//now we will do the insertion sort of the gapped elements
		i = gap;
		while(i < n) {
			temp = arr[i];
			//shifting gap sorted element to correct location
			for(j = i; (j >= gap) && (arr[j - gap] > temp); j -=gap) {
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
			i++;
		}
		gap = gap / 2;
	}
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    // arr[] = {12, 11, 13, 5, 6};
    shell_insertion(arr, n);
    printArray(arr, n);

    return 0;
}
