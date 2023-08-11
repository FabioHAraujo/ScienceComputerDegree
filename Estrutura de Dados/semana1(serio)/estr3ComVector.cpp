#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct Aluno{
    string nome;
    float nota1, nota2, media;
};

float insercao(vector<Aluno> *alunos);

void getMedias (vector<Aluno> *alunos);

int main(void){
    vector<Aluno> aln;
    
    insercao(&aln);

    getMedias(&aln);

}

float insercao(vector<Aluno> *alunos){
    int qtdAlunos;

    cout << "Por favor, quantos alunos deseja inserir?" << endl;
    cin >> qtdAlunos;

    for (int i=0;i<qtdAlunos;i++){
        Aluno tempAluno;

        cout << "Ola, seja bem vindo, vamos calcular sua media. Primeiramente, qual seu nome?\n";
        cin.ignore(); getline(cin, tempAluno.nome);

        cout << "Certo, vou te chamar de " << tempAluno.nome << ". Agora digite suas 2 notas\n";
        cin >> tempAluno.nota1 >> tempAluno.nota2;

        tempAluno.media = (tempAluno.nota1+tempAluno.nota2)/2;
        (*alunos).push_back(tempAluno);
    }
}

void getMedias (vector<Aluno> *alunos)
{
    for (int i=0;i<(*alunos).size();i++) cout << "A Media do Aluno " << (*alunos)[i].nome << " Foi: " << fixed << setprecision(2) << (*alunos)[i].media << endl;

    return;
}