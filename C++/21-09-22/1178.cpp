#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    int count=0;
    double metade, valor, N[100];
    cin >> valor;
    while (count<100)
    {
        N[count]=valor;
        cout << fixed << setprecision(4) << "N[" << count << "] = " << N[count]<< endl;
        valor/=2;
        count++;
    }

    return 0;
}