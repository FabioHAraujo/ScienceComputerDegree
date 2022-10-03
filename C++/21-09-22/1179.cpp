#include <iomanip>
#include <iostream>

using namespace std;

int main ()
{
    int valor, par[5]={0}, impar[5]={0}, count=0, auxPar=0, auxImpar=0, aux=0, aux2=0, aux3=0, aux4=0;
    while (count<15)
    {
        cin >> valor;
        if (valor%2==0)
        {
            par[auxPar]=valor;
            auxPar++;
            if (auxPar>=5)
            {
                cout << "par[0] = " << par[0] << endl;
                cout << "par[1] = " << par[1] << endl;
                cout << "par[2] = " << par[2] << endl;
                cout << "par[3] = " << par[3] << endl;
                cout << "par[4] = " << par[4] << endl;
                auxPar=0;
                par[0]=0;
                par[1]=0;
                par[2]=0;
                par[3]=0;
                par[4]=0;
            }
        }
        else
        {
            impar[auxImpar]=valor;
            auxImpar++;
            if (auxImpar>=5)
            {
                cout << "impar[0] = "<< impar[0] << endl;
                cout << "impar[1] = "<< impar[1] << endl;
                cout << "impar[2] = "<< impar[2] << endl;
                cout << "impar[3] = "<< impar[3] << endl;
                cout << "impar[4] = "<< impar[4] << endl;
                auxImpar=0;
                impar[0]=0;
                impar[1]=0;
                impar[2]=0;
                impar[3]=0;
                impar[4]=0;
            }
        }
        count++;
    }
    while (aux<10)
    {
        if (impar[aux2]!=0)
        {
            cout << "impar[" << aux2 << "] = "<< impar[aux2] << endl;
            aux2++;
        }
        aux++;
    }
    while (aux3<10)
    {
        if (par[aux4]!=0)
        {
            cout << "par[" << aux4 << "] = "<< par[aux4] << endl;
            aux4++;
        }
        aux3++;
    }
    
    return 0;
}