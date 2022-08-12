#include <iostream>

int main ()
{
    int nota1, nota2;
    std::cout << "Bem-Vindo ao ToNamedia - Para Calcular a Media de um Aluno Insira:" "\n";
    std::cout << "Primeira Nota  do Aluno? ";
    std::cin >> nota1;
    std::cout << "Segunda Nota do Aluno? ";
    std::cin >> nota2;
    std::cout << "A Media de Notas do Aluno eh = " << (nota1+nota2)/2 << "\n";


    return 0;
}