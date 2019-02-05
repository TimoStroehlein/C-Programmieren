#include "header.h"
//Gespeichertes Spiel dem Struct hinzufügen
void liste_hinzufuegen (t_feld *f)
{
  f -> mom = (t_spiel*)malloc(sizeof(t_spiel));  //Reserviert Größe des structs im Hauptspeicher, Typecast nötig, da return value von malloc Void-Zeiger ist
  liste_hinzufuegen_daten(f);  //Kopiert eingelesenes in die Liste

  f -> mom -> davor = f -> letzter;
  f -> mom -> danach = 0;

  if (f -> letzter == 0) f -> erster = f -> mom;
  else f -> letzter -> danach = f-> mom;

  f -> letzter = f -> mom;
  anzahl_spiele++;
}
//Daten in das Struct speichern
void liste_hinzufuegen_daten (t_feld *f)
{
  strcpy(f -> mom -> name, f -> name);
  strcpy(f -> mom -> genre, f -> genre);
  f -> mom -> preis = f -> preis;
  strcpy(f -> mom -> datum, f -> datum);
}
//Spiel aus dem Struct kopieren und danach bearbeiten
void liste_kopieren (t_feld *f)
{
  int i = 1, index;
  printf("--------------------------------------\n");
  printf("Spiel kopieren: \n");
  scanf("%i", &index);
  f -> mom = f -> erster;
  while (f -> mom && i < index)
  {
    f -> mom = f -> mom -> danach;
    i++;
  }
  strcpy(f -> name, f -> mom -> name);
  strcpy(f -> genre, f -> mom -> genre);
  f -> preis = f -> mom -> preis;
  strcpy(f -> datum, f -> mom -> datum);

  int eingabe;
  while (eingabe != 0)
  {
    printf("--------------------------------------\n");
    printf("[1] Name : %s\n", f -> name);
    printf("[2] Genre: %s\n", f -> genre);
    printf("[3] Preis: %i\n", f -> preis);
    printf("[4] Datum: %s\n", f -> datum);
    printf("--------------------------------------\n");
    printf("Datensatz editieren (0 um zu beenden): ");
    scanf("%i", &eingabe);

    switch (eingabe)
    {
      case 0:
        break;
      case 1:
        printf("Neuer Name: ");
        scanf("%s", f -> name);
        break;
      case 2:
        printf("Neues Genre: ");
        scanf("%s", f -> genre);
        break;
      case 3:
        printf("Neuer Preis: ");
        scanf("%i", &f -> preis);
        break;
      case 4:
        printf("Neues Datum: ");
        scanf("%s", f -> datum);
        break;
      default:
        break;
    }
  }
  liste_hinzufuegen(f);
}
//Spiele anzeigen
void liste_anzeigen (t_feld *f, bool anzeigen_anzahl)
{
  int anzahl;
  if (anzeigen_anzahl)
  {
    printf("Anzahl an Spielen (0 um alle Spiele anzuzeigen): ");
    scanf("%i", &anzahl);
    fflush(stdin);
  }
  else if (!anzeigen_anzahl)
  {
    anzahl = 0;
  }
  printf("   |--------------Name--------------|--------------Genre-------------|--Preis--|---------Datum--------|\n");
  f -> mom = f -> erster;
  int i = 0;
  if (anzahl == 0) anzahl = anzahl_spiele;
  while (f -> mom && i < anzahl)
  {
    printf("%-2i | %-30s | %-30s | %-7i | %-20s |\n",i+1 , f -> mom -> name, f -> mom -> genre, f -> mom -> preis, f -> mom -> datum);
    f -> mom = f -> mom -> danach;
    i++;
  }
}
//Spiele löschen
void liste_loeschen (t_feld *f, bool mehrere_loeschen)
{
  int i, k, anfang, ende, anzahl;
  //Bereich an Spielen löschen
  if (mehrere_loeschen)
  {
    printf("--------------------------------------\n");
    printf("L\224schen von Spiel: ");
    scanf("%i", &anfang);
    fflush(stdin);
    printf("bis Spiel: ");
    scanf("%i", &ende);
    fflush(stdin);
    anzahl = ende - anfang + 1;
  }
  //Einzelnes Spiel löschen
  else if (!mehrere_loeschen)
  {
    printf("--------------------------------------\n");
    printf("Datensatz: ");
    scanf("%i", &ende);
    fflush(stdin);
    anzahl = 1;
  }

  f -> mom = f -> erster;
  for (k = 0; k < anzahl; k++)
  {
    i = 1;
    while (f -> mom && i < ende - k)
    {
      f -> mom = f -> mom -> danach;
      i++;
    }
    if (f -> mom == 0)
    {
      //Kein Satz
      printf("Nicht zugelassener Wert");
    }
    else if (f -> mom -> danach && f -> mom -> davor)
    {
      //Aus Mitte
      f -> mom -> davor -> danach = f -> mom -> danach;
      f -> mom -> danach -> davor = f -> mom -> davor;
      free(f -> mom);
      f -> mom = f -> erster;
      anzahl_spiele--;
    }
    else if (f -> mom -> davor)
    {
      //Der Letzte
      f -> mom -> davor -> danach = 0;
      f -> letzter = f -> mom -> davor;
      free(f -> mom);
      f -> mom = f -> erster;
      anzahl_spiele--;
    }
    else if (f -> mom -> danach)
    {
      //Der Erste
      f -> mom -> danach -> davor = 0;
      f -> erster = f -> mom -> danach;
      free(f -> mom);
      f -> mom = f -> erster;
      anzahl_spiele--;
    }
    else
    {
      //Der Einzige
      free(f -> mom);
      anzahl_spiele--;
    }
  }
}
//Alle Spiele aus dem Struct löschen
void liste_leeren (t_feld *f)
{
  memset(f, 0, anzahl_spiele);
  f -> mom = 0;
  f -> erster = 0;
  f -> letzter = 0;
  anzahl_spiele = 0;
}

void hex (t_feld *f)
{
  f -> mom = f -> erster;
  printf("%-30s %-30s %-5s %-20s %-7s %-7s %-7s", "Name", "Genre", "Preis", "Datum", "mom", "davor", "danach\n");
  while (f -> mom)
  {
    printf("%-30s %-30s %-5i %-20s %-7x %-7x %-7x\n",
      f -> mom -> name,
      f -> mom -> genre,
      f -> mom -> preis,
      f -> mom -> datum,
      f -> mom,
      f -> mom -> davor,
      f -> mom -> danach);

    f -> mom = f -> mom -> danach;
  }
  printf("erster : %-7x\n", f -> erster);
  printf("letzter: %-7x\n", f -> letzter);
}
