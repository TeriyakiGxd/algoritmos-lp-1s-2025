#include <stdio.h>
#include "biblioteca.h"
#include <math.h>

    int main(int argc, char const *argv[])
    {

    /*
    Requisitando a determinação dos pontos
    */
    ponto ponto1 = LerPonto(1);
    ponto ponto2 = LerPonto(2);

    /*
    Calculando a distancia dos pontos
    */
    double distancia = CalculoDeDistancia(ponto1, ponto2);

    /*
    Resultado
    */
    printf("A distância entre o ponto 1 = (%d, %d) e o ponto 2 = (%d, %d) é de %.3lf\n", ponto1.x, ponto1.y, ponto2.x, ponto2.y, distancia);

    return 0;
}