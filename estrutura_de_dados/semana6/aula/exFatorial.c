#include <stdio.h>
// Fatorial usando a estratégia iterativa
int fatorial_iterativo(int n) {
    int i;
    int fat = 1;
    for (i=n; i>1; i--)
        fat *= i;
    return fat;
}
// Fatorial usando a estratégia recursiva
int fatorial_recursivo(int n) {
    if (n == 1)
        return 1;
    else
        return n * fatorial_recursivo(n-1);
}

int main (void) {
    int n;
    printf("Sobre qual numero, voce deseja descobrir o fatorial? ");
    scanf("%d", &n);
    printf("Fatorial de %d = %d\n\n", n, fatorial_iterativo(n));
    printf("Fatorial de %d = %d", n, fatorial_recursivo(n));
    getchar();
    return 1;
}