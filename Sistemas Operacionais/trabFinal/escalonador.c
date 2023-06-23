#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;
    int tempo_chegada;
    int burst_time;
    int prioridade;
    int tempo_restante;
} Processo;

void trocar(Processo *xp, Processo *yp) {
    Processo temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void ordenar_por_prioridade(Processo *processos, int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (processos[j].prioridade > processos[j+1].prioridade) {
                trocar(&processos[j], &processos[j+1]);
            }
        }
    }
}

void escalonar(Processo *processos, int n) {
    int tempo_atual = 0;
    int i, j;

    while (1) {
        int processo_encontrado = 0;
        ordenar_por_prioridade(processos, n);

        for (i = 0; i < n; i++) {
            if (processos[i].tempo_chegada <= tempo_atual && processos[i].tempo_restante > 0) {
                processo_encontrado = 1;
                printf("Executando Processo %d\n", processos[i].pid);

                processos[i].tempo_restante--;

                if (processos[i].tempo_restante == 0) {
                    printf("Processo %d concluído\n", processos[i].pid);
                }

                for (j = 0; j < n; j++) {
                    if (j != i && processos[j].tempo_chegada <= tempo_atual && processos[j].tempo_restante > 0) {
                        printf("Preemptando Processo %d (Tempo Restante: %d) com Processo %d (Tempo Restante: %d)\n",
                            processos[j].pid, processos[j].tempo_restante,
                            processos[i].pid, processos[i].tempo_restante);

                        break;
                    }
                }

                break;
            }
        }

        if (!processo_encontrado)
            break;

        tempo_atual++;
    }
}

int main() {
    FILE *arquivo = fopen("processos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    int num_processos;
    fscanf(arquivo, "%d", &num_processos);

    Processo *processos = (Processo *)malloc(num_processos * sizeof(Processo));

    int i;
    for (i = 0; i < num_processos; i++) {
        fscanf(arquivo, "%d %d %d %d",
            &processos[i].pid,
            &processos[i].tempo_chegada,
            &processos[i].burst_time,
            &processos[i].prioridade);

        processos[i].tempo_restante = processos[i].burst_time;
    }

    fclose(arquivo);

    printf("Processos:\n");
    for (i = 0; i < num_processos; i++) {
        printf("PID: %d, Tempo de Chegada: %d, Burst Time: %d, Prioridade: %d\n",
            processos[i].pid,
            processos[i].tempo_chegada,
            processos[i].burst_time,
            processos[i].prioridade);
    }

    printf("\n");

    escalonar(processos, num_processos);

    free(processos);

    return 0;
}
