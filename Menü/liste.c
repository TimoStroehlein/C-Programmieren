#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void liste();
void liste_add();
void liste_add_items();
void liste_anzeigen();
void liste_loeschen();
void liste_bubblesort();
void liste_feld_tauschen();
void datei_lesen();
void datei_schreiben();

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

int anzahl_spiele;

void liste (int modus)
{
  t_feld feld;
  t_feld *f = &feld;
  f -> mom = 0;
  f -> erster = 0;
  f -> letzter = 0;
  datei_lesen(f);

  switch (modus)
  {
    case 0:
      liste_anzeigen(f);
      getchar();
      break;
    case 1:
      liste_loeschen(f);
      break;
    //Name
    case 2:
      liste_bubblesort(f, 0);
      system("cls");
      liste_anzeigen(f);
      getchar();
      break;
    case 3:
      liste_bubblesort(f, 1);
      system("cls");
      liste_anzeigen(f);
      getchar();
      break;
    //Genre
    case 4:
      liste_bubblesort(f, 2);
      system("cls");
      liste_anzeigen(f);
      getchar();
      break;
    case 5:
      liste_bubblesort(f, 3);
      system("cls");
      liste_anzeigen(f);
      getchar();
      break;
    //Preis
    case 6:
      liste_bubblesort(f, 4);
      system("cls");
      liste_anzeigen(f);
      getchar();
      break;
    case 7:
      liste_bubblesort(f, 5);
      system("cls");
      liste_anzeigen(f);
      getchar();
      break;
    //Datum
    case 8:
      liste_bubblesort(f, 6);
      system("cls");
      liste_anzeigen(f);
      getchar();
      break;
    case 9:
      liste_bubblesort(f, 7);
      system("cls");
      liste_anzeigen(f);
      getchar();
      break;
    default:
      printf("Modus nicht bekannt.\n");
      break;
  }
}

void liste_add (t_feld *f)
{
  f -> mom = (t_spiel*)malloc(sizeof(t_spiel));  //Reserviert Größe des structs im Hauptspeicher, Typecast nötig, da return value von malloc Void-Zeiger ist
  liste_add_items(f);  //Kopiert eingelesenes in die Liste

  f -> mom -> davor = f -> letzter;
  f -> mom -> danach = 0;

  if (f -> letzter == 0) f -> erster = f -> mom;
  else f -> letzter -> danach = f-> mom;

  f -> letzter = f -> mom;
}

void liste_add_items (t_feld *f)
{
  strcpy(f -> mom -> name, f -> name);
  strcpy(f -> mom -> genre, f -> genre);
  f -> mom -> preis = f -> preis;
  strcpy(f -> mom -> datum, f -> datum);
}

void liste_anzeigen (t_feld *f)
{
  printf("  |---------Name---------|---------Genre---------|--Preis--|----Datum----|\n");
  f -> mom = f -> erster;
  int i = 1;
  while (f -> mom != NULL)
  {
    printf("%i | %-20s | %-21s | %-7i | %-11s |\n",i , f -> mom -> name, f -> mom -> genre, f -> mom -> preis, f -> mom -> datum);
    f -> mom = f -> mom -> danach;
    i++;
  }
}

void liste_loeschen (t_feld *f)
{

}

void liste_bubblesort (t_feld *f, int modus)
{
  f -> mom = f -> erster;
  char temp[20+1];
  int temp2;
  for (int i = 0; i < anzahl_spiele - 1; i++)
  {
    for (int j = 0; j < anzahl_spiele - 1; j++)
    {
      switch (modus)
      {
        //Name
        case 0:
          if (strcmp(f -> mom -> name, f -> mom -> danach -> name) > 0) liste_feld_tauschen(f); //Aufsteigend sortieren (A-Z)
          break;
        case 1:
          if (strcmp(f -> mom -> name, f -> mom -> danach -> name) < 0) liste_feld_tauschen(f); //Absteigend sortieren (Z-A)
          break;
        //Genre
        case 2:
          if (strcmp(f -> mom -> genre, f -> mom -> danach -> genre) > 0) liste_feld_tauschen(f); //Aufsteigend sortieren (A-Z)
          break;
        case 3:
          if (strcmp(f -> mom -> genre, f -> mom -> danach -> genre) < 0) liste_feld_tauschen(f); //Absteigend sortieren (Z-A)
          break;
        //Preis
        case 4:
          if (f -> mom -> preis > f -> mom -> danach -> preis) liste_feld_tauschen(f); //Aufsteigend sortieren
          break;
        case 5:
          if (f -> mom -> preis < f -> mom -> danach -> preis) liste_feld_tauschen(f); //Absteigend sortieren
          break;
        //Datum
        case 6:
          if (strcmp((f -> mom -> datum)+6, (f -> mom -> danach -> datum)+6) > 0) liste_feld_tauschen(f); //Aufsteigend sortieren (A-Z)
          break;
        case 7:
          if (strcmp((f -> mom -> datum)+6, (f -> mom -> danach -> datum)+6) < 0) liste_feld_tauschen(f); //Absteigend sortieren (Z-A)
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

void liste_feld_tauschen (t_feld *f)
{
  char temp[20+1];
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

void datei_lesen (t_feld *f)
{
  FILE *datei;
  char text[100];
  anzahl_spiele = 0;
  if (!datei) printf("Datei ist leer");
  else
  {
    datei = fopen("spiele.txt", "a+");
    fgets(text, 100, datei);
    while (!feof(datei))
    {
      strncpy(f -> name, text, 20);
      strncpy(f -> genre, text+20, 20);
      char preis[3];
      strncpy(preis, text+40, 3);
      f -> preis = 0;
      for (int i = 0; i < sizeof(preis); i++) f -> preis += (int)preis[i];
      strncpy(f -> datum, text+43, 10);

      liste_add(f);
      fgets(text, 100, datei);
      anzahl_spiele++;
    }
  }
  fclose(datei);
}
