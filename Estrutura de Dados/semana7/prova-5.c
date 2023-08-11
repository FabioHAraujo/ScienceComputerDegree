#include <stdio.h>
#define TAM 5

void funcao1(int v[], int l, int r) {
    int a;
    if (l >= r)
        return;
    else {
        a = v[l];
        v[l] = v[r];
        v[r] = a;
        funcao1(v, l + 1, r - 1);
    }
}

int main(int argc, const char *argv[]) {
    int v[11] = {1, 2, 3, 4, 5};
    funcao1(v, 0, TAM - 1);
    for (int i = 0; i < TAM; i++)
        printf("%d\t", v[i]);
    return 0;
}
