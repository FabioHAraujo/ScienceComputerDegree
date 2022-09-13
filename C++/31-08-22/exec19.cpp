#include <iomanip>
#include <iostream>

using namespace std;

int main ()
{
    double idade=0, peso=0, totalIdade=0, count20=0, media=0, countCria=0;
    while (idade>=0)
    {
        cin >> idade;
        cin >> peso;
        if (idade<20 && idade>0)
        {
            media+=peso;
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
    cout << count20 << " Alunos tem mais de 20 anos." << endl;
    cout << fixed << setprecision(2) << "A media de peso dos alunos menores de 20 anos eh: " << media/countCria << endl;
    cout << "Os alunos que pesam entre 60 e 70 quilos, tem idade somada de: " << totalIdade << endl;

    
    return 0;
}