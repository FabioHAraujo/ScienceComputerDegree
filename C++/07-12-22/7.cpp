#include <iomanip>
#include <iostream>

using namespace std;

int main ()
{
    int vetor[10], num, auxMaior=0, auxMenor=0;
    cout << "por favor, insira as nota de seus 10 alunos para a prova" << endl;
    for (int i=0; i<10; i++)
    {
        cin >> vetor[i];
    }
    cout << "qual sera a media para essa prova?" << endl;
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
    cout << "As notas na media de " << num << " ou acima sao: " << endl;
    for (int i=0; i<auxMaior; i++)
    {
        cout << "Aluno Numero [" << posiMaior[i] << "] "  << maiores[i] << endl;
    }
    cout << "As notas abaixo de " << num << " sao: " << endl;
    for (int i=0; i<auxMenor; i++)
    {
        cout << "Aluno Numero [" << posiMenor[i] << "] " << menores[i] << endl;
    }
    return 0;
}
