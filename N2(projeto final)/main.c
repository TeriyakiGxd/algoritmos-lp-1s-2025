#include "biblioteca.h"
#include "menus.h"
#include "pilotos.h"
#include "cadastro.h"
#include <stdio.h>
#include <stdlib.h>
#include "aeronaves.h"


int main(int agrc, char *argv[]){
 FILE *arquivo = fopen("logins.txt", "a+");

    if (login()) {
        mainMenu();
    }

    return 0; 
}