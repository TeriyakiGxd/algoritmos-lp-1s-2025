#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include "biblioteca.h"
#include "menus.h"
#include <time.h>

void Pilotos();
void gerenciarPilotos();
void consultarPiloto();
char *gerarID(const char *tipo_voo);
int idExiste(const char *id);

void Pilotos() {
    gerenciarPilotos();
}

void gerenciarPilotos() {
    srand(time(NULL));

    FILE *arquivo = fopen("pilotos.txt", "a+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de pilotos.\n");
        return;
    }

    system("cls");
    printf("=== Pilotos Cadastrados ===\n");

    char linha[256];
    rewind(arquivo);
    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }

    printf("\n1. Cadastrar novo piloto\n2. Consultar piloto\n3. Remover Piloto\n0. Sair\nEscolha uma opcao: ");
    int escolha;
    scanf("%d", &escolha);
    limparBuffer();

    if (escolha == 0) {
        fclose(arquivo);
        fecharPrograma();
    } else if (escolha == 1) {
        fclose(arquivo);
        int capacidade = 2;
        int quantidade = 0;

        char **nomes = malloc(capacidade * sizeof(char *));
        char **cpfs = malloc(capacidade * sizeof(char *));
        char **licencas = malloc(capacidade * sizeof(char *));
        char **telefones = malloc(capacidade * sizeof(char *));
        char **emails = malloc(capacidade * sizeof(char *));
        char **tipos_voo = malloc(capacidade * sizeof(char *));
        char **ids = malloc(capacidade * sizeof(char *));

        if (!nomes || !cpfs || !licencas || !telefones || !emails || !tipos_voo || !ids) {
            printf("Erro ao alocar memória inicial.\n");
            return;
        }

        while (1) {
            if (quantidade == capacidade) {
                capacidade *= 2;
                nomes = realloc(nomes, capacidade * sizeof(char *));
                cpfs = realloc(cpfs, capacidade * sizeof(char *));
                licencas = realloc(licencas, capacidade * sizeof(char *));
                telefones = realloc(telefones, capacidade * sizeof(char *));
                emails = realloc(emails, capacidade * sizeof(char *));
                tipos_voo = realloc(tipos_voo, capacidade * sizeof(char *));
                ids = realloc(ids, capacidade * sizeof(char *));
                if (!nomes || !cpfs || !licencas || !telefones || !emails || !tipos_voo || !ids) {
                    printf("Erro ao realocar memória.\n");
                    return;
                }
            }

            nomes[quantidade] = malloc(100);
            cpfs[quantidade] = malloc(20);
            licencas[quantidade] = malloc(50);
            telefones[quantidade] = malloc(20);
            emails[quantidade] = malloc(100);
            tipos_voo[quantidade] = malloc(20);
            ids[quantidade] = malloc(30);

            printf("\nDigite o nome do piloto: ");
            fgets(nomes[quantidade], 100, stdin);
            nomes[quantidade][strcspn(nomes[quantidade], "\n")] = 0;

            printf("Digite o CPF: ");
            fgets(cpfs[quantidade], 20, stdin);
            cpfs[quantidade][strcspn(cpfs[quantidade], "\n")] = 0;
            while (strlen(cpfs[quantidade]) != 11) {
                printf("CPF inválido. Digite novamente (11 dígitos): ");
                fgets(cpfs[quantidade], 20, stdin);
                cpfs[quantidade][strcspn(cpfs[quantidade], "\n")] = 0;
            }

            printf("Digite a licenca de piloto: ");
            fgets(licencas[quantidade], 50, stdin);
            licencas[quantidade][strcspn(licencas[quantidade], "\n")] = 0;

            printf("Digite o numero de telefone: ");
            fgets(telefones[quantidade], 20, stdin);
            telefones[quantidade][strcspn(telefones[quantidade], "\n")] = 0;

            printf("Digite o email: ");
            fgets(emails[quantidade], 100, stdin);
            emails[quantidade][strcspn(emails[quantidade], "\n")] = 0;
            while (!strchr(emails[quantidade], '@')) {
                printf("Email invalido. Digite novamente: ");
                fgets(emails[quantidade], 100, stdin);
                emails[quantidade][strcspn(emails[quantidade], "\n")] = 0;
            }

            printf("O piloto faz voos internacionais? (s/n): ");
            char resposta;
            scanf(" %c", &resposta);
            limparBuffer();
            strcpy(tipos_voo[quantidade], (resposta == 's' || resposta == 'S') ? "Internacional" : "Nacional");

            do {
                strcpy(ids[quantidade], gerarID(tipos_voo[quantidade]));
            } while (idExiste(ids[quantidade]));

            FILE *arquivoNovo = fopen("pilotos.txt", "a");
            if (arquivoNovo != NULL) {
                fprintf(arquivoNovo, "ID: %s | Nome: %s | CPF: %s | Licenca: %s | Telefone: %s | Email: %s\n\n",
                        ids[quantidade], nomes[quantidade], cpfs[quantidade], licencas[quantidade], telefones[quantidade], emails[quantidade]);
                fclose(arquivoNovo);
            }

            printf("\nPiloto cadastrado com sucesso, ID registrado: %s\n", ids[quantidade]);
            quantidade++;

            printf("Deseja cadastrar outro piloto? (s/n): ");
            scanf(" %c", &resposta);
            limparBuffer();
            if (resposta != 's' && resposta != 'S') break;
        }

        for (int i = 0; i < quantidade; i++) {
            free(nomes[i]);
            free(cpfs[i]);
            free(licencas[i]);
            free(telefones[i]);
            free(emails[i]);
            free(tipos_voo[i]);
            free(ids[i]);
        }
        free(nomes);
        free(cpfs);
        free(licencas);
        free(telefones);
        free(emails);
        free(tipos_voo);
        free(ids);
        Pilotos();

    } else if (escolha == 2) {
        fclose(arquivo);
        consultarPiloto();
    } else if (escolha == 3) {
        fclose(arquivo);
        char id[30];
        printf("Digite o ID do piloto a ser removido: ");
        fgets(id, sizeof(id), stdin);
        id[strcspn(id, "\n")] = 0;

        if (idExiste(id)) {
            apagarLinhaArquivo("pilotos.txt", id);
            printf("Piloto com ID %s removido com sucesso.\n", id);
        } else {
            printf("ID %s nao encontrado.\n", id);
        }
        Pilotos();
    } else {
        printf("Opcao invalida!\n");
        system("pause");
        fclose(arquivo);
        gerenciarPilotos();
    }
}

char *gerarID(const char *tipo_voo) {
    static char id[30];
    int num = rand() % 9000 + 1000;

    if (strcmp(tipo_voo, "Internacional") == 0) {
        sprintf(id, "INT-%d", num);
    } else {
        sprintf(id, "NAC-%d", num);
    }

    return id;
}

int idExiste(const char *id) {
    FILE *arquivo = fopen("pilotos.txt", "r");
    if (arquivo == NULL) return 0;

    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo)) {
        if (strstr(linha, id) != NULL) {
            fclose(arquivo);
            return 1;
        }
    }

    fclose(arquivo);
    return 0;
}

void consultarPiloto() {
    FILE *arquivo = fopen("pilotos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para consulta.\n");
        return;
    }

    char buscarPiloto[100];
    printf("\nDigite o nome ou ID do piloto que deseja consultar: ");
    fgets(buscarPiloto, sizeof(buscarPiloto), stdin);
    buscarPiloto[strcspn(buscarPiloto, "\n")] = 0;

    char linha[256];
    int encontrado = 0;
    while (fgets(linha, sizeof(linha), arquivo)) {
        if (strstr(linha, buscarPiloto) != NULL) {
            printf("Resultado encontrado:\n%s\n", linha);
            encontrado = 1;
        }
    }

    if (!encontrado)
        printf("Nenhum piloto encontrado com a busca: %s\n", buscarPiloto);

    fclose(arquivo);
    system("pause");
    Pilotos();
}