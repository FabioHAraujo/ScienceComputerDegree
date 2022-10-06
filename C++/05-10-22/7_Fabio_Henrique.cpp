#include <iostream>
#include <iomanip>

#define NC "\e[0m"
#define GREEN "\e[0;32m"

using namespace std;

int main ()
{
    double salario=0, cFaixa1=0, cFaixa2=0, cFaixa3=0, mFaixa1=0, mFaixa2=0, mFaixa3=0;
    while (salario>=0)
    {
        cin >> salario;
        if (salario>=0 && salario<=5000)
        {
            cFaixa1++;
            mFaixa1+=salario;
        }
        else if (salario>5000 && salario<=10000)
        {
            cFaixa2++;
            mFaixa2+=salario;
        }
        else if (salario>10000)
        {
            cFaixa3++;
            mFaixa3+=salario;
        }
    }
    cout << fixed << setprecision(0) << "Qtde pessoas na faixa de 0,00 a 5.000,00: " GREEN << cFaixa1 << NC << endl;
    cout << fixed << setprecision(2) << "Media de salarios na faixa de 0,00 a 5000,00: " GREEN << mFaixa1/cFaixa1 << NC << endl;
    cout << fixed << setprecision(0) << "Qtde pessoas na faixa de 5.000,01 a 10.000,00: " GREEN << cFaixa2 << NC << endl;
    cout << fixed << setprecision(2) << "Media de salarios na faixa de 5.000,01 a 10.000,00: " GREEN << mFaixa2/cFaixa2 << NC << endl;
    cout << fixed << setprecision(0) << "Qtde pessoas que recebem mais de 10.000,00: " GREEN << cFaixa3 << NC << endl;
    cout << fixed << setprecision(2) << "Media de salarios maiores de 10.000,00: " GREEN << mFaixa3/cFaixa3 << NC << endl;
}