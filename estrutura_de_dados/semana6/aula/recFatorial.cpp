#include <iostream>
#include <iomanip>

using namespace std;

int fatorial(int n);

int fatorial(int n){
    if (n == 1) return 1;
    else return n * fatorial(n - 1);
}

int main(void){
    int n, fat;
    cout << "Bem vindo ao programa de Fatorial" << endl;
    cout << "Digite o numero que deseja calcular o fatorial: ";
    cin >> n;
    fat = fatorial(n);
    cout << "O fatorial de " << n << " eh " << fat << endl;
}