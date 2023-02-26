#include <iomanip>
#include <iostream>

using namespace std;

float notas(float pastelina, float salgadinho){  
    cout << "Digite Nota 1: ";
    cin >> pastelina;
    cout << "Digite Nota 2: ";
    cin >> salgadinho;
    float media;
    media = (pastelina+salgadinho)/2;
    return media;
}

int main(){
    float nota1, nota2, media;
    char nome[120];
    cout << "Digite seu nome: ";
    cin >> nome;
    media = notas(nota1, nota2);
    cout << "Caro aluno " << nome << ", Sua Media foi: " << fixed << setprecision(2) << media;
}