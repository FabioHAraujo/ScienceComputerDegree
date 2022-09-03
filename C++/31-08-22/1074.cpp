#include <iomanip>
#include <iostream>

using namespace std;

int main ()
{
    int quant, numero, aux=1;
    cin >> quant;
    while (aux<=quant)
    {
        aux++;
        cin >> numero;
        if (numero==0)
        {
            cout << "NULL\n";
        }
        else if ((numero%2)==0)
        {
            cout << "EVEN ";
            if (numero>0)
            {
                cout << "POSITIVE\n";
            }
            else if (numero<0)
            {
                cout << "NEGATIVE\n";
            }
        }
        else if ((numero%2)==1 || (numero%2)==-1)
        {
            cout << "ODD ";
                if (numero>0)
                {
                    cout << "POSITIVE\n";
                }
                else if (numero<0)
                {
                    cout << "NEGATIVE\n";
                }
        }
    }
    
    return 0;
}