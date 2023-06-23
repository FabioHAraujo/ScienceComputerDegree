/*
Fábio Henrique Araújo - 0370091
Código pra verificar se uma palavra é um palíndromo ou não, utilizando recursividade
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>


bool ehPalindromo(char palavra[], int ini, int fim) {
    // caso o ini da palavra seja maior que o fim, ele já percorreu toda a palavra e é um palindromo :) 
    //[OU SÓ TEM UMA LETRA, O QUE NAO DESCARTA ELE SER UM PALINDROMO]
    if (ini >= fim) {
        return true;
    }
    
    // caso a letra do ini seja diferente da letra do fim, não é um palindromo :(
    else{
        if (palavra[ini] != palavra[fim]) {
            return false;
        }
        
        // caso a letra do inicio seja igual a letra do fim, ele chama a função novamente, mas com o inicio + 1 e o fim - 1 :)
        return ehPalindromo(palavra, ini + 1, fim - 1);
    }
}

int main() {
    char palavra[100];
    
    printf("Digite uma palavra: ");
    fgets(palavra, sizeof(palavra), stdin);
    
    int tam = strlen(palavra);
    
    if (ehPalindromo(palavra, 0, tam - 1)) {
        printf("A palavra eh um palindromo.\n");
    } else {
        printf("A palavra nao eh um palindromo.\n");
    }
    
    return 0;
}
