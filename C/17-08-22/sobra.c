#include <stdio.h>

int main ()
{
    int num1, num2;
    printf ("Vamos Dividir dois numeros e mostrar sua sobra\n");
    printf ("Insira o primiro Numero: ");
    scanf ("%d", &num1);
    printf ("Agora insira o segundo numero: ");
    scanf ("%d", &num2);
    printf ("A Sobra da Subtração Deste dois Numeros é: %d", num1%num2);

    return 0;
}