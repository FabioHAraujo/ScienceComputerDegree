#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PontoTuristico {
    char descricao[41];
    float latitude;
    float longitude;
    struct PontoTuristico *proximo;
};

struct PontoTuristico* criar_lista(void);
struct PontoTuristico* inserir_inicio(struct PontoTuristico* cabeca);
struct PontoTuristico* inserir_final(struct PontoTuristico* cabeca);
void lePontoTuristico(struct PontoTuristico *aux);
void imprimir(struct PontoTuristico* cabeca);
int verificar_lista_vazia(struct PontoTuristico* cabeca);
struct PontoTuristico* buscar_lista(struct PontoTuristico* cabeca, char *desc);
struct PontoTuristico* remover_lista(struct PontoTuristico* cabeca, char *desc);

int main() {
    struct PontoTuristico* cabeca;
    cabeca = criar_lista();
    /*cabeca = inserir_inicio(cabeca);
    cabeca = inserir_inicio(cabeca);*/
    cabeca = inserir_inicio(cabeca);
    imprimir(cabeca);
    cabeca = inserir_final(cabeca);
    imprimir(cabeca);
    printf("Vamos buscar um\n");
    char *desc[41];
    scanf("%[^\n]", *desc);
    buscar_lista(cabeca, *desc);
    fflush(stdin);
    printf("Vamos deletar um\n");
    scanf("%[^\n]", *desc);
    remover_lista(cabeca, *desc);
    fflush(stdin);
    imprimir(cabeca);
    /*struct PontoTuristico* busca = buscar_lista(cabeca, "poa");
    if (busca)
        printf("Ponto turistico encontrado: %s - Lat: %.2f - Long: %.2f", 
        busca->descricao, busca->latitude, busca->longitude);
    return 0;*/
}

struct PontoTuristico* criar_lista(void) {
    return NULL;
}

void lePontoTuristico(struct PontoTuristico *aux) {
    printf("Descricao: ");
    scanf("%[^\n]", aux->descricao);
    fflush(stdin);
    printf("\nLat: ");
    scanf("%f", &aux->latitude);
    fflush(stdin);
    printf("\nLong: ");
    scanf("%f", &aux->longitude);
    fflush(stdin);
}

struct PontoTuristico* inserir_inicio(struct PontoTuristico* cabeca) {
    struct PontoTuristico* novo = (struct PontoTuristico*) malloc(sizeof(struct PontoTuristico));
    lePontoTuristico(novo);
    novo->proximo = cabeca;
    return(novo);
}

void imprimir(struct PontoTuristico* cabeca) {
    struct PontoTuristico* paux;
    for (paux = cabeca; paux != NULL; paux = paux->proximo)
        printf("%s: lat: %.2f, long: %.2f\n", paux->descricao, paux->latitude, paux->longitude);
}

struct PontoTuristico* inserir_final(struct PontoTuristico* cabeca){
    struct PontoTuristico* novo = (struct PontoTuristico*) malloc(sizeof(struct PontoTuristico));
    lePontoTuristico(novo);
    novo->proximo=NULL;
    if (verificar_lista_vazia(cabeca)) {
        cabeca = novo;
    } else {
        struct PontoTuristico* ultimo = cabeca;
        while (ultimo->proximo != NULL) {
            ultimo = ultimo->proximo;
        }
        ultimo->proximo = novo;
    }

    return cabeca;
}

int verificar_lista_vazia(struct PontoTuristico* cabeca){
    return (cabeca == NULL);
}

struct PontoTuristico* buscar_lista(struct PontoTuristico* cabeca, char *desc){
    struct PontoTuristico* paux;
    for (paux = cabeca; paux != NULL; paux = paux->proximo){
        if(strcmp(paux->descricao, desc) == 0)
            printf("%s: lat: %.2f, long: %.2f\n", paux->descricao, paux->latitude, paux->longitude);
    }
}
/* ESSE É MEU, É UMA MERDA, NÃO FUNCIONA
struct PontoTuristico* remover_lista(struct PontoTuristico* cabeca, char *desc){
    struct PontoTuristico* paux;
    struct PontoTuristico* ultimo = cabeca;
    for (paux = cabeca; paux != NULL; paux = paux->proximo){
        if(strcmp(paux->descricao, desc) == 0)
            paux = NULL;
            paux = ultimo;            
    }
}*/

/*ESSE É DO BOT - COPILOT*/
/*
struct PontoTuristico* remover_lista(struct PontoTuristico* cabeca, char *desc){
    struct PontoTuristico* paux;
    struct PontoTuristico* ultimo = cabeca;
    for (paux = cabeca; paux != NULL; paux = paux->proximo){
        if(strcmp(paux->descricao, desc) == 0){
            if(paux == cabeca){
                cabeca = paux->proximo;
            }else{
                ultimo->proximo = paux->proximo;
            }
            free(paux);
            return cabeca;
        }
        ultimo = paux;
    }
}*/
/*JULIANO*/
struct PontoTuristico* remover_lista(struct PontoTuristico* cabeca, char *desc){
    struct PontoTuristico *paux = cabeca;
    struct PontoTuristico *anterior = NULL;
    while (paux != NULL && strcmp(paux->descricao, desc) != 0) {
        anterior = paux;
        paux = paux->proximo;
    }
    if (paux == NULL)
        return cabeca;
    if (anterior == NULL)
        cabeca = paux->proximo;
    else
        anterior->proximo = paux->proximo;
    free(paux);
    return cabeca;
}
/*DO BOT*/
struct PontoTuristico* liberar_lista (struct PontoTuristico* cabeca) {
    struct PontoTuristico* paux;
    while (cabeca != NULL) {
        paux = cabeca;
        cabeca = cabeca->proximo;
        free(paux);
    }
    return NULL;
}

/*DO JULIANO*/

struct PontoTuristico* liberar_lista (struct PontoTuristico* cabeca){
    struct PontoTuristico* paux = cabeca, *aux = NULL;
    while (paux != NULL) {
        aux = paux->proximo;
        free(paux);
        paux = aux;
    }
    return NULL;
}
