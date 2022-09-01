#include <iomanip>
#include <iostream>

using namespace std;

int main ()
{
    double salBruto, salImposto;
    cin >> salBruto;
    salImposto = salBruto-2000;
    cout << salImposto;
    if (salBruto>=2000.01 && salBruto<=3000.00)
    {
        cout << fixed << setprecision(2) << "R$ " << salImposto*0.08 << endl;
    }
    else if (salBruto>=3000.01 && salBruto<=4500.00)
    {
        cout << fixed << setprecision(2) << "R$ " << salImposto*0.18 << endl;
    }
    else if (salBruto>4500.00)
    {
        cout << fixed << setprecision(2) << "R$ " << salImposto*0.28 << endl;
    }
    else
    {
        cout << fixed << setprecision(2) << "Isento" << endl;
    }
    
    return 0;
}