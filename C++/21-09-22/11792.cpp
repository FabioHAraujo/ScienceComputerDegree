#include <iomanip>
#include <iostream>

using namespace std;

int main ()
{
    int valor, par[5], impar[5], auxPar[15], auxImpar[15], cPar=0, cImpar=0, count=0, auxCount=0, aux2=0;
    while (count<15)
    {
        cin >> valor;
        if (valor%2==0)
        {
            auxPar[cPar]=valor;
            cPar++;
        }
        else if (valor%2==1)
        {
            auxImpar[cImpar]=valor;
            cImpar++;
        }
        count++;
    }
    while (auxCount<5)
    {
        par[auxCount]=auxPar[aux2];
        cout << par[auxCount];
        auxCount++;
        aux2++;
    }
    
    return 0;
}