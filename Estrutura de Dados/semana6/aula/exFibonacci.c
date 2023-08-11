#include <stdio.h>
// Série de Fibonacci usando a estratégia iterativa
long long int fibonacci_iterativo(int n) {
    long long int i, n_k, n_k_mais_1, res;
    if (n == 0 || n == 1)
        return 1;
    else {
        n_k = 1; n_k_mais_1 = 1;
        for (i=2; i<=n; i++) {
            res = n_k + n_k_mais_1;
            n_k = n_k_mais_1;
            n_k_mais_1 = res;
        }
        return res;
    }
}
// Série de Fibonacci usando a estratégia recursiva
long fibonacci_recursivo(int n) {
    if (n==1 || n==2) return 1;
    else return fibonacci_recursivo(n-1) + 
    fibonacci_recursivo(n-2);
}



int main (void) {
    int n;
    printf("Sobre qual numero, voce deseja descobrir o termo de Fibonacci? ");
    scanf("%d", &n);
    //printf("Fibonacci de F(%d) = %lld\n\n", n, fibonacci_iterativo(n));
    printf("Fibonacci de F(%d) = %ld", n, fibonacci_recursivo(n));
    getchar();
    return 1;
}