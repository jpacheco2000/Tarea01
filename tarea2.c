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
    int vec[tam];
    time_t inicio,fin;
    int tvec2[tam];
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
    ret=fread(vec, sizeof(int), tam, arch);
    printf("Lei %d\n",ret);

    n = sizeof(vec) / sizeof(vec[0]);
    inicio = time(NULL);
    quickSort(vec, 0, n-1);
    fin = time(NULL);

    fprintf(informe,"Reporte Tarea2\n");
    fprintf(informe,"==============\n\n\n");
    fprintf(informe,"Tiempo QuickSort O(nLog(n)) : %ld \n\n",fin-inicio);



    n = sizeof(vec) / sizeof(vec[0]);
    inicio = time(NULL);
    radixsort(vec, n);
    fin = time(NULL);

    fprintf(informe,"Tiempo RadixSort O(d x) : %ld \n\n",fin-inicio);

/*    insertionSort(tvec2, n);  */
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

