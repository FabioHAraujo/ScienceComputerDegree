#include <iostream>
#include <iomanip>

using namespace std;

int main (){
    int LIN = 3;
    int COL =2;
    int a=0, i, j;
    int matriz[LIN][COL] = {
        {1,2},
        {3,4},
        {5,6}
        };
    for (i=0; i<LIN; i++){
        for (j=0; j<COL;j++){
            a+=matriz[i][j];
        }
    }
    cout << "Este eh o valor de A = " << a << endl;

    int *ponteiro = &matriz[0][0];
    int acumulador = 0;
    for (int i=0; i<LIN*COL; i++) {
            acumulador+=(*(ponteiro+i));
    }
    cout << "O Acumulador Eh = " << acumulador << endl;


    int *ponteiro2 = &matriz[0][0];
    int acumulador2 = 0;
    for (int i=0; i<LIN*COL; i++) {
            acumulador2+= *ponteiro2;
            ponteiro2++;
            //anda uma posição no vetor.
    }
    cout << "O Acumulador Eh = " << acumulador2 << endl;
}