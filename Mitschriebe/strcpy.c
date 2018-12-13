#include<stdio.h>

int main (void)
{
  int e;
  char t1[80+1], t2[80+1];
  strcpy(t1, "Hannes");
  int l = Stringkopie(t2, t1);
  printf("%s\n", t2);
}

int Stringkopie (char *t2, char *t1)
{
  int laenge, i;
  laenge = Stringlaenge(t1);
  
  for (i = 0;i < laenge; i++)
  {
    t2[i] = t1[i];
  }
  t2[i] = 0; //oder \0
  return laenge;
}

int Stringlaenge (char *t)
{
  int l;
  while (t[l++] != 0) return l;
}

void Stringkopie2 (char *t2, char *t1)
{
  while (*t2++ = *t1++);
}
