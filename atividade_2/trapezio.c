#include <stdio.h>

int main (int argc, char* argv[]){

    int area;
    int base1;
    int base2;
    int altura;

    printf("CALCULO DE AREA: TRAPEZIO\n\n");
        printf("Insira a medida de uma das bases:");
        scanf("%d", &base1);
        getchar();
        printf("Insira a medida da segunda base:");
        scanf("%d", &base2);
        getchar();
        printf("Insira a medida da altura:");
        scanf("%d", &altura);
        getchar();

    area = ((base1 + base2 ) * altura) / 2;

        printf("\nA area desse trapezio eh de %d", area);


        return 0;
}