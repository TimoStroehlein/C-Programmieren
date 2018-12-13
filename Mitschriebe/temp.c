#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void main (void)
{
  char datum[80+1];
  up_datum(datum);
  printf("%s", datum);
}
void up_datum (char *datum)
{
  char htext[80+1];
  char monat[80+1];
  struct tm *zeit;
  long sec;
  time(&sec); //Sekunden seit 1970
  zeit = localtime(&sec);  //Legt Struktur an
  switch (zeit -> tm_wday)
  {
    case 0: strcpy(datum, "Sonntag, den "); break;
    case 1: strcpy(datum, "Montag, den "); break;
    case 2: strcpy(datum, "Dienstag, den "); break;
    case 3: strcpy(datum, "Mittwoch, den "); break;
    case 4: strcpy(datum, "Donnerstag, den "); break;
    case 5: strcpy(datum, "Freitag, den "); break;
    case 6: strcpy(datum, "Samstag, den "); break;

    default: printf("Fehler");
  }
  itoa(zeit -> tm_mday, htext, 10); //Zahl, Text (z.B. 13), Basis
  strcat(datum, htext);
  strcat(datum, ".");
  printf("%s", datum);

  switch (zeit -> tm_mon)
  {
    case 0: strcpy(datum, "Januar "); break;
    case 1: strcpy(datum, "Februar "); break;
    case 2: strcpy(datum, "März "); break;
    case 3: strcpy(datum, "April "); break;
    case 4: strcpy(datum, "Mai "); break;
    case 5: strcpy(datum, "Juni "); break;
    case 6: strcpy(datum, "Juli "); break;
    case 7: strcpy(datum, "August "); break;
    case 8: strcpy(datum, "September "); break;
    case 9: strcpy(datum, "Oktober "); break;
    case 10: strcpy(datum, "November "); break;
    case 11: strcpy(datum, "Dezember "); break;

    default: printf("Fehler");
  }
  strcat(datum, monat);
  itoa(zeit -> tm_year + 1900, htext, 10);
  strcat(datum, htext);
}
