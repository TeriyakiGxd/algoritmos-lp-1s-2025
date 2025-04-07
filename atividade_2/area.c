#include <stdio.h>

int main(int argc, char* argv){

    printf("AREA\n\n");

    printf("Digite a opcao desejada:");

    printf("c-circulo\n");
    printf("l-losango\n");
    printf("q-quadrado\n");
    printf("r-retangulo\n");
    printf("z-trapezio\n");
    printf("t-triangulo\n");

    char opcao;
    scanf("%c", &opcao);

    switch (opcao)
    {
    case 'c':
        float area;
        int raio;
        float const pi = 3.1415;

    printf("CALCULO DE AREA: CIRCULO\n\n");
        printf("Insira a medida do raio:");
        scanf("%d", &raio);
        getchar();

    area = (raio * raio) * pi;

        printf("\nA area desse circulo eh de %.2f", area);

        break;
    
        case 'l':

    int area;
    int diagonal1;
    int diagonal2;

    printf("CALCULO DE AREA: losango\n\n");
        printf("Insira a medida de uma das diagonais:");
        scanf("%d", &diagonal1);
        getchar();
        printf("por fim, insira a medida da segunda diagonal:");
        scanf("%d", &diagonal2);
        getchar();

    area = (diagonal1 * diagonal2) / 2;

        printf("\nA area desse losango eh de %d", area);

        break;
    
        case 'q':

    
        int area;
        int lado;

    printf("CALCULO DE AREA: QUADRADO\n\n");
        printf("Insira a medida dos lados:");
        scanf("%d", &lado);
        getchar();

        area = lado * lado;

        printf("\nA area desse quadrado eh de %d", area);


        break;
        
        case 'r':

    int area;
    int base;
    int altura;

    printf("CALCULO DE AREA: RETANGULO\n\n");
        printf("Insira a medida da base:");
        scanf("%d", &base);
        getchar();
        printf("Insira a medida da altura:");
        scanf("%d", &altura);
        getchar();

    area = base * altura;

        printf("\nA area desse retangulo eh de %d", area);

        break;

        case 'z':

    int area;
    int base1;
    int base2;
    int altura;

    printf("CALCULO DE AREA: TRAPEZIO\n\n");
        printf("Insira a medida de uma das bases:");
        scanf("%d", &base1);
        getchar();
        printf("Insira a medida da segunda base:");
        scanf("%d", &base2);
        getchar();
        printf("Insira a medida da altura:");
        scanf("%d", &altura);
        getchar();

    area = ((base1 + base2 ) * altura) / 2;

        printf("\nA area desse trapezio eh de %d", area);


         break;

        case 't':


    int area;
    int base;
    int altura;

    printf("CALCULO DE AREA: TRIANGULO\n\n");
        printf("Insira a medida da base:");
        scanf("%d", &base);
        getchar();
        printf("Insira a medida da altura:");
        scanf("%d", &altura);
        getchar();

    area = (base * altura) / 2;

        printf("\nA area desse triangulo eh de %d", area);

        break;
    }

}
