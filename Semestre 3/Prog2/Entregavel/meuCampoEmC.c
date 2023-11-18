#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar o campo
typedef struct {
    int linhas;
    int colunas;
    char** campo;
} Campo;

// Função para criar um campo
Campo* criaCampo(int linhas, int colunas) {
    Campo* campo = (Campo*)malloc(sizeof(Campo));
    campo->linhas = linhas;
    campo->colunas = colunas;

    campo->campo = (char**)malloc(linhas * sizeof(char*));
    for (int i = 0; i < linhas; i++) {
        campo->campo[i] = (char*)malloc(colunas * sizeof(char));
    }

    return campo;
}

// Função para liberar a memória de um campo
void liberaCampo(Campo* campo) {
    for (int i = 0; i < campo->linhas; i++) {
        free(campo->campo[i]);
    }
    free(campo->campo);
    free(campo);
}

// Função para inicializar um campo
void zeraCampo(Campo* campo) {
    for (int i = 0; i < campo->linhas; i++) {
        for (int j = 0; j < campo->colunas; j++) {
            if (campo->campo[i][j] == '.') {
                campo->campo[i][j] = '0';
            }
        }
    }
}

// Função para alterar o campo
void alteraCampo(Campo* campo) {
    int linhas = campo->linhas;
    int colunas = campo->colunas;

    // Define as posições
    int posColuna[] = {1, 0, -1};
    int posLinha[] = {1, 0, -1};

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (campo->campo[i][j] == '*') {
                // Se encontrar uma bomba, percorre os vizinhos
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        int agoraLinha = i + posLinha[k];
                        int agoraColuna = j + posColuna[l];
                        // Verifica se é menor que linhas e menor que colunas e se não é uma bomba.
                        if (agoraLinha >= 0 && agoraLinha < linhas && agoraColuna >= 0 && agoraColuna < colunas && campo->campo[agoraLinha][agoraColuna] != '*') {
                            campo->campo[agoraLinha][agoraColuna]++;
                        }
                    }
                }
            }
        }
    }
}

// Função para imprimir o campo
void imprimeCampo(Campo* campo, int index) {
    printf("Field #%d:\n", index);
    for (int i = 0; i < campo->linhas; i++) {
        for (int j = 0; j < campo->colunas; j++) {
            printf("%c", campo->campo[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int linhas, colunas;
    int index = 1;
    Campo** campos = NULL; // Array de campos

    while (scanf("%d %d", &linhas, &colunas) == 2) {
        if (linhas == 0 && colunas == 0) {
            break;
        }

        // Criar um novo campo
        Campo* campo = criaCampo(linhas, colunas);

        // Ler o campo
        for (int i = 0; i < linhas; i++) {
            scanf("%s", campo->campo[i]);
        }

        // Zerar e alterar o campo
        zeraCampo(campo);
        alteraCampo(campo);

        // Acompanhar os campos
        campos = (Campo**)realloc(campos, index * sizeof(Campo*));
        campos[index - 1] = campo;

        index++;
    }

    // Imprimir os campos
    for (int i = 0; i < index - 1; i++) {
        imprimeCampo(campos[i], i+1);
        liberaCampo(campos[i]); // Liberar a memória de cada campo
    }

    free(campos); // Liberar a memória do array de campos

    return 0;
}
