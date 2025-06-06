/*
Retorna o maior entre 2 números inteiros.
*/

int maior_2n(int a, int b){
    int maior;
    if (a > b){
        maior = a;
    } else {
        maior = b;
    }
    return maior;
}

/*
    retorna o maior entre 3 números inteiros.
*/

int maior_3n(int a, int b, int c){
    return maior_2n (maior_2n(a,b), c);

}

/*
Retorna o menor entre 2 números inteiros.
*/

int menor_2n(int a, int b){
    int menor;
    if (a < b){
        menor = a;
    } else {
        menor = b;
    }
    return menor;
}

/*
    retorna o menor entre 3 números inteiros.
*/

int menor_3n(int a, int b, int c){
    return menor_2n (menor_2n(a,b), c);

}