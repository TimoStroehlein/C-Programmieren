#include "header.h"
/*
void datei_daten_schreiben_einzeln (t_feld *f)
{
  FILE *datei;
  datei = fopen("spiele.txt", "a+");
  fprintf(datei, "%s %s %i %s\n", f -> name, f -> genre, f -> preis, f -> datum);
  fclose(datei);
}
*/
void datei_daten_lesen (t_feld *f)
{
  FILE *datei;
  char text[100];
  anzahl_spiele = 0;
  if (!datei) printf("Datei ist leer");
  else
  {
    datei = fopen("spiele.txt", "r");

    fgets(text, 100, datei);
    while (!feof(datei))
    {
      sscanf(text, "%s %s %i %s", f -> name, f -> genre, &f -> preis, f -> datum);
      liste_hinzufuegen(f);
      fgets(text, 100, datei);
    }
  }
  fclose(datei);
  printf("Daten wurde eingelesen\n");
}

void datei_daten_schreiben (t_feld *f)
{
  FILE *datei;
  int i = 0;
  datei = fopen("spiele.txt", "w");
  f -> mom = f -> erster;
  while (f -> mom && i++ < anzahl_spiele)
  {
    fprintf(datei, "%s %s %i %s\n", f -> mom -> name, f -> mom -> genre, f -> mom -> preis, f -> mom -> datum);
    f -> mom = f -> mom -> danach;
  }
  fclose(datei);
}
