#include <stdio.h>
#include "biblioteca.h"
#include <stdlib.h>

int main (int argc, char* argv[]){

    if(argc != 3 && argc != 4){
        printf("informe 2 ou mais argumentos");
        return 1;
    }

    if (argc == 3){
        int x = atoi(argv[1]);
        int y = atoi(argv[2]);
        printf("maior (%d, %d): %d", x, y, maior_2n(x, y));
    }

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    int z = atoi(argv[3]);

    printf("maior (%d, %d, %d): %d", x, y, z, maior_3n(x, y, z));

    return 0;

}