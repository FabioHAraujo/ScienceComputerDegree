#include <iostream>
#include <iomanip>


#define NC "\e[0m"
#define GREEN "\e[0;32m"
#define CYAN "\e[0;36m"
#define RED "\e[0;31m"
#define YELLOW "\e[0;33m"

using namespace std;

int main ()
{
    int qtd=0, count=0, pos=0, cond=0; 
    double valFinal=1000;
    cout << "Voce recebe R$ 1000,00, e deve somar ou diminuir deste valor\n";
    cout << "Por favor, decida o que deseja fazer\n";
    cout << "Digite " << GREEN << "1" << NC << " para soma\n";
    cout << "Digite " << RED << "2" << NC << " para subtracao\n";

    cin >> cond;

    if (cond==1)
    {
        cout << "Quantos numeros deseja somar?\n";
        cin >> pos;
        qtd=pos;
    }
    else if (cond==2)
    {
        cout << "Quantos Numos deseja diminuir\n";
        cin >> pos;
        qtd=pos;
    }
    else
    {
        cout << "Poxa, voce tinha uma missao :(\n";
    }
    double numeros[qtd];
    while (count<pos)
    {
        cin >> numeros[count];
        if (cond==1)
        {
            valFinal+=numeros[count];
        }
        else if (cond==2)
        {
            valFinal-=numeros[count];
        }
        count ++;
    }
    if (cond==1 || cond==2)
    {
        cout << fixed << setprecision(2) << "Ao todo voce tem: R$ " << valFinal << endl;
    }

    return 0;
}   