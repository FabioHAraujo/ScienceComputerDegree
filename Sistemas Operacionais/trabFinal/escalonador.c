#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define TEMPO 200000

typedef struct {
    int pid;
    int tempo_chegada;
    int burst;
    int prioridade;
    int tempo_restante;
    int tempo_espera;  // Novo campo para armazenar o tempo de espera
} Processo;

void trocar(Processo *procAntes, Processo *procDepois);
void ordenar_por_prioridade(Processo *processos, int n);
void escalonador(Processo *processos, int n);
void cabecalho_terminal();
void cabecalho_arquivo(FILE *arquivo_saida);

int main() {
    cabecalho_terminal();

    FILE *arquivo = fopen("fila.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    } else {
        printf("Arquivo carregado com sucesso\n");
    }

    FILE *arquivo_saida = fopen("ultimaExecucao.txt", "w");
    if (arquivo_saida == NULL) {
        printf("Erro ao criar o arquivo de saída\n");
        fclose(arquivo);
        return 1;
    }


    // Escreve o cabeçalho no arquivo
    cabecalho_arquivo(arquivo_saida);

    int num_processos;
    fscanf(arquivo, "%d", &num_processos);

    Processo *processos = (Processo *)malloc(num_processos * sizeof(Processo));

    int i;
    for (i = 0; i < num_processos; i++) {
        fscanf(arquivo, "%d %d %d %d",
            &processos[i].pid,
            &processos[i].tempo_chegada,
            &processos[i].burst,
            &processos[i].prioridade);

        processos[i].tempo_restante = processos[i].burst;
        processos[i].tempo_espera = 0;
    }

    rewind(arquivo);
    printf("Este eh o arquivo inicial:\n");
    char tempChar;
    while ((tempChar = fgetc(arquivo)) != EOF) {
        printf("%c", tempChar);
        usleep(TEMPO/4);
    }
    printf("\n");
    printf("Com base nesse arquivo, o escalonador ira executar os processos abaixo.\n");
    fprintf(arquivo_saida, "Com base nesse arquivo, o escalonador ira executar os processos abaixo.\n");
    fprintf(arquivo_saida, "Este eh o arquivo inicial:\n");
    rewind(arquivo);
    while ((tempChar = fgetc(arquivo)) != EOF) {
        fputc(tempChar, arquivo_saida);
    }
    fputc('\n', arquivo_saida);

    fclose(arquivo);

    printf("Lista de Processos Montada:\n");
    fprintf(arquivo_saida, "Lista de Processos Montada:\n");
    for (i = 0; i < num_processos; i++) {
        printf("PID: %d, Tempo de Chegada: %d, BURST: %d, Prioridade: %d\n",
            processos[i].pid,
            processos[i].tempo_chegada,
            processos[i].burst,
            processos[i].prioridade);
        fprintf(arquivo_saida, "PID: %d, Tempo de Chegada: %d, BURST: %d, Prioridade: %d\n",
            processos[i].pid,
            processos[i].tempo_chegada,
            processos[i].burst,
            processos[i].prioridade);
        usleep(TEMPO);
        fflush(arquivo_saida);
    }

    printf("\n");
    fprintf(arquivo_saida, "\n");

    sleep(1);

    fflush(arquivo_saida);

    escalonador(processos, num_processos);

    free(processos);

    fclose(arquivo_saida);

    return 0;
}

void trocar(Processo *procAntes, Processo *procDepois) {
    Processo temp = *procAntes;
    *procAntes = *procDepois;
    *procDepois = temp;
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

void escalonador(Processo *processos, int n) {
    double total_tempo = 0;
    int tempo_atual = 0;
    int i, j;

    FILE *arquivo_saida = fopen("ultimaExecucao.txt", "a");  // Abrir arquivo de saída

    while (1) {
        int processo_encontrado = 0;
        ordenar_por_prioridade(processos, n);

        for (i = 0; i < n; i++) {
            if (processos[i].tempo_chegada <= tempo_atual && processos[i].tempo_restante > 0) {
                processo_encontrado = 1;
                printf("Executando Processo %d, tempo restante: %d\n", processos[i].pid, processos[i].tempo_restante);
                fprintf(arquivo_saida, "Executando Processo %d, tempo restante: %d\n", processos[i].pid, processos[i].tempo_restante);
                usleep(TEMPO);

                processos[i].tempo_restante--;
                for (j = 0; j < n; j++) {
                    if (j != i && processos[j].tempo_chegada <= tempo_atual && processos[j].tempo_restante > 0 && processos[i].tempo_restante > 0) {
                        processos[j].tempo_espera++;
                    }
                }

                if (processos[i].tempo_restante == 0) {
                    printf("Processo %d concluido\n", processos[i].pid);
                    fprintf(arquivo_saida, "Processo %d concluido\n", processos[i].pid);
                    printf("Tempo de espera: %d\n", processos[i].tempo_espera);
                    total_tempo+=processos[i].tempo_espera;
                    fprintf(arquivo_saida, "Tempo de espera: %d\n", processos[i].tempo_espera);
                    usleep(TEMPO);
                }

                for (j = 0; j < n; j++) {
                    if (j != i && processos[j].tempo_chegada <= tempo_atual && processos[j].tempo_restante > 0 && processos[i].tempo_restante > 0) {
                        printf("Preemptando Processo %d (Tempo Restante: %d) com Processo %d (Tempo Restante: %d)\n",
                        processos[j].pid, processos[j].tempo_restante,
                        processos[i].pid, processos[i].tempo_restante);
                        fprintf(arquivo_saida, "Preemptando Processo %d (Tempo Restante: %d) com Processo %d (Tempo Restante: %d)\n",
                        processos[j].pid, processos[j].tempo_restante,
                        processos[i].pid, processos[i].tempo_restante);
                        usleep(TEMPO);

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

    // Cálculo do tempo médio de espera (TME)

    int processos_concluidos = 0;
    for (i = 0; i < n; i++) {
        if (processos[i].tempo_restante == 0) {
            processos_concluidos++;
        }
    }
    float tme = total_tempo / processos_concluidos;

    printf("Tempo Medio de Espera (TME): %.2f\n", tme);
    fprintf(arquivo_saida, "Tempo Medio de Espera (TME): %.2f\n", tme);


    fclose(arquivo_saida);  // Fechar arquivo de saída
}

void cabecalho_terminal() {
    printf("====================================================================================================\n");
    printf("Trabalho Final de Sistemas Operacionais\n");
    printf("Aluno: Fabio Henrique Araujo\n");
    printf("Professor: Dr. Paulo Ricardo Muniz Barros\n");
    printf("Disciplina: Sistemas Operacionais\n");
    printf("Curso: Ciencia da Computacao\n");
    printf("Universidade: Universidade Feevale\n");
    printf("Ano: 2023\n");
    printf("====================================================================================================\n");
    printf("\n");
    usleep(TEMPO*15);

    printf("====================================================================================================\n");
    printf("Seja bem vindo ao simulador de escalonamento de processos!\n");
    printf("Este programa ira simular o escalonamento de processos de acordo com o arquivo de entrada\n");
    printf("O arquivo de entrada deve estar no formato:\n");
    printf("Numero de Processos\n");
    printf("PID Tempo_de_Chegada Burst Prioridade\n");
    printf("Exemplo:\n");
    printf("3\n");
    printf("1 0 10 1\n");
    printf("2 1 5 2\n");
    printf("3 2 3 3\n");
    printf("====================================================================================================\n");
    printf("\n");
    usleep(TEMPO*15);

    printf("====================================================================================================\n");
    printf("Para fins de demonstracao, foi adicionado um sleep de 200ms entre cada acao do programa\n");
    printf("Para os detalhes, como este cabecalho, foi adicionado um sleep de 2 e 3 segundos\n");
    printf("Isso foi feito para que o usuario possa acompanhar o que esta acontecendo\n");
    printf("Carregando arquivo de processos...\n");
    printf("====================================================================================================\n");
    usleep(TEMPO*10);
}

void cabecalho_arquivo(FILE *arquivo_saida) {
    fprintf(arquivo_saida, "====================================================================================================\n");
    fprintf(arquivo_saida, "Trabalho Final de Sistemas Operacionais\n");
    fprintf(arquivo_saida, "Aluno: Fabio Henrique Araujo\n");
    fprintf(arquivo_saida, "Professor: Dr. Paulo Ricardo Muniz Barros\n");
    fprintf(arquivo_saida, "Disciplina: Sistemas Operacionais\n");
    fprintf(arquivo_saida, "Curso: Ciencia da Computacao\n");
    fprintf(arquivo_saida, "Universidade: Universidade Feevale\n");
    fprintf(arquivo_saida, "Ano: 2023\n");
    fprintf(arquivo_saida, "====================================================================================================\n");
    fprintf(arquivo_saida, "\n");

    fprintf(arquivo_saida, "====================================================================================================\n");
    fprintf(arquivo_saida, "Seja bem vindo ao simulador de escalonamento de processos!\n");
    fprintf(arquivo_saida, "Este programa ira simular o escalonamento de processos de acordo com o arquivo de entrada\n");
    fprintf(arquivo_saida, "O arquivo de entrada deve estar no formato:\n");
    fprintf(arquivo_saida, "Numero de Processos\n");
    fprintf(arquivo_saida, "PID Tempo_de_Chegada Burst Prioridade\n");
    fprintf(arquivo_saida, "Exemplo:\n");
    fprintf(arquivo_saida, "3\n");
    fprintf(arquivo_saida, "1 0 10 1\n");
    fprintf(arquivo_saida, "2 1 5 2\n");
    fprintf(arquivo_saida, "3 2 3 3\n");
    fprintf(arquivo_saida, "====================================================================================================\n");
    fprintf(arquivo_saida, "\n");
}
