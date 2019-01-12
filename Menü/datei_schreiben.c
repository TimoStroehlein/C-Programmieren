#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void daten_lesen();
void datei_daten_schreiben_neu();

struct
{
  char name[20+1];
  char genre[20+1];
  int preis;
  char datum[10+1];
} spiel;

void daten_lesen (void)
{
  printf("Name: ");
  scanf("%[^\n]s", spiel.name);
  fflush(stdin);

  printf("Genre: ");
  scanf("%[^\n]s", spiel.genre);
  fflush(stdin);

  printf("Preis: ");
  scanf("%i", &spiel.preis);
  fflush(stdin);

  printf("Datum: ");
  scanf("%[^\n]s", spiel.datum);
  fflush(stdin);

  datei_daten_schreiben_neu();
}

void datei_daten_schreiben_neu (void)
{
  FILE *datei;
  datei = fopen("spiele.txt", "a+");
  fwrite(spiel.name, 20, 1, datei);
  fwrite(spiel.genre, 20, 1, datei);
  fwrite(&spiel.preis, 3, 1, datei);
  fwrite(spiel.datum, 10, 1, datei);
  fwrite("\n", 1, 1, datei);
  fclose(datei);

  memset(spiel.name, 0, strlen(spiel.name));
  memset(spiel.genre, 0, strlen(spiel.genre));
  memset(spiel.datum, 0, strlen(spiel.datum));
}
