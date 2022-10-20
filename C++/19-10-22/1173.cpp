#include <iostream>
#include <iomanip>
 
using namespace std;
 
int main()
{
    int count=0, n[10] = {0};
    cin >> n[0];
    while (count<10)
    {
        n[count+1]=n[count]*2;
        count++;
    }
    count = 0;
    while (count<10)
    {
        cout << "N[" << count << "] = " << n[count] << endl;
        count ++;
    }

    return 0;
}