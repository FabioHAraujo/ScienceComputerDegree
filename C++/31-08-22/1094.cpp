#include <iomanip>
#include <iostream>

using namespace std;

int main ()
{
    int casos, testes, count=1;
    double numTestes, coelhos=0, ratos=0, sapos=0;
    char cobaia;
    cin >> casos;
    while (count<=casos)
    {
        count++;
        cin >> testes >> cobaia;
        numTestes+=testes;
        if (cobaia=='C')
        {
            coelhos+=testes;
        }
        else if (cobaia=='R')
        {
            ratos+=testes;
        }
        else if (cobaia=='S')
        {
            sapos+=testes;
        }
    }
    cout << "Total: " << numTestes << " cobaias" << endl;
    cout << "Total de coelhos: " << coelhos << endl;
    cout << "Total de ratos: " << ratos << endl;
    cout << "Total de sapos: " << sapos << endl;
    cout << fixed << setprecision(2) << "Percentual de coelhos: " << (coelhos*100)/numTestes << " %" << endl;
    cout << fixed << setprecision(2) << "Percentual de ratos: " << (ratos*100)/numTestes << " %" << endl;
    cout << fixed << setprecision(2) << "Percentual de sapos: " << (sapos*100)/numTestes << " %" << endl;

    return 0;
}