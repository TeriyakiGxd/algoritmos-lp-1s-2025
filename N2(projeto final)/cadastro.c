#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include "menus.h"
#include "biblioteca.h"

#define loginMax 150
#define senhaMax 150

int validarSenhaForte(const char *senha);
int login();
void CadastrarGerente();

int validarSenhaForte(const char *senha) {
    int tem_maiuscula = 0, tem_minuscula = 0, tem_numero = 0, tem_especial = 0;

    for (int i = 0; senha[i]; i++) {
        if (isupper(senha[i])) tem_maiuscula = 1;
        else if (islower(senha[i])) tem_minuscula = 1;
        else if (isdigit(senha[i])) tem_numero = 1;
        else if (ispunct(senha[i])) tem_especial = 1;
    }

    return tem_maiuscula && tem_minuscula && tem_numero && tem_especial;
}

int login() {
    FILE *arquivo = fopen("logins.txt", "a+");
    if (!arquivo) {
        printf("Erro ao abrir arquivo de login.\n");
        return 0;
    }

    char email[loginMax], senha[senhaMax], linha[200];

    while (1) {
        printf("=== Login ===\n");
        printf("Digite seu email e senha para acessar o sistema.\n\n");
        printf("Email: ");
        fgets(email, sizeof(email), stdin);
        email[strcspn(email, "\n")] = '\0';

        printf("Senha: ");
        fgets(senha, sizeof(senha), stdin);
        senha[strcspn(senha, "\n")] = '\0';

        rewind(arquivo);
        int autenticado = 0;
        while (fgets(linha, sizeof(linha), arquivo)) {
            char email_arquivo[loginMax], senha_arquivo[senhaMax];
            sscanf(linha, "%[^;];%[^\n]", email_arquivo, senha_arquivo);
            if (strcmp(email, email_arquivo) == 0 && strcmp(senha, senha_arquivo) == 0) {
                autenticado = 1;
                break;
            }
        }

        if (autenticado) {
            printf("\nLogin realizado com sucesso!\n");
            fclose(arquivo);
            return 1;
        } else {
            printf("\nEmail ou senha inválidos. Tente novamente.\n\n");
        }
    }
}

void cadastrarGerente() {
    system("cls");
    printf("=== Cadastro de Gerente ===\n");
    FILE *arquivo = fopen("logins.txt", "a+");
    if (!arquivo) {
        printf("Erro ao abrir arquivo de login.\n");
        return;
    }

    char email[loginMax], senha[senhaMax];

    while (1) {
        printf("Novo email: ");
        fgets(email, sizeof(email), stdin);
        email[strcspn(email, "\n")] = '\0';

        if (!strchr(email, '@')) {
            printf("Email inválido. Deve conter '@'.\n");
            continue;
        }

        printf("Nova senha: ");
        fgets(senha, sizeof(senha), stdin);
        senha[strcspn(senha, "\n")] = '\0';

        if (!validarSenhaForte(senha)) {
            printf("Senha fraca. Deve conter maiúsculas, minúsculas, números e caracteres especiais.\n");
            continue;
        }
        if (strlen(senha) < 8) {
            printf("Senha muito curta. Deve ter pelo menos 8 caracteres.\n");
            continue;
        }
        if (strlen(email) > loginMax - 1 || strlen(senha) > senhaMax - 1) {
            printf("Email ou senha muito longos. Tente novamente.\n");
            continue;
        }
       
        rewind(arquivo);
        char linha[200];
        int email_existe = 0;
        while (fgets(linha, sizeof(linha), arquivo)) {
            char email_arquivo[loginMax];
            sscanf(linha, "%[^;];", email_arquivo);
            if (strcmp(email, email_arquivo) == 0) {
                email_existe = 1;
                break;
            }
        } 
        if (email_existe) {
            printf("Email já cadastrado. Tente outro.\n");
            continue;
        }
        rewind(arquivo);
        limparBuffer();
        letrasMinusculas(email);

        fprintf(arquivo, "%s;%s\n", email, senha);
        printf("Usuário cadastrado com sucesso!\n");


        printf("deseja cadastrar outro gerente? (s/n): ");
        char resposta;
        scanf(" %c", &resposta);
        limparBuffer();
        if (resposta == 's' || resposta == 'S') {
            cadastrarGerente();
            break;
        } else if(resposta == 'n' || resposta == 'N') {
            printf("Voltando ao menu principal...\n");
            system("pause");
            mainMenu();
            break;
         } else {
            printf("Insira uma entrada valida (s/n).\n");
            continue;
    }
        fclose(arquivo);
        break;
    } }

    