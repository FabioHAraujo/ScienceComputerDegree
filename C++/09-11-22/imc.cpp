#include <iomanip>
#include <iostream>
#include <math.h>

using namespace std;

struct aluno
{
    char nome[30];
    double peso, altura, imc;
    int ano;
};

int main()
{
    int alunos, aux=0;
    cout << "Quantos Alunos serao cadastrados?\n";
    cin >> alunos;
    aluno a[alunos];
    while (aux<alunos)
    {
        cout << "Por favor, insira o nome do aluno: \n> ";
        cin >> a[aux].nome;
        cout << "Agora insira em sequencia, Peso e Altura do Aluno:" << endl;
        cout << "> ";
        cin >> a[aux].peso;
        cout << "> ";
        cin >> a[aux].altura;
        cout << "Em que ano o aluno nasceu? \n> ";
        cin >> a[aux].ano;
        a[aux].imc = a[aux].peso/(pow(a[aux].altura,2));
        aux++;
    }
    aux = 0;
    cout << "\nOs Alunos com IMC Abaixo de 25 Sao:" << endl;
    while (aux<alunos)
    {
        
        if (a[aux].imc <= 25)
        {
            cout << fixed << setprecision(2) << "Aluno " << aux+1 << " -- " << a[aux].nome << " Tem IMC de: " << a[aux].imc << endl;
        }
        aux++;
    }
    cout << "=============================================================" << endl;
    cout << "Os Alunos Com IMC maior de 25 sao:" << endl;
    aux = 0;
    while (aux<alunos)
    {
        if (a[aux].imc > 25)
        {
            cout << fixed << setprecision(2) << "Aluno " << aux+1 << " -- " << a[aux].nome << " Tem IMC de: " << a[aux].imc << endl;
        }
        aux++;
    }

    return 0;
}