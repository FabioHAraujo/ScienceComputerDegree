#include <stdio.h>

void recursivaA(int num) {   
    if (num < 5)   {     
        printf("%d\n", num);
        recursivaA(num + 1);
    }
}
void recursivaB(int num) {   
    if (num < 5)   {      
        recursivaB(num + 1);
        printf("%d\n", num);
    }
}

int main() {
    recursivaA(1);
    printf("\n");
    recursivaB(1);
    return 0;
}