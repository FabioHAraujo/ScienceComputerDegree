#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <iostream>
#include <iomanip>
#include <chrono>
#include <random>

using namespace std;

class Ordenacao {
private:
    void aleatorios(long A[], long n, long B[]) {
        cout << "Certo, você gerou " << n << " números, agora vou colocá-los em um array aleatório." << endl;
        
        srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios

        for (long i = 0; i < n; i++) {
            A[i] = rand() % n;
            B[i] = A[i];
        }
    }



    void merge(long A[], long ini, long meio, long fim){
        long tamArray=fim-ini;
        long fitaIni=ini;
        long fitaMeio=meio;

        long k=0;
        long *arrayAux = new long[tamArray];

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

        for(long i=0; i<tamArray; i++)
            A[ini+i] = arrayAux[i];
        delete[] arrayAux;
    }

    void mergeSort(long A[], long ini, long fim){
        if (ini<fim){ // 
            long meio = (ini+fim)/2;
            mergeSort(A, ini, meio);
            mergeSort(A, meio+1, fim);
            merge(A, ini, meio, fim);
        }
    }

    void buscaBinaria(long A[],long ini, long numero, long fim){
        if (ini<fim){
            long meio = (ini+fim)/2;
            if(numero==A[meio]) {
                cout << "Cara, achei o numero na posicao " << meio << "!!!"<< endl;
            }
            else if(numero<A[meio]){
                buscaBinaria(A, ini, numero, meio);
            }
            else if(numero>A[meio]){
                buscaBinaria(A, meio+1, numero, fim);
            }
        }
        else cout << "NAO DEU NAO, BROTHER!!!" << endl;
    }

public:
    void executarOrdenacao() {
        long n=0, numero;
        cout << "Bem vindo ao programa de ordenacao de arrays." << endl;
        cout << "Este Programa ordena arrays usando 5 metodos diferentes e imprime em ordem, o array original, o tempo gasto para ordenar o array em cada metodo e o array final." << endl;
        cout << "Digite sua escolha: ";
        cout << "Quantos numeros deseja gerar? ";  
        cin >> n;

        long A[n], B[n];
        aleatorios(A, n, B);

        cout << "Agora escolha um numero para buscar: ";
        cin >> numero;

        auto inicio = chrono::high_resolution_clock::now();
        mergeSort(A, 0, n);
        auto fim = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = fim - inicio;
        double segundos = duration.count();
        cout << "Tempo Gasto para ordenar por Merge Sort: " << segundos << " segundos!" << endl;

        buscaBinaria(A, 0, numero, n);
    }
};

#endif
