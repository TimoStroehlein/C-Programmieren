#include "header.h"

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

void liste_hinzufuegen_daten (t_feld *f)
{
  strcpy(f -> mom -> name, f -> name);
  strcpy(f -> mom -> genre, f -> genre);
  f -> mom -> preis = f -> preis;
  strcpy(f -> mom -> datum, f -> datum);
}

void liste_anzeigen (t_feld *f)
{
  int anzahl;
  printf("Anzahl an Datens\204tzen: ");
  scanf("%i", &anzahl);
  fflush(stdin);
  printf("   |--------------Name--------------|--------------Genre-------------|--Preis--|---------Datum--------|\n");
  f -> mom = f -> erster;
  int i = 1;
  while (f -> mom != NULL && i < anzahl+1)
  {
    printf("%-2i | %-30s | %-30s | %-7i | %-20s |\n",i , f -> mom -> name, f -> mom -> genre, f -> mom -> preis, f -> mom -> datum);
    f -> mom = f -> mom -> danach;
    i++;
  }
}

void liste_loeschen (t_feld *f)
{
  int i, k, anfang, ende, anzahl;
  printf("--------------------------------------\n");
  printf("L\224schen von Datensatz: ");
  scanf("%i", &anfang);
  fflush(stdin);
  printf("bis Datensatz: ");
  scanf("%i", &ende);
  fflush(stdin);
  anzahl = ende - anfang;

  f -> mom = f -> erster;
  for (k = 0; k < anzahl + 1; k++)
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
      printf("Nicht zugelassener Wert.");
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
      free(f -> mom);
      anzahl_spiele--;
    }
  }
}

void hex (t_feld *f)
{
  f -> mom = f -> erster;
  printf("%-10s %-10s %-5s %-10s %-7s %-7s %-7s", "Name", "Genre", "Preis", "Datum", "mom", "davor", "danach");
  while (f -> mom)
  {
    printf("\n%-10s %-10s %-5i %-10s %-7x %-7x %-7x",
      f -> mom -> name,
      f -> mom -> genre,
      f -> mom -> preis,
      f -> mom -> datum,
      f -> mom,
      f -> mom -> davor,
      f -> mom -> danach);

    f -> mom = f -> mom -> danach;
  }
  printf("\nerster : %-7x", f -> erster);
  printf("\nletzter: %-7x", f -> letzter);
}
