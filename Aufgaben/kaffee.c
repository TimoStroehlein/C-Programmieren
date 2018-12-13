#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main (void)
{
  char namen[2][20+1];
  int zufallsZahl, untergrenze = 1, obergrenze = 1000, zuege = 0, eingabe = 0, gewinner, verlierer, zufallsInit;

  printf("Gib den ersten Namen ein: ");
  scanf("%s", namen[0]);
  fflush(stdin);
  printf("Gib den zweiten Namen ein: ");
  scanf("%s", namen[1]);
  fflush(stdin);

  printf("Gib eine beliebige Zahl ein: ");
  scanf("%d", &zufallsInit);
  fflush(stdin);
  srand(zufallsInit);
  zufallsZahl = rand() % 1000 + 1;

  while (eingabe != zufallsZahl)
  {
    printf("%s: Gib eine Zahl zwischen %d und %d ein: ", namen[0], untergrenze, obergrenze);
    scanf("%d", &eingabe);
    fflush(stdin);

    if (eingabe > zufallsZahl) obergrenze = eingabe;
    else if (eingabe < zufallsZahl) untergrenze = eingabe;
    else { gewinner = namen[0]; verlierer = namen[1]; break; }

    zuege++;

    printf("%s: Gib eine Zahl zwischen %d und %d ein: ", namen[1], untergrenze, obergrenze);
    scanf("%d", &eingabe);
    fflush(stdin);

    if (eingabe > zufallsZahl) obergrenze = eingabe;
    else if (eingabe < zufallsZahl) untergrenze = eingabe;
    else { gewinner = namen[1]; verlierer = namen[0]; break; }

    zuege++;
  }
  printf("%s hat gewonnen\n", gewinner);
  printf("%s bezahlt den Kaffee\n", verlierer);
  printf("Es wurden %d Zuege benoetigt\n", zuege);

  return 42;
}
