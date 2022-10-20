#include <iomanip>
#include <iostream>

using namespace std;

int main ()
{
    int pos=0, count1=0, tam=20, count2=19, auxArray=0, aux=0;
    int N[tam];
    int pos2 = tam -1;
    while (count1<20)
    {
        cin >> N[pos];
        pos++;
        count1++;
    }
    tam
    while (count2>0)
    {
        auxArray = N[tam-1-pos];
        N[tam-1-pos] = N[pos];
        N[pos] = auxArray;
        count2--;
    }
    while (aux<20)
    {
        cout << "N["<< aux << "] = " << N[aux] << endl;
        aux++;
    }
    
    return 0;
}


