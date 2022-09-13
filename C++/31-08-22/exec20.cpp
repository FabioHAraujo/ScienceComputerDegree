// 20. Implementar um programa em C que controle a utilização de um Elevador. Características a serem observadas:
// O elevador suporta no máximo 10 pessoas; ou 
// 700 kg de peso total, o que ocorrer primeiro.

// Como resultado, o programa deve mostrar com quantas pessoas e com qual peso total partiu o elevador.

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int pessoas=0, opcao=1;
    double totalKg, peso;
    while (opcao==1 && pessoas<10 && totalKg<700)
    {
        pessoas++;
        cout << "Voce esta de frente ao elevador, gostaria de entrar?" << endl;
        cout << "Aperte 1 para entrar, 2 para deixar o elevador seguir >= ";
        cin >> opcao;
        if (opcao==1)
        {
            cout << "Quantos kg voce pesa? >= ",
            cin >> peso;
            totalKg+=peso;
        }
        else
        {
            pessoas--;
        }
    }
    cout << fixed << setprecision(2) << "O elevador Partiu com " << pessoas << " pessoa(s) e com peso total de " << totalKg << "Kg." << endl;
        
    return 0;
}