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
    printf("[3] Spiel kopieren\n");
    printf("[4] Spiele sortieren\n");
    printf("[5] Spiele anzeigen\n");
    printf("[6] Spiele l\224schen\n");
    printf("[7] Spiele speichern\n");
    printf("[8] Zeiger anzeigen\n");
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
      //Spiel kopieren
      case 3:
        system("cls");
        printf("Spiel kopieren\n");
        printf("--------------------------------------\n");
        liste_anzeigen(f, false);
        liste_kopieren(f);
        liste_anzeigen(f, false);
        printf("--------------------------------------\n");
        printf("Enter zum Verlassen...\n");
        getchar();
        break;
      //Spiele sortieren
      case 4:
        system("cls");
        main_spiele_sortieren(f);
        getchar();
        break;
      //Spiele anzeigen
      case 5:
        system("cls");
        printf("Spiele\n");
        printf("--------------------------------------\n");
        liste_anzeigen(f, true);
        printf("--------------------------------------\n");
        printf("Enter zum Verlassen...\n");
        getchar();
        break;
      //Spiele löschen
      case 6:
        system("cls");
        printf("Spiele l\224schen\n");
        printf("--------------------------------------\n");
        main_spiele_loeschen(f);
        printf("--------------------------------------\n");
        printf("Enter zum Verlassen...\n");
        getchar();
        break;
      //Spiele speichern
      case 7:
        system("cls");
        datei_daten_schreiben(f);
        printf("Die Spiele wurden gespeichert\n");
        printf("--------------------------------------\n");
        printf("Enter zum Verlassen...\n");
        getchar();
        break;
      //Zeiger anzeigen
      case 8:
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
      printf("Einlesen\n");
      printf("--------------------------------------\n");
      liste_leeren(f);
      datei_daten_lesen(f);
      break;
    case 2:
      system("cls");
      printf("Einlesen\n");
      printf("--------------------------------------\n");
      liste_leeren(f);
      daten_einlesen_datei(f);
      datei_daten_lesen(f);
      break;
    default:
      break;
  }
}

void main_spiele_loeschen (t_feld *f)
{
  int eingabe;

  system("cls");

  printf("L\224schen\n");
  printf("--------------------------------------\n");
  printf("[1] Ein Eintrag l\224schen\n");
  printf("[2] Mehrere Eintr\204ge l\224schen\n");
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
      printf("L\224schen\n");
      printf("--------------------------------------\n");
      liste_anzeigen(f, false);
      liste_loeschen(f, false);
      break;
    case 2:
      printf("L\224schen\n");
      printf("--------------------------------------\n");
      liste_anzeigen(f, false);
      liste_loeschen(f, true);
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
      printf("Bubblesort\n");
      printf("--------------------------------------\n");
      liste_bubblesort(f, eingabe);
      liste_anzeigen(f, false);
      printf("--------------------------------------\n");
      printf("Enter zum Verlassen...\n");
      break;
    case 2:
      printf("Bubblesort\n");
      printf("--------------------------------------\n");
      liste_bubblesort(f, eingabe);
      liste_anzeigen(f, false);
      printf("--------------------------------------\n");
      printf("Enter zum Verlassen...\n");
      break;
    case 3:
      printf("Bubblesort\n");
      printf("--------------------------------------\n");
      liste_bubblesort(f, eingabe);
      liste_anzeigen(f, false);
      printf("--------------------------------------\n");
      printf("Enter zum Verlassen...\n");
      break;
    case 4:
      printf("Bubblesort\n");
      printf("--------------------------------------\n");
      liste_bubblesort(f, eingabe);
      liste_anzeigen(f, false);
      printf("--------------------------------------\n");
      printf("Enter zum Verlassen...\n");
      break;
    case 5:
      printf("Bubblesort\n");
      printf("--------------------------------------\n");
      liste_bubblesort(f, eingabe);
      liste_anzeigen(f, false);
      printf("--------------------------------------\n");
      printf("Enter zum Verlassen...\n");
      break;
    case 6:
      printf("Bubblesort\n");
      printf("--------------------------------------\n");
      liste_bubblesort(f, eingabe);
      liste_anzeigen(f, false);
      printf("--------------------------------------\n");
      printf("Enter zum Verlassen...\n");
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
  system("cls");

  switch (eingabe)
  {
    case 0:
      break;
    case 1:
      printf("Quicksort\n");
      printf("--------------------------------------\n");
      liste_quicksort(f, 1, anzahl_spiele, eingabe);
      liste_anzeigen(f, false);
      printf("--------------------------------------\n");
      printf("Enter zum Verlassen...\n");
      break;
    case 2:
      printf("Quicksort\n");
      printf("--------------------------------------\n");
      liste_quicksort(f, 1, anzahl_spiele, eingabe);
      liste_anzeigen(f, false);
      printf("--------------------------------------\n");
      printf("Enter zum Verlassen...\n");
      break;
    case 3:
      printf("Quicksort\n");
      printf("--------------------------------------\n");
      liste_quicksort(f, 1, anzahl_spiele, eingabe);
      liste_anzeigen(f, false);
      printf("--------------------------------------\n");
      printf("Enter zum Verlassen...\n");
      break;
    case 4:
      printf("Quicksort\n");
      printf("--------------------------------------\n");
      liste_quicksort(f, 1, anzahl_spiele, eingabe);
      liste_anzeigen(f, false);
      printf("--------------------------------------\n");
      printf("Enter zum Verlassen...\n");
      break;
    case 5:
      printf("Quicksort\n");
      printf("--------------------------------------\n");
      liste_quicksort(f, 1, anzahl_spiele, eingabe);
      liste_anzeigen(f, false);
      printf("--------------------------------------\n");
      printf("Enter zum Verlassen...\n");
      break;
    case 6:
      printf("Quicksort\n");
      printf("--------------------------------------\n");
      liste_quicksort(f, 1, anzahl_spiele, eingabe);
      liste_anzeigen(f, false);
      printf("--------------------------------------\n");
      printf("Enter zum Verlassen...\n");
      break;
    default:
      break;
  }
}
