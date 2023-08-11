#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
using namespace std;

class Ordenacao {
private:
    void aleatorios(int A[], int n, int B[]) {
        cout << "Certo, voce gerou " << n << " numeros, agora vou coloca-los em um array aleatorio." << endl;
        for (int i = 0; i < n; i++) {
            A[i] = rand() % n;
            B[i] = A[i];
        }
    }

    void decrescentes(int A[], int n, int B[]) {
        cout << "Certo, voce gerou " << n << " numeros, agora vou coloca-los em um array decrescente." << endl;
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
        cout << "Tempo gasto para ordenar pelo Bubble Sort: ";
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
        cout << "Tempo gasto para ordenar pelo Selection Sort: ";
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

    void merge(int A[], int ini, int meio, int fim) {

        // Calcula o tamanho do array auxiliar
        int tamArray = fim - ini + 1;
        int* arrayAux = new int[tamArray];

        // Inicializa os ponteiros das fitas
        int fitaEsq = ini;
        int fitaMeio = meio + 1;
        int k = 0;

        // Combina os elementos em ordem crescente
        while (fitaEsq <= meio && fitaMeio <= fim) {
            if (A[fitaEsq] <= A[fitaMeio]) {
                arrayAux[k] = A[fitaEsq];
                fitaEsq++;
            } else {
                arrayAux[k] = A[fitaMeio];
                fitaMeio++;
            }
            k++;
        }

        // Copia os elementos restantes da fita esquerda
        while (fitaEsq <= meio) {
            arrayAux[k] = A[fitaEsq];
            fitaEsq++;
            k++;
        }

        // Copia os elementos restantes da fita do meio
        while (fitaMeio <= fim) {
            arrayAux[k] = A[fitaMeio];
            fitaMeio++;
            k++;
        }

        // Copia os elementos do array auxiliar de volta para o array original
        for (int i = 0; i < tamArray; i++) {
            A[ini + i] = arrayAux[i];
        }

        // Libera a memoria alocada para o array auxiliar
        delete[] arrayAux;
    }

    void mergeSort(int A[], int ini, int fim) {
        // Verifica se e necessario continuar dividindo o array
        if (ini < fim) {
            int meio = (ini + fim) / 2;

            // Divide o array ao meio e chama a funcao recursivamente para cada metade
            mergeSort(A, ini, meio);
            mergeSort(A, meio + 1, fim);

            // Combina as duas metades ordenadas
            merge(A, ini, meio, fim);
        }
    }


    void buscaBinaria(int A[], int ini, int numero, int fim) {
        if (ini < fim) {
            int meio = (ini + fim) / 2;
            if (numero == A[meio]) {
                cout << "Cara, achei o numero " << numero << " na posicao " << meio << " do array!!!" << endl;
                cout << "Ou, caso voce seja humano (improvavel), achei o numero " << numero << " na posicao " << meio + 1 << " da sua contagem humana :(" << endl;
            } 
            else if (numero < A[meio]) {
                buscaBinaria(A, ini, numero, meio);
            } 
            else if (numero > A[meio]) {
                buscaBinaria(A, meio + 1, numero, fim);
            }
        } 
        else cout << "Nao foi possivel encontrar o numero " << numero << " no array." << endl;
    }

public:
    void volta(int A[], int n, int B[]) {
        for (int i = 0; i < n; i++) {
            A[i] = B[i];
        }
        cout << "O ARRAY FOI RETORNADO AO PADRaO!" << endl;
    }

    void imprime(int A[], int n) {
        for (int i = 0; i < n - 1; i++) {
            cout << A[i] << ", ";
        }
        cout << A[n - 1] << ". " << endl;
    }

    void executarOrdenacao() {
        int n = 0, decisao, numero;
        cout << "Bem-vindo ao programa de ordenacao de arrays." << endl;
        cout << "Este programa ordena arrays usando 4 metodos diferentes e imprime, em ordem, o array original, o tempo gasto para ordenar o array em cada metodo e o array final." << endl;
        cout << "Nesta versao, tambem conta com a Busca Binaria para localizar um numero especifico" << endl;

        cout << "Qual tipo de array deseja gerar?" << endl;
        cout << "1 - Array com numeros aleatorios." << endl;
        cout << "2 - Array com numeros em ordem decrescente." << endl;
        cout << "Digite sua escolha: ";
        cin >> decisao;

        if (decisao != 3) {
            cout << "Quantos numeros deseja gerar? ";
            cin >> n;
        } else {
            n = 10;
        }

        int A[n], B[n];

        while (decisao != 1 && decisao != 2) {
            cout << "Opcao invalida. Por favor, selecione novamente: ";
            cin >> decisao;
        }
        if (decisao == 1)
            aleatorios(A, n, B);
        else if (decisao == 2)
            decrescentes(A, n, B);
        
        cout << "Agora escolha um numero para buscar: ";
        cin >> numero;
        // imprime(A, n); removido para nao spammar o CLI
        auto inicio = chrono::high_resolution_clock::now();
        bubble(A, n);
        auto fim = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = fim - inicio;
        double segundos = duration.count();
        cout << "Tempo gasto para ordenar por Bubble Sort: " << segundos << " segundos." << endl;
        // RETORNA O ARRAY AO PADRaO
        volta(A, n, B);
        inicio = chrono::high_resolution_clock::now();
        selection(A, n);
        fim = chrono::high_resolution_clock::now();
        duration = fim - inicio;
        segundos = duration.count();
        cout << "Tempo Gasto para ordenar por Selection Sort: " << segundos << " segundos." << endl;
        // RETORNA O ARRAY AO PADRaO
        volta(A, n, B);
        inicio = chrono::high_resolution_clock::now();
        insertion(A, n);
        fim = chrono::high_resolution_clock::now();
        duration = fim - inicio;
        segundos = duration.count();
        cout << "Tempo gasto para ordenar pelo Insertion Sort: " << segundos << " segundos." << endl;
        cout << "Agora vou usar o Merge Sort para ordenar seus numeros... aguenta ai!" << endl;
        inicio = chrono::high_resolution_clock::now();
        mergeSort(A, 0, n);
        fim = chrono::high_resolution_clock::now();
        duration = fim - inicio;
        segundos = duration.count();
        cout << "Tempo Gasto para ordenar por Merge Sort: " << segundos << " segundos!" << endl;
        // imprime(A, n); retirado para evitar um spam no CLI
        buscaBinaria(A, 0, numero, n);
    }
};


int main(void) {
    srand(time(0));
    Ordenacao ordenacao;
    ordenacao.executarOrdenacao();

    return 0;
}

