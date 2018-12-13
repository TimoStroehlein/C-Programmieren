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

//Zeiger (ff)
int i = 42;
int *zi = &i;       //Zeiger zeigt auf i
int **zzi = &zi;    //Zeiger zeigt auf zi
int ***zzzi = &zzi; //Zeiger zeigt auf  zzi

//String
char namen[3][5+1];

printf("%d, %d, %d, %d", i, *zi, **zzi, ***zzzi);  //42, 42, 42, 42

i = 33;
*zi = 43;
**zzi = 45;
***zzzi = 99;
