#include <iomanip>
#include <iostream>

using namespace std;

int main ()
{
    int vetor[10], num, auxMaior=0, auxMenor=0;
    for (int i=0; i<10; i++)
    {
        cin >> vetor[i];
    }
    cin >> num;
    for (int i=0; i<10; i++)
    {
        if (vetor[i]<num)
        {
            auxMenor++;
        }
        else if (vetor[i]>=num)
        {
            auxMaior++;
        }
    }
    int menores[auxMenor], maiores[auxMaior];
    int posiMenor[auxMenor], posiMaior[auxMaior];
    auxMenor = 0;
    auxMaior = 0;
    for (int i=0; i<10; i++)
    {
        if (vetor[i]<num)
        {
            menores[auxMenor] = vetor[i];
            posiMenor[auxMenor] = i;
            auxMenor++;
        }
        else if (vetor[i]>=num)
        {
            maiores[auxMaior] = vetor[i];
            posiMaior[auxMaior] = i;
            auxMaior++;
        }
    }
    for (int i=0; i<auxMaior; i++)
    {
        cout << "X[" << posiMaior[i] << "] "  << maiores[i] << endl;
    }
    for (int i=0; i<auxMenor; i++)
    {
        cout << "X[" << posiMenor[i] << "] " << menores[i] << endl;
    }
    return 0;
}
