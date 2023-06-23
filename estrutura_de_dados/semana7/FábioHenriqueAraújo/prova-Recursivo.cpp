/*
Fábio Henrique Araújo - 0370091
Código pra verificar se uma palavra é um palíndromo ou não, utilizando recursividade
*/

#include <iostream>
#include <iomanip>

/*Oi professor, comecei fazendo em C++ pra conseguir desenvolver a ideia, mas coloquei o codigo em C no zip também pra previnir
Boa correção!
*/

using namespace std;


bool ehPalindromo(string palavra, int ini, int fim) {
    // caso o ini da palavra seja maior que o fim, ele já percorreu toda a palavra e é um palindromo :) 
    //[OU SÓ TEM UMA LETRA, O QUE NAO DESCARTA ELE SER UM PALINDROMO]
    if (ini >= fim)
        return true;
    // caso a letra do ini seja diferente da letra do fim, não é um palindromo :(
    else {
        if (palavra[ini] != palavra[fim])
            return false;
        // caso a letra do inicio seja igual a letra do fim, ele chama a função novamente, mas com o inicio + 1 e o fim - 1 :)
        else
            return ehPalindromo(palavra, ini + 1, fim - 1);
    }
}

int main() {
    string palavra;
    
    cout << "Digite uma palavra: ";
    //aceita enter como uma palavra vazia
    getline(cin, palavra);
    // remove diferentes cases da palavra, por exemplo, se a palavra é PasTelInA, ele vai deixar ela como "pastelina"
    // peco desculpas, mas nao sei fazer isso em C :(
    for (int i = 0; i < palavra.length(); i++)
        palavra[i] = tolower(palavra[i]);
    
    int tam = palavra.length();
    
    if (ehPalindromo(palavra, 0, tam - 1))
        cout << "A palavra foi testada eh um palindromo!!!" << endl;
    else
        cout << "A palavra foi testada e nao eh um palindromo." << endl;
    
    return 0;
}
