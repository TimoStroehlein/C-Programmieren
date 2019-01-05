#include<stdio.h>
#include<string.h>

struct
{
  int i;
  float f;
  unsigned char c[4];
}zahl;

void main (void)
{
  char htext[80+1];
  float zahl.f;

  printf("Eingabe der Gleitkommazahl: ");
  scanf("%f", &zahl.f);
  fflush(stdin);
  printf("Eingegebene Zahl: %f\n", zahl.f);

  itoa(zahl.c[1],htext , 2)
}
