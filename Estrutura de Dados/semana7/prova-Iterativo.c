/*
Fábio Henrique Araújo - 0370091
Código pra verificar se uma palavra é um palíndromo ou não, dessa vez de forma iterativa
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool ehPalindromo(char palavra[], int tamanho) {
    // se for uma palavra vazia ou só tiver uma letra, é um palindromo :)
    if (tamanho == 0 || tamanho == 1) {
        return true;
    }
    for (int i = 0; i < tamanho; i++) {
        if (palavra[i] != palavra[tamanho])
            return false;
        tamanho--;
    }
    return true; //retorna true por padrao, caso nao tenha encontrado nenhuma letra diferente :)
}

int main() {
    char palavra[100];
    
    printf("Digite uma palavra: ");
    fgets(palavra, sizeof(palavra), stdin);

    int tam = strlen(palavra);
    
    if (ehPalindromo(palavra, tam - 1))
        printf("A palavra foi testada e eh um palindromo!!!\n");
    else
        printf("A palavra foi testada e nao eh um palindromo.\n");
    
    return 0;
    
    return 0;
}