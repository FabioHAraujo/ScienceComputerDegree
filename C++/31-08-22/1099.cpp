#include <iomanip>
#include <iostream>

using namespace std;

int main ()
{
    int aux=1, vezes=0, X=0, Y=0, maior=0, menor=0, count=0, soma=0;
    cin >> vezes;
    while (aux<=vezes)
    {
        cin >> X >> Y;
        aux++;
        if (X>Y)
        {
            maior = X;
            menor = Y;
            count = menor;
            while (menor < (maior-1))
            {
                menor++;
                count++;
                if ((menor%2)==1)
                {  
                    soma+=count;
                }
            }
            cout << soma << endl;
            soma = 0;
        }
        else if (Y>X)
        {
            maior = Y;
            menor = X;
            count = menor;
            while (menor < (maior-1))
            {
                menor++;
                count++;
                if ((menor%2)==1)
                {  
                    soma+=count;
                }
            }
            cout << soma << endl;
            soma = 0;
        }
        else
        {
            cout << "0" << endl;
        }
        
        }

    
    return 0;
}