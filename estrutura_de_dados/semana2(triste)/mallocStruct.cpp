#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

struct aluno {
    int matricula;
    char nome[31];
    float media;
};

void mostraAlunos(aluno *aln, int qtd);

int main(void){
    aluno *aln;
    int qtd;
    cout << "Quantos Alunos Deseja Armazenar? ";
    cin >> qtd;
    //abaixo está exemplo criando objeto
    aln = new aluno[qtd];
    //esse outro exemplo usa o que foi ensinado em aula, para alocação usando Malloc
    //aln=(aluno*) malloc(qtd*sizeof(aluno));
    if(aln){
        for (int i=0; i<qtd; i++){
            cout << "Por Favor, insira o nome do Aluno: " << endl;
            cin >> aln[i].nome;
            cout << "Agora Insira Sua Matricula: " << endl;
            cin >> aln[i].matricula;
            cout << "Agora Insira Sua Media: " << endl;
            cin >> aln[i].media;
        }
    }
    mostraAlunos(aln, qtd);
}

void mostraAlunos(aluno *aln, int qtd){
    for (int i=0; i<qtd; i++){
    cout << "\n\n";
    cout << aln[i].nome << endl;
    cout << aln[i].matricula << endl;
    cout << aln[i].media << endl;
    cout << "\n\n";
    }
}