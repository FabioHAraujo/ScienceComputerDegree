#include <iostream>

using namespace std;

int main ()
{
    float agua;
    cout << "Vamos ver se voce está bem hidratado?" << endl;
    cout << "Quantos Litros de Agua voce bebe por dia?" << endl;
    cin >> agua;
    if (agua >= 2.5)
    {
        cout << "Parabens, voce esta bem hidratado :)" << endl;
    }
    else
    {
        cout << "Voce esta consumindo pouca agua" << endl;
    }

    return 0;
}