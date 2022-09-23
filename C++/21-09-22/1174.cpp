#include <iostream>
#include <iomanip>
 
using namespace std;
 
int main()
{
    int count=0;
    double A[100];
    while (count<100)
    {
        cin >> A[count];
        if (A[count]<=10)
        {
            cout << fixed << setprecision(1) << "A[" << count << "] = " << A[count] << endl;
        }
        count ++;

    }

    return 0;
}