#include <stdio.h>

int main(int argc, char const *argv[])
{
    int quantidade_alunos;
  
    printf("Qual a quantidade de alunos? ");
    scanf("%d", &quantidade_alunos);

    float notas[quantidade_alunos];

    for(int i= 0; i < quantidade_alunos; i++){
        printf("Digite a nota do aluno %d: ",i);
        scanf("%d", &notas[i]);
    }
    
    return 0;
}
