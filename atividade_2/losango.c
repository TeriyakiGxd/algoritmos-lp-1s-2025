#include <stdio.h>

int main (int argc, char* argv[]){

    int area;
    int diagonal1;
    int diagonal2;

    printf("CALCULO DE AREA: losango\n\n");
        printf("Insira a medida de uma das diagonais:");
        scanf("%d", &diagonal1);
        getchar();
        printf("por fim, insira a medida da segunda diagonal:");
        scanf("%d", &diagonal2);
        getchar();

    area = (diagonal1 * diagonal2) / 2;

        printf("\nA area desse losango eh de %d", area);


        return 0;
}