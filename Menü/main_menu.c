#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void spieleAnzeigen();
void spielHinzufuegen();

struct m_spiel
{
  char name[30+1];
  char genre[30+1];
  int preis;
  char veroeffentlichung[10+1];
};

void main ()
{
  int eingabe;

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
    case 0:
      printf("Beendet\n");
      break;
    case 1:
      printf("Funktion 1 wurde ausgef\201hrt\n");
      break;
    case 2:
      printf("Funktion 2 wurde ausgef\201hrt\n");
      spielHinzufuegen();
      break;
    case 3:
      printf("Funktion 3 wurde ausgef\201hrt\n");
      break;
    case 4:
      printf("Funktion 4 wurde ausgef\201hrt\n");
      break;
    case 5:
      printf("Funktion 5 wurde ausgef\201hrt\n");
      break;
    default:
      printf("Zahl nicht gefunden.\n");
      break;
  }
}

void spieleAnzeigen ()
{

}

void spielHinzufuegen ()
{
  char cname[30+1];
  char cgenre[30+1];
  int cpreis;
  char cveroeffentlichung[10+1];

  printf("Name: ");
  scanf("%s", cname);
  fflush(stdin);
  printf("Genre: ");
  scanf("%s", cgenre);
  fflush(stdin);
  printf("Preis: ");
  scanf("%i", &cpreis);
  fflush(stdin);
  printf("Ver\201ffentlichung: ");
  scanf("%s", cveroeffentlichung);
  fflush(stdin);

}

void hauptmenue ()
{

}
