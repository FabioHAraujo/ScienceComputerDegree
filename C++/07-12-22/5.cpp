#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    int array[10], num1, num2;
    for (int i=0; i<10; i++)
    {
        cin >> array[i];
    }
    cin >> num1 >> num2;
    for (int i=0; i<10; i++)
    {
        if (array[i]>num1 && array[i]<num2)
        {
            cout << "vet[" << i << "]: " << array[i] << endl;
        }
    }
    return 0;
}
