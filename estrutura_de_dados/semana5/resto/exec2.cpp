#include <iomanip>
#include <iostream>

using namespace std;

void bubble(int A[], int n){
    for(int i=0; i<n; i++){
        cout << A[i] << endl;
    }
}

int main(void){
    int n = 10;
    int A[n] = {9,8,7,6,5,4,3,2,1,0};
    bubble(A,n);
}