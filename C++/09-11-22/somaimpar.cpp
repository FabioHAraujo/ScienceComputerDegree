#include <iostream>
#include <iomanip>

using namespace std;

int Soma(int ini, int fim)
{
    int soma=0, i, aux;
    if (ini > fim)
        {
            aux = ini;
            ini = fim;
            fim = aux;
        }
    for (i=ini+1; i<fim; i++)
    {
        if (i%2 != 0)
        {
            soma = soma+i;
        }
    }

    return soma;
}

int main ()
{
    int x, y, qtd;
    cin >> qtd;
    for (int i=0; i<qtd;i++)
    {
        cin >> x >> y;
        cout << "Soma = " << Soma(x,y) << endl;
    }
}