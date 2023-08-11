#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void aleatorios(int A[], int n, int B[]) {
    printf("Certo, voce gerou %d números, agora vou coloca-los em um array aleatório.\n", n);
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 100;
        B[i] = A[i];
    }
}

void decrescentes(int A[], int n, int B[]) {
    printf("Certo, voce gerou %d números, agora vou coloca-los em um array decrescente.\n", n);
    for (int i = 0; i < n; i++) {
        A[i] = n - i;
        B[i] = A[i];
    }
}

void exemplo(int A[], int n, int B[]) {
    printf("Voce gerou o array de exemplo da aula! \n");
    printf("Este Array comeca em 9 e vai ateh 0, decrescente.\n");
    for (int i = 0; i < n; i++) {
        A[i] = n - i - 1;
        B[i] = A[i];
    }
}

void bubble(int A[], int n) {
    n -= 1;
    int aux;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[j] > A[j + 1]) {
                aux = A[j];
                A[j] = A[j + 1];
                A[j + 1] = aux;
            }
        }
    }
    printf("Array Ordenado por Bubble Sort: ");
}

void selection(int A[], int n) {
    n -= 1;
    int aux, posi;
    for (int i = 0; i < n; i++) {
        posi = i;
        for (int j = i + 1; j <= n; j++) {
            if (A[j] < A[posi])
                posi = j;
        }
        aux = A[i];
        A[i] = A[posi];
        A[posi] = aux;
    }
    printf("Array Ordenado por Selection Sort: ");
}

void insertion(int A[], int n) {
    n -= 1;
    int aux;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j > 0; j--) {
            if (A[j] < A[j - 1]) {
                aux = A[j - 1];
                A[j - 1] = A[j];
                A[j] = aux;
            }
        }
    }
    printf("Array Ordenado por Insertion Sort: ");
}

void volta(int A[], int n, int B[]) {
    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }
    printf("O ARRAY FOI RETORNADO AO PADRAO: ");
}

void imprime(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%d, ", A[i]);
    }
    printf("%d.\n", A[n - 1]);
}

void executarOrdenacao() {
    int n=0, decisao;
    printf("Bem vindo ao programa de ordenacao de arrays.\n");
    printf("Este programa gera eh capaz de gerar 2 diferentes de array e depois ordena-los em ordem crescente.\n");

    #include <stdio.h>

    printf("Qual tipo de array deseja gerar?\n");
    printf("1 - Array com numeros aleatorios.\n");
    printf("2 - Array com numeros em ordem decrescente.\n");
    printf("3 - Array de Exemplo da Aula\n");
    printf("Digite sua escolha: ");
    scanf("%d", &decisao);

    if (decisao != 3) {
        printf("Quantos numeros deseja gerar? ");
        scanf("%d", &n);
    } else {
        n = 10;
    }

    int A[n], B[n];

    while (decisao != 1 && decisao != 2 && decisao != 3) {
        printf("Opção inválida. Por favor, selecione novamente: ");
        scanf("%d", &decisao);
    }

    if (decisao == 1)
        aleatorios(A, n, B);
    else if (decisao == 2)
        decrescentes(A, n, B);
    else if (decisao == 3)
        exemplo(A, n, B);

    printf("Array Original: ");
    imprime(A, n);
    bubble(A, n);
    imprime(A, n);
    volta(A, n, B);
    imprime(A, n);
    selection(A, n);
    imprime(A, n);
    volta(A, n, B);
    imprime(A, n);
    insertion(A, n);
    imprime(A, n);
}

int main(void) {
    srand(time(NULL));
    executarOrdenacao();

    return 0;
}
