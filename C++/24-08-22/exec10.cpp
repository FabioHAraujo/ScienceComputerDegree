#include <iostream>
#include <iomanip>
#include <windows.h>

#define NC "\e[0m"
#define GREEN "\e[0;32m"
#define CYAN "\e[0;36m"
#define RED "\e[0;31m"
#define YELLOW "\e[0;33m"

using namespace std;

int main ()
{
    double nota1, nota2, optativa =0, media;
    cout << "Vamos Calcular a Media das Notas de Um Aluno: \n";
    cout << "Qual Nota ele Recebeu Pela Prova 1? > ";
    cin >> nota1;
    cout << "Qual Nota ele Recebeu Pela Prova 2? > ";
    cin >> nota2;
    cout << "Qual Nota ele Recebeu Pela Prova Optativa (0 caso nao tenha feito)? > ";
    cin >> optativa;
    if (optativa <= 0)
    {
        optativa = -1;
    }
    media = (nota1+nota2+optativa)/3;
    cout << fixed << setprecision(2) << "A Media do Aluno Foi: " << YELLOW << media << NC << endl;
    if (media >= 7)
    {
        cout << " E o Aluno foi " << GREEN "APROVADO" << NC << endl;
    }
    else if (media >=3)
    {
        cout << "E o Aluno Precisa de " << CYAN "AVALIACAO COMPLEMENTAR" << NC << endl;
    }
    else
    {
        cout << "E Infelizmente o Aluno foi " << RED "REPROVADO" << NC << endl;
    }

    return 0;
}