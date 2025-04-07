#include <stdio.h>

#define size 9

void mostrar_tabuleiro (int tabuleiro [size][size]) {

    for (int i = 0; i < size; i++){
        if (i % 3 == 0 && i != 0) printf ("---------------------\n");
    for (int j = 0; j < size; j++){
        if(j % 3 == 0 && j != 0) printf ("|");

        printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int tabuleiro[size][size] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    mostrar_tabuleiro(tabuleiro);
    return 0;
}

int VerificarMovimento(int board[size][size], int linha, int coluna, int numero ){

    //verificar linha
    for (int j = 0;  j < size; j++){
        if(board [linha][j] == numero) return 0;
    }
    //verificar coluna
    for (int i = 0;  i < size; i++){
        if(board [i][coluna] == numero) return 0;
    }

    

}
