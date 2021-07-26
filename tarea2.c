#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define tam 2073600

#include "radixSort.h"
#include "insertionSort.h"
#include "quickSort.h"



int main (int argc, char **argv){
    int n;
    FILE *arch,*informe,*salida;
    int *vec;
    int *vec2;
    clock_t inicio,fin;
    int f,i,j,ret;
    char str[100];
  

    if (argc < 3){
    	printf("Modo de uso: %s ArchivoEntrada ArchivoSalida.pbm \n",argv[0]);
        exit(1);
    }
    arch = fopen(argv[1], "rb");
    if (arch == NULL){
    	printf("No se puede abrir archivo binario %s\n",argv[1]);
    	printf("Modo de uso: %s ArchivoEntrada ArchivoSalida.pbm \n",argv[0]);
        exit(1);
    }
    informe = fopen("informe.txt","w");
    salida = fopen(argv[2],"w");
    if (salida == NULL){
    	printf("No se puede abrir archivo  %s\n",argv[2]);
    	printf("Modo de uso: %s ArchivoEntrada ArchivoSalida.pbm \n",argv[0]);
        exit(1);
    }
    vec = malloc(sizeof(int)*(tam));
    vec2 = malloc(sizeof(int)*(tam));
    ret=fread(vec, sizeof(int), tam, arch);
    for ( i=0; i<tam ; i++) {
	    vec2[i] = vec[i] ; 
    }

    n = sizeof(vec) / sizeof(vec[0]);
    inicio = clock();
    quickSort(vec, 0, n-1);
    fin = clock();

    fprintf(informe,"Reporte Tarea2\n");
    fprintf(informe,"==============\n\n\n");
    fprintf(informe,"Tiempo QuickSort O(nLog(n)) : %f \n\n",(double)(fin - inicio)/CLOCKS_PER_SEC);



    n = sizeof(vec2) / sizeof(vec2[0]);
    inicio = clock();
    radixsort(vec2, n);
    fin = clock();

    fprintf(informe,"Tiempo RadixSort O(d x) : %f \n\n",(double)(fin - inicio)/CLOCKS_PER_SEC);

/*    insertionSort(vec2, n);  */
    fprintf(informe,"Tiempo InsertionSort O(n2) : No Disponible muy lento\n\n");


    
    fprintf(salida,"P1\n");
    fprintf(salida,"1920 1080\n");

    i=0;j=0;
    for (f = 0; f<tam; f++) {
      fprintf(salida,"%i", vec[f]%2);
      i++;
      if ( i == 1920 ) { 
       i=0;j++; 
       fprintf(salida,"\n");
      }
    }

    fclose(arch);
    fclose(salida);
    fclose(informe);
    
}

