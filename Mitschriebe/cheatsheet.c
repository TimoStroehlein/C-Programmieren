//Standard-Librarys
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

//Einlesen
scanf("%i", &int);
scanf("%c", &char);
scanf("%f", &float);
scanf("%lf", &double);
scanf("%s", text[]);
fflush(stdin);
fflush(stdout);

//Zeiger
int i = 42;
int *zi = &i;       //Zeiger zeigt auf i
int **zzi = &zi;    //Zeiger zeigt auf zi
int ***zzzi = &zzi; //Zeiger zeigt auf zzi

//Stringfunktionen
strcpy(s1, s2);     //wird direkt hinein kopiert
strncpy(s1, s2, n); //wird direkt hinein kopiert, wobei nur n Anzahl an chars kopiert wird
strcat(s1, s2);     //wird hinten angehängt
strncat(s1, s2, n); //wird hinten angehängt, wobei nur n Anzahl an chars hinten angehängt werden
strlen(s1);         //gibt die String Länge zurück
strrev(s1);         //dreht den String um
strstr(s1, s2);     //findet einen String in einem anderen String
strcmp(s1, s2);     //vergleicht zwei Strings
strncmp(s1, s2, n); //vergleicht die ersten n Anzahl an Zeichen der Strings
strcmpi(s1, s2);    //vergleicht zwei Strings ignoriert jedoch die Groß- und Kleinschreibung
stricmp(s1, s2);    //vergleicht zwei Strings ignoriert jedoch die Groß- und Kleinschreibung

//Sonstige Funktionen
itoa(zahl, text, basis);              //Basis 16 = Hexadezimalzahl
array = (int *) malloc(sizeof(int));  //Speicher reservieren
