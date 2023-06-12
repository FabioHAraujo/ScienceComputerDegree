#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <iostream>
#include <iomanip>
#include <chrono>

using namespace std;

class Ordenacao {
private:
    void aleatorios(int A[], int n, int B[]) {
        cout << "Certo, voce gerou " << n << " numeros, agora vou coloca-los num array aleatorio." << endl;
        for (int i = 0; i < n; i++) {
            A[i] = rand() % 100;
            B[i] = A[i];
        }
    }

    void decrescentes(int A[], int n, int B[]) {
        cout << "Certo, voce gerou " << n << " numeros, agora vou coloca-los num array decrescente." << endl;
        for (int i = 0; i < n; i++) {
            A[i] = n - i;
            B[i] = A[i];
        }
    }

    void exemplo (int A[], int n, int B[]) {
        cout << "Voce gerou o array de exemplo da aula! " << endl;
        cout << "Este Array comeca em 9 e vai ateh 0, decrescente." << endl;
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
        cout << "Tempo gasto para ordenar por Bubble Sort: ";
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
        cout << "Tempo Gasto para ordenar por Selection Sort: ";
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
        cout << "Tempo Gasto para ordenar por Insertion Sort: ";
    }

    /*Merge do Raphael das Tartarugas Ninja \(>.<)/ */

    void merge(int A[], int ini, int meio, int fim){ // 6 elementos = 3 0,1,2,3 - 4,5
        int tamArray=fim-ini;
        int fitaIni=ini;
        int fitaMeio=meio;

        int k=0;
        int *arrayAux = new int[tamArray];

        while(fitaIni<meio && fitaMeio<fim){
            if(A[fitaIni]<=A[fitaMeio]){
                arrayAux[k]=A[fitaIni];
                fitaIni++; //0-1-2
                k++;
            }
            else{
                arrayAux[k]=A[fitaMeio];
                fitaMeio++; //3-4-5-6
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
        delete[] arrayAux;
        /*
        tentativa de for
        for (int j=0; j<tamArray; j++){
            if(A[fitaIni+k]<=arrayAux[fitaMeio+j]){
                A[j]=arrayAux[fitaIni+k];
                k++;
            }
            else{
                A[j]=arrayAux[fitaMeio+j];
                j++;
                k++;
            }
        }*/
        
    }

    void mergeSort(int A[], int ini, int fim){
        if (ini<fim){ // 
            int meio = (ini+fim)/2; //100 /50 /25 / 12 / 6 / 3 / 1 / 0 | 
            mergeSort(A, ini, meio); // 101+200/2 = 101+150/2 = 101+125/2 = 101+113/2 = 101+107/2 = 101+103/2 = 101+101/2 
            mergeSort(A, meio+1, fim); //101 / 
            merge(A, ini, meio, fim);
        }
    }

    /*Merge do Gepetão

    void merge(int A[], int ini, int meio, int fim) {
    int n1 = meio - ini + 1;
    int n2 = fim - meio;

    int *auxN1 = new int[n1];
    int *auxN2 = new int[n2];

    for (int i = 0; i < n1; i++)
        auxN1[i] = A[ini + i];

    for (int j = 0; j < n2; j++)
        auxN2[j] = A[meio + 1 + j];

    int i = 0;
    int j = 0;
    int k = ini;

    while (i < n1 && j < n2) {
        if (auxN1[i] <= auxN2[j]) {
            A[k] = auxN1[i];
            i++;
        } else {
            A[k] = auxN2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = auxN1[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = auxN2[j];
        j++;
        k++;
    }

    delete[] auxN1;
    delete[] auxN2;
    }

    */


/*
Deu ruim, apenas
    void merge(int A[], int ini, int meio, int fim){
        int n1 = meio - ini +1;
        int n2 = fim-meio;
        int *auxN1 = new int[n1];
        int *auxN2 = new int[n2];
        /*Guarda lado esquerdo
        for (int i=0; i<n1; i++)
            auxN1[i] = A[ini+i];
        /*Guarda lado direito, comecando do meio
        for (int j=0; j<n2; j++)
            auxN2[j] = A[meio+j];
        //int m=0;
        //while(m<fim){
            for (int k=0; k<fim; k++){
                if(auxN1[k]<=auxN2[k]){
                    A[k]=auxN1[k];
                    //m++;
                }
                else {
                    A[k]=auxN2[k];
                    //m++;
                }
            }
        //}
        //A[m]=auxN2[m];
    }

*/


public:
    void volta(int A[], int n, int B[]) {
        for (int i = 0; i < n; i++) {
            A[i] = B[i];
        }
        cout << "O ARRAY FOI RETORNADO AO PADRAO!" << endl;
    }

    void imprime(int A[], int n) {
        for (int i = 0; i < n - 1; i++) {
            cout << A[i] << ", ";
        }
        cout << A[n - 1] << ". " << endl;
    }

    void executarOrdenacao() {
        int n=0, decisao;
        cout << "Bem vindo ao programa de ordenacao de arrays." << endl;
        cout << "Este programa gera eh capaz de gerar 2 diferentes de array e depois ordena-los em ordem crescente." << endl;
        
        cout << "Qual tipo de array deseja gerar?" << endl; 
        cout << "1 - Array com numeros aleatorios." << endl;
        cout << "2 - Array com numeros em ordem decrescente." << endl;
        cout << "3 - Array de Exemplo da Aula" << endl;
        cout << "Digite sua escolha: ";
        cin >> decisao;
        
        if (decisao !=3) {
            cout << "Quantos numeros deseja gerar? ";  
            cin >> n;
        }
        else {
            n = 10;
        }

        int A[n], B[n];
        
        while (decisao != 1 && decisao != 2 && decisao != 3) {
            cout << "Opção inválida. Por favor, selecione novamente: ";
            cin >> decisao;
        }
        if (decisao == 1) aleatorios(A, n, B);
        else if (decisao == 2) decrescentes(A, n, B);
        else if (decisao == 3) exemplo(A, n, B);

        imprime(A, n);
        auto inicio = chrono::high_resolution_clock::now();
        bubble(A, n);
        auto fim = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = fim - inicio;
        double segundos = duration.count();
        cout << segundos << " segundos." << endl;
        //RETORNA O ARRAY AO PADRAO
        volta(A, n, B);
        inicio = chrono::high_resolution_clock::now();
        selection(A, n);
        fim = chrono::high_resolution_clock::now();
        duration = fim - inicio;
        segundos = duration.count();
        cout << segundos << " segundos." << endl;
        //RETORNA O ARRAY AO PADRAO
        volta(A, n, B);
        inicio = chrono::high_resolution_clock::now();
        insertion(A, n);
        fim = chrono::high_resolution_clock::now();
        duration = fim - inicio;
        segundos = duration.count();
        cout << segundos << " segundos." << endl;
        mergeSort(A, 0, n);
        cout << "array ordenado" << endl;
        imprime(A, n);
    }
};

#endif
