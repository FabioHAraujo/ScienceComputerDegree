#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    void (*aleatorios)(int A[], int n, int B[]);
    void (*decrescentes)(int A[], int n, int B[]);
    void (*exemplo)(int A[], int n, int B[]);
    void (*bubble)(int A[], int n);
    void (*selection)(int A[], int n);
    void (*insertion)(int A[], int n);
    void (*merge)(int A[], int ini, int meio, int fim);
    void (*mergeSort)(int A[], int ini, int fim);
    void (*buscaBinaria)(int A[], int ini, int numero, int fim);
    void (*volta)(int A[], int n, int B[]);
    void (*imprime)(int A[], int n);
    void (*executarOrdenacao)();
} Ordenacao;

void aleatorios(int A[], int n, int B[]) {
    printf("Certo, voce gerou %d numeros, agora vou coloca-los num array aleatorio.\n", n);
    for (int i = 0; i < n; i++) {
        A[i] = rand() % n;
        B[i] = A[i];
    }
}

void decrescentes(int A[], int n, int B[]) {
    printf("Certo, voce gerou %d numeros, agora vou coloca-los num array decrescente.\n", n);
    for (int i = 0; i < n; i++) {
        A[i] = n - i;
        B[i] = A[i];
    }
}

void exemplo(int A[], int n, int B[]) {
    printf("Voce gerou o array de exemplo da aula!\n");
    printf("Este Array comeca em 9 e vai ate 0, decrescente.\n");
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
    printf("Tempo gasto para ordenar por Bubble Sort: ");
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
    printf("Tempo Gasto para ordenar por Selection Sort: ");
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
    printf("Tempo Gasto para ordenar por Insertion Sort: ");
}

void merge(int A[], int ini, int meio, int fim) {
    int tamArray = fim - ini;
    int fitaIni = ini;
    int fitaMeio = meio;

    int k = 0;
    int *arrayAux = (int*)malloc(tamArray * sizeof(int));

    while (fitaIni < meio && fitaMeio < fim) {
        if (A[fitaIni] <= A[fitaMeio]) {
            arrayAux[k] = A[fitaIni];
            fitaIni++;
            k++;
        }
        else {
            arrayAux[k] = A[fitaMeio];
            fitaMeio++;
            k++;
        }
    }

    while (fitaIni < meio) {
        arrayAux[k] = A[fitaIni];
        fitaIni++;
        k++;
    }
    while (fitaMeio < fim) {
        arrayAux[k] = A[fitaMeio];
        fitaMeio++;
        k++;
    }

    for (int i = 0; i < tamArray; i++)
        A[ini + i] = arrayAux[i];
    free(arrayAux);
}

void mergeSort(int A[], int ini, int fim) {
    if (ini < fim) {
        int meio = (ini + fim) / 2;
        mergeSort(A, ini, meio);
        mergeSort(A, meio + 1, fim);
        merge(A, ini, meio, fim);
    }
}

void buscaBinaria(int A[], int ini, int numero, int fim) {
    if (ini < fim) {
        int meio = (ini + fim) / 2;
        if (numero == A[meio]) {
            printf("Cara, achei o numero na posicao %d!!!\n", meio);
        }
        else if (numero < A[meio]) {
            buscaBinaria(A, ini, numero, meio);
        }
        else if (numero > A[meio]) {
            buscaBinaria(A, meio + 1, numero, fim);
        }
    }
    else printf("NAO DEU NAO, BROTHER!!!\n");
}

void volta(int A[], int n, int B[]) {
    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }
    printf("O ARRAY FOI RETORNADO AO PADRAO!\n");
}

void imprime(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%d, ", A[i]);
    }
    printf("%d.\n", A[n - 1]);
}

void executarOrdenacao() {
    int n = 0, decisao, numero;
    printf("Bem vindo ao programa de ordenacao de arrays.\n");
    printf("Este Programa ordena arrays usando 5 metodos diferentes e imprime em ordem, o array original, o tempo gasto para ordenar o array em cada metodo e o array final.\n");
    
    printf("Qual tipo de array deseja gerar?\n");
    printf("1 - Array com numeros aleatorios.\n");
    printf("2 - Array com numeros em ordem decrescente.\n");
    printf("Digite sua escolha: ");
    scanf("%d", &decisao);
    
    if (decisao != 3) {
        printf("Quantos numeros deseja gerar? ");
        scanf("%d", &n);
    }
    else {
        n = 10;
    }

    int A[n], B[n];
    
    while (decisao != 1 && decisao != 2) {
        printf("Opção inválida. Por favor, selecione novamente: ");
        scanf("%d", &decisao);
    }
    if (decisao == 1) aleatorios(A, n, B);
    else if (decisao == 2) decrescentes(A, n, B);

    printf("Agora escolha um numero para buscar: ");
    scanf("%d", &numero);
    // imprime(A, n);
    clock_t inicio = clock();
    bubble(A, n);
    clock_t fim = clock();
    double segundos = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("%f segundos.\n", segundos);
    //RETORNA O ARRAY AO PADRAO
    volta(A, n, B);
    inicio = clock();
    selection(A, n);
    fim = clock();
    segundos = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("%f segundos.\n", segundos);
    //RETORNA O ARRAY AO PADRAO
    volta(A, n, B);
    inicio = clock();
    insertion(A, n);
    fim = clock();
    segundos = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("%f segundos.\n", segundos);
    inicio = clock();
    mergeSort(A, 0, n);
    fim = clock();
    segundos = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo Gasto para ordenar por Merge Sort: %f segundos!\n", segundos);
    // imprime(A, n);
    buscaBinaria(A, 0, numero, n);
}

int main(void) {
    srand(time(0));
    executarOrdenacao();

    return 0;
}
