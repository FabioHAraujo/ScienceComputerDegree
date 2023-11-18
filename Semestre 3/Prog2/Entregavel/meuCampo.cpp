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

        // Define as posições
        int posColuna[] = {1, 0, -1};
        int posLinha[] = {1, 0, -1};

        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                if (campo[i][j] == '*') {
                    // Se achar bomba percore os vizinhos
                    for (int k = 0; k <3 ; k++) {
                        for (int l = 0; l < 3; l++) {
                            int agoraLinha = i + posLinha[k];
                            int agoraColuna = j + posColuna[l];
                            // Verifica se é menor que linhas e menor que colunas e se não é uma bomba. Sem isso ele crashava :v
                            if (agoraLinha < linhas && agoraColuna < colunas && campo[agoraLinha][agoraColuna] != '*') {
                                campo[agoraLinha][agoraColuna]++;
                            }
                        }
                    }
                }
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