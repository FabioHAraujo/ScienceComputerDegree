#include <iostream>
#include <math.h>
//math.h é o repositório matemático para o c++

int main ()
{
    float peso, altura, imc;
    std::cout << "Vamos calcular o IMC de nossos Alunos" "\n";
    std::cout << "Qual a Altura do Aluno? (em metros) ";
    std::cin >> altura;
    std::cout << "Qual o Peso do Aluno? (Em KG)";
    std::cin >> peso;
    imc=peso/(std::pow(altura,2));
    //std::pow é uma função que eleva uma variável sob determinado expoente
    std::cout << imc << "\n";
    if (imc<18.5)
    {
        std::cout << "O Aluno esta na faixa baixo peso" << "\n";
    }
    else if (imc<25)
    {
        std::cout << "O Aluno esta na faixa normal" << "\n";
    }
    else if (imc<30)
    {
        std::cout << "O Aluno esta na faixa sobrepeso" << "\n";
    }
    else if (imc<35)
    {
        std::cout << "O Aluno esta na faixa obeso 1" << "\n";
    }
    else if (imc<40)
    {
        std::cout << "O Aluno esta na faixa obeso 2" << "\n";
    }
    else if (imc>=40)
    {
        std::cout << "O Aluno esta na faixa obeso 3" << "\n";
    }
}