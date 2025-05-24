#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){

typedef struct {
    int x;
    int y;    
    } ponto;

    ponto ponto1;
    printf("Digite o ponto x1: ");
    scanf("%d", &ponto1.x);
    printf("\n");
    printf("Digite o ponto y1: ");
    scanf("%d", &ponto1.y);
    printf("\n");

    ponto ponto2;
    printf("Digite o ponto x2: ");
    scanf("%d", &ponto2.x);
    printf("\n");
    printf("Digite o ponto y2: ");
    scanf("%d", &ponto2.y);
    printf("\n");

    int distancia = sqrt(pow(ponto2.x - ponto1.x, 2) + pow(ponto2.y - ponto1.y, 2)); 

    printf("A distância entre o ponto 1 = (%d, %d) e o ponto 2 = (%d, %d) é de %d", ponto1.x, ponto1.y, ponto2.x, ponto2.y, distancia);

    return 0;
}

