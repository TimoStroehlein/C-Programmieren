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
          printf("Eingabe nicht bekannt.\n");
          break;
      }
      f -> mom = f -> mom -> danach;
    }
    f -> mom = f -> erster;
  }
}

void liste_quicksort (t_feld *f, int links, int rechts, int eingabe)
{
  int ili = links, ire = rechts, imed = (links + rechts) / 2, i = 0;

  while (ili < ire)
  {
    //Aufsteigend sortieren
    if (eingabe == 1 || eingabe == 3)
    {
      while (strcmp(liste_feld_char(f, ili, eingabe), liste_feld_char(f, imed, eingabe)) < 0) ili++;
      while (strcmp(liste_feld_char(f, ire, eingabe), liste_feld_char(f, imed, eingabe)) > 0) ire--;
    }
    else if (eingabe == 5)
    {
      while (liste_feld_int(f, ili, eingabe) < liste_feld_int(f, imed, eingabe)) ili++;
      while (liste_feld_int(f, ire, eingabe) > liste_feld_int(f, imed, eingabe)) ire--;
    }
    //Absteigend sortieren
    if (eingabe == 2 || eingabe == 4)
    {
      while (strcmp(liste_feld_char(f, ili, eingabe), liste_feld_char(f, imed, eingabe)) > 0) ili++;
      while (strcmp(liste_feld_char(f, ire, eingabe), liste_feld_char(f, imed, eingabe)) < 0) ire--;
    }
    else if (eingabe == 6)
    {
      while (liste_feld_int(f, ili, eingabe) > liste_feld_int(f, imed, eingabe)) ili++;
      while (liste_feld_int(f, ire, eingabe) < liste_feld_int(f, imed, eingabe)) ire--;
    }
    //Felder tauschen anhand vom Index
    liste_felder_tauschen_index(f, ili, ire);
    if (ili == imed) imed = ire;
    else if (ire == imed) imed = ili;
    if (ili < imed) ili++;
    if (ire > imed) ire--;
  }
  if (links < imed - 1) liste_quicksort(f, links, imed -1, eingabe);
  if (rechts > imed + 1) liste_quicksort(f, imed + 1, rechts, eingabe);
}
//Inhalt eines Feldes anhand einem Index bekommen
char* liste_feld_char (t_feld *f, int index, int eingabe)
{
  int i = 1;
  f -> mom = f -> erster;
  while (f -> mom && i < index)
  {
    f -> mom = f -> mom -> danach;
    i++;
  }
  switch (eingabe)
  {
    case 1:
      return f -> mom -> name;
      break;
    case 2:
      return f -> mom -> name;
      break;
    case 3:
      return f -> mom -> genre;
      break;
    case 4:
      return f -> mom -> genre;
      break;
    default:
      return 0;
      break;
  }
}
//Inhalt eines Feldes anhand einem Index bekommen
int liste_feld_int (t_feld *f, int index, int eingabe)
{
  int i = 1;
  f -> mom = f -> erster;
  while (f -> mom && i < index)
  {
    f -> mom = f -> mom -> danach;
    i++;
  }
  switch (eingabe)
  {
    case 5:
      return f -> mom -> preis;
      break;
    case 6:
      return f -> mom -> preis;
      break;
    default:
      return 0;
      break;
  }
}
//Feld mit dem Feld danach tauschen
void liste_feld_tauschen (t_feld *f)
{
  char temp[30];
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

  strcpy(temp, f -> mom -> datum);
  strcpy(f -> mom -> datum, f -> mom -> danach -> datum);
  strcpy(f -> mom -> danach -> datum, temp);
}
//Zwei bestimmte Felder anhand vom Index tauschen
void liste_felder_tauschen_index (t_feld *f, int ili, int ire)
{
  char name[30], name2[30], genre[30], genre2[30], datum[20], datum2[20];
  int preis, preis2, i;
  //Daten vom linken Feld zwischenspeichern
  i = 1;
  f -> mom = f -> erster;
  while (f -> mom && i++ < ili) f -> mom = f -> mom -> danach;
  strcpy(name, f -> mom -> name);
  strcpy(genre, f -> mom -> genre);
  preis = f -> mom -> preis;
  strcpy(datum, f -> mom -> datum);
  //Daten vom rechten Feld zwischenspeichern
  i = 1;
  f -> mom = f -> erster;
  while (f -> mom && i++ < ire) f -> mom = f -> mom -> danach;
  strcpy(name2, f -> mom -> name);
  strcpy(genre2, f -> mom -> genre);
  preis2 = f -> mom -> preis;
  strcpy(datum2, f -> mom -> datum);
  //Daten vom rechten in das linke Feld speichern
  i = 1;
  f -> mom = f -> erster;
  while (f -> mom && i++ < ili) f -> mom = f -> mom -> danach;
  strcpy(f -> mom -> name, name2);
  strcpy(f -> mom -> genre, genre2);
  f -> mom -> preis = preis2;
  strcpy(f -> mom -> datum, datum2);
  i = 1;
  //Daten vom linken in das rechte Feld speichern
  f -> mom = f -> erster;
  while (f -> mom && i++ < ire) f -> mom = f -> mom -> danach;
  strcpy(f -> mom -> name, name);
  strcpy(f -> mom -> genre, genre);
  f -> mom -> preis = preis;
  strcpy(f -> mom -> datum, datum);
}
