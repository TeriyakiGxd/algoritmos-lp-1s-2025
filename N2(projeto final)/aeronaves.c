#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "biblioteca.h"
#include "menus.h"

void consultarAeronaves();
void gerenciarAeroNaves();

void gerenciarAeroNaves() {
    FILE *arquivo = fopen("Aeronaves.txt", "a+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de Aeronaves.\n");
        return;
    }

    system("cls");
    printf("=== Aeronaves Cadastradas ===\n");

    char linha[256];
    rewind(arquivo);
    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }

    printf("\n1. Cadastrar Aeronave\n2. Consultar Aeronave\n3. Voltar\n0. Sair\nEscolha uma opcao: ");
    char entrada[10];
    int escolha;
    fgets(entrada, sizeof(entrada), stdin);
    escolha = atoi(entrada);

    if (escolha == 0) {
        fecharPrograma();
    } else if (escolha == 1) {
        char modelo[50], prefixo[10], matricula[10], tipo[30];

        printf("\nDigite o modelo: ");
        fgets(modelo, sizeof(modelo), stdin);
        modelo[strcspn(modelo, "\n")] = 0;

        printf("Digite o prefixo: ");
        fgets(prefixo, sizeof(prefixo), stdin);
        prefixo[strcspn(prefixo, "\n")] = 0;

        printf("Digite a matricula: ");
        fgets(matricula, sizeof(matricula), stdin);
        matricula[strcspn(matricula, "\n")] = 0;

        printf("Digite o tipo (Comercial / Carga / Executivo): ");
        fgets(tipo, sizeof(tipo), stdin);
        tipo[strcspn(tipo, "\n")] = 0;

        fprintf(arquivo, "modelo: %s | marca: %s-%s | tipo: %s\n\n",
                modelo, prefixo, matricula, tipo);

        printf("\nAeronave cadastrada com sucesso, marca da aeronave: %s-%s\n", prefixo, matricula);
        system("pause");
        fclose(arquivo);
        gerenciarAeroNaves(); 
    } else if (escolha == 2) {
        fclose(arquivo);
        consultarAeronaves();
    } else if (escolha == 4) {
        fclose(arquivo);
        mainMenu();
    } else {
        printf("Opcao invalida!\n");
        fclose(arquivo);
        system("pause");
        gerenciarAeroNaves();
    }
}

void consultarAeronaves() {
    FILE *arquivo = fopen("Aeronaves.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para consulta.\n");
        return;
    }

    char buscarAeronave[100];
    printf("\nDigite o nome da Aeronave que deseja consultar: ");
    fgets(buscarAeronave, sizeof(buscarAeronave), stdin);
    buscarAeronave[strcspn(buscarAeronave, "\n")] = 0;

    char linha[256];
    int encontrado = 0;
    while (fgets(linha, sizeof(linha), arquivo)) {
        if (strstr(linha, buscarAeronave) != NULL) {
            printf("Resultado encontrado:\n%s\n", linha);
            encontrado = 1;
        }
    }

    if (!encontrado)
        printf("Nenhuma Aeronave encontrada com a busca: %s\n", buscarAeronave);

    fclose(arquivo);
    system("pause");
    gerenciarAeroNaves();
}
