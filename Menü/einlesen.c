#include "header.h"
//Eingegebene Daten einlesen und in das Struct speichern
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
//Daten aus externer Datei in die Standard Datei "spiele.txt" kopieren
void daten_einlesen_datei (t_feld *f)
{
  char dateiname[20], c;
  printf("Dateinamen eingeben: ");
  scanf("%s", dateiname);
  fflush(stdin);

  FILE *datei_1, *datei_2;
  datei_1 = fopen(dateiname, "r");
  datei_2 = fopen("spiele.txt", "w");
  bool zeile_lesen = true;
  int i = 0, j = 0;
  if (!datei_1) printf("Datei ist leer\n");
  else
  {
    while (!feof(datei_1))
    {
      c = fgetc(datei_1);
      if (c == '*') i++;

      if (i == 3 && j == 3) zeile_lesen = false;
      if (zeile_lesen && c != '*')
      {
        fputc(c, datei_2);
      }
      j++;
      if (c == '\n')
      {
        zeile_lesen = true;
        i = 0;
        j = 0;
      }
    }
  }
  fclose(datei_1);
  fclose(datei_2);
}
