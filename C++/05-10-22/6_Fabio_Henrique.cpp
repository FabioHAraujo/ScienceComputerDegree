#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    int N, X, Y, counter=0;
    double auxX, auxY;

    cin >> N;
    while (counter<N)
    {
        cin >> X >> Y;
        if (Y == 0)
        {
            cout << "divisao impossivel" << endl;
        }
        else
        {
            auxX = X;
            auxY = Y;
            cout << fixed << setprecision(1) << auxX/auxY << endl;
        }
        counter++;
    }

    return 0;
}