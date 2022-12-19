#include <iostream>
#include <iomanip>

using namespace std;

int ehPrimo (int num)
{
    int aux, div=0, primo=0;

    for(aux=1 ; aux<=num ; aux++)
        if(num%aux==0)
        {
            div++;
        }
    if(div==2)
    {
        primo++;
    }
    return primo;
}

int main ()
{
    int N, primos=0;
    cin >> N;
    int vetor[N];
    
    for (int i=0; i<N; i++)
    {
        cin >> vetor[i];
    }
    for (int i=0; i<N; i++)
    {
        primos=primos+ehPrimo(vetor[i]);
    }
    
    cout << primos << endl;
    
    
    return 0;
}
