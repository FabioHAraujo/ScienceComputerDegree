#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    int count=0, pos=0;
    cout << "Quantas notas voce quer ler?\n";
    cin >> pos;
    double notas[pos];
    while (count<pos)
    {
        cin >> notas[count];
        count++;
    }
    cout << fixed << setprecision(2) << notas[4];

    return 0;
}