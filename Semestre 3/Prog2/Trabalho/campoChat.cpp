#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Campo {
public:
    Campo(int linhas, int colunas) : linhas(linhas), colunas(colunas) {
        criaCampo();
    }

    void criaCampo() {
        campo.resize(linhas, vector<char>(colunas));
        for (int i = 0; i < linhas; i++) {
            string temporaria;
            cin >> temporaria;
            for (int j = 0; j < colunas; j++) {
                campo[i][j] = temporaria[j];
            }
        }
    }

    void zeraCampo() {
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                if (campo[i][j] == '.') campo[i][j] = '0';
            }
        }
    }

    void alteraCampo() {
    int linhas = campo.size();
    int colunas = campo[0].size();

    // Define os movimentos para as posições vizinhas (8 posições possíveis).
    int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
    int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (campo[i][j] == '*') {
                // Se a posição atual contém uma bomba (*), incrementa os vizinhos.
                for (int k = 0; k < 8; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && ni < linhas && nj >= 0 && nj < colunas && campo[ni][nj] != '*') {
                        // Verifica se a posição vizinha é válida e não é uma bomba.
                        campo[ni][nj]++;
                    }
                }
            } /*else if (campo[i][j] == '.') {
                // Se a posição atual é um lugar limpo, transforma em 0.
                campo[i][j] = '0';
            }*/  // NÃO FUNCIONA BEM, POIS SE ELE ACHA UMA BOMBA, TENTA SOMAR NUM ., GERANDO UMA / 
        }
    }
}

    void imprime(int index) {;
        cout << "Field #" << index << ":" << endl;
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                cout << campo[i][j];
            }
            cout << endl;
        }
    }

private:
    int linhas;
    int colunas;
    vector<vector<char>> campo; 
};

int main() {
    int linhas, colunas;
    int index = 1;
    vector<Campo> campos; // Vetor para armazenar os campos

    while (cin >> linhas >> colunas) {
        if (linhas == 0 && colunas == 0) {
            break;
        }
        Campo campo(linhas, colunas);
        campo.zeraCampo(); // Zera o campo
        campo.alteraCampo(); // Chama a função para alterar o campo
        campos.push_back(campo); // Armazena o campo no vetor
    }
    for (Campo& campo : campos) {
        campo.imprime(index);
        index++;
        cout << endl;
    }

    return 0;
}
