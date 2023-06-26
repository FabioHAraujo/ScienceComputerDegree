#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    int aux, j;
    for (int i = 1; i <= n; i++) {
        aux = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > aux) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = aux;
    }
    printf("Tempo gasto para ordenar pelo Insertion Sort: ");
}

void merge(int A[], int ini, int meio, int fim){
    int tamArray=fim-ini;
    int fitaIni=ini;
    int fitaMeio=meio;

    int k=0;
    int *arrayAux = (int*) malloc(tamArray * sizeof(int));

    while(fitaIni<meio && fitaMeio<fim){
        if(A[fitaIni]<=A[fitaMeio]){
            arrayAux[k]=A[fitaIni];
            fitaIni++;
            k++;
        }
        else{
            arrayAux[k]=A[fitaMeio];
            fitaMeio++;
            k++;
        }
    }

    while(fitaIni<meio){
        arrayAux[k]=A[fitaIni];
        fitaIni++;
        k++;
    }
    while(fitaMeio<fim){
        arrayAux[k]=A[fitaMeio];
        fitaMeio++;
        k++;
    }

    for(int i=0; i<tamArray; i++)
        A[ini+i] = arrayAux[i];
    free(arrayAux);
}

void mergeSort(int A[], int ini, int fim){
    if (ini<fim){
        int meio = (ini+fim)/2;
        mergeSort(A, ini, meio);
        mergeSort(A, meio+1, fim);
        merge(A, ini, meio, fim);
    }
}

void volta(int A[], int n, int B[]) {
    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }
    printf("O ARRAY FOI RETORNADO AO PADRAO!\n");
}

void executarOrdenacao() {
    int n = 0, decisao, numero;
    printf("Bem vindo ao programa de ordenacao de arrays.\n");
    printf("Este Programa ordena arrays usando 4 metodos diferentes e imprime em ordem, o array original, o tempo gasto para ordenar o array em cada metodo e o array final.\n");
    printf("\n");

    printf("Qual tipo de array deseja gerar?\n");
    printf("1 - Array com numeros aleatorios.\n");
    printf("2 - Array com numeros em ordem decrescente.\n");
    printf("Digite sua escolha: ");
    scanf("%d", &decisao);

    if (decisao != 3) {
        printf("Quantos numeros deseja gerar? ");
        scanf("%d", &n);
    } else {
        n = 10;
    }

    int *A = (int*) malloc(n * sizeof(int));
    int *B = (int*) malloc(n * sizeof(int));

    while (decisao != 1 && decisao != 2) {
        printf("Opção inválida. Por favor, selecione novamente: ");
        scanf("%d", &decisao);
    }
    if (decisao == 1) aleatorios(A, n, B);
    else if (decisao == 2) decrescentes(A, n, B);

    //ORDENACAO BUBBLE SORT
    clock_t inicio = clock(); // Inicia o timer
    bubble(A, n);
    clock_t fim = clock(); // Encerra o timer
    double duracao = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000; // Calcula a duração em milissegundos
    printf("%.4lf milissegundos! Ou, %.5lf segundos\n", duracao, duracao / 1000);
    //RETORNA O ARRAY AO PADRAO
    volta(A, n, B);


    // ORDENACAO SELECTION SORT
    inicio = clock();
    selection(A, n);
    fim = clock();
    duracao = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000;
    printf("%.4lf milissegundos! Ou, %.5lf segundos\n", duracao, duracao / 1000);
    //RETORNA O ARRAY AO PADRAO
    volta(A, n, B);

    // ORDENACAO INSERTION SORT
    inicio = clock();
    insertion(A, n);
    fim = clock();
    duracao = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000;
    printf("%.4lf milissegundos! Ou, %.5lf segundos\n", duracao, duracao / 1000);

    //RETORNA O ARRAY AO PADRAO
    inicio = clock();
    mergeSort(A, 0, n);
    fim = clock();
    duracao = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000;
    printf("Tempo Gasto para ordenar por Merge Sort: %.4lf milissegundos! Ou, %.5lf segundos\n", duracao, duracao / 1000);

    free(A);
    free(B);
}

int main(void) {
    srand(time(0));
    executarOrdenacao();

    return 0;
}
