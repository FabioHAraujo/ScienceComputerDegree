#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct {
    int pid;
    int tempo_chegada;
    int tempo_exec;
    int prioridade;
    int tempo_restante;
} Processo;

void trocar(Processo *xp, Processo *yp);
void ordenar_por_prioridade(Processo *processos, int n);
void escalonador(Processo *processos, int n);
void cabecalho_terminal();

int main() {
    cabecalho_terminal();

    FILE *arquivo = fopen("fila.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    else {
        printf("Arquivo carregado com sucesso\n");
    }

    int num_processos;
    fscanf(arquivo, "%d", &num_processos);

    Processo *processos = (Processo *)malloc(num_processos * sizeof(Processo));

    int i;
    for (i = 0; i < num_processos; i++) {
        fscanf(arquivo, "%d %d %d %d",
            &processos[i].pid,
            &processos[i].tempo_chegada,
            &processos[i].tempo_exec,
            &processos[i].prioridade);

        processos[i].tempo_restante = processos[i].tempo_exec;
    }

    rewind(arquivo);
    printf("Este eh o arquivo inicial:\n");
    char tempChar;
    while ((tempChar = fgetc(arquivo)) != EOF) {
        printf("%c", tempChar);
    }
    printf("\n");
    printf("Com base nesse arquivo, o escalonador ira executar os processos abaixo.\n");
    sleep(1);

    fclose(arquivo);

    printf("Lista de Processos Montada:\n");
    for (i = 0; i < num_processos; i++) {
        printf("PID: %d, Tempo de Chegada: %d, Tempo para Execucao: %d, Prioridade: %d\n",
            processos[i].pid,
            processos[i].tempo_chegada,
            processos[i].tempo_exec,
            processos[i].prioridade);
    }

    printf("\n");

    sleep(1);

    escalonador(processos, num_processos);

    free(processos);

    return 0;
}


void trocar(Processo *procAntes, Processo *prosDepois) {
    Processo temp = *procAntes;
    * procAntes = *prosDepois;
    *prosDepois = temp;
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
    int tempo_atual = 0;
    int i, j;

    while (1) {
        int processo_encontrado = 0;
        ordenar_por_prioridade(processos, n);

        for (i = 0; i < n; i++) {
            if (processos[i].tempo_chegada <= tempo_atual && processos[i].tempo_restante > 0) {
                processo_encontrado = 1;
                printf("Executando Processo %d, tempo restante: %d\n", processos[i].pid, processos[i].tempo_restante);
                sleep(0.5);

                processos[i].tempo_restante--;

                if (processos[i].tempo_restante == 0) {
                    printf("Processo %d concluido\n", processos[i].pid);
                    sleep(1);
                }

                for (j = 0; j < n; j++) {
                    if (j != i && processos[j].tempo_chegada <= tempo_atual && processos[j].tempo_restante > 0 && processos[i].tempo_restante > 0) {
                        printf("Preemptando Processo %d (Tempo Restante: %d) com Processo %d (Tempo Restante: %d)\n",
                        processos[j].pid, processos[j].tempo_restante,
                        processos[i].pid, processos[i].tempo_restante);
                        sleep(0.5);

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

void cabecalho_terminal() {
    printf("Trabalho Final de Sistemas Operacionais\n");
    printf("Aluno: Fabio Henrique Araujo\n");
    printf("Professor: Dr. Paulo Ricardo Muniz Barros\n");
    printf("Disciplina: Sistemas Operacionais\n");
    printf("Curso: Ciencia da Computacao\n");
    printf("Universidade: Universidade Feevale\n");
    printf("Ano: 2023\n");
    printf("\n");
    sleep(1);

    printf("Seja bem vindo ao simulador de escalonamento de processos!\n");
    printf("Este programa ira simular o escalonamento de processos de acordo com o arquivo de entrada\n");
    printf("O arquivo de entrada deve estar no formato:\n");
    printf("Numero de Processos\n");
    printf("PID Tempo_de_Chegada Tempo_de_Execucao Prioridade\n");
    printf("Exemplo:\n");
    printf("3\n");
    printf("1 0 10 1\n");
    printf("2 1 5 2\n");
    printf("3 2 3 3\n");
    printf("\n");

    printf("Para fins de demonstracao, foi adicionado um sleep de meio segundo entre cada acao do programa\n");
    printf("Isso foi feito para que o usuario possa acompanhar o que esta acontecendo\n");

    printf("Carregando arquivo de processos...\n");
    sleep(1);
}

int cabecalho_arquivo() {
    FILE *arquivo_saida = fopen("ultimaExecucao.txt", "w");
    if (arquivo_saida == NULL) {
        printf("Erro ao criar o arquivo de saida\n");
        return 1;
    }

    dup2(fileno(arquivo_saida), STDOUT_FILENO);

    fprintf(arquivo_saida, "Trabalho Final de Sistemas Operacionais\n");
    fprintf(arquivo_saida, "Aluno: Fabio Henrique Araujo\n");
    fprintf(arquivo_saida, "Professor: Dr. Paulo Ricardo Muniz Barros\n");
    fprintf(arquivo_saida, "Disciplina: Sistemas Operacionais\n");
    fprintf(arquivo_saida, "Curso: Ciencia da Computacao\n");
    fprintf(arquivo_saida, "Universidade: Universidade Feevale\n");
    fprintf(arquivo_saida, "Ano: 2023\n");
    fprintf(arquivo_saida, "\n");

    fprintf(arquivo_saida, "Seja bem vindo ao simulador de escalonamento de processos!\n");
    fprintf(arquivo_saida, "Este programa ira simular o escalonamento de processos de acordo com o arquivo de entrada\n");
    fprintf(arquivo_saida, "O arquivo de entrada deve estar no formato:\n");
    fprintf(arquivo_saida, "Numero de Processos\n");
    fprintf(arquivo_saida, "PID Tempo_de_Chegada Tempo_de_Execucao Prioridade\n");
    fprintf(arquivo_saida, "Exemplo:\n");
    fprintf(arquivo_saida, "3\n");
    fprintf(arquivo_saida, "1 0 10 1\n");
    fprintf(arquivo_saida, "2 1 5 2\n");
    fprintf(arquivo_saida, "3 2 3 3\n");
    fprintf(arquivo_saida, "\n");

    fprintf(arquivo_saida, "Para fins de demonstracao, foi adicionado um sleep de meio segundo entre cada acao do programa\n");
    fprintf(arquivo_saida, "Isso foi feito para que o usuario possa acompanhar o que esta acontecendo\n");

    fprintf(arquivo_saida, "Carregando arquivo de processos...\n");
    sleep(1);

    fclose(arquivo_saida);


}