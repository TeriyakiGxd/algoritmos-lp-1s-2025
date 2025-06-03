#include <stdio.h>

int buscar_na_PA(int a1, int r, int x) {
    
    if (r == 0) {
        if (x == a1)
            return 1;
        else
            return -1;
    }

    int n = (x - a1) / r + 1;

    if ((x - a1) % r != 0 || n <= 0)
        return -1;

    return n;
}

int main() {
    int a1, r, x;

    printf("Digite o primeiro termo da PA: ");
    scanf("%d", &a1);

    printf("Digite a razão da PA: ");
    scanf("%d", &r);

    printf("Digite o valor a ser buscado: ");
    scanf("%d", &x);

    int posicao = buscar_na_PA(a1, r, x);

    if (posicao == -1)
        printf("Valor %d não encontrado na PA.\n", x);
    else
        printf("Valor %d encontrado na posição %d da PA.\n", x, posicao);

    return 0;
}