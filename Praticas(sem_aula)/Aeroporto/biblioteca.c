#include <stdio.h>
#include <stdlib.h>

// Protótipos das funções
void menu(const char *titulo, const char *introducao, const char *opcoes[], int n_opcoes);
void MenuFuncionarios();
void Menu_EquipeDeBordo();
void Pilotos();
void mainMenu();

void menu(const char *titulo, const char *introducao, const char *opcoes[], int n_opcoes) {
    system("cls"); // Em sistemas Unix, troque por system("clear")
    printf("%s\n", titulo);

    if (introducao != NULL) {
        printf("%s:\n\n", introducao);
    }

    for (int i = 0; i < n_opcoes; i++) {
        printf("%d. %s\n", i + 1, opcoes[i]);
    }

    printf("\n");
}

void MenuFuncionarios() {
    int opcao;
    const char *opcoes[] = {
        "Equipe de bordo",
        "Seguranca",
        "Engenheiros",
        "Passageiros"
    };

    menu("Opcao escolhida - Funcionarios", "Especifique o grupo", opcoes, 4);
    scanf("%d", &opcao);

    if (opcao == 1) {
        Menu_EquipeDeBordo();
    }
}

void Menu_EquipeDeBordo() {
    int opcao;
    const char *opcoes[] = {
        "Piloto / Copiloto",
        "Comissarios de bordo"
    };

    menu("Opcao escolhida - Equipe de bordo", "Pilotos ou comissarios?", opcoes, 2);
    scanf("%d", &opcao);

    if (opcao == 1) {
        Pilotos();
    }
}

void Pilotos() {
    FILE *pilotos = fopen("pilotos.txt", "r");
    if (pilotos == NULL) {
        printf("Erro ao abrir o arquivo 'pilotos.txt'.\n");
        return;
    }

    // Exemplo: ler e imprimir o conteúdo do arquivo
    char linha[100];
    while (fgets(linha, sizeof(linha), pilotos)) {
        printf("%s", linha);
    }

    fclose(pilotos);
}

void mainMenu() {
    int opcao;
    const char *opcoes[] = {
        "Funcionarios",
        "Voos",
        "Aeronaves",
        "Passageiros"
    };

    menu("Aeroporto Santos Dumont", "Escolha uma opcao", opcoes, 4);
    scanf("%d", &opcao);

    if (opcao == 1) {
        MenuFuncionarios();
    }
}

int main() {
    mainMenu();
    return 0;
}

