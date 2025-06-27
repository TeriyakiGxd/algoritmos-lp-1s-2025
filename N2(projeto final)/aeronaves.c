#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "biblioteca.h"
#include "menus.h"

void consultarAeronaves();
void gerenciarAeroNaves();

void gerenciarAeroNaves() {
    int capacidade = 2;
    int quantidade = 0;

    char **modelos = malloc(capacidade * sizeof(char *));
    char **prefixos = malloc(capacidade * sizeof(char *));
    char **matriculas = malloc(capacidade * sizeof(char *));
    char **tipos = malloc(capacidade * sizeof(char *));

    if (!modelos || !prefixos || !matriculas || !tipos) {
        printf("Erro de alocacao de memoria.\n");
        return;
    }

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

    fclose(arquivo);

    printf("\n1. Cadastrar Aeronave\n2. Consultar Aeronave\n3. Voltar\n0. Sair\nEscolha uma opcao: ");
    char entrada[10];
    int escolha;
    fgets(entrada, sizeof(entrada), stdin);
    escolha = atoi(entrada);

    if (escolha == 0) {
        fecharPrograma();
    } else if (escolha == 1) {
        while (1) {
            if (quantidade == capacidade) {
                capacidade *= 2;
                modelos = realloc(modelos, capacidade * sizeof(char *));
                prefixos = realloc(prefixos, capacidade * sizeof(char *));
                matriculas = realloc(matriculas, capacidade * sizeof(char *));
                tipos = realloc(tipos, capacidade * sizeof(char *));

                if (!modelos || !prefixos || !matriculas || !tipos) {
                    printf("Erro ao realocar memoria.\n");
                    return;
                }
            }

            modelos[quantidade] = malloc(50);
            prefixos[quantidade] = malloc(10);
            matriculas[quantidade] = malloc(10);
            tipos[quantidade] = malloc(30);

            if (!modelos[quantidade] || !prefixos[quantidade] || !matriculas[quantidade] || !tipos[quantidade]) {
                printf("Erro de alocacao de string.\n");
                return;
            }

            printf("\nDigite o modelo: ");
            fgets(modelos[quantidade], 50, stdin);
            modelos[quantidade][strcspn(modelos[quantidade], "\n")] = 0;

            printf("Digite o prefixo: ");
            fgets(prefixos[quantidade], 10, stdin);
            prefixos[quantidade][strcspn(prefixos[quantidade], "\n")] = 0;

            printf("Digite a matricula: ");
            fgets(matriculas[quantidade], 10, stdin);
            matriculas[quantidade][strcspn(matriculas[quantidade], "\n")] = 0;

            printf("Digite o tipo (Comercial / Carga / Executivo): ");
            fgets(tipos[quantidade], 30, stdin);
            tipos[quantidade][strcspn(tipos[quantidade], "\n")] = 0;

            FILE *arq = fopen("Aeronaves.txt", "a");
            if (arq) {
                fprintf(arq, "modelo: %s | marca: %s-%s | tipo: %s\n\n",
                        modelos[quantidade], prefixos[quantidade], matriculas[quantidade], tipos[quantidade]);
                fclose(arq);
            }

            printf("\nAeronave cadastrada com sucesso, marca da aeronave: %s-%s\n", prefixos[quantidade], matriculas[quantidade]);
            quantidade++;

            char resposta;
            printf("Deseja cadastrar outra aeronave? (s/n): ");
            scanf(" %c", &resposta);
            getchar();
            if (resposta != 's' && resposta != 'S') break;
        }

        for (int i = 0; i < quantidade; i++) {
            free(modelos[i]);
            free(prefixos[i]);
            free(matriculas[i]);
            free(tipos[i]);
        }
        free(modelos);
        free(prefixos);
        free(matriculas);
        free(tipos);

        gerenciarAeroNaves();

    } else if (escolha == 2) {
        consultarAeronaves();
    } else if (escolha == 3) {
        mainMenu();
    } else {
        printf("Opcao invalida!\n");
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