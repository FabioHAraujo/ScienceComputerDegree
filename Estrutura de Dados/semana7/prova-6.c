#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool ehPalindromo(char palavra[], int inicio, int fim) {
    //testa se a palavra contem apenas um caractere
    if (inicio >= fim) {
        return true;
    }
    
    // Verifica se a primeira e última letra são distintas
    if (palavra[inicio] != palavra[fim]) {
        return false;
    }
    
    // Chama recursivamente para a próxima letra da esquerda e da direita
    return ehPalindromo(palavra, inicio + 1, fim - 1);
}

int main() {
    char palavra[100];
    
    printf("Digite uma palavra: ");
    scanf("%s", palavra);
    
    int tamanho = strlen(palavra);
    
    if (ehPalindromo(palavra, 0, tamanho - 1)) {
        printf("A palavra eh um palindromo.\n");
    } else {
        printf("A palavra nao eh um palindromo.\n");
    }
    
    return 0;
}
