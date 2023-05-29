#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int contador = 0;
pthread_mutex_t mutex;

void *threadPrint(void *vargp){
    long tid = (long)vargp;
    for(int i=0;i<100;i++){
        pthread_mutex_lock(&mutex); // trava o mutex
        contador++;
        printf("thread #%ld incrementou %d\n", tid, contador);
        pthread_mutex_unlock(&mutex); // destrava o mutex
        int randomTime = rand() %2 + 1;
        sleep(randomTime);
    }
}

int main(){
    pthread_t threads[6];
    for(long i=0; i<6;i++){
        pthread_create(&(threads[i]), NULL, threadPrint, (void *) i);
    }
    for (int i=0; i<6; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("Valor final: %d\n", contador);
    return EXIT_SUCCESS;
}
