#include <iostream>
#include <iomanip>
 
using namespace std;
 
int main()
{
    int count=0, x[10];
    while (count<10)
    {
        cin >> x[count];
        if (x[count]<=0)
        {
            x[count]= 1;
        }
        cout << "X[" << count << "] = " << x[count] << endl;
        count ++;

    }

    return 0;
}