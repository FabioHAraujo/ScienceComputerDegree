#include <stdlib.h>
#include <stdio.h>

void imprime(int A[], int n){
    for (int i=0; i<n; i++){
        printf("%d", A[i]);
        printf(" ");
    }
}

int bubble(int A[], int n){
    for(int i=0; i<n; i++){
        while(A[i]<A[n-i]){
            
        }
    }
}

int main(){
    int A[10] = {9,8,7,6,5,4,3,2,1,0};
    /*Fazer uma buble, selection e insertion*/
    /*Bubble*/
    /*Sem desordenar primeiro*/
    /*O desordenar pode fazer tanto aleatório quanto voltar para o inicial*/
    printf("Bubble\n");
    bubble(A, 10);
    imprime(A, 10);
    //imprime(A);
    /*printf("Selection\n");
    desordenar(A, 10);
    selection_sort(A, 10);
    imprime(A);
    printf("Insertion\n");
    desordenar(A, 10);
    insertion_sort(A, 10);
    imprime(A);*/
    return 0;
}