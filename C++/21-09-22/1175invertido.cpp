#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
 
// Utility function to reverse elements of an array
void reverse(int arr[], int n) {
    reverse(arr, arr + n);
}
 
int main()
{
    int pos;
    int arr[pos];
    for (pos=0; pos<20; pos++)
    {
        cin >> arr[pos];
    }
    
    int n = sizeof(arr)/sizeof(arr[0]);
 
    reverse(arr, n);
    print(arr, n);
 
    return 0;
}