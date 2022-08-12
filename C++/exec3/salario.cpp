#include <iostream>

int main ()
{
    float valorHora, horasMes, salBruto, IR, INSS, sindicato, salLiquido;
    std::cout << "Vamos Calcular o Salario de um Funcionario pago em Horas" "\n";
    std::cout << "Quantas Horas Por Mes Trabalha Este Funcionario?  ";
    std::cin >> horasMes;
    std::cout << "Quanto recebe por Hora?  ";
    std::cin >> valorHora;
    salBruto = horasMes*valorHora;
    std::cout << "Este Funcionario Tem Salario Bruto Mensal de R$ " << salBruto << "\n";
    std::cout << "Deste valor Bruto Foram Descontadas as Seguintes Aliquotas" "\n";
    IR = salBruto*0.11;
    INSS = salBruto*0.08;
    sindicato = salBruto*0.05;
    std::cout << "Desconto do Imposto de Renda = R$ " << IR << "\n";
    std::cout << "Desconto do INSS = R$ " << INSS << "\n";
    std::cout << "Desconto do sindicado = R$ " << sindicato << "\n";
    salLiquido = salBruto-IR-INSS-sindicato;
    std::cout << "E Seu Salario Liquido Equivale a = R$ " << salLiquido << "\n";
}