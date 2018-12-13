//Logische Negierung
a = 7;
b = !a; //0

a = 0;
b = !a; //1

//Bitweise Negierung
a = 7;
b = ~a; //-8

/*
 0000 0111
 1111 1000
 0000 0111
+0000 0111
----------
 0000 1000 = -8
*/

"Zeigeroperator": *
"Adressoperator": &

//Typecast
int a = 7;
char b = 'A';
float f = 2.39;
double d = 3.45;

erg = a + (int)b + (int)f + (int)d;

//Operatoren
"Addition": +
"Subtraktion": -
"Multiplikation": *
"Ganzzahldivision": /
"Modulo Restwertbildung": %

int a = 7;  //0000...0111       7 / 2² = 1
b = a >> 2; //0000...0001
a = 7;      //0000...0111
b = a << 3; //0000...0111 000   7 * 2³ = 56

"Vergleiche": <, <=, >, >=, ==, !=

//Bitweise
int a = 7, b = 13, erg;
erg = a & b;
//0111
//1101
//----
//0101
erg = a | b;
//0111
//1101
//----
//1111
erg = a ^ b;
//0111
//1101
//----
//1010

//Logisch
"Und": &&
"Oder": ||
if (a > b) b = 4;
else a = 4;

//Trennungsoperator
"Komma": ,
int a, b, c;

//Zuweisungen
a = 7;
a += 7; oder a = a + 7;

//For-Schleife
for (i = 7; i < 40; i++)
{
  /* code */
}
for (i = 7, j = 8, l = 10; a > 5; i++, j--, l = l - 20)
{
  /* code */
}

//While-Schleife
while (a > b) {
  /* code */
}

//Do-While-Schleife
do
{
  /* code */
} while(a > b);

//Zeiger und Co.
char bu = 'A';
char text[80+1]; //Immer eins mehr
char *z;
strcpy(text, "Hannes");
z = text;

//Einlesen
scanf("%i", &a);  int a;
scanf("%c", &bu); char bu;
scanf("%f", &f1); float f1;
scanf("%lf", &d1); double d1;
scanf("%s", text); char text[80+1];
"Nach jedem scanf": fflush(stdin);

//Stringfunktionen
strcpy();   //wird direkt hinein kopiert
strncpy();  //wird direkt hinein kopiert, wobei nur n Anzahl an chars kopiert wird
strcat();   //wird hinten angehängt
strncat();  //wird hinten angehängt, wobei nur n Anzahl an chars hinten angehängt werden
strlen();   //gibt die String Länge zurück
strrev();   //dreht String um
strstr();   //findet einen String in einem anderen String
strcmp();   //vergleicht zwei Strings
strncmp();  //vergleicht die ersten n Anzahl an Zeichen der Strings
strcmpi();  //vergleicht zwei Strings ignoriert jedoch die Groß- und Kleinschreibung
stricmp();  //vergleicht zwei Strings ignoriert jedoch die Groß- und Kleinschreibung
//Beispiel 2
strcpy(t1, "Hannes");
strcpy(t2, "ist schlau");
strcat(t1, t2);
strncat(t1, t2, 4);
strcat(t1, "fleissig");
//Beispiel 2
char namen[3][5+1];
strcpy(namen[0], "Max");
printf("---%s---\n", namen[0]); //---Max---
strcpy(namen[1], "Elisabeth");
printf("---%s---\n", namen[1]); //---Elisabeth--
strcpy(namen[2], "Horst");
printf("---%s---\n", namen[2]); //---Horst---
printf("---%s---\n", namen[1]); //---Elisabttorst---
//Beispiel 3
int laenge;
laenge = strlen("Hannes");
int strlen(char*);
char t1[] = "Hugo";
strrev(t1); //oguH
//Buchstaben in String schreiben
char t1[80+1];
strcpy(t1, "eine Aufgabe 12");
bu = t1[6]; //u
t1[7] = 's';
zahl = t1[14];  //50 == '2'
zahl = zahl - 48;

//Zeiger (ff)
int i = 42;
int *zi = &i;       //Zeiger zeigt auf i
int **zzi = &zi;    //Zeiger zeigt auf zi
int ***zzzi = &zzi; //Zeiger zeigt auf  zzi

//Funktionen und Unterprogramme
int main(void)
{
  int a = 7, b = 4;
  float erg;
  char bu = 'A';
  char text[80+1];
  strcpy(text, "Hannes");
  erg = up(a, &b, bu, &bu, text);
}

float up(int a, int *b, char bu, char *bu, char *text)
{
  float erg;
  erg = a + *b + bu + *bu + strlen(text);
  return erg;
}

//Zeiger in Zeiger
char namen[3][5+1];

printf("%d, %d, %d, %d", i, *zi, **zzi, ***zzzi);  //42, 42, 42, 42

i = 33;
*zi = 43;
**zzi = 45;
***zzzi = 99;

//Strukturen bzw. Unions
//(1) Real Existent
struct
{
  char name[20+1];
  char vname[20+1];
  int par;
  float gehalt;
  double bauchweite;
  int farbe[3];
}dhler;
}dhler[30];
dhler.gehalt = 10.5;
strcpy(dhler.name, "Hannes");
dhler[3].farbe[2] = 19;

//(2) Muster
struct m_dhler
{
  char name[20+1];
  char vname[20+1];
  int par;
  float gehalt;
  double bauchweite;
  int farbe[3];
};
struct m_dhler hannes, TINF18B[29], *zdhler, hannes.gehalt = 2.30;

//(3) Eigener Datentyp
typedef struct
{
  char name[20+1];
  char vname[20+1];
  int par;
  float gehalt;
  double bauchweite;
  int farbe[3];
}t_dhler;
t_dhler hannes, TINF18B[25], *z
//Beispiel
typedef struct m_dhler
{
  struct m_dhler *davor;
  struct m_dhler *danach;
}t_dhler;
t_dhler *mom;
mom = (t_dhler*)malloc(sizeof(t_dhler));
mom -> gehalt = 3.90;

//Beispiel
#include<time.h>

main (void)
{
  char datum[80+1];
  up_datum(datum);
  printf("\n%s", datum);
}
void up_datum (char *datum)
{
  char htext[80+1];
  struct tm *zeit;
  long sec;
  time(&sec); //Sekunden seit 1970
  zeit = localtime(&sec);  //Legt Struktur an
  switch (zeit -> tm_wday)
  {
    case 0: strcpy(datum, "Sonntag, den"); break;
    case 1: strcpy(datum, "Montag, den"); break;
    default: printf("Fehler");
  }
}
itoa(zeit -> tm_wday, htext, 10); //Zahl, Text (z.B. 13), Basis
strcat(datum, htext);
