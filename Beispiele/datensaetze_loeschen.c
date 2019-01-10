#include <stdio.h>

typedef struct
{
  char name[20+1];
  t_dhler *mom, *start, *zwischen;
} t_feld;
//Listelemente
typedef struct m_dhler
{
  char name[20+1];

  struct m_dhler *davor;
  struct m_dhler *danach;
}

void main (void)
{

}

up_loesche(t_feld *f)
{
  int i = 1;
  up_ausgabe(f);
  printf("Gib Nr ein");
  scanf(...);
  fflush(stdin);
  f -> mom = f -> start;
  while (f -> mom && i++ < eingabe)
  {
    f -> mom = f -> mom -> danach;
  }
  if (f -> mom == 0)
  {
    //Kein Satz
    printf("Nicht zugelassener Wert");
  }
  else if (f -> mom -> danach && f -> mom -> davor)
  {
    //Aus Mitte
    f -> mom -> davor -> danach = f -> mom -> danach;
    f -> mom -> danach -> davor = f -> mom -> davor;
    free(f -> mom);
    f -> mom = f -> start;
  }
  else if (f -> mom -> davor)
  {
    //Der Letzte
  }
  else if (f -> mom -> danach)
  {
    //Der Erste
  }
  else
  {
    //Der Einzige
  }
} //Ende up_loesche()
//------
//Datensätze einlesen
void up_einlesen (t_feld *f)
{
  //vorlesen
  while(!feof(...))
  {
    //verarbeiten
    strncpy(f -> name, text, 20);
    strncpy(f -> vname, text+20, 20);
    strncpy(f -> stadt, text+40, 30);

    up_listeAdd(f);
    //nachlesen
  }
}
//------
