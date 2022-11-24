#include <iostream>
#include <iomanip>

using namespace std;


void troca(int *n1,int *n2)
{
    cout << "isso ai " << *n1 << " " <<  *n2 << endl;
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
    cout << "agora isso ai " << *n1 << " " << *n2 << endl;

}


int main()
{
    int n1=5, n2=10;


    cout << "aqui eh iso aqui " << n1 << " " << n2 << endl;
    troca(&n1,&n2);
    cout << "agora aqui eh isso ai " << n1 << " " << n2 << endl;

    return 0;
}