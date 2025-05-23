#include <stdio.h>
#include <stdlib.h>



void menu(const char *titulo, const char *introducao, const char *opcoes[], int n_opcoes){



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
    const char *opcoes[] = {
        "Equipe de bordo",
        "Seguranca",
        "Engenheiros",
        "Passageiros"
    };

    menu("Opcao escolhida - Funcionarios","Especifique o grupo", opcoes, 4);
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

