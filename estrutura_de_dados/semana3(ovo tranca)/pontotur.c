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
struct PontoTuristico* liberar_lista(struct PontoTuristico* cabeca);


int main() {
    struct PontoTuristico* cabeca;
    cabeca = criar_lista();
    cabeca = inserir_inicio(cabeca);
    cabeca = inserir_inicio(cabeca);
    cabeca = inserir_inicio(cabeca);
    imprimir(cabeca);
    struct PontoTuristico* busca = buscar_lista(cabeca, "poa");
    if (busca)
        printf("Ponto turistico encontrado: %s - Lat: %.2f - Long: %.2f", 
        busca->descricao, busca->latitude, busca->longitude);
    return 0;
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

struct PontoTuristico* buscar_lista(struct PontoTuristico* cabeca, char *desc) {
    struct PontoTuristico* paux;
    for (paux = cabeca; paux != NULL; paux = paux->proximo) {
        if (strcmp(paux->descricao, desc) == 0) {
            return paux;
        }
    }
    return NULL;
}

int verificar_lista_vazia(struct PontoTuristico* cabeca) {
    if (cabeca == NULL) {
        return 1;
    } else {
        return 0;
    }
}

struct PontoTuristico* inserir_final(struct PontoTuristico* cabeca) {
    struct PontoTuristico* novo = (struct PontoTuristico*) malloc(sizeof(struct PontoTuristico));
    lePontoTuristico(novo);
    novo->proximo = NULL;

    if (cabeca == NULL) {
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




struct PontoTuristico* remover_lista(struct PontoTuristico* cabeca, char *desc) {
    struct PontoTuristico* paux, * ant = NULL;

    for (paux = cabeca; paux != NULL; ant = paux, paux = paux->proximo) {
        if (strcmp(paux->descricao, desc) == 0) {
            if (ant == NULL) {
                cabeca = paux->proximo;
            } else {
                ant->proximo = paux->proximo;
            }
            free(paux);
            return cabeca;
        }
    }
    printf("Descricao nao encontrada.");
    return cabeca;
}

