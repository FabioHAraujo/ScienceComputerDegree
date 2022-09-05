#include <iomanip>
#include <iostream>

using namespace std;

int main ()
{
    int grenais=0, opcao=1, gremio, inter, colorado=0, tricolor=0, empate=0;
    for (opcao=1; opcao <2; grenais++)
    {
        cin >> inter >> gremio;
        cout << "Novo grenal (1-sim 2-nao)" << endl;
        cin >> opcao;
        if (inter>gremio)
        {
            colorado++;
        }
        else if (gremio>inter)
        {
            tricolor++;
        }
        else
        {
            empate++;
        }
    }
    cout << grenais << " grenais" << endl;
    cout << "Inter: " << colorado << endl;
    cout << "Gremio: " << tricolor << endl;
    cout << "Empates: " << empate << endl;
    if (inter>gremio)
    {
        cout << "Inter venceu mais" << endl;
    }
    else if (gremio>inter)
    {
        cout << "Gremio venceu mais" << endl;
    }
    else
    {
        cout << "Nao houve vencedor" << endl;
    }

    return 0;
}