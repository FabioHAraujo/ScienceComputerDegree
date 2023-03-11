#include <iostream>
#include <iomanip>

using namespace std;

int copiaString(char *auxorigem, char *auxdestino);

int main(void){
    char origem[10] = "Ana";
    char destino[10];

    copiaString(origem, destino);
    cout << origem << "  " <<  destino;
}


int copiaString(char *origem, char *destino){
    while (*origem != '\0') {
        *destino=*origem;
        origem++;
        destino++;
    }
    *destino = '\0';
    return 1;
}
