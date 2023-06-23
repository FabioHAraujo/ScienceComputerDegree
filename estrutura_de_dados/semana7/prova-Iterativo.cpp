/*
Fábio Henrique Araújo - 0370091
Código pra verificar se uma palavra é um palíndromo ou não, dessa vez de forma iterativa
*/

#include <iostream>
#include <iomanip>

using namespace std;

bool ehPalindromo(string palavra, int tamanho){
    // se for uma palavra vazia, ou com apenas uma letra, é um palindromo :)
    if (tamanho == 0) {
        return true;
    }
    for (int i=0; i<tamanho; i++){
        if (palavra[i] != palavra[tamanho])
            return false;
        tamanho--;
    }
    return true;//retorna true por padrao, caso nao tenha encontrado nenhuma letra diferente :)
}

int main(){
    string palavra;
    
    cout << "Digite uma palavra: ";
    //aceita enter como uma palavra vazia
    getline(cin, palavra);
    // remove diferentes cases da palavra, por exemplo, se a palavra é PasTelInA, ele vai deixar ela como "pastelina"
    // peco desculpas, mas nao sei fazer isso em C :(
    for (int i = 0; i < palavra.length(); i++)
        palavra[i] = tolower(palavra[i]);
    
    int tam = palavra.length();
    
    if (ehPalindromo(palavra, tam - 1))
        cout << "A palavra foi testada e eh um palindromo!!!" << endl;
    else
        cout << "A palavra foi testada e nao eh um palindromo." << endl;
    
    return 0;
}