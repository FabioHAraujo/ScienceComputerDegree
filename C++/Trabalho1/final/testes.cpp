#include <iostream>
#include <iomanip>
#include "dados.cpp"

using namespace std;

int atributos(int forca, int destreza, int magia, int vida)
{
    int atributosGerais;
    atributosGerais = forca+destreza+magia+vida;
    return atributosGerais;
}

int main ()
{
    int f=1, d=2, m=3, vi=4, vl=5;
    int s;  
    s = atributos (f,d,m,vi);
    cout << "atributos > " << s << endl;


    return 0;
}