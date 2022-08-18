#include <stdio.h>

int main ()
{
    double peso, altura, imc;
    printf ("Vamos Calcular o IMC de um Aluno Usando Altura (em metro) e peso (em kg)\n");
    printf ("Primeiro Insira a Altura do Aluno: >");
    scanf ("%lf", &altura);
    printf ("Agora Insira o Peso do Aluno");
    scanf ("%lf", &peso);
    imc = peso/(altura*altura);
    printf ("O IMC do Aluno É Igual à: %.2lf", imc);
    return 0;
}