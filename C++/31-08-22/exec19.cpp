#include <iomanip>
#include <iostream>

using namespace std;

int main ()
{
    int idade=0, peso, count=0, totalIdade=0, totalPeso, count20=0, media;
    cin >> idade;
    cin >> peso;
    while (idade>=0)
    {
        cin >> idade;
        cin >> peso;
        count++;
        if (idade>=20)
        {
            count20++;
        }
        if (peso>=60 && peso<=70)
        {
            totalIdade+=idade;
        }
    }
    cout << count << endl;

    
    return 0;
}