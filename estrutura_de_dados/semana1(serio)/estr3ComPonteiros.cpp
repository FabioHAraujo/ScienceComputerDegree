#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Aluno{
    string nome;
    float nota1, nota2, media;
};

float insercao(Aluno alunos[], int qtdAlunos);

void getMedias (Aluno alunos[], int qtdAlunos);

int main(){
    int qtdAlunos;
    cout << "Por favor, quantos alunos deseja inserir?" << endl;
    cin >> qtdAlunos;
    Aluno aln[qtdAlunos];
    insercao(aln, qtdAlunos);
    getMedias(aln, qtdAlunos);

    return 0;
}

float insercao(Aluno alunos[], int qtdAlunos){
    for (int i=0;i<qtdAlunos;i++){
        cout << "Ola, seja bem vindo, vamos calcular sua media. Primeiramente, qual seu nome?\n";
        cin.ignore(); getline(cin, alunos[i].nome);
        cout << "Certo, vou te chamar de " << alunos[i].nome << ". Agora digite suas 2 notas\n";
        cin >> alunos[i].nota1 >> alunos[i].nota2;
        alunos[i].media = (alunos[i].nota1+alunos[i].nota2)/2;
    }
}

void getMedias (Aluno alunos[], int qtdAlunos)
{
    for (int i=0;i<qtdAlunos;i++){
        cout << "A Media do Aluno " << alunos[i].nome << " Foi: " << fixed << setprecision(2) << alunos[i].media << endl;
    }

    return;
}