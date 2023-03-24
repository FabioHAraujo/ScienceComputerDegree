#include <stdio.h>
#define COLUNAS 5
#define LINHAS  3
#define INFINITO 999999999999

void melhor_vendedor(float vendas[LINHAS][COLUNAS]);
void pior_mes(float vendas[LINHAS][COLUNAS]);

int main() {

    float vendas[LINHAS][COLUNAS] =
    {
        {2500.90,1300.99,3000.10,4400.80,2800.90},
        {1000.90,500.90 ,600.25 ,1200.40,2300.50},
        {8900.50,9000.75,7500.30,7000.20,8500.00}
    };
    melhor_vendedor(vendas);
    pior_mes(vendas);

}

void melhor_vendedor(float vendas[LINHAS][COLUNAS]) {
    int i, j, maior_vendedor;
    float soma_vendas_por_vendedor;
    float soma_maior_vendedor = vendas[0][0];
    maior_vendedor = 0;
    for (i=0; i<COLUNAS; i++) {
        soma_vendas_por_vendedor = 0;
        for (j=0; j<LINHAS; j++)
            soma_vendas_por_vendedor += vendas[j][i];
        if (soma_vendas_por_vendedor > soma_maior_vendedor) {
            soma_maior_vendedor = soma_vendas_por_vendedor;
            maior_vendedor = i;
        }
        printf("\nVendedor %d: %10.2f\n", i, soma_vendas_por_vendedor);
    }
    printf("\n\nO vendedor %d foi o que mais vendeu, R$%10.2f\n\n",maior_vendedor,soma_maior_vendedor);
}

void pior_mes(float vendas[LINHAS][COLUNAS]) {
    int i, j, pior_mes;
    float soma_vendas_por_mes;
    float soma_pior_mes = INFINITO;
    pior_mes = 0;
    for (i=0; i<LINHAS; i++) {
        soma_vendas_por_mes = 0;
        for (j=0; j<COLUNAS; j++)
            soma_vendas_por_mes += vendas[i][j];
        if (soma_vendas_por_mes < soma_pior_mes) {
            soma_pior_mes = soma_vendas_por_mes;
            pior_mes = i;
        }
        printf("\nMes %d: %10.2f\n", i, soma_vendas_por_mes);
    }
    printf("\n\nO mes %d foi o que menos vendeu, R$%10.2f\n\n",pior_mes,soma_pior_mes);
}
