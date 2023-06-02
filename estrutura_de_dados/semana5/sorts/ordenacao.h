#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <iostream>
#include <iomanip>

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
        cout << "Array Ordenado por Bubble Sort: ";
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
        cout << "Array Ordenado por Selection Sort: ";
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
        cout << "Array Ordenado por Insertion Sort: ";
    }

public:
    void volta(int A[], int n, int B[]) {
        for (int i = 0; i < n; i++) {
            A[i] = B[i];
        }
        cout << "O ARRAY FOI RETORNADO AO PADRAO: ";
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
        
        cout << "Array Original: ";
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
};

#endif
