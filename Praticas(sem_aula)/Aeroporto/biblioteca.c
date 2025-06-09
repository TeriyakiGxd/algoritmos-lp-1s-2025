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