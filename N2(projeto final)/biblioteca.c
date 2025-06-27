#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>
#include "menus.h"

void limparBuffer();
void letrasMinusculas(char *str);

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
} 

void letrasMinusculas(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
}

int fecharPrograma(){
    printf("Saindo do programa, ate logo!\n\n");
    exit(0);
}

void apagarLinhaArquivo(const char *arquivo_Base, const char *termo_apagar) {
    FILE *arquivo_original;
    FILE *arquivo_temp;
    char linha[256];
    const char *arquivo_Base_temp = "temp.txt";
    int linha_apagada = 0;

    while (1){   
    
    arquivo_original = fopen(arquivo_Base, "r");
    if (arquivo_original == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo '%s' para leitura.\n", arquivo_Base);
        return;
    }

    arquivo_temp = fopen(arquivo_Base_temp, "w");
    if (arquivo_temp == NULL) {
        printf("Erro: Nao foi possivel criar o arquivo temporario '%s'.\n", arquivo_Base_temp);
        fclose(arquivo_original);
        return;
    }

    while (fgets(linha, sizeof(linha), arquivo_original) != NULL) {
        if (strstr(linha, termo_apagar) == NULL) {
            fprintf(arquivo_temp, "%s", linha);
        } else {
            printf("Linha contendo '%s' encontrada e removida.\n", termo_apagar);
            linha_apagada = 1;
        }
    }

    fclose(arquivo_original);
    fclose(arquivo_temp);

    if (remove(arquivo_Base) != 0) {
        printf("Erro: Nao foi possivel remover o arquivo original '%s'.\n", arquivo_Base);
        return;
    }

    if (rename(arquivo_Base, arquivo_Base) != 0) {
        printf("Erro: Nao foi possivel renomear o arquivo temporario para '%s'.\n", arquivo_Base);
       
    } else {
        if (linha_apagada) {
            printf("Linha(s) apagada(s) com sucesso de '%s'.\n", arquivo_Base);
            break;
        } else {
            printf("Nenhuma linha contendo '%s' foi encontrada em '%s'.\n", termo_apagar, arquivo_Base);
            break;
        }
    }
}
}