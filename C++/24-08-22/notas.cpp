#include <iostream>

using namespace std;

int main() {
    int valor, valorSobra, contador;
    cin >> valor;
    contador = valor/100;
    valorSobra = valor % 100;
//    contador = (valor-valorSobra)/100;
    cout << contador << " Notas de R$100,00" << endl;
    contador = (valorSobra)/50;
    valorSobra = valorSobra % 50;
    cout << contador << " Notas de R$50,00" << endl;
    contador = (valorSobra)/20;
    valorSobra = valorSobra % 20;
    cout << contador << " Notas de R$20,00" << endl;
    contador = (valorSobra)/10;
    valorSobra = valorSobra % 10;
    cout << contador << " Notas de R$10,00" << endl;
    contador = (valorSobra)/5;
    valorSobra = valorSobra % 5;
    cout << contador << " Notas de R$5,00" << endl;
    contador = (valorSobra)/2;
    valorSobra = valorSobra % 2;
    cout << contador << " Notas de R$2,00" << endl;
    contador = (valorSobra)/1;
    valorSobra = valorSobra % 1;
    cout << contador << " Notas de R$1,00" << endl;
    
    return 0;
}
