#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int valor = 0, contador = 0;
    cin >> valor;
    while (valor >=100)
    {
        valor -= 100;
        contador++;
    }
    cout << contador << " Notas de R$100,00" << endl;
    contador = 0;
    while (valor >=50)
    {
        valor -= 50;
        contador++;
    }
    cout << contador << " Notas de R$50,00" << endl;
    contador = 0;
    while (valor >=20)
    {
        valor -=20;
        contador++;
    }
    cout << contador << " Notas de R$20,00" << endl;
    contador = 0;
    while (valor >=10)
    {
        valor -=10;
        contador++;
    }
    cout << contador << " Notas de R$10,00" << endl;
    contador = 0;
    while (valor >=5)
    {
        valor -= 5;
        contador++;
    }
    cout << contador << " Notas de R$5,00" << endl;
    contador = 0;
    while (valor >=2)
    {
        valor -= 2;
        contador++;
    }
    cout << contador << " Notas de R$2,00" << endl;
    contador = 0;
    while (valor >=1)
    {
        valor -=1;
        contador++;
    }
    cout << contador << " Notas de R$1,00" << endl;
    contador = 0;
    
    return 0;
}
