#include <stdio.h>

int main (int argc, char* argv[]){

    int area;
    int base;
    int altura;

    printf("CALCULO DE AREA: RETANGULO\n\n");
        printf("Insira a medida da base:");
        scanf("%d", &base);
        getchar();
        printf("Insira a medida da altura:");
        scanf("%d", &altura);
        getchar();

    area = base * altura;

        printf("\nA area desse retangulo eh de %d", area);


        return 0;
}