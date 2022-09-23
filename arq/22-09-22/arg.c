#include <stdio.h>

int main() {
    char variavel;

    printf("Qual o valor de variavel? ");
    scanf("%d", &variavel);

    printf("\n%d", variavel);

    return 0;
}


//O resultado deste código quando inserido o número 200 é -56 pois foi definida a variavel "variavel" como um char, que armazena 1 byte de informação, ou seja, 8 bits.
//Assim sendo, a variável insere números de 0 a +127, sobrando 72 números que são inseridos de -128 até -56, resultando em -56.