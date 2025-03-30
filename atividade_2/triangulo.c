#include <stdio.h>

int main (int argc, char* argv[]){

    int area;
    int base;
    int altura;

    printf("CALCULO DE AREA: TRIANGULO\n\n");
        printf("Insira a medida da base:");
        scanf("%d", &base);
        getchar();
        printf("Insira a medida da altura:");
        scanf("%d", &altura);
        getchar();

    area = (base * altura) / 2;

        printf("\nA area desse triangulo eh de %d", area);


        return 0;
}