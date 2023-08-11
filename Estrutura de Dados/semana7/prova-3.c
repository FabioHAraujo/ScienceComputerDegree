#include <stdio.h>

void bubbleSort(int arr[], int size) {
    int i, j, temp;
    int comparisons = 0;
    int swaps = 0;
    
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            comparisons++;
            if (arr[j] > arr[j+1]) {
                swaps++;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    printf("Número de comparações: %d\n", comparisons);
    printf("Número de trocas: %d\n", swaps);
}

int main() {
    int arr[] = {5, 4, 1, 3, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int i;

    printf("Vetor antes da ordenação: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubbleSort(arr, size);

    printf("Vetor após a ordenação: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
