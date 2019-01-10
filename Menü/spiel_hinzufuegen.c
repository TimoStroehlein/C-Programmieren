#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void spiel_hinzufuegen();
void struct_liste();
void lesen();
void schreiben();

typedef struct m_spiel
{
  char name[20+1];
  char genre[20+1];
  char preis[20+1];
  char datum[10+1];

  struct m_spiel *davor;
  struct m_spiel *danach;
} t_spiel;
typedef struct
{
  char name[20+1];
  char genre[20+1];
  char preis[20+1];
  char datum[10+1];

  t_spiel *mom, *start, *zwischen;
} t_feld;

void main (void)
{
  t_feld feld;
  t_feld *f = &feld;
  f -> mom = 0;
  f -> start = 0;
  f -> zwischen = 0;

  printf("Name: ");
  scanf("%s", f -> name);
  fflush(stdin);
  printf("Genre: ");
  scanf("%s", f -> genre);
  fflush(stdin);
  printf("Preis: ");
  scanf("%s", f -> preis);
  fflush(stdin);
  printf("Datum: ");
  scanf("%s", f -> datum);
  fflush(stdin);
  spiel_hinzufuegen();
  lesen();
}

void spiel_hinzufuegen (t_feld *f)
{
  f -> mom = (t_spiel*)malloc(sizeof(t_spiel));  //Malloc liefert void Zeiger
  struct_liste(f);

  f -> mom -> davor = f -> zwischen;
  f -> mom -> danach = 0;

  if (f -> zwischen == 0) f -> start = f -> mom;
  else f -> zwischen -> danach = f-> mom;

  f -> zwischen = f -> mom;
}

void struct_liste (t_feld *f)
{
  strcpy(f -> mom -> name, f -> name);
}

void schreiben (void)
{
  FILE *datei;
  datei = fopen("spiele.txt", "w");
}

void lesen (t_feld *f)
{
  FILE *datei;
  char text[200+1];
  datei = fopen("spiele.txt", "r");
  if (!datei)
  {
    printf("Datei ist leer");
  }
  else
  {
    fgets(text, 200, datei);
    while (!feof(datei))
    {
      //printf("\n%s", text);
      fgets(text, 200, datei);
      strncpy(f -> name, text, 20);
      strncpy(f -> genre, text+20, 20);
      strncpy(f -> preis, text+40, 20);
      strncpy(f -> datum, text+60, 20);

      printf("%s\n", f -> name);
      printf("%s\n", f -> genre);
      printf("%s\n", f -> preis);
      printf("%s\n", f -> datum);
    }
    fclose(datei);
  }
}
