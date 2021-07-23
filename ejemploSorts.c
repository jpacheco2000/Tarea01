// Radix Sort in C Programming

#include <stdio.h>
#include "radixSort.h"
#include "insertionSort.h"
#include "quickSort.h"


// Print an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  int array1[] = {121, 432, 564, 23, 1, 45, 788};
  int array2[] = {121, 432, 564, 23, 1, 45, 788};
  int array3[] = {121, 432, 564, 23, 1, 45, 788};
  int n = sizeof(array1) / sizeof(array1[0]);

  printf(" Arreglo Inicial ");
  printf(" =============== \n \n");
  printArray(array1, n);
  printf(" \n");
  printf(" =============== \n \n");
  
  printf(" Radix Sort \n");
  printf(" ========== \n \n");
  radixsort(array1, n);
  printArray(array1, n);
  printf(" \n");
  printf(" =============== \n \n");

  printf(" Insertion Sort \n");
  printf(" ============== \n \n");
  insertionSort(array2, n);
  printArray(array2, n);
  printf(" \n");
  printf(" =============== \n \n");

  printf(" Quick Sort \n");
  printf(" ========== \n \n");
  quickSort(array3, 0, n-1);
  printArray(array3, n);
  printf(" \n");
  printf(" =============== \n \n");

}
