#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
int main() {
    srand(time(NULL));
    int resultado=0;
    int dado=20;
    int i;
    for (i=0; i<20; i=i+1)
    {
        resultado = rand()% dado +1;
    }
    cout << resultado;


return 0;
}