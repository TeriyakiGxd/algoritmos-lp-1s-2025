#include <stdio.h>

int main(int argc, char* argv[]){
    int qtd_Alunos = 0;

    printf("Informe a quantidade de alunos: ");
    scanf("%d", &qtd_Alunos);

    float notas[qtd_Alunos];

    for(int i = 0; i < qtd_Alunos; i++){
        do{

            printf("\nDigite a nota %d: ", i);
            scanf("%f", &notas[i]);

        } while (notas[i] > 10.0 || notas[i] < 0.0);
    }

    int posicaoNota;

    printf("\nInforme a posicao da nota: ");
    scanf("%d", &posicaoNota);

    float soma_Notas = 0.0;
    float media_Notas = 0.0;
    float menor_Nota = notas[0];
    float maior_Nota = notas[0];
    int qtd_Alunos_Aprovados = 0;


    for(int i = 0; i < qtd_Alunos; i++){
        soma_Notas += notas[i];

        if(menor_Nota > notas[i]){
            menor_Nota = notas[i];
        }

        if(maior_Nota < notas[i]){
            maior_Nota = notas[i];
        }

        if(notas[i] >= 6.0){
            qtd_Alunos_Aprovados++;
        }

    }


    media_Notas = soma_Notas / qtd_Alunos;
    printf("\nMedia das notas: %.2f", media_Notas);
    printf("\nMenor nota: %.2f", menor_Nota);
    printf("\nMaior nota: %.2f", maior_Nota);
    printf("\nQtd. alunos aprovados: %d", qtd_Alunos_Aprovados);
    printf("\nNota do aluno %d: %.2f", posicaoNota, notas[posicaoNota]);


    return 0;
}