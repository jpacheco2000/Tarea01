#include <math.h> 
#include <stdio.h>   
#include "insertionSort.h"
   
// Function to print the elements of an array
void printArray(int array[], int n) 
{ 
int i; 
for (i = 0; i < n; i++) 
printf("%d ", array[i]); 
printf("\n"); 
}  
// Main Function 
int main() 
{ 
int array[] = { 122, 17, 93, 3, 56 }; 
int n = sizeof(array) / sizeof(array[0]); 
insertionSort(array, n); 
printArray(array, n); 
return 0; 
}
