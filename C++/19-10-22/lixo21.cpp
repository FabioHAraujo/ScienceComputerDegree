#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main ()
{
    int maiorMedia[10]{0}, menorMedia[10]{0}, auxMaior, auxMenor, count=0, tst=0, tst2=0;
    double nota;
    while (count<10)
    {
        cin >> nota;
        if (nota >= 7)
        {
            maiorMedia[count]=nota;
        }
        else if (nota<7 && nota>=0)
        {
            menorMedia[count]=nota;
        }
        count++;
    }
    while (tst<10)
    if (maiorMedia[tst]>=0)
    {

    }
    {
        cout << maiorMedia[tst] << endl;
        tst++;
    }
    while (tst2<10)
    {
        cout << menorMedia[tst2] << endl;
        tst2++;
    }


    return 0;
}