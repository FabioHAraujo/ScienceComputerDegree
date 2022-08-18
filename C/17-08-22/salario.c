#include <stdio.h>

int main ()
{
    double horas, salHora, IR, INSS, sindicato, salBruto, salLiquido;
    printf ("Para Descobrir Qual Seu Salário Mensal Bruto e Líquito, por favor, siga os passos:\n");
    printf ("Quantas Hora Mensais Você Trabalha? ");
    scanf ("%lf", &horas);
    printf ("Quanto Recebe Por Hora? ");
    scanf ("%lf", &salHora);
    salBruto = salHora*horas;
    IR = salBruto*0.11;
    INSS = salBruto*0.08;
    sindicato = salBruto*0.05;
    salLiquido = salBruto-IR-INSS-sindicato;
    printf ("Você Recebe Como Salário Bruto: R$ %.2lf", salBruto);
    printf ("\nDos Quais São Descontados os Seguintes Valores:");
    printf ("\nIR: R$%.2lf", IR);
    printf ("\nINSS: R$%.2lf", INSS);
    printf ("\nSindicato: R$%.2lf", sindicato);
    printf ("\nResta Como Salário Líquido: R$%.2lf", salLiquido);

    return 0;
}