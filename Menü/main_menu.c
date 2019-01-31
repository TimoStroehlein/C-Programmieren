#include "liste.c"
#include "sortieren.c"
#include "datei.c"
#include "einlesen.c"
#include "header.h"

void main (void)
{
  t_feld feld;
  t_feld *f = &feld;
  f -> mom = 0;
  f -> erster = 0;
  f -> letzter = 0;
  anzahl_spiele = 0;

  int eingabe;

  while (eingabe != 0)
  {
    system("cls");

    printf("Spielebibliothek\n");
    printf("--------------------------------------\n");
    printf("[1] Spiele aus Datei einlesen\n");
    printf("[2] Spiel aus Eingabe hinzuf\201gen\n");
    printf("[3] Spiele sortieren\n");
    printf("[4] Spiele anzeigen\n");
    printf("[5] Spiele l\224schen\n");
    printf("[6] Spiele speichern\n");
    printf("[7] Zeiger anzeigen\n");
    printf("--------------------------------------\n");
    printf("[0] Programm beenden\n");

    scanf("%i", &eingabe);
    fflush(stdin);

    switch (eingabe)
    {
      case 0:
        system("cls");
        printf("Programm beendet.\n");
        break;
      //Spiele aus Datei einlesen
      case 1:
        system("cls");
        main_spiele_einlesen(f);
        printf("--------------------------------------\n");
        printf("Enter zum Verlassen...\n");
        getchar();
        break;
      //Spiele aus eingabe hinzufügen
      case 2:
        system("cls");
        printf("Spiel hinzuf\201gen\n");
        printf("--------------------------------------\n");
        daten_einlesen_eingabe(f);
        break;
      //Spiele sortieren
      case 3:
        system("cls");
        main_spiele_sortieren(f);
        getchar();
        break;
      //Spiele anzeigen
      case 4:
        system("cls");
        printf("Spiele\n");
        printf("--------------------------------------\n");
        liste_anzeigen(f);
        printf("--------------------------------------\n");
        printf("Enter zum Verlassen...\n");
        getchar();
        break;
      //Spiele löschen
      case 5:
        system("cls");
        printf("Spiele l\224schen\n");
        printf("--------------------------------------\n");
        liste_anzeigen(f);
        liste_loeschen(f);
        liste_anzeigen(f);
        printf("--------------------------------------\n");
        printf("Enter zum Verlassen...\n");
        getchar();
        break;
      //Spiele speichern
      case 6:
        system("cls");
        printf("Spiele speichern\n");
        printf("--------------------------------------\n");
        datei_daten_schreiben(f);
        printf("--------------------------------------\n");
        printf("Enter zum Verlassen...\n");
        getchar();
        break;
      //Zeiger anzeigen
      case 7:
        system("cls");
        printf("Zeiger\n");
        printf("--------------------------------------\n");
        hex(f);
        printf("--------------------------------------\n");
        printf("Enter zum Verlassen...\n");
        getchar();
        break;
      default:
        system("cls");
        printf("Zahl nicht gefunden.\n");
        printf("Programm beendet.\n");
        break;
    }
  }
}

void main_spiele_einlesen (t_feld *f)
{
  int eingabe;

  system("cls");

  printf("Einlesen\n");
  printf("--------------------------------------\n");
  printf("[1] Standard Datei\n");
  printf("[2] Eigene Datei\n");
  printf("--------------------------------------\n");
  printf("[0] Zur\201ck\n");

  scanf("%i", &eingabe);
  fflush(stdin);

  switch (eingabe)
  {
    case 0:
      break;
    case 1:
      system("cls");
      datei_daten_lesen(f);
      break;
    case 2:
      system("cls");
      daten_einlesen_datei(f);
      datei_daten_lesen(f);
      break;
    default:
      break;
  }
}

void main_spiele_sortieren (t_feld *f)
{
  int eingabe;

  system("cls");

  printf("Sortieren\n");
  printf("--------------------------------------\n");
  printf("[1] Bubblesort\n");
  printf("[2] Quicksort\n");
  printf("--------------------------------------\n");
  printf("[0] Zur\201ck\n");

  scanf("%i", &eingabe);
  fflush(stdin);

  switch (eingabe)
  {
    case 0:
      break;
    case 1:
      main_spiele_sortieren_bubblesort(f);
      break;
    case 2:
      main_spiele_sortieren_quicksort(f);
      break;
    default:
      break;
  }
}

void main_spiele_sortieren_bubblesort (t_feld *f)
{
  int eingabe;

  system("cls");

  printf("Bubblesort\n");
  printf("--------------------------------------\n");
  printf("[1] Name Aufsteigend (A-Z)\n");
  printf("[2] Name Absteigend (Z-A)\n");
  printf("[3] Genre Aufsteigend (A-Z)\n");
  printf("[4] Genre Absteigend (Z-A)\n");
  printf("[5] Preis Aufsteigend\n");
  printf("[6] Preis Absteigend\n");
  printf("--------------------------------------\n");
  printf("[0] Zur\201ck\n");

  scanf("%i", &eingabe);
  fflush(stdin);
  system("cls");

  switch (eingabe)
  {
    case 0:
      break;
    case 1:
      liste_anzeigen(f);
      liste_bubblesort(f, eingabe);
      liste_anzeigen(f);
      break;
    case 2:
      liste_bubblesort(f, eingabe);
      break;
    case 3:
      liste_bubblesort(f, eingabe);
      break;
    case 4:
      liste_bubblesort(f, eingabe);
      break;
    case 5:
      liste_bubblesort(f, eingabe);
      break;
    case 6:
      liste_bubblesort(f, eingabe);
      break;
    default:
      break;
  }
}

void main_spiele_sortieren_quicksort (t_feld *f)
{
  int eingabe;

  system("cls");

  printf("Quicksort\n");
  printf("--------------------------------------\n");
  printf("[1] Name Aufsteigend (A-Z)\n");
  printf("[2] Name Absteigend (Z-A)\n");
  printf("[3] Genre Aufsteigend (A-Z)\n");
  printf("[4] Genre Absteigend (Z-A)\n");
  printf("[5] Preis Aufsteigend\n");
  printf("[6] Preis Absteigend\n");
  printf("--------------------------------------\n");
  printf("[0] Zur\201ck\n");

  scanf("%i", &eingabe);
  fflush(stdin);

  switch (eingabe)
  {
    case 0:
      break;
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
    default:
      break;
  }
}
