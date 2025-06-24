#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorio.h"
#include "biblioteca.h"
#include "menus.h"

void exibirRelatorio();
void relatorioPilotosPorTipo();

void relatorioPilotosPorTipo() {
    FILE *arquivo = fopen("pilotos.txt", "r");
    if (!arquivo) {
        printf("Erro ao abrir arquivo de pilotos.\n");
        system("pause");
        return;
    }

    char linha[256];
    int totalNAC = 0, totalINT = 0;
    while (fgets(linha, sizeof(linha), arquivo)) {
        if (strstr(linha, "INT")) totalINT++;
        else if (strstr(linha, "NAC")) totalNAC++;
    }
    fclose(arquivo);

    printf("\nTotal de pilotos:\n");
    printf("Nacionais: %d\n", totalNAC);
    printf("Internacionais: %d\n", totalINT);
    system("pause");
}