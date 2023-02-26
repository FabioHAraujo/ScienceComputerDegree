#include <iostream>
#include <iomanip>
#include <string>
#define Red             0xF800

using namespace std;

struct Aluno{
    string nome;
    float nota1, nota2, media;
};


void escrita (){
    cout << "piriri";

}

int main(){
    int qtdAlunos;
    cout << "Por favor, quantos alunos deseja inserir?" << endl;
    cin >> qtdAlunos;
    Aluno aln[qtdAlunos];
    for (int i=0;i<qtdAlunos;i++){
        cout << "Ola, seja bem vindo, vamos calcular sua media. Primeiramente, qual seu nome?\n";
        cin.ignore();
        getline(cin, aln[i].nome);
        cout << "Certo, vou te chamar de " << aln[i].nome << ". Agora digite suas 2 notas\n";
        cin >> aln[i].nota1 >> aln[i].nota2;
        aln[i].media = (aln[i].nota1+aln[i].nota2)/2;
    }
    for (int i=0;i<qtdAlunos;i++){
        cout << "A Media do Aluno " << aln[i].nome << " Foi: " << fixed << setprecision(2) << aln[i].media << endl;
    }

    return 0;
}