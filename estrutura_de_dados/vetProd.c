#include <stdio.h>
#define TAM 100

struct produto {
    char nome[40];
    float preco;
};

int insere_produtos(struct produto produtos[], int contador);
void lista_produtos(struct produto produtos[], int contador);
int produto_mais_caro(struct produto produtos[], int contador);
float produto_mais_barato(struct produto produtos[], int contador);
float soma_total(struct produto produtos[], int contador);
float media(struct produto produtos[], int contador);

main() {
  struct produto produtos[TAM];
  int contador = 0;
  int posicao_produto_mais_caro = 0;

  contador = insere_produtos(produtos, contador);
  fflush(stdin);
  printf("\nAperte uma tecla para visualizar todos os produtos.");
  getchar(); fflush(stdin);
  lista_produtos(produtos, contador);
  printf("\nAperte uma tecla para visualizar o produto mais caro.");
  getchar(); fflush(stdin);
  posicao_produto_mais_caro = produto_mais_caro(produtos, contador);
  printf("Nome do produto: %s\t%10.2f", produtos[posicao_produto_mais_caro].nome, produtos[posicao_produto_mais_caro].preco);
  printf("\nAperte uma tecla para visualizar o produto mais barato.");
  getchar(); fflush(stdin);
  printf("%10.2f", produto_mais_barato(produtos, contador));
  printf("\nAperte uma tecla para visualizar o valor da soma dos produtos.");
  getchar(); fflush(stdin);
  printf("%10.2f", soma_total(produtos, contador));
  printf("\nAperte uma tecla para visualizar o valor medio dos produtos.");
  getchar(); fflush(stdin);
  printf("%10.2f", media(produtos, contador));
}

int insere_produtos(struct produto produtos[], int contador) {
    char resposta = 'S';
    while ((resposta == 'S' || resposta == 's') && contador < TAM) {
        printf("Digite o nome do produto %d: ", contador+1);
        scanf("%s", produtos[contador].nome);
        fflush(stdin);
        printf("Digite o preço do produto %d: ", contador+1);
        scanf("%f", &produtos[contador++].preco);
        printf("\nCadastrar outro produto (S) ou (s)? ");
        fflush(stdin);
        scanf("%c", &resposta);
        system("cls");
    }
    return contador;
}

void lista_produtos(struct produto produtos[], int contador) {
    int i;
    printf("\n");
    for (i=0; i<contador; i++)
        printf("Produto %d: %s - valor: %10.2f\n", i+1,
               produtos[i].nome, produtos[i].preco);
}

int produto_mais_caro(struct produto produtos[], int contador) {
    int i, i_mais_caro = 0;
    float mais_caro = produtos[0].preco;
    for (i=1; i<contador; i++)
        if (produtos[i].preco > mais_caro) {
            mais_caro = produtos[i].preco;
            i_mais_caro = i;
        }
    return i_mais_caro;
}

float produto_mais_barato(struct produto produtos[], int contador) {
    int i;
    float mais_barato = produtos[0].preco;
    for (i=1; i<contador; i++)
        if (produtos[i].preco < mais_barato)
            mais_barato = produtos[i].preco;
    return mais_barato;
}

float soma_total(struct produto produtos[], int contador) {
    int i;
    float soma = 0;
    for (i=0; i<contador; i++)
        soma += produtos[i].preco;
    return soma;
}

float media(struct produto produtos[], int contador) {
    return soma_total(produtos, contador)/contador;
}
