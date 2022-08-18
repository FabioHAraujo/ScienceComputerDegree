#include <stdio.h>

int main ()
{
    int num1, num2, resul;
    printf ("Vamos Somar dois numeros Inteiros\n");
    printf ("Insira o primiro Numero: ");
    scanf ("%d", &num1);
    printf ("Agora insira o segundo numero: ");
    scanf ("%d", &num2);
    resul = num1+num2;
    printf ("O Resultado da Soma é: %d", resul);

    return 0;
}