#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    int numProdutos, counter=0;
    double valProduto, total=0;
    cout << "Quantidade de produtos comprados: ";
    cin >> numProdutos;
    while (counter<numProdutos)
    {
        cout << "Valor do produto: ";
        cin >> valProduto;
        total+=valProduto;
        counter++;
    }
    cout << fixed << setprecision(2) << "VALOR TOTAL DA COMPRA: " << total << endl;

    return 0;
}