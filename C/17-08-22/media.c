#include <stdio.h>

int main ()
{
    double nota1, nota2, media;
    printf ("Vamos descobir a média das notas de um determinado aluno\n");
    printf ("Insira a Primeira Nota do Aluno: >");
    scanf ("%lf", &nota1);
    printf ("Agora Insira a Segunda Nota do Aluno: >");
    scanf ("%lf", &nota2);
    media = (nota1+nota2)/2;
    printf ("Media: %.2lf", media);
    
    return 0;
}