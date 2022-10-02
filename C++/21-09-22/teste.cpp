#include <iomanip>
#include <iostream>

using namespace std;

int main ()
{
    int array[5]={0}, count=0;
    while (count<30)
    {
        cin >> array[count];
        cout <<  array[count];
        count++;
    }
    
    return 0;
}