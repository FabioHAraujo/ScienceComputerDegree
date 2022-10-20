#include <iostream>
#include <iomanip>
#include <math.h>
#include <windows.h>

using namespace std;

int main ()
{
    HANDLE  pintarTexto;
	    int cor=7;
    pintarTexto = GetStdHandle(STD_OUTPUT_HANDLE);

    int auxMaior=0, auxMenor=0, count=0;
    double nota=0, maiorMedia[10]{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, menorMedia[10]{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, media=0;

    while (count<10)
    {
        cin >> nota;
        media+=nota;
        if (nota>=7)
        {
            maiorMedia[auxMaior]=nota;
            auxMaior++;
        }
        else if (nota<7)
        {
            menorMedia[auxMenor]=nota;
            auxMenor++;
        }
        count++;
    }
    cout << "MEDIA DA TURMA: ";
    cor = 6;
    SetConsoleTextAttribute(pintarTexto, cor);
    cout << fixed << setprecision(2) << media/10 << endl;
    cor = 7;
    SetConsoleTextAttribute(pintarTexto, cor);
    count = 0;
    while (count<10)
    {
        if (maiorMedia[count]>=0)
        {
            cout << "Nota Acima da Media Numero " << count+1 << ": ";
            cor = 2;
            SetConsoleTextAttribute(pintarTexto, cor);
            cout << maiorMedia[count] << endl;
            cor = 7;
            SetConsoleTextAttribute(pintarTexto, cor);
        }
        count++;
    }
    count = 0;
    while (count<10)
    {
        if (menorMedia[count]>=0)
        {
            cout << "Nota Abaixo da Media Numero " << count+1 << ": ";
            cor = 4;
            SetConsoleTextAttribute(pintarTexto, cor);
            cout << menorMedia[count] << endl;
            cor = 7;
            SetConsoleTextAttribute(pintarTexto, cor);
        }
        count++;
    }


    return 0;
}