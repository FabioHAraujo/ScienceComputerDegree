#include <iomanip>
#include <iostream>

using namespace std;

struct passageiro{
    int qtdBag;
    string nome;
}

int main(){
    int qtdPassageiros, qtdBag;
    string nome;
    cout << "Por favor, informe o numero de passageiros deste voo: ";
    cin >> qtdPassageiros;
    passageiro psg[qtdPassageiros];
    for (int i=0; i<qtdPassageiros; i++){
        cin >> psg.qtdBag;
    }
    
}