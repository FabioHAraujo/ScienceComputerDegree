#include <iostream>
#include <iomanip>
#include <math.h>

#define NC "\e[0m"
#define GREEN "\e[0;32m"
#define CYAN "\e[0;36m"

using namespace std;

int main ()
{
    int codigo;
    cout << "LOCALIZAR ORIGEM DO PRODUTO: \n";
    cout << "INSIRA O CODIGO DO PRODUTO: > ";
    cin >> codigo;
    cout << "ESTE PRODUTO VEM DA REGIAO " << GREEN;
    if (codigo ==1)
    {
        cout << "SUL" << NC;
    }
    else if (codigo ==1)
    {
        cout << "NORTE" << NC;
    }
    else if (codigo ==5 or codigo==6)
    {
        cout << "NORDESTE" << NC;
    }
    else if (codigo ==7 or codigo==8 or codigo==9)
    {
        cout << "SUDESTE" << NC;
    }
    else if (codigo >=10 and codigo <=20)
    {
        cout << "CENTRO-OESTE" << NC;
    }
    else if (codigo >=25 and codigo <=50)
    {
        cout << "NORDESTE" << NC;
    }
    else
    {
        cout << CYAN "IMPORTADO" << NC;
    }

    return 0;
}