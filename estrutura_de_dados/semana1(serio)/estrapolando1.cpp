#include <iomanip>
#include <iostream>

using namespace std;

float calMed(int tamanho){
    float media;
    float nota[tamanho]={0}, auxiliar=0;
    for (int i=0; i < tamanho; i++){
        cin >> nota[i];
        auxiliar+=nota[i];
    }
    media = auxiliar/tamanho;
    return media;
}

/* float notas(float pastelina, float salgadinho){  
    cout << "Digite Nota 1: ";
    cin >> pastelina;
    cout << "Digite Nota 2: ";
    cin >> salgadinho;
    return (pastelina+salgadinho)/2;
} */

int main(){
    int numNotas;
    float nota1, nota2, media;
    char nome[120];
    cout << "Digite seu nome: ";
    cin >> nome;
    cout << "Quantas notas possui? ";
    cin >> numNotas;
    media = calMed(numNotas);
    cout << "Caro aluno " << nome << ", Sua Media foi: " << fixed << setprecision(2) << media;
}