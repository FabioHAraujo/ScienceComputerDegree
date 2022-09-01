#include <iomanip>
#include <iostream>

using namespace std;

int main ()
{
    int A, B, C;
    cin >> A >> B >> C;
    if (A<B && B<C)
    {
        cout << A << endl;
        cout << B << endl;
        cout << C << endl;
    }
    else if (B<C && C<A)
    {
        cout << B << endl;
        cout << C << endl;
        cout << A << endl;
    }
    else if (C<A && A<B)
    {
        cout << C << endl;
        cout << A << endl;
        cout << B << endl;
    }
    else if (B<A && A<C)
    {
        cout << B << endl;
        cout << A << endl;
        cout << C << endl;
    }
    else if (C<B && B<A)
    {
        cout << C << endl;
        cout << B << endl;
        cout << A << endl;
    }
    else if (A<B && C<B)
    {
        cout << A << endl;
        cout << C << endl;
        cout << B << endl;
    }
    cout << endl;
    cout << A << endl;
    cout << B << endl;
    cout << C << endl;

    return 0;
}