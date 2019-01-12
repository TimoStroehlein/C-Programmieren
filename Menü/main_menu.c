#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liste.c"
#include "datei_schreiben.c"

void spiele_sortieren();

void main (void)
{
  int eingabe;
  while (eingabe != 0)
  {
    system("cls");

    printf("Hauptmen\201\n");
    printf("--------------------------------------\n");
    printf("[1] Spiele Anzeigen\n");
    printf("[2] Spiel Hinzuf\201gen\n");
    printf("[3] Spiel L\224schen\n");
    printf("[4] Spiele Sortieren\n");
    printf("--------------------------------------\n");
    printf("[0] Beenden\n");

    scanf("%i", &eingabe);
    fflush(stdin);

    switch (eingabe)
    {
      case 0:
        system("cls");
        printf("Programm Beendet.\n");
        break;
      case 1:
        system("cls");
        printf("Spiele\n");
        printf("--------------------------------------\n");
        liste(0);
        break;
      case 2:
        system("cls");
        printf("Spiel Hinzuf\201gen\n");
        printf("--------------------------------------\n");
        daten_lesen();
        break;
      case 3:
        system("cls");
        printf("Spiel L\224schen\n");
        printf("--------------------------------------\n");
        liste(1);
        break;
      case 4:
        system("cls");
        printf("Spiele sortieren\n");
        printf("--------------------------------------\n");
        spiele_sortieren();
        break;
      default:
        system("cls");
        printf("Zahl nicht gefunden.\n");
        printf("Programm Beendet.\n");
        break;
    }
  }
}

void spiele_sortieren (void)
{
  int eingabe;

  system("cls");

  printf("Sortieren\n");
  printf("--------------------------------------\n");
  printf("[1] Name Aufsteigend (A-Z)\n");
  printf("[2] Name Absteigend (Z-A)\n");
  printf("[3] Genre Aufsteigend (A-Z)\n");
  printf("[4] Genre Absteigend (Z-A)\n");
  printf("[5] Preis Aufsteigend\n");
  printf("[6] Preis Absteigend\n");
  printf("[7] Datum Aufsteigend\n");
  printf("[8] Datum Absteigend\n");
  printf("--------------------------------------\n");
  printf("[0] Beenden\n");

  scanf("%i", &eingabe);
  fflush(stdin);

  if (eingabe >= 2) liste(eingabe+1);
}
