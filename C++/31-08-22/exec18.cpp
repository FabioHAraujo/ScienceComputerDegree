#include <iomanip>
#include <iostream>

using namespace std;

int main ()
{
    int numero, count = 1;
    cin >> numero;
    for (count >0; count <=10; count++)
    {
        cout << numero << " x " << count << " = " << numero*count << endl;
    }
    
    return 0;
}