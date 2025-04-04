#include <stdio.h>

int main (int argc, char* argv){

        printf("METFLIX\n");
        printf("Escolher tipo de filme:\n");

    int tipo;
        printf("1. Leve\n");
        printf("2. Intenso\n");
        scanf ("%d", &tipo);


        if (tipo = 1){
            printf("Escolher genero:\n");
                int filmeLeve;
                    printf("1. Comedia\n");
                    printf("2. Animacao\n");
            scanf ("%d", &filmeLeve);           
                if (filmeLeve = 1){
                printf("Assistir ao filme 'As Branquelas'");
                if (filmeLeve = 2)
                printf("Assistir ao filme 'Toy Story'");}
            
        if (tipo = 2){

            printf("Escolher genero:\n");
                int generoIntenso;
                    printf("1. Terror\n");
                    printf("2. Acao\n");
                    scanf ("%d", &generoIntenso);

                    if (generoIntenso = 1){
                        printf("Escolher subgenero:\n");
                            int subgeneroTerror;
                                printf("1. Psicologico\n");
                                printf("2. Sobrenatural\n");
                                scanf("%i", &subgeneroTerror);
                                    if (subgeneroTerror = 1)
                                        printf("Assistir ao filme 'Corrra'\n");
                                    if (subgeneroTerror = 2);
                                        printf("Assistir ao filme 'invocacao do mal'");
   
        }


    

            return 0;

        }

        return 0;
        
                        }