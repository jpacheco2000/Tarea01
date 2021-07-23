#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "quickSort.h"
#define tam 2073600

int main (int argc, char **argv){
    int n;
    FILE *arch;
    arch = fopen(argv[1], "rb");
    if (arch == NULL){
        exit(1);
    }
    int32_t vec[tam];
    fread(vec, sizeof(int), tam, arch);
    n = sizeof(vec) / sizeof(vec[0]);
    quickSort(vec, 0, n-1);

    int f,i,j;

    i=0;j=0;
    for (f = 0; f<tam; f++) {
      printf("%i", vec[f]%2);
      i++;
      if ( i == 1920 ) { 
       i=0;j++; 
       printf("\n");
      }
    }
    printf("%i x %i\n",i,j);
    fclose(arch);
    
}

