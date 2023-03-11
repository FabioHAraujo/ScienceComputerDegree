#include <iostream>
#include <iomanip>
#include <iostream>

using namespace std;

void troca(int *a, int *b);

int main (void){
    int a,b;
    a = 10;
    b = 20;
    
    cout << a << "       " << b << endl;
    
    troca(&a,&b);

    cout << a << "       " << b << endl;

    printf("%u", &a);

    return 0;

}

void troca (int *a, int *b) {
    int temp;
    temp = *a;
    *a=*b;
    *b=temp;
}



