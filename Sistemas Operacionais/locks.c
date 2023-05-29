#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int valor = 0;
pthread_mutex_t lock; // Declaração do Lock

void* incrementar(void* arg) {
    pthread_mutex_lock(&lock); // Adquire o Lock
    valor++;
    printf("Valor incrementado para %d\n", valor);
    pthread_mutex_unlock(&lock); // Libera o Lock
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[10];
    pthread_mutex_init(&lock, NULL); // Inicializa o Lock
    int i;

    for (i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, incrementar, NULL);
    }

    for (i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock); // Libera o Lock
    return 0;
}
