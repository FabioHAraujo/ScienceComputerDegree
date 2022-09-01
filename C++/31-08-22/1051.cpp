#include <iomanip>
#include <iostream>

using namespace std;

int main ()
{
    double salario, faixa1, faixa2, faixa3;
    cin >> salario;
    if (salario>=2000.01 && salario<=3000)
    {
        faixa1 = (salario-2000)*0.08;
        cout << fixed << setprecision(2) << "R$ " << faixa1 << endl;
    }
    else if (salario>=3000.01 && salario<=4500.00)
    {
        faixa1 = 1000*0.08;
        faixa2 = (salario-3000)*0.18;
        cout << fixed << setprecision(2) << "R$ " << faixa2+faixa1 << endl;
    }
    else if (salario>4500)
    {
        faixa1 = 1000*0.08;
        faixa2 = 1500*0.18;
        faixa3 = (salario-4500)*0.28;
        cout << fixed << setprecision(2) << "R$ " << faixa3+faixa2+faixa1 << endl;
    }
    else
    {
        cout << "Isento\n";
    }
    
    return 0;
}