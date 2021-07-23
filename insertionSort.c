#include <math.h> 
#include <stdio.h>   
// Insertion Sort Function
void insertionSort(int array[], int n) 
{ 
int i, element, j; 
for (i = 1; i < n; i++) { element = array[i]; j = i - 1; while (j >= 0 && array[j] > element) { 
array[j + 1] = array[j]; 
j = j - 1; 
} 
array[j + 1] = element; 
} 
}   
