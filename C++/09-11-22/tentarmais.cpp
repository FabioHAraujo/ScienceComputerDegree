#include <iostream>
#include <iomanip>

using namespace std;

int SeFor (int um, int dois)
{
    int aux;
    if (dois>um)
    {
        aux = um;
        um = dois;
        dois = aux;
    }

    return um, dois;
}

int main ()
{
    int soma, x, y, qtd;
    cin >> qtd;
    for (int i=0; i<qtd;i++)
    {
        cin >> x >> y;
        SeFor(x,y);
    }
}