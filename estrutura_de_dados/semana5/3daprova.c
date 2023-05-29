#include <stdio.h>

int main() {
  int valor = 7, *p, *q;
  p = &valor;
  q = p;
  //tete abaixo
  printf("%p\n", p);
  printf("%p\n", p+1);
  printf("%d\n", *p);
  printf("%d\n", (*p+1));
  printf("%d\n", *q+1); //Só errei essa porque sou um animal, estuda fdp
  printf("%d\n", (*p)%(*q));
  
  return 0;
}
