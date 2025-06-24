#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>
#include "biblioteca.h"
#include "pilotos.h"
#include "aeronaves.h"
#include "relatorio.h"
#include "cadastro.h"

void menu(const char *titulo, const char *introducao, const char *opcoes[], int n_opcoes);
void MenuFuncionarios();
void Menu_EquipeDeBordo();
void mainMenu();

void menu(const char *titulo, const char *introducao, const char *opcoes[], int n_opcoes) {
   
   
    system("cls");
    printf("===%s===\n", titulo);

    if (introducao != NULL) {
        printf("%s:\n\n", introducao);
    }

    for (int i = 0; i < n_opcoes; i++) {
        printf("%d. %s\n", i + 1, opcoes[i]);
    }

    printf("0. Sair\n\n");
}

void mainMenu() {

    
    int opcao;
    const char *opcoes[] = {
        "Pilotos",
        "Aeronaves",
        "Cadastro de gerente",
        "Relatorio"
    };
    while(1){
    menu("Aeroporto Santos Dumont", "Escolha uma opcao", opcoes, 4);
    scanf("%d", &opcao);
    limparBuffer();

    if (opcao == 0){
        fecharPrograma();
    }
    else if (opcao == 1) {
        Pilotos();
        break;
        }
    else if (opcao == 2) {
        gerenciarAeroNaves();
        break;
        }
        else if (opcao == 3) {
        cadastrarGerente();
        break;
        }
        else if (opcao == 4) {
        exibirRelatorio();
        break;
        }
    else {
        printf("Entrada invalida\n\n");
        system("pause");
    }
}
}

void exibirRelatorio() {
    int opcao;
    const char *opcoes[] = {
        "Total de pilotos por tipo",
        "Voltar",
    };
    while(1){
    menu("Relatorios", "Escolha uma opcao", opcoes, 3);
    scanf("%d", &opcao);
    limparBuffer();
        if (opcao == 0) {
            break;
        } else if (opcao == 1) {
            relatorioPilotosPorTipo();
        } else if (opcao == 2) {
            mainMenu();
            break;
        } else {
            printf("Opção inválida.\n");
            system("pause");
        }
    }
}
