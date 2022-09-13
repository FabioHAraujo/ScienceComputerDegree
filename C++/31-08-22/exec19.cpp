#include <iomanip>
#include <iostream>

using namespace std;

int main ()
{
    int idade=0, peso=0, totalIdade=0, count20=0, media=0, countCria=0;
    while (idade>=0)
    {
        cin >> idade;
        cin >> peso;
        if (idade<20 && idade>0)
        {
            media+=idade;
            countCria++;
        }

        if (idade>=20)
        {
            count20++;
        }
        if (peso>=60 && peso<=70)
        {
            totalIdade+=idade;
        }
        if (idade<0)
        {
            totalIdade-=idade;
        }
    }
    cout << count20 << " Tem mais de 20 anos." << endl;
    cout << media/countCria << endl;
    cout << totalIdade << endl;

    
    return 0;
}