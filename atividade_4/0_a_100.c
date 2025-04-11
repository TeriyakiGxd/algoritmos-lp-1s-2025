#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 1;
    printf("com WHILE:\n");
    
    do {
        printf("%d\n", n);
        n++;
    } while (n < 101);

    printf("com FOR:\n");

    for (n = 1; n < 101; n++){
        printf("%d\n", n);
    }

    return 0;
}
