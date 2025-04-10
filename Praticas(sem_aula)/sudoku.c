#include <stdio.h>

#define size 9

void mostrar_tabuleiro (int board [size][size]) {

    for (int i = 0; i < size; i++){
        if (i % 3 == 0 && i != 0) printf ("---------------------\n");
    for (int j = 0; j < size; j++){
        if(j % 3 == 0 && j != 0) printf ("|");

        printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int VerificarMovimento(int board[size][size], int lin, int col, int num ){

    //verificar lin
    for (int j = 0;  j < size; j++){
        if(board [lin][j] == num) return 0;
    }
    //verificar col
    for (int i = 0;  i < size; i++){
        if(board [i][lin] == num) return 0;
    }

    // Verificar a subgrade 3x3
    int startLin = lin - lin % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startLin + i][startCol + j] == num) return 0;
        }
    }

    return 1; // Movimento valido
}

int Solucionar(int board [size][size] ){
    int linha, coluna;
    int vazio = 0;

    for (int linha = 0; linha < size; linha++){
    for (int coluna = 0; coluna < size; coluna++){

    if (board[linha][coluna] == vazio){
            vazio = 1;
            break;
        }
    }

    if (vazio) break;
}

if (!vazio) return 1;

for (int num = 0; num <= 9; num ++){
    if (board [linha][coluna] == vazio){
        if (VerificarMovimento(board, linha, coluna, num)){

            board [linha][coluna] = num;
            if (Solucionar(board)) return 1;

            board [linha][coluna] = 0;
        
            }
        }
    }
}

void jogarSudoku ( int board [size][size]){

    int lin, col, num;

    while(1){
        printf("Digite a linha, Coluna e o Numero: ");
        scanf("%d %d %d", &lin, &col, &num);

        if (lin == 0 && col == 0 && num == 0) break;

        if (lin < 1 || lin > 9 || col < 1 || col > 9 || num < 1 || num > 9) {
            printf("Entrada invalida! Tente novamente.");
        }

        if (board [lin-1] [col-1] == 0  && VerificarMovimento(board, lin - 1, col - 1, num)){
            board [lin-1][col-1] = num;
            
            
        }else{
            printf("Movimento Invalido! Tente Novamente.");
        }
    }
}

int main(int argc, char const *argv[])
{
    int board[size][size] = {
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

    mostrar_tabuleiro(board);

    jogarSudoku(board);
        if (!Solucionar){
            printf("Nao existe solucao");
        }else{
            printf("Sudoku resolvido com sucesso!");
            mostrar_tabuleiro;
        }
    
    return 0;
}
