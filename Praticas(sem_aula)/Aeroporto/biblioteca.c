#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>

void menu(const char *titulo, const char *introducao, const char *opcoes[], int n_opcoes);
void MenuFuncionarios();
void Menu_EquipeDeBordo();
void Pilotos();
void gerenciarPilotos();
void consultarPiloto();
char *gerarID(const char *tipo_voo);
int idExiste(const char *id);
void limparBuffer();
void letrasMinusculas(char *str);
void mainMenu();

void menu(const char *titulo, const char *introducao, const char *opcoes[], int n_opcoes) {
    system("cls");
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
    limparBuffer();

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
    limparBuffer();

    if (opcao == 1) {
        Pilotos();
    }
}

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

    printf("\n1. Cadastrar novo piloto\n2. Consultar piloto\n3. Voltar\nEscolha uma opçcao: ");
    int escolha;
    scanf("%d", &escolha);
    limparBuffer();

    if (escolha == 1) {
        char  nome[100], cpf[20], licenca[50], numero[20], email[100], tipo_voo[20], id[30];

        printf("\nDigite o nome do piloto: ");
        fgets(nome, sizeof(nome), stdin);

        printf("Digite o CPF: ");
        fgets(cpf, sizeof(cpf), stdin);

        printf("Digite a licenca de piloto: ");
        fgets(licenca, sizeof(licenca), stdin);

        printf("Digite o numero de telefone: ");
        fgets(numero, sizeof(numero), stdin);

        printf("Digite o email: ");
        fgets(email, sizeof(email), stdin);

        printf("O piloto faz voos internacionais? (s/n): ");
        char resposta;
        scanf("%c", &resposta);
        limparBuffer();
        
        strcpy(tipo_voo, (resposta == 's' || resposta == 'S') ? "Internacional" : "Nacional");

        do {
            strcpy(id, gerarID(tipo_voo));
        } while (idExiste(id));

        nome[strcspn(nome, "\n")] = 0;
        cpf[strcspn(cpf, "\n")] = 0;
        licenca[strcspn(licenca, "\n")] = 0;
        numero[strcspn(numero, "\n")] = 0;
        email[strcspn(email, "\n")] = 0;

        fprintf(arquivo, "ID: %s | Nome: %s | CPF: %s | Licenca: %s | Telefone: %s | Email: %s | Tipo de Voo: %s\n\n",
                id, nome, cpf, licenca, numero, email, tipo_voo);

        printf("\nPiloto cadastrado com sucesso, ID registrado: %s\n", id);
        system("pause");
    } else if (escolha == 2) {
        consultarPiloto();
    }

    fclose(arquivo);
    Menu_EquipeDeBordo();
}

char *gerarID(const char *tipo_voo) {
    static char id[30];
    int num = rand() % 9000 + 1000;

    if (strcmp(tipo_voo, "internacional") == 0){
        sprintf(id, "INT-%d", num);}
    else if (strcmp(tipo_voo, "nacional") == 0){
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
        printf("Nenhum piloto encontrado com o termo: %s\n", buscarPiloto);

    fclose(arquivo);
    system("pause");
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
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
    limparBuffer();

    if (opcao == 1) {
        MenuFuncionarios();
    }
}

void letrasMinusculas(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
}