#include <stdio.h>
// funcao recursiva

int prova(int N){
    if (N==0) return 0;
    else return N*2 - 1 + prova(N-1);
}
// resto do codigo
int main(){
    int N;
    scanf("%d", &N);
    printf("%d\n", prova(N));
    return 0;
}