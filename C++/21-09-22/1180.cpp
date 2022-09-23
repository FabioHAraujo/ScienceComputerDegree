#include <iostream>
#include <iomanip>
 
using namespace std;
 
int main()
{
    int count=0, num=0, valor=0, menor=1000, posi=0;
    cin >> num;
    int  array[num];
    while (count<num)
    {
        cin >> valor;
        if (valor<menor)
        {
            menor=valor;
            posi=count;
            array[posi]=menor;
        }
        count ++;

    }
    cout << "Menor valor: " << array[posi] << endl;
    cout << "Posicao: " << posi << endl;

    return 0;
}