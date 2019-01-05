#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void up_listeAdd(void);
void up_struct_liste(void);
void up_hex(void);

typedef struct m_dhler
{
  char name[20+1];
  char vname[20+1];
  int matnr;

  struct m_dhler *davor;
  struct m_dhler *danach;
} t_dhler;
t_dhler *mom = 0, *zwischen = 0, *start = 0;
struct
{
  char name[20+1];
  char vname[20+1];
  int matnr;
} dhler;

void main (void)
{
  int i;

  for (i = 0; i < 3; i++)
  {
    printf("Gib %d. Namen ein: ", i+1);
    scanf("%s", &dhler.name);
    fflush(stdin);
    up_listeAdd();
  }
  up_hex();
}

void up_listeAdd (void)
{
  mom = (t_dhler*)malloc(sizeof(t_dhler));  //Malloc liefert void Zeiger
  up_struct_liste();

  mom -> davor = zwischen;
  mom -> danach = 0;

  if (zwischen == 0) start = mom;
  else zwischen -> danach = mom;

  zwischen = mom;
}

void up_struct_liste (void)
{
  strcpy(mom -> name, dhler.name);
}

void up_hex (void)
{
  mom = start;

  while (mom)
  {
    printf("\n%-10s %x %x %x", mom -> name, mom, mom -> davor, mom -> danach);
    mom = mom -> danach;
  }
}
