#include <iomanip>
#include <iostream>

using namespace std;

int main ()
{
    int aux=1, vezes, X, Y, auxX, valorX, auxY, valorX, valorY;
    cin >> vezes;
    while (aux!=vezes)
    {
        aux++;
        cin >> X >> Y;
        if (X > Y)
        {
            while (X < Y)
            {
                X++;
                auxX = X%2;
                if (auxX==1)
                {
                    valorX = X;
                }
            }
        }
    }
    
    return 0;
}