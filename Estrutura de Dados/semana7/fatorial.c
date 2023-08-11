#include <stdio.h>

int fatorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * fatorial(n - 1);
}

int main() {
    int num;
    printf("Digite um número inteiro não negativo: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("O número deve ser não negativo.\n");
        return 1;
    }

    int resultado = fatorial(num);
    printf("O fatorial de %d é: %d\n", num, resultado);

    return 0;
}
