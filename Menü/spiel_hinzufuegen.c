#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void liste_lesen();
void liste_add();
void struct_liste();
void datei_lesen();
void datei_schreiben();
void debug();

typedef struct m_spiel
{
  char name[20+1];
  char genre[20+1];
  int preis;
  char datum[10+1];

  struct m_spiel *davor;
  struct m_spiel *danach;
} t_spiel;

typedef struct
{
  char name[20+1];
  char genre[20+1];
  int preis;
  char datum[10+1];

  t_spiel *mom, *erster, *letzter;
} t_feld;

void liste_lesen (void)
{
  int temp;
  t_feld feld;
  t_feld *f = &feld;
  f -> mom = 0;
  f -> erster = 0;
  f -> letzter = 0;

  printf("Name: ");
  scanf("%s", f -> name);
  fflush(stdin);

  printf("Genre: ");
  scanf("%s", f -> genre);
  fflush(stdin);

  printf("Preis: ");
  scanf("%i", &(f -> preis));
  fflush(stdin);

  printf("Datum: ");
  scanf("%s", f -> datum);
  fflush(stdin);

  liste_add(f);

  //debug(f);
  datei_lesen(f);
  //datei_schreiben(f);
}

void liste_add (t_feld *f)
{
  f -> mom = (t_spiel*)malloc(sizeof(t_spiel));  //Reserviert Größe des structs im Hauptspeicher, Typecast nötig, da return value von malloc Void-Zeiger ist
  struct_liste(f);  //Kopiert eingelesenes in die Liste

  f -> mom -> davor = f -> letzter;
  f -> mom -> danach = 0;

  if (f -> letzter == 0) f -> erster = f -> mom;
  else f -> letzter -> danach = f-> mom;

  f -> letzter = f -> mom;
}

void struct_liste (t_feld *f)
{
  strcpy(f -> mom -> name, f -> name);
  strcpy(f -> mom -> genre, f -> genre);
  f -> mom -> preis = f -> preis;
  strcpy(f -> mom -> datum, f -> datum);
}

void debug (t_feld *f)
{
  f -> mom = f -> erster;

  while (f -> mom)
  {
    printf("\n%s %s %s %s %x %x %x",
      f -> mom -> name,
      f -> mom -> genre,
      f -> mom -> preis,
      f -> mom -> datum,
      f -> mom,
      f -> mom -> davor,
      f -> mom -> danach);

    f -> mom = f -> mom -> danach;
  }
}

void datei_schreiben (t_feld *f)
{
  FILE *datei;
  datei = fopen("spiele.txt", "a+");
  fwrite(f -> mom -> name, 20, 1, datei);
  fwrite(f -> mom -> genre, 20, 1, datei);
  fwrite(&(f -> mom -> preis), 3, 1, datei);
  fwrite(f -> mom -> datum, 10, 1, datei);
  fclose(datei);
}

void datei_lesen (t_feld *f)
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
      fgets(text, 200, datei);
      strncpy(f -> mom -> name, text, 20);
      strncpy(f -> mom -> genre, text+20, 20);
      char temp[3+1];
      strncpy(temp, text+40, 3);
      for (int i = 0; i < sizeof(temp); i++)
      {
        if ((int)temp[i] != 0)  f -> mom -> preis = (int)temp[i];
      }
      strncpy(f -> mom -> datum, text+43, 10);
      printf("%s\n", f -> mom -> name);
      printf("%s\n", f -> mom -> genre);
      printf("%i\n", f -> mom -> preis);
      printf("%s\n", f -> mom -> datum);
    }
  }
  fclose(datei);
}

//Peter               Drama               56                  07.06.18
