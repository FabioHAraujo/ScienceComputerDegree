#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno{
    char nome[100];
    float nota1, nota2, media;
};

float insercao(struct Aluno *alunos, int qtdAlunos);
void getMedias (struct Aluno *alunos, int qtdAlunos);

int main(void){
    struct Aluno aln[100];
    int qtdAlunos;
    
    printf("Por favor, quantos alunos deseja inserir?\n");
    scanf("%d", &qtdAlunos);
    fflush(stdin);

    insercao(aln, qtdAlunos);

    getMedias(aln, qtdAlunos);

    return 0;
}

float insercao(struct Aluno *alunos, int qtdAlunos){
    for (int i=0;i<qtdAlunos;i++){
        struct Aluno tempAluno;

        printf("Ola, seja bem vindo, vamos calcular sua media. Primeiramente, qual seu nome?\n");
        fflush(stdin);
        fgets(tempAluno.nome, 100, stdin);
        tempAluno.nome[strcspn(tempAluno.nome, "\n")] = '\0';

        printf("Certo, vou te chamar de %s. Agora digite suas 2 notas\n", tempAluno.nome);
        scanf("%f %f", &tempAluno.nota1, &tempAluno.nota2);

        tempAluno.media = (tempAluno.nota1+tempAluno.nota2)/2;
        alunos[i] = tempAluno;
    }
    return 0;
}

void getMedias (struct Aluno *alunos, int qtdAlunos)
{
    for (int i=0;i<qtdAlunos;i++) printf("A Media do Aluno %s Foi: %.2f\n", alunos[i].nome, alunos[i].media);

    return;
}
