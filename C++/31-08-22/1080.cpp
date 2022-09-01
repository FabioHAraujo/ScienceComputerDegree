#include <iomanip>
#include <iostream>

using namespace std;

int main ()
{
    int numero, auxCount=0, auxNum=0, count=1;
    for (count >1; count <=100; count++)
    {
        cin >> numero;
        if (numero>auxNum)
        {
            auxCount=count;
            auxNum=numero;
        }
    }
    cout << auxNum << endl;
    cout << auxCount << endl;
    
    return 0;
}