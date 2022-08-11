#include <iostream>

int main ()
{
    float peso, altura, imc;
    std::cout << "Vamos calcular o IMC de nossos Alunos" "\n";
    std::cout << "Qual a Altura do Aluno? (em metros) ";
    std::cin >> altura;
    std::cout << "Qual o Peso do Aluno? (Em KG)";
    std::cin >> peso;
    std::cout << peso/(altura*altura);

    return 0;
}