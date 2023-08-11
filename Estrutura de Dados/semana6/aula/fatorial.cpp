#include <iostream>
#include <iomanip>

using namespace std;

int fatorial(int n);

int main(void){
    int n, fat;
    cout << "Bem vindo ao programa de Fatorial" << endl;
    cout << "Digite o numero que deseja calcular o fatorial: ";
    cin >> n;
    fat = fatorial(n);
    cout << "O fatorial de " << n << " eh " << fat << endl;
}

int fatorial(int n){
    int fat = 1;
    while(n > 1){
        fat *= n;
        n--;
    }
    return fat;
}