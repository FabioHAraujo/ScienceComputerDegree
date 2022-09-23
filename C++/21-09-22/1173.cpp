#include <iostream>
#include <iomanip>
 
using namespace std;
 
int main()
{
    int count=0, n[10] = {0}, V;
    cin >> V;
    while (count<10)
    {
        n[count]=V;
        cout << "N[" << count << "] = " << n[count] << endl;
        V*=2;
        count ++;
    }

    return 0;
}