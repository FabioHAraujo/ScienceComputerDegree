#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    int valor, atual, nro, qtdDiv = 0;
    cout << "digite um valor ";
    cin >> valor;
    for (atual = 2; atual <= valor; atual++)
    {
        qtdDiv = 0;
        for (nro = 2; nro < atual; nro++)
        {
            if (atual % nro == 0)
            {
                qtdDiv++;
                break;
            }
        }
        if (qtdDiv == 0)
        {
            cout << atual << endl;
        }
    }
    
    return 0;
}