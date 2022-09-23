#include <iomanip>
#include <iostream>

using namespace std;

int main ()
{
    int count1=0, N[20], count2=19, aux=0;
    while (count1<20)
    {
        cin >> N[count1];
        count1++;
    }
    while (count2>=0)
    {
        cout << "N["<< aux << "] = " << N[count2] << endl;
        aux++;
        count2--;
    }
    
    return 0;
}