#include <iomanip>
#include <iostream>
#include <math.h>

using namespace std;

int main ()
{
    double opcao, num1, num2;
    cout << "Vamos calcular com dois numeros. Por favor, escolha os numeros:\n";
    cout << "Primeiro Numero? ";
    cin >> num1;
    cout << "Segundo Numero? ";
    cin >> num2;
    cout << "Agora, Digite Um Dos Numeros de Indice Para Escolher o Que Deseja Fazer:\n";
    cout << "1 - Somar\n";
    cout << "2 - Subtrair\n";
    cout << "3 - Multiplicar\n";
    cout << "4 - Dividir\n";
    cout << "> ";
    cin >> opcao;
    if (opcao<=0)
    {
        cout << "NUMERO INVALIDO, INICIE NOVAMENTE" << endl;
    }
    else if (opcao<=1)
    {
        cout << "O Resultado da Soma eh: " << num1+num2 << endl;
    }
    else if (opcao<=2) 
    {
        cout << "O Resultado da Subtracao eh: " << num1-num2 << endl;
    }
    else if (opcao<=3)
    {
        cout << "O Resultado da Multiplicacao eh: " << num1*num2 << endl;
    }
    else if (opcao<=4)
    {
        cout << "O Resultado da Divisao eh: " << num1/num2 << endl;
    }
    else if (opcao>=5)
    {
        cout << "NUMERO INVALIDO, INICIE NOVAMENTE" << endl;
    }
    
    return 0;
}