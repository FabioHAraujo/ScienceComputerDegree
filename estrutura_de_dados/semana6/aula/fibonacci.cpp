#include <iostream>
#include <iomanip>

using namespace std;

long long iteraFibonacci(long long n);

long long recursFibonacci(long long n);

int main(){
    long long n;
    cout << "Bem vindo ao programa de Fibonacci" << endl;
    cout << "Qual numero de Fibonacci deseja descobrir? ";
    cin >> n;
    long long fib = iteraFibonacci(n);
    cout << "O " << n << " numero de Fibonacci eh: " << fib << endl;
    cout << "Agora vamos fazer Recursivo: " << endl;
    fib = recursFibonacci(n);
    cout << "O " << n << " numero de Fibonacci eh: " << fib << endl;

    return 0;

}

long long iteraFibonacci(long long n){
    long long fib;
    if (n == 1 || n == 2) fib = 1;
    else{
        long long a = 0, b = 1;
        for (int i = 2; i < n; i++){
            fib = a + b;
            a = b;
            b = fib;
        }
        return fib;
    }
    
    return fib;
}

long long recursFibonacci(long long n){
    if (n == 1){
        return 0;
    }
    else if (n == 2){
        return 1;
    }
    else{
        return recursFibonacci(n-1)+recursFibonacci(n-2);
    }
}