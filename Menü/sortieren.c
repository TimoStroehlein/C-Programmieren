#include "header.h"

void liste_bubblesort (t_feld *f, int eingabe)
{
  f -> mom = f -> erster;
  for (int i = 0; i < anzahl_spiele-1; i++)
  {
    for (int j = 0; j < anzahl_spiele-1; j++)
    {
      switch (eingabe)
      {
        //Name
        case 1:
          if (strcmp(f -> mom -> name, f -> mom -> danach -> name) > 0) liste_feld_tauschen(f); //Aufsteigend sortieren (A-Z)
          break;
        case 2:
          if (strcmp(f -> mom -> name, f -> mom -> danach -> name) < 0) liste_feld_tauschen(f); //Absteigend sortieren (Z-A)
          break;
        //Genre
        case 3:
          if (strcmp(f -> mom -> genre, f -> mom -> danach -> genre) > 0) liste_feld_tauschen(f); //Aufsteigend sortieren (A-Z)
          break;
        case 4:
          if (strcmp(f -> mom -> genre, f -> mom -> danach -> genre) < 0) liste_feld_tauschen(f); //Absteigend sortieren (Z-A)
          break;
        //Preis
        case 5:
          if (f -> mom -> preis > f -> mom -> danach -> preis) liste_feld_tauschen(f); //Aufsteigend sortieren
          break;
        case 6:
          if (f -> mom -> preis < f -> mom -> danach -> preis) liste_feld_tauschen(f); //Absteigend sortieren
          break;
        default:
          printf("Modus nicht bekannt.\n");
          break;
      }
      f -> mom = f -> mom -> danach;
    }
    f -> mom = f -> erster;
  }
}

void liste_quicksort (t_feld *f, int eingabe)
{
/*
  t_feld *ili, *ire, *med;
  t_feld *links = f -> erster;
  t_feld *rechts = f -> letzter;
  ili = links, ire = rechts;
  med = (links + rechts) / 2;

  while (ili < ire)
  {
    while (f[ili] < f[med])
    {
      ili++;
    }
    while (f[ire] > f[med])
    {
      ire--;
    }
    tausche f[ili], f[ire];
    if (ili == med)
    {
      med = ire;
    }
    else if (ire == med)
    {
      med = ili;
    }
    if (ili < med)
    {
      ili++;
    }
    if (ire > med)
    {
      ire--;
    }
  }
  if (links < med-1)
  {
    liste_quicksort(*f, links, med-1);
  }
  if (rechts > med+1)
  {
    liste_quicksort(*f, med+1, rechts);
  }
  */
}

void liste_feld_tauschen (t_feld *f)
{
  char temp[30+1];
  int temp2;

  strcpy(temp, f -> mom -> name);
  strcpy(f -> mom -> name, f -> mom -> danach -> name);
  strcpy(f -> mom -> danach -> name, temp);

  strcpy(temp, f -> mom -> genre);
  strcpy(f -> mom -> genre, f -> mom -> danach -> genre);
  strcpy(f -> mom -> danach -> genre, temp);

  temp2 = f -> mom -> preis;
  f -> mom -> preis = f -> mom -> danach -> preis;
  f -> mom -> danach -> preis = temp2;
}
