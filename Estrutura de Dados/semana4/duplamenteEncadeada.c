#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PontoTuristico {
    char descricao[41];
    float latitude;
    float longitude;
    struct PontoTuristico *anterior;
    struct PontoTuristico *proximo;
};
typedef struct PontoTuristico PontoTuristico;

struct descritor_lista {
    PontoTuristico *inicio;
    PontoTuristico *fim;
    int tamanho;
};
typedef struct descritor_lista TipoDescritorLista;

/* Criação de uma lista vazia */
void criar_lista(TipoDescritorLista *descritor_lista) {
    descritor_lista->inicio = NULL;
    descritor_lista->fim = NULL;
    descritor_lista->tamanho = 0;
}

/* Leitura de um novo ponto turistico */
void lerPontoTuristico(struct PontoTuristico *aux) {
    printf("\nDescricao: ");
    scanf("%[^\n]", aux->descricao);
    fpurge(stdin);
    printf("\nLatitude: ");
    scanf("%f", &aux->latitude);
    fpurge(stdin);
    printf("\nLongitude: ");
    scanf("%f", &aux->longitude);
    fpurge(stdin);
}

/* Insercao no início da lista */
void inserir_lista_inicio (TipoDescritorLista* descritor_lista) {
    PontoTuristico* novo = (PontoTuristico*) malloc(sizeof(PontoTuristico));
    lerPontoTuristico(novo);
    if (!descritor_lista->inicio) {
        novo->proximo  = NULL;
        novo->anterior = NULL;
        descritor_lista->fim = novo;
    }
    else {
        novo->anterior = NULL;
        novo->proximo = descritor_lista->inicio;
        descritor_lista->inicio->anterior = novo;
    }
    descritor_lista->inicio = novo;
    descritor_lista->tamanho++;
}

/* Insercao no final da lista */
void inserir_lista_fim (TipoDescritorLista* descritor_lista) {
    PontoTuristico* novo = (PontoTuristico*) malloc(sizeof(PontoTuristico));
    lerPontoTuristico(novo);

    if (!descritor_lista->inicio) {
        novo->proximo  = NULL;
        novo->anterior = NULL;
        descritor_lista->inicio = novo;
    }
    else {
        novo->proximo = NULL;
        novo->anterior = descritor_lista->fim;
        descritor_lista->fim->proximo = novo;
    }
    descritor_lista->fim = novo;
    descritor_lista->tamanho++;
}

/* Retorna 1 se a lista está vazia ou 0 se não está vazia */
int verificar_lista_vazia (TipoDescritorLista* descritor_lista) {
    return (descritor_lista->inicio == NULL);
}

/* Impressão dos nodos da lista, do inicio para o fim  */
void imprimir_lista (TipoDescritorLista* descritor_lista) {
    if (verificar_lista_vazia(descritor_lista))
        printf("Lista vazia\n");
    else {
        PontoTuristico* paux;
        for (paux = descritor_lista->inicio; paux != NULL; paux = paux->proximo)
            printf("%-41s\t%.2f\t%.2f\n", paux->descricao, paux->latitude, paux->longitude);
    }

/* Impressao dos nodos da lista na ordem inversa */
void imprimir_lista_invertida (TipoDescritorLista* descritor_lista) {
    if (verificar_lista_vazia(descritor_lista))
        printf("Lista vazia\n");
    else {
        PontoTuristico* paux;
        for (paux = descritor_lista->fim; paux != NULL; paux = paux->anterior)
            printf("%-41s\t%.2f\t%.2f\n", paux->descricao, paux->latitude, paux->longitude);
    }
}



/* Busca de um nodo na lista pelo valor da descricao do ponto turistico */
PontoTuristico* buscar_nodo_lista (TipoDescritorLista* descritor_lista, char *desc) {
    PontoTuristico* paux;
    for (paux=descritor_lista->inicio; paux!=NULL; paux = paux->proximo) {
        if (strcmp(paux->descricao,desc) == 0)
            return paux;
    }
    return NULL;
}


/* Remocao de nodo da lista a partir da descricao do ponto turistico */
void remover_nodo_lista (TipoDescritorLista* descritor_lista, char *desc) {
    PontoTuristico* anterior_paux = NULL;   /* ponteiro para nodo anterior */
    PontoTuristico* paux = descritor_lista->inicio;      /* ponteiro para percorrer a lista */
    while (paux != NULL && strcmp(paux->descricao,desc) != 0) {   /* procura o nodo desejado na lista, guardando sempre o nodo anterior */
        anterior_paux = paux;
        paux = paux->proximo;
    }
    if (paux == NULL)
        return;                     /* não encontrou nodo a ser removido */
    if (anterior_paux == NULL) {
        descritor_lista->inicio = paux->proximo;
        descritor_lista->inicio->anterior = NULL;    /* remocao do nodo do inicio da lista */
    }
    else {
        if (paux->proximo == NULL) {       /* remocao do nodo do final da lista */
            anterior_paux->proximo = NULL;
            descritor_lista->fim = anterior_paux;
        }
        else {
            anterior_paux->proximo = paux->proximo;      /* remocao do nodo de outra posicao qualquer */
            paux->proximo->anterior = anterior_paux;
        }
    }
    descritor_lista->tamanho--;
    free(paux);
}




/* Esvazia a lista, desalocando o bloco de memoria de cada nodo */
void liberar_lista (TipoDescritorLista* descritor_lista) {
    PontoTuristico *paux = descritor_lista->inicio;
    PontoTuristico *aux;
    while (paux != NULL) {
        aux = paux->proximo;        /* guarda referência p/ próximo nodo */
        free(paux);               /* libera a memória apontada por paux */
        paux = aux;               /* faz paux apontar para o próximo */
    }
    criar_lista(descritor_lista);
}




















/* Função que apaga os n primeiros nodos da lista */
void acao (TipoDescritorLista* descritor_lista, int n) {
    PontoTuristico* p;
    PontoTuristico* q;
    int i = 1;
    p = descritor_lista->inicio;
    while (p != NULL && i <= n) {
        i++;
        q = p->proximo;
        free(p);
        p = q;
    }
    p->anterior = NULL;
    descritor_lista->inicio = p;
    descritor_lista->tamanho -= n;
}

int main () {
    char desc[41];
    TipoDescritorLista *descritor_lista;
    descritor_lista = (TipoDescritorLista*) malloc(sizeof(TipoDescritorLista));
    printf("Criando uma lista duplamente encadeada...");    
    getchar();
    criar_lista(descritor_lista);

    printf("Inserindo nodos no inicio da lista duplamente encadeada...");    
    getchar();
    inserir_lista_inicio(descritor_lista);
    //imprimir_lista(descritor_lista); getchar();
    inserir_lista_inicio(descritor_lista);
    //imprimir_lista(descritor_lista); getchar();
    inserir_lista_inicio(descritor_lista);
    //inserir_lista_inicio(descritor_lista);
    //inserir_lista_inicio(descritor_lista);
    //inserir_lista_inicio(descritor_lista);
    imprimir_lista(descritor_lista); getchar();
    acao(descritor_lista,4);
    imprimir_lista(descritor_lista); getchar();
    printf("Buscando um nodo na lista duplamente encadeada...\n");
    printf("Qual a descricao do ponto turistico que deseja encontrar? ");
    scanf("%[^\n]", desc);
    fpurge(stdin);
    PontoTuristico *no = buscar_nodo_lista(descritor_lista, desc);
    if (no) {
        printf("Endereco do Nodo buscado %p %p %p: %s\n\n", no->anterior, no, no->proximo, no->descricao);
        printf("Nodo anterior: %s\n\n", no->anterior->descricao);
        printf("Nodo posterior: %s\n\n", no->proximo->descricao);
    }
    else
        printf("Nodo nao encontrado\n");
    printf("Removendo um nodo da lista...\n");
    printf("Qual a descricao do ponto turistico que deseja remover? ");
    scanf("%[^\n]", desc);
    fpurge(stdin);
    remover_nodo_lista(descritor_lista, desc);
    printf("Imprimindo os nodos da lista duplamente encadeada, do fim para o inicio\n");    
    getchar();
    imprimir_lista_invertida(descritor_lista);*/
    return 0;
}