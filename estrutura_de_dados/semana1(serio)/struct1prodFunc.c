#include <stdio.h>
#include <string.h>
#include <locale.h>

struct  TipoProduto {
		int codigo;
		char descricao[60];
		float preco;
		char promocao;
	};

struct TipoProduto leProduto (struct TipoProduto produto);
void imprimeProduto (struct TipoProduto produto);

int main () {
    struct TipoProduto produto;
    setlocale(LC_ALL, "Portuguese");
    produto = leProduto(produto);
    imprimeProduto(produto);
	return 0;
}

struct TipoProduto leProduto (struct TipoProduto produto) {
	printf("Digite o código do produto: ");
	scanf("%d", &produto.codigo);
    fpurge(stdin);
	printf("\nDigite a descricao do produto s: ");
	scanf("%[^\n]", produto.descricao);
	fpurge(stdin);
	printf("\nDigite o preco do produto: ");
	scanf("%f", &produto.preco);
	printf("\nO produto esta em promocao (responda 's' para sim ou 'n' para nao): ");
	fpurge(stdin);
	scanf("%c", &produto.promocao);
	return produto;
}
void imprimeProduto (struct TipoProduto produto) {
	printf("Os valores digitados pelo usuario foram: \n");
	printf("Codigo: %d\n", produto.codigo);
	printf("Descricao: %s\n", produto.descricao);
	printf("Preco: %6.2f\n", produto.preco);
	printf("Promocao: %c\n", produto.promocao);
}