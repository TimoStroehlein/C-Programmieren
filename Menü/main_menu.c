#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spiel_hinzufuegen.c"

void main (void)
{
  int eingabe;
  while (eingabe != 0)
  {
    system("cls");

    printf("Hauptmen\201\n");
    printf("--------------------------------------\n");
    printf("[1] Spiele Anzeigen\n");
    printf("[2] Spiele Hinzuf\201gen\n");
    printf("[3] Funktion 3\n");
    printf("[4] Funktion 4\n");
    printf("[5] Funktion 5\n");
    printf("--------------------------------------\n");
    printf("[0] Beenden\n");

    scanf("%i", &eingabe);
    fflush(stdin);

    switch (eingabe)
    {
      case 1:
        system("cls");
        printf("Funktion 1 wurde ausgef\201hrt\n");
        liste_lesen();
        break;
      case 2:
        system("cls");
        printf("Funktion 2 wurde ausgef\201hrt\n");
        break;
      case 3:
        system("cls");
        printf("Funktion 3 wurde ausgef\201hrt\n");
        break;
      case 4:
        system("cls");
        printf("Funktion 4 wurde ausgef\201hrt\n");
        break;
      case 5:
        system("cls");
        printf("Funktion 5 wurde ausgef\201hrt\n");
        break;
      case 0:
        system("cls");
        printf("Programm Beendet.\n");
        break;
      default:
        system("cls");
        printf("Zahl nicht gefunden.\n");
        printf("Programm Beendet.\n");
        break;
    }
  }
}
