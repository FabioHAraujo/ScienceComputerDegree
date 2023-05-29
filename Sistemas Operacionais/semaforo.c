#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 5

int contador = 0; // recurso compartilhado
sem_t semaforo; // semáforo binário

void *thread_func(void *arg) {
  int id = *(int *) arg;

  // acessa a Seção Crítica
  sem_wait(&semaforo);
  contador++;
  printf("Thread %d incrementou o contador para %d\n", id, contador);
  sem_post(&semaforo);

  pthread_exit(NULL);
}

int main() {
  pthread_t threads[NUM_THREADS];
  int ids[NUM_THREADS];
  int i;

  // inicial semáforo com valor 1 (seção livre)
  
sem_init(&semaforo, 0, 1);

// cria as threads
for (i = 0; i < NUM_THREADS; i++) {
ids[i] = i;
pthread_create(&threads[i], NULL, thread_func, &ids[i]);
}

// aguarda as threads terminarem
for (i = 0; i < NUM_THREADS; i++) {
pthread_join(threads[i], NULL);
}

// destroi o semáforo
sem_destroy(&semaforo);

return 0;
}