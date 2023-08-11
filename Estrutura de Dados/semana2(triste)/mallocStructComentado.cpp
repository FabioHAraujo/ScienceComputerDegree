#include <iostream>
#include <iomanip>

using namespace std;

// Define a struct aluno, que será usada para armazenar os dados de um aluno
struct aluno {
    int matricula;
    char nome[31];
    float media;
};

// Função que exibe os dados dos alunos
void mostraAlunos(aluno *aln, int qtd);

int main(void){
    // Declara um ponteiro para aluno e uma variável para armazenar a quantidade de alunos
    aluno *aln;
    int qtd;
    
    // Solicita que o usuário informe a quantidade de alunos a serem armazenados
    cout << "Quantos Alunos Deseja Armazenar? ";
    cin >> qtd;
    
    // Aloca memória para armazenar um array de alunos usando new
    aln = new aluno[qtd];
    
    // Verifica se a alocação de memória foi bem-sucedida
    if (aln) {
        // Pede que o usuário insira os dados de cada aluno
        for (int i = 0; i < qtd; i++) {
            cout << "Por Favor, insira o nome do Aluno: " << endl;
            cin >> aln[i].nome;
            cout << "Agora Insira Sua Matricula: " << endl;
            cin >> aln[i].matricula;
            cout << "Agora Insira Sua Media: " << endl;
            cin >> aln[i].media;
        }
    } else {
        // Caso a alocação de memória tenha falhado, exibe uma mensagem de erro
        cout << "Erro: nao foi possivel alocar memoria suficiente." << endl;
    }
    
    // Chama a função que exibe os dados dos alunos
    mostraAlunos(aln, qtd);
    
    // Libera a memória alocada com new
    delete[] aln;
    
    // Retorna 0 para indicar que o programa terminou sem erros
    return 0;
}

// Implementa a função que exibe os dados dos alunos
void mostraAlunos(aluno *aln, int qtd){
    for (int i = 0; i < qtd; i++) {
        cout << aln[i].nome << endl;
        cout << aln[i].matricula << endl;
        cout << aln[i].media << endl;
        cout << "\n\n";
    }
}
