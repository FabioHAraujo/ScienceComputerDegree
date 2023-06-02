#include <stdlib.h>

void buble_sort(int *A, int n){
    for (int i=0; i<n; i++){
        printf("%d\n", A[i]);
    }
}

int main(){
    int A[10] = {9,8,7,6,5,4,3,2,1,0};
    printf("Bubble\n");
    bubble_sort(A, 10);
    return 0;
}