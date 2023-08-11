#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Produto {
    int codigo;
    char nome[41];
    float preco;
};
struct Produto *p1, p2;
int main(){
    /*Inicio do que faltou*/
    p1 = (struct Produto *) malloc(sizeof(struct Produto));
    /*Fim do que faltou*/
    p1->codigo=1001;
    strcpy(p1->nome, "Leite");
    p1->preco=1.99;
    p2.codigo=1002;
    strcpy(p2.nome, "Cafe");
    p2.preco=19.80;
    return 0;
}