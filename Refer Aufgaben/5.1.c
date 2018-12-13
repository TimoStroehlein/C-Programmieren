#include<stdio.h>
#include<string.h>
/*
Erstellen Sie eine Funktion, die in eine Zahl Tausenderpunkte einfügt. (Beispiel: 1083456 -> 1.083.456)
Prototyp:
int separateThousands(char *string, int zahl);
Rückgabewert: Anzahl der eingefügten Punkte
*/
void main (void)
{
  int zahl;

  printf("Geben sie eine Zahl ein: ");
  scanf("%d\n", zahl);
  fflush(stdin);
  separateThousands(zahl)
}

int separateThousands(int zahl);
{
  
}
