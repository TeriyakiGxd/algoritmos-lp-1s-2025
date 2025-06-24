#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>
#include "biblioteca.h"
#include "menus.h"

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

    if (escolha == 0){
        fecharPrograma();
    }
    else if (escolha == 1) {
        char  nome[100], cpf[20], licenca[50], numero[20], email[100], tipo_voo[20], id[30];

        printf("\nDigite o nome do piloto: ");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = 0;

        printf("Digite o CPF: ");
        fgets(cpf, sizeof(cpf), stdin);
        cpf[strcspn(cpf, "\n")] = 0;
        
        while (strlen(cpf) != 11) {
        printf("CPF inválido. Digite novamente (11 dígitos): ");
        fgets(cpf, sizeof(cpf), stdin);
        cpf[strcspn(cpf, "\n")] = 0;}

        printf("Digite a licenca de piloto: ");
        fgets(licenca, sizeof(licenca), stdin);
        licenca[strcspn(licenca, "\n")] = 0;

        printf("Digite o numero de telefone: ");
        fgets(numero, sizeof(numero), stdin);
        numero[strcspn(numero, "\n")] = 0;

        printf("Digite o email: ");
        fgets(email, sizeof(email), stdin);
        email[strcspn(email, "\n")] = 0;

        while (!strchr(email, '@')) {
        printf("Email invalido. Digite novamente: ");
        fgets(email, sizeof(email), stdin);
        email[strcspn(email, "\n")] = 0;}

        printf("O piloto faz voos internacionais? (s/n): ");
        char resposta;
        scanf(" %c", &resposta);
        limparBuffer();
        
        strcpy(tipo_voo, (resposta == 's' || resposta == 'S') ? "Internacional" : "Nacional");
        
        do {
            strcpy(id, gerarID(tipo_voo));
        } while (idExiste(id));
 
        
        fprintf(arquivo, "ID: %s | Nome: %s | CPF: %s | Licenca: %s | Telefone: %s | Email: %s \n\n",
                id, nome, cpf, licenca, numero, email);

        printf("\nPiloto cadastrado com sucesso, ID registrado: %s\n", id);
        system("pause");
    } else if (escolha == 2) {
        consultarPiloto();
    } 
     else if(escolha == 3){
             char id[30];
        printf("Digite o ID do piloto a ser removido: ");
        fgets(id, sizeof(id), stdin);
        id[strcspn(id, "\n")] = 0;

        if (idExiste(id)) {
            apagarLinhaArquivo("pilotos.txt", id);
            printf("Piloto com ID %s removido com sucesso.\n", id);
        } else {
            printf("ID %s nao encontrado.\n", id);
            gerenciarPilotos();
        }

    fclose(arquivo);
    Pilotos();
     }
    else if (escolha == 4) {
        mainMenu();
} else {
        printf("Opcao invalida!\n");
        system("pause");
        gerenciarPilotos();
    }
}

char *gerarID(const char *tipo_voo) {
    static char id[30];
    int num = rand() % 9000 + 1000;

    if (strcmp(tipo_voo, "Internacional") == 0){
        sprintf(id, "INT-%d", num);}
    else if (strcmp(tipo_voo, "Nacional") == 0){
        sprintf(id, "NAC-%d", num);}

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
}