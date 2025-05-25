/*
Definindo estrutura "ponto"
*/

typedef struct {
    int x;
    int y;
} ponto;

/*
Inserindo funções determinadas em biblioteca.c
*/
ponto LerPonto(int n);

double CalculoDeDistancia(ponto a, ponto b);
