#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void criaCampo(int campo[100][100], int linhas, int colunas);
void imprimeCampo(int campo[100][100], int linhas, int colunas);
void armazenaCampo(int campo[100][100], int linhas, int colunas);

int main (void) {
    bool entrada = true;
    while (entrada) {
        int campo[100][100];
        int linhas, colunas;
        cin >> linhas >> colunas; 
        cin.ignore();  // Ignora a quebra de linha
        if (linhas == 0 && colunas == 0) {
            entrada = false;
        } else {
            criaCampo(campo, linhas, colunas);
            armazenaCampo(campo, linhas, colunas);
        }
    }
}


void criaCampo(int campo[100][100], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        string temporaria;
        getline(cin, temporaria);
        for (int j = 0; j < colunas; j++) {
            char caracter = temporaria[j];
            campo[i][j] = caracter;
        }
    }
}

// Imprime todos os campos salvos em armazenaCampo, com #Field i
void imprimeCampo(int campo[100][100], int linhas, int colunas) {
    static int contador = 1;
    cout << "Field #" << contador << ":" << endl;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << campo[i][j];
        }
        cout << endl;
    }
    contador++;
}


// Salva o ultimo campo em uma string, todos os campos são impressos ao final com #Field i
string armazenaCampo(int campo[100][100], int linhas, int colunas) {
    static int contador = 1;
    string campoString;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            campoString += campo[i][j];
        }
        campoString += '\n';
    }
    contador++;

    return campoString;
}