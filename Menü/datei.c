#include "header.h"
//Daten aus der Standard Datei "spiele.txt" lesen und in das Struct speichern
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
      sscanf(text, "%[^,], %[^,], %i, %[^\n]", f -> name, f -> genre, &f -> preis, f -> datum);
      liste_hinzufuegen(f);
      fgets(text, 100, datei);
    }
    printf("Spiele wurden eingelesen\n");
  }
  fclose(datei);
}
//Daten vom Struct in die Standard Datei "spiele.txt" schreiben
void datei_daten_schreiben (t_feld *f)
{
  FILE *datei;
  datei = fopen("spiele.txt", "w");
  f -> mom = f -> erster;
  while (f -> mom)
  {
    fprintf(datei, "%s, %s, %i, %s\n", f -> mom -> name, f -> mom -> genre, f -> mom -> preis, f -> mom -> datum);
    f -> mom = f -> mom -> danach;
  }
  fclose(datei);
}
