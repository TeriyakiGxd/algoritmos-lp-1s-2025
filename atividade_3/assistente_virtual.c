#include <stdio.h>

int main (int argc, char* argv){

        printf("METFLIX\n");
        printf("Escolher tipo de filme:\n");

    int tipo;
        printf("1. Leve\n");
        printf("2. Intenso\n");
        scanf ("%d", &tipo);

        
        if (tipo == 1){
        printf("Escolher genero:\n");
            int filmeLeve;
                printf("1. Comedia\n");
                printf("2. Animacao\n");
            scanf ("%d", &filmeLeve);

                if (filmeLeve == 1){
                    printf("Assistir ao filme 'As Branquelas'");
                    
                } else if (filmeLeve == 2){
                    printf("Assistir ao filme 'Toy Story'");
        
                } else {

                    printf("opcao invalida!");

                }
             
            } else if (tipo == 2){
                printf("Escolher genero:\n");
                int filmeIntenso;
                printf("1. Terror\n");
                printf("2. Acao\n");
                scanf ("%d", &filmeIntenso);
    
                    if (filmeIntenso == 1){
                    printf("Escolha o Subgenero\n");
                    int subTerror;
                        printf("1. Psicologico\n");
                        printf("2. Sobreantural\n");
                        scanf ("%d", &subTerror);
                            if (subTerror == 1){
                                printf("Assistir ao filme 'corra'");
                                
                            } else if (subTerror == 2){
                                printf("Assistir ao filme 'Invocacao do Mal'");
                                
                            } else {

                             printf("Opcao invalida!");  

                            }

                }   else if (filmeIntenso == 2){
                    printf("Escolha o Subgenero\n");
                    int subAcao;
                        printf("1. Herois\n");
                        printf("2. Realista\n");
                        scanf ("%d", &subAcao);
                            if (subAcao == 1){
                                printf("Assistir ao filme 'Vingadores: Ultimato'");
                               
                            } else if (subAcao == 2){
                                printf("Assistir ao filme 'Mad Max: Estrada da Furia'");
                                
                            } else {

                             printf("Opcao invalida!");  

                            }

                    
                    }                   
                }
return 0; 
        }
            
