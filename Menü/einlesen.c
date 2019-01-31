#include "header.h"

void daten_einlesen_eingabe (t_feld *f)
{
  printf("Name: ");
  scanf("%[^\n]s", f -> name);
  fflush(stdin);

  printf("Genre: ");
  scanf("%[^\n]s", f -> genre);
  fflush(stdin);

  printf("Preis: ");
  scanf("%i", &f -> preis);
  fflush(stdin);

  printf("Datum: ");
  scanf("%[^\n]s", f -> datum);
  fflush(stdin);

  liste_hinzufuegen(f);
}

void daten_einlesen_datei (t_feld *f)
{
  char dateiname[20], c;
  printf("Dateinamen eingeben: ");
  scanf("%s", dateiname);
  fflush(stdin);

  FILE *datei_1, *datei_2;
  datei_1 = fopen(dateiname, "r");
  datei_2 = fopen("spiele.txt", "w");

  if (!datei_1) printf("Datei ist leer");
  else
  {
    c = fgetc(datei_1);
    while (!feof(datei_1))
    {
        fputc(c, datei_2);
        c = fgetc(datei_1);
    }
  }
  fclose(datei_1);
  fclose(datei_2);
}
