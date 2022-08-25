#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    double salBruto = 1000, vendas, salComiss;
    cout << "Vamos Calcular o Salario Comissionado de um Vendedor \n";
    cout << "Qual Valor este funcionario Vendeu este Mes?\n";
    cin >> vendas;


    if (vendas >= 1000)
    {
        salComiss = salBruto+vendas*0.05;
    }
    else
    {
        salComiss = salBruto+vendas*0.03;
    }

    cout << fixed << setprecision(2) << "Seu Salario Bruto Eh: R$" << salBruto << endl;
    cout << fixed << setprecision(2) << "Sua Comissao Total Foi De: R$" << salComiss - salBruto << endl;
    cout << fixed << setprecision(2) << "Este Vendedor Recebe ao Todo: R$" << salComiss << endl;

    return 0;
}