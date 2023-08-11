#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void listaFloats(float *ptr, int qtd);

int main(void){
    int qtd;
    float *ptr;
    cout << "Quantos Floats deseja armazenar?" << endl;
    cin >> qtd;
    ptr=(float*) malloc(qtd*sizeof(float));
    if(ptr){
        for (int i=0; i<qtd; i++){
            cout << "Digite o Valor do produto N " << i << " :";
            cin >> ptr[i];
        }
    }
    listaFloats(ptr, qtd);
}

void listaFloats(float *ptr, int qtd){
    cout << "Precos Armazenados na Tabela:" << endl;
    for (int i=0; i<qtd; i++){
    cout << ptr[i] << endl;
    /*
    FUNCIONA ASSIM:
    cout << *(ptr+i) << endl;
    E ASSIM:
    cout << *ptr << endl;
    ptr++;
    */
    }
}