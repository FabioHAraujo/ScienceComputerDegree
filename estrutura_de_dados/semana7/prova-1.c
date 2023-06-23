#include <stdio.h>

#define TAMANHO 6

void sort1(int A[]) {
    int i, j, k, menor, aux;
    for (i = 0; i < TAMANHO; i++) {
        menor = i;
        for (j = i + 1; j < TAMANHO; j++) {
            if (A[j] < A[menor])
                menor = j;
        }
        aux = A[menor];
        A[menor] = A[i];
        A[i] = aux;
        
        for (k = 0; k < TAMANHO; k++)
            printf("%d ", A[k]);
        
        printf("\n");
    }
}

int main() {
    int A[TAMANHO] = {5, 3, 4, 6, 1, 2};
    sort1(A);
    return 0;
}
