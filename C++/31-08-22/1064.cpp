#include <iomanip>
#include <iostream>

using namespace std;

int main ()
{
    float count=0, numero, aux=1, media, final=0;
    while (aux <=6)
    {
        cin >> numero;
        media = numero;
        aux++;
        if (numero >=0)
        {
            count++;
            final+=media;
        }
    }
    cout << count << " valores positivos" << endl;
    cout << fixed << setprecision(1) << final/count << endl;

    return 0;
}