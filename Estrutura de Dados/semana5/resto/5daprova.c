#include <stdio.h>
#define TAM 4
int main() {
    int matriz[TAM][TAM] = {
        {5, 6, 10, 2},
        {1, 4, 3, 0},
        {0, 0, 6, 4},
        {2, 3, 4, 8},
    };
    int *p, i;
    int soma = 0;
    p=&matriz[0][0];
    for (i=0; i < (TAM*TAM); i++){
        soma=soma+*p;
        p++;
    }

    printf("%d\n", soma);
    getchar();
}