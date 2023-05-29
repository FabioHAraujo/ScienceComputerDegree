#include <iostream>
#include <iomanip>


using namespace std;


int volta(int A[], int n){
    for (int i=0; i<n; i++){ 
        A[i]=B[i];
    }
}

/* 
antiga função volta, que na verdade só inverte a ordem utilizando bubble sort.
int volta(int A[], int n){
    n-=1;
    int aux;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (A[j] < A[j+1]){
               
                //Método mais inteligente para trocar valores de lugar
                //swap(A[j],A[j+1]);
                
                aux = A[j];
                A[j] = A[j+1];
                A[j+1] = aux;
            }
        }
    }
    cout << "O ARRAY FOI RETORNADO AO PADRAO: ";
}

*/

void bubble(int A[], int n){
    n-=1;
    int aux;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (A[j] > A[j+1]){/*
                swap(A[j],A[j+1]);*/
                aux = A[j];
                A[j] = A[j+1];
                A[j+1] = aux;
            }
        }
    }
    cout << "Array Ordenado por Bubble Sort: ";
}

void selection(int A[], int n){
    n-=1;
    int aux, posi;
    for (int i=0; i<n; i++){
        posi=i;
        for (int j=i+1; j<=n; j++){
            if (A[j] < A[posi]) posi = j;
        }
        aux = A[i];
        A[i] = A[posi];
        A[posi] = aux;
    }
    cout << "Array Ordenado por Selection Sort: ";
}

void insertion(int A[], int n){
    n-=1;
    int aux;
    for (int i=1; i<=n; i++){
        for (int j=i; j>0; j--){
            if(A[j] < A[j-1]){
                aux = A[j-1];
                A[j-1] = A[j];
                A[j] = aux;
            }
        }
    }

    cout << "Array Ordenado por Insertion Sort: ";

}

void imprime(int A[], int n){
    for (int i=0; i<n-1; i++){
        cout << A[i] << ", ";   
    }
    cout << A[n-1] << ". " << endl;
}


int main(void) {
    int n;
    cout << "Bem vindo ao programa de ordenacao de arrays." << endl;
    cout << "Este programa gera um array de n numeros aleatorios e o ordena." << endl;
    cout << "Quantos numeros deseja gerar? ";
    cin >> n;
    cout << "Certo, voce gerou " << n << " numeros, agora vou coloca-los num array." << endl;
    int A[n], B[n];
    for (int i=0; i<n; i++){ 
        A[i]= rand()%100;
        B[i]=A[i];
    }
    cout << "Array Original: ";
    imprime(A,n);
    bubble(A,n);
    imprime(A,n);
    volta(A,n);
    imprime(A,n);
    selection(A,n);
    imprime(A,n);
    volta(A,n);
    imprime(A,n);
    insertion(A,n);
    imprime(A,n);
}