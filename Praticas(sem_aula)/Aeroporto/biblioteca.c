#include <stdio.h>
#include <stdlib.h>



void menu(const char *titulo, const char *introducao, const char *opcoes[], int n_opcoes){

    system("cls");
    printf("%s\n", titulo);

    if(introducao != NULL){
        printf("%s:\n\n", introducao);
    }
    for (int i = 0; i < n_opcoes; i++){
        printf("%d. %s\n", i+1, opcoes[i]);
    }
    printf("\n");

}

void MenuFuncionarios (){
    int opcao;
    const char *opcoes[] = {
        "Equipe de bordo",
        "Seguranca",
        "Engenheiros",
        "Passageiros"
    };

    menu("Opcao escolhida - Funcionarios","Especifique o grupo", opcoes, 4);

    scanf("%d", &opcao);

    if (opcao == 1){
        Menu_EquipeDeBordo();
    }

}

void Menu_EquipeDeBordo(){
    int opcao;
    const char *opcoes[] = {
        "Piloto / Copiloto",
        "Comissarios de bordo"
    };

    menu("Opcao escolhida - Equipe de bordo","Pilotos ou comissarios?", opcoes, 2);
    scanf("%d", &opcao);

}



void mainMenu (){

    int opcao;
    const char *opcoes[] = {
        "Funcionarios",
        "Voos",
        "Aeronaves",
        "Passageiros"
    }; 
    menu("Aeroporto Santos Dumont","Escolha uma opcao", opcoes, 4);

    scanf("%d", &opcao);

    if (opcao == 1){
        MenuFuncionarios();
    }
}



