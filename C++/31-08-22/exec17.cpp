#include <iomanip>
#include <iostream>

using namespace std;

int main ()
{
    double numero=0, result=0, count=0;
    while (numero>=0)
    {
        cin >> numero;
        if (numero>=0)
        {
            result+=numero;
            count++;
        }
    }
    cout << "Foram informados " << count << " valores." << endl;
    cout << fixed << setprecision(1) << "Media dos valores positivos digitados = " << result/count << endl;
    return 0;
}