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
            A[i] = rand() % n;
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
        cout << "Tempo gasto para ordenar pelo Insertion Sort: ";
    }
    void merge(int A[], int ini, int meio, int fim){
        int tamArray=fim-ini;
        int fitaIni=ini;
        int fitaMeio=meio;

        int k=0;
        int *arrayAux = new int[tamArray];

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
        delete[] arrayAux;
    }

    void mergeSort(int A[], int ini, int fim){
        if (ini<fim){ // 
            int meio = (ini+fim)/2;
            mergeSort(A, ini, meio);
            mergeSort(A, meio+1, fim);
            merge(A, ini, meio, fim);
        }
    }

public:
    void volta(int A[], int n, int B[]) {
        for (int i = 0; i < n; i++) {
            A[i] = B[i];
        }
        cout << "O ARRAY FOI RETORNADO AO PADRAO!" << endl;
    }

    void executarOrdenacao() {
        int n=0, decisao, numero;
        cout << "Bem vindo ao programa de ordenacao de arrays." << endl;
        cout << "Este Programa ordena arrays usando 4 metodos diferentes e imprime em ordem, o array original, o tempo gasto para ordenar o array em cada metodo e o array final." << endl;
        cout << endl;
        
        cout << "Qual tipo de array deseja gerar?" << endl; 
        cout << "1 - Array com numeros aleatorios." << endl;
        cout << "2 - Array com numeros em ordem decrescente." << endl;
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
        
        while (decisao != 1 && decisao != 2) {
            cout << "Opção invalida. Por favor, selecione novamente: ";
            cin >> decisao;
        }
        if (decisao == 1) aleatorios(A, n, B);
        else if (decisao == 2) decrescentes(A, n, B);

        //ORDENACAO BUBBLE SORT
        auto inicio = chrono::high_resolution_clock::now(); // Inicia o timer
        bubble(A, n);
        auto fim = chrono::high_resolution_clock::now(); // Encerra o timer
        chrono::duration<double, milli> duracao = fim - inicio; // Calcula a duração em milissegundos
        double milissegundos = duracao.count();
        cout << milissegundos << " milissegundos! Ou, " << milissegundos/1000 << " segundos" << endl;
        //RETORNA O ARRAY AO PADRAO
        volta(A, n, B);


        // ORDENACAO SELECTION SORT
        inicio = chrono::high_resolution_clock::now();
        selection(A, n);
        fim = chrono::high_resolution_clock::now();
        duracao = fim - inicio;
        milissegundos = duracao.count();
        cout << milissegundos << " milissegundos! Ou, " << milissegundos/1000 << " segundos" << endl;
        //RETORNA O ARRAY AO PADRAO
        volta(A, n, B);

        // ORDENACAO INSERTION SORT
        inicio = chrono::high_resolution_clock::now();
        insertion(A, n);
        fim = chrono::high_resolution_clock::now();
        duracao = fim - inicio;
        milissegundos = duracao.count();
        cout << milissegundos << " milissegundos! Ou, " << milissegundos/1000 << " segundos" << endl;

        //RETORNA O ARRAY AO PADRAO
        inicio = chrono::high_resolution_clock::now();
        mergeSort(A, 0, n);
        fim = chrono::high_resolution_clock::now();
        duracao = fim - inicio;
        milissegundos = duracao.count();
        cout << "Tempo Gasto para ordenar por Merge Sort: " << milissegundos << " milissegundos! Ou, " << fixed << setprecision(5) << milissegundos/1000 << " segundos" << endl;
    }
};

#endif
