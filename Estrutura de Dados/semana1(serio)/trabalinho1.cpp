#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct Alunos {
    string nome;
    float nota1, nota2, media;
};

float getMedias (vector<Alunos> *alnGet);

void outMedias (vector<Alunos> *alnOut);

int main (void){
    vector<Alunos> aluno;

    getMedias(&aluno);

    outMedias(&aluno);

}

float getMedias(vector<Alunos> *alnMed){
    int qtdAlunos;

    cout << "Ola, quantos alunos deseja inserir" << endl;
    cin >> qtdAlunos;

    for (int i=0; i<qtdAlunos; i++){
        Alunos tempAluno;

        cout << "Ola, seja bem vindo aluno numero " << i+1 << ", qual seu nome?" << endl;
        cin.ignore(); getline(cin, tempAluno.nome);

        cout << "Qual foi a sua primeira nota?" << endl;
        cin >> tempAluno.nota1;

        cout << "Qual foi a sua segunda nota?" << endl;
        cin >> tempAluno.nota2;

        tempAluno.media = (tempAluno.nota1+tempAluno.nota2)/2;
        (*alnMed).push_back(tempAluno);
    }
}

void outMedias(vector<Alunos> *alnOut){
    for (int i=0;i<(*alnOut).size();i++) cout << "A Media do Aluno " << (*alnOut)[i].nome << " Foi: " << fixed << setprecision(2) << (*alnOut)[i].media << endl;

}