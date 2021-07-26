// Radix Sort in C Programming

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
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
  int array1[100000] ;
  int array2[100000] ;
  int array3[100000] ;
  clock_t start, end;
  int n = sizeof(array1) / sizeof(array1[0]);
  int i;

  srand ( 123 );
  for (i=0;i<n;i++) {
	  array1[i] = rand()%100000;
	  array2[i] = array1[i];
	  array3[i] = array1[i];

  }

  printf(" Arreglo Inicial : 100000 elementos");
  printf(" =============== \n \n");
  printf(" \n");
  printf(" =============== \n \n");
 
  start = clock(); 
  radixsort(array1, n);
  end = clock();
  printf(" Radix Sort : %f clocks \n",(double)(end - start));
  printf(" ========== \n \n");
  printf(" \n");
  printf(" =============== \n \n");

  start = clock(); 
  insertionSort(array2, n);
  end = clock();
  printf(" Insertion Sort %f clocks \n",(double)(end - start));
  printf(" ============== \n \n");
  printf(" \n");
  printf(" =============== \n \n");

  start = clock(); 
  quickSort(array3, 0, n-1);
  end = clock();
  printf(" Quick Sort %f clocks \n",(double)(end - start));
  printf(" ========== \n \n");
  printf(" \n");
  printf(" =============== \n \n");

}
