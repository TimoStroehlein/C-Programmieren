#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <sys\timeb.h>

void up_TvH(int scheibe, int von, int nach);
double nimmzeit(void);

int main (void)
{
  int anzahl = 4, von = 1, nach = 3;

  printf("%.3f\n", nimmzeit());
  up_TvH (anzahl, von, nach);
  printf("%.3f\n", nimmzeit());
}

void up_TvH (int scheibe, int von, int nach)
{
  int zwischen;

  if (scheibe > 1)
  {
    zwischen = 6 - von - nach;
    up_TvH(scheibe - 1, von, zwischen);
    //printf("Scheibe %i von %i nach %i\n", scheibe, von, nach);
    up_TvH(scheibe - 1, zwischen, nach);
  }
  else
  {
    //printf("Scheibe %i von %i nach %i\n", scheibe, von, nach);
  }
}

double nimmzeit(void)
{
    double messwert;
    struct timeb tb;

    ftime(&tb);

    messwert = (double)tb.time + (double)tb.millitm/1000.0;

    return(messwert);
}
