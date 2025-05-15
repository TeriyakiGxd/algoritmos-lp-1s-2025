#include <stdio.h>
#include <math.h>

int main(int argc, char *argv){

    int primo;
    
    printf("digite um numero: ");
    scanf ("%d", &primo);
    printf ("\n");

    if (primo <= 1){
        printf("Numeros menores ou iguais a 1 nao sao primos");
    }

    for (int i = 2; i <= sqrt(primo); i++){

        if (primo % i == 0){
            printf("O numero nao eh primo!");
        } else {
            printf("O numero eh primo!");
        }
        
    }

return 0;
}