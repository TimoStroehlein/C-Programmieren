#include <stdio.h>

void main (void)
{
  FILE *einlesen;
  char text[100+1];
  einlesen = fopen("beispiel.txt", "r");  //Namen //Mode zb. r = reading w = writing a = writing operations
  if (!einlesen)  //entspricht einlesen == 0
  {
    printf("Kann nicht gelesen werden.");
  }
  else
  {
    fgets(text, 80, einlesen);  //vorlesen
    while (!feof(einlesen))
    {
      printf("\n%s", text);  //verarbeiten
      fgets(text, 80, einlesen);  //nachlesen
    }
    fclose(einlesen);
  }
}
