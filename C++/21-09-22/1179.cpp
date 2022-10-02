#include <iomanip>
#include <iostream>

using namespace std;

int main ()
{
    int cPar=0, cImpar=0, par[5]={0}, impar[5]={0}, valor[15], count=0, aux=0;
    while (count<15)
    {
        cin >> valor[count];
        if (valor[count]%2!=0)
        {
            impar[cImpar]=valor[count];
            cImpar++;
        }
        count++;
    }
    
    return 0;
}