#include<stdio.h>  
#include "quickSort.h"

// Function to print array
void printArray(int arr[], int size) 
{ 
int i; 
for (i=0; i < size; i++) 
printf("%d ", arr[i]); 
}   
// Main Function 
int main() 
{ 
int arr[] = {81, 27, 38, 99, 51, 5}; 
int n = sizeof(arr)/sizeof(arr[0]); 
quickSort(arr, 0, n-1); 
printf("Sorted array: "); 
printArray(arr, n); 
return 0; 
}
