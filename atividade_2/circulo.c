#include <stdio.h>

int main (int argc, char* argv[]){

    float area;
    int raio;
    float const pi = 3.1415;

    printf("CALCULO DE AREA: CIRCULO\n\n");
        printf("Insira a medida do raio:");
        scanf("%d", &raio);
        getchar();

    area = (raio * raio) * pi;

        printf("\nA area desse circulo eh de %.2f", area);


        return 0;
}