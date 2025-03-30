#include <stdio.h>

int main (int argc, char* argv[]){

    int area;
    int lado;

    printf("CALCULO DE AREA: QUADRADO\n\n");
        printf("Insira a medida dos lados:");
        scanf("%d", &lado);
        getchar();

    area = lado * lado;

        printf("\nA area desse quadrado eh de %d", area);


        return 0;
}