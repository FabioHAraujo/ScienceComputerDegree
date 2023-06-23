#include <stdio.h>

int recursao(int n) {
    if (n <= 10) {
        return n * 2;
    }
    else {
        return recursao(recursao(n / 3));
    }
}

int main() {
    int n = 27;
    int resultado = recursao(n);
    printf("O valor de retorno da funcao recursao(%d) eh: %d\n", n, resultado);
    return 0;
}
