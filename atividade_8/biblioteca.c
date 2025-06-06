#include <stdio.h>
#include <math.h>
#include "biblioteca.h"

/*
Ler pontos
*/

ponto LerPonto(int n) {
    ponto p;
    printf("Digite o ponto x%d: ", n);
    scanf("%d", &p.x);

    printf("Digite o ponto y%d: ", n);
    scanf("%d", &p.y);

    return p;
}

/*
Calcular distancia
*/

double CalculoDeDistancia(ponto a, ponto b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}