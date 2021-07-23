#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define tam 2073600

int main (int argc, char **argv){
    FILE *arch;
    arch = fopen(argv[1], "rb");
    if (arch == NULL){
        exit(1);
    }
    int vec[tam];
    fread(vec, sizeof(int), tam, arch);
    int f;
    for (f = 0; f<tam; f++) {
    printf("%i\n", vec[f]);
    }
    fclose(arch);
    
}

