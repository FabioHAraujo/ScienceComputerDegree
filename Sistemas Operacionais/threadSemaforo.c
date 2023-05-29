#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

int contador = 0;
sem_t semaforo;

void *threadPrint(void *vargp){
    long tid = (long)vargp;
    for(int i=0;i<100;i++){
        sem_wait(&semaforo); // espera o semáforo ficar livre
        contador++;
        printf("thread #%ld incrementou %d\n", tid, contador);
        sem_post(&semaforo); // libera o semáforo
        int randomTime = rand() %2 + 1;
        sleep(randomTime);
    }
}

int main(){
    pthread_t threads[6];
    sem_init(&semaforo, 0, 1); // inicializa o semáforo com 1
    for(long i=0; i<6;i++){
        pthread_create(&(threads[i]), NULL, threadPrint, (void *) i);
    }
    for (int i=0; i<6; i++) {
        pthread_join(threads[i], NULL);
    }
    sem_destroy(&semaforo); // destrói o semáforo
    printf("Valor final: %d\n", contador);
    return EXIT_SUCCESS;
}