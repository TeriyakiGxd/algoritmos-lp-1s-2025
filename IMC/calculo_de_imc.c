#include <stdio.h>

int main (){

float peso;
float altura;

printf("CALCULO DE IMC\n\n");
printf("Ola! Digite o seu peso(kg):\n");
printf("Peso:");
scanf("%f", &peso);
printf("\n");
getchar();
printf("Por fim, digite a sua altura(metros):\n");
printf("Altura:");
scanf("%f", &altura);
printf("\n");
getchar();

float imc;

imc = peso/ (altura*altura) ;

printf ("%f", imc);

if(imc <= 18.5){

    printf("Seu IMC esta abaixo de 18,5 (abaixo do peso)");

} else if (imc >= 18.6 && imc <= 24.9 ) {

   printf("Seu IMC esta entre 18,6 e 24,9 (Peso ideal, meus parabens!)");

} else if (imc >= 25 && imc <= 29.9 ) {

   printf("Seu IMC esta entre 25 e 29,9 (Levemente acima do peso)");

} else if (imc >= 30 && imc <= 34.9 ) {

   printf("Seu IMC esta entre 30 e 34,9 (Obesidade)");

} else if (imc >= 35 && imc <= 39.9 ) {

   printf("Seu IMC esta entre 35 e 39,9 (Obesidade grau II [severa])");

}  if (imc > 40 ) {

   printf("Seu IMC esta acima de 40 (Obesidade grau III [morbida])");

}


return 0;
}