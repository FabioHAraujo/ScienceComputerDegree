#include <stdio.h>

int main (){
    int num1, num2;

    printf("Por favor, digite dois numeros inteiros para que possamos iniciar: \n");
    printf("Numero 1: ");
    scanf("%d", &num1);
    printf("Numero 2: ");
    scanf("%d", &num2);

    printf("Digite a operação que de seja fazer, \n");
    printf("Soma '+', multiplicação '*', divisão '/', subtração '-': ");

    char entrada;

    scanf("%s", &entrada);

    int result;
    
    if (entrada=='+') {
        result = num1+num2;
        printf("O resutlado eh: %d", result);
    }
    else if (entrada=='-') {
        
    }
    else if (entrada=='*') {
        
    }
    else if (entrada=='/') {
        
    }

}