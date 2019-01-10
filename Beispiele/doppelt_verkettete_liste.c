#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void up_listeAdd();
void up_struct_liste();
void up_hex();

typedef struct m_dhler
{
  char name[20+1];
  char vname[20+1];
  int matnr;

  struct m_dhler *davor;
  struct m_dhler *danach;
} t_dhler;

typedef struct
{
  char name[20+1];
  char vname[20+1];
  int matnr;

  t_dhler *mom, *start, *zwischen;
} t_feld;

void main (void)
{
  t_feld feld;
  t_feld *f = &feld;
  f -> mom = 0;
  f -> start = 0;
  f -> zwischen = 0;

  int i;
  for (i = 0; i < 3; i++)
  {
    printf("Gib %d. Namen ein: ", i+1);
    scanf("%s", f -> vname);
    fflush(stdin);
    up_listeAdd(f);
  }
  up_hex(f);
}

void up_listeAdd (t_feld *f)
{
  f -> mom = (t_dhler*)malloc(sizeof(t_dhler));  //Malloc liefert void Zeiger
  up_struct_liste(f);

  f -> mom -> davor = f -> zwischen;
  f -> mom -> danach = 0;

  if (f -> zwischen == 0) f -> start = f -> mom;
  else f -> zwischen -> danach = f-> mom;

  f -> zwischen = f -> mom;
}

void up_struct_liste (t_feld *f)
{
  strcpy(f -> mom -> name, f -> name);
}

void up_hex (t_feld *f)
{
  f -> mom = f -> start;

  while (f -> mom)
  {
    printf("\n%-10s %x %x %x",
      f -> mom -> name,
      f -> mom,
      f -> mom -> davor,
      f -> mom -> danach);

    f -> mom = f -> mom -> danach;
  }
}
