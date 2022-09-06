#include <iomanip>
#include <iostream>

using namespace std;

int main ()
{
    int aux=1, vezes=0, X=0, Y=0, maior=0, menor=0, num1=0, num2=0,num3=0;
    cin >> vezes;
    while (aux<=vezes)
    {
        cin >> X >> Y;
        aux++;
        if (X>Y)
        {
            maior = X;
            menor = Y;
            while (menor < (maior-1))
            {
                menor++;
                if ((menor%2)==1)
                {
                    num1+=menor;
                    num2+=num1;
                    num3=num2;
                }

            }
            cout << num3 << endl;
        }
        else if (Y>X)
        {
            maior = Y;
            menor = X;
            while (menor < (maior-1))
            {
                menor++;
                if ((menor%2)==1)
                {
                    num1+=menor;
                    num2+=num1;
                    num3=num2;
                }

            }
            cout << num3 << endl;
        }
        else
        {
            cout << "0" << endl;
        }
        
        }

    
    return 0;
}
