#include <iomanip>
#include <iostream>

using namespace std;

int main ()
{
    int quant=0, count=0;
    double numeros, result=0;
    cout << "De quantos numeros deseja obter a media?" << endl;
    cin >> quant;
    while (count!=quant)
    {
        count++;
        cin >> numeros;
        result+=numeros;
    }
    cout << fixed << setprecision(1) << "Media = " << result/quant << endl;
    return 0;
}