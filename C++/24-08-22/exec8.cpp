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
    double nota1, nota2, media;
    cout << "Vamos calcular a media entre duas notas de um aluno" << endl;
    cout << "Por favor, insira a Primeira nota do aluno: ";
    cin >> nota1;
    cout << "Agora insira a Segunda nota do aluno: ";
    cin >> nota2;
    media = (nota1+nota2)/2;
    cout << fixed << setprecision(2) << "O Aluno Teve Como Media " << YELLOW << media << NC;
    if (media >= 7)
    {
        cout << " E esta" << GREEN " APROVADO" << NC;
    }
    else if (media >= 3)
    {
        cout << " E Precisa de" << CYAN << " AVALIACAO COMPLEMENTAR" << NC;
    }
    else
    {
        cout << " E Infelizmente, foi " << RED << "REPROVADO" << NC;
    }


    return 0;
}
