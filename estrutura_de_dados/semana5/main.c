#include <stdio.h> 

#include <string.h> 

void bubble_Sort(int A[], int n) {
    int i, j, aux;
    int steps = 0;

    for (i = n - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (A[j] > A[j + 1]) {
                aux = A[j];
                A[j] = A[j + 1];
                A[j + 1] = aux;
            }
            steps++;
        }
    }

    printf("Bubble: ");
    for (i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d.   Steps: %d\n", A[i], steps);
        } else {
            printf("%d, ", A[i]);
        }
    }
}

void Selection_Sort(int A[], int n){ 

int i = 0, j = 0, Aux = 0;
int minIndex=0;
    int steps = 0;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < n; j++) {
            if (A[j] < A[minIndex]) {
                minIndex = j;
            }
            steps++;
        }

        if (minIndex != i) {
            Aux = A[i];
            A[i] = A[minIndex];
            A[minIndex] = Aux;
        }
    }
    printf("Selection: ");
    for (i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d.   Steps: %d\n", A[i], steps);
        } else {
            printf("%d, ", A[i]);
        }
    }
}

void Insertion_Sort(int A[], int n){ 

    int i = 0, f = 0, key = 0, Steps = 0;

    for (i = 1; i < n; i++) {
        key = A[i];
        f = i - 1;

        while (f >= 0 && A[f] > key) {
            A[f + 1] = A[f];
            f = f - 1;
            Steps = (Steps + 1);
        }
        A[f + 1] = key;
    }

    
    printf("Insertion: ");
    
    for(i=0; i<n; i++){
        if(i==n-1){                   //Comfere se é ultimo elemento.
            
            printf("%d.   Steps: %d\n",A[i], Steps);
            
        }
        
        else{
            
            printf("%d, ",A[i]);
            
        }

    }

} 

void Reset(int A[], int n, int R[]){
    int i=0;
    for(i=0; i<n; i++){
        
        A[i] = (R[i]);
        
    }
    printf("Reset: ");
    
    for(i=0; i<n; i++){
        if(i==n-1){
            printf("%d.\n",A[i]);
        }
        else{
            printf("%d, ",A[i]);
        }
    }
}

int main () { 

    int i = 0, A[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; 
    int n = sizeof(A) / sizeof(A[0]);
    
    int R[n];
    for(i=0; i<n; i++){
        
        R[i]=(A[i]);
        
    }
    printf("n= %d\n",n);
    printf("Start: ");
    
    for(i=0; i<n; i++){
        if(i==n-1){
            
            printf("%d.\n",A[i]);
            
        }
        
        else{
            
            printf("%d, ",A[i]);
            
        }

    }

    bubble_Sort(A, n); 
    
    Reset(A, n, R); 

    Selection_Sort(A, n); 

    Reset(A, n, R); 

    Insertion_Sort(A, n); 

    return 0; 

} 