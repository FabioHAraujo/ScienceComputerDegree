#include <iomanip>
#include <iostream>

using namespace std;

int main ()
{
    int code, unidades;
    double hotDog=4.00, xSalada=4.50, xBacon=5.00, torrada=2.00, refri=1.50;
    cin >> code >> unidades;
    if (code==1)
    {
        cout << fixed << setprecision(2) << "Total: R$ " << hotDog*unidades << endl;
    }
    else if (code==2)
    {
        cout << fixed << setprecision(2) << "Total: R$ " << xSalada*unidades << endl;
    }
    else if (code==3)
    {
        cout << fixed << setprecision(2) << "Total: R$ " << xBacon*unidades << endl;
    }
    else if (code==4)
    {
        cout << fixed << setprecision(2) << "Total: R$ " << torrada*unidades << endl;
    }
    else if (code==5)
    {
        cout << fixed << setprecision(2) << "Total: R$ " << refri*unidades << endl;
    }
    
    return 0;
}