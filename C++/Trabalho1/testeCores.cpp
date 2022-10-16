#include <iostream>
#include <windows.h>   // WinApi header

using namespace std;    // std::cout, std::cin

int main()
{
  HANDLE  pintarTexto;
	int k;
	
  pintarTexto = GetStdHandle(STD_OUTPUT_HANDLE);

  // you can loop k higher to see more color choices
  for(k = 1; k < 255; k++)
  {
    // pick the colorattribute k you want
    SetConsoleTextAttribute(pintarTexto, k);
    cout << k << " I want to be nice today!" << endl;
  }
  k = 2;
  SetConsoleTextAttribute(pintarTexto, k);
  cout << " fim " << endl;
  return 0;
}