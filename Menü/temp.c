#include <stdio.h>

struct {
  char characterName[10];
  char cardName[20];
  char cardType[10];
  int damageNumber[1];
  char afflictionType[20]
} card;

char readData();
void writeData();

int main() {
  printf("Starting read process...\n");
  char input = readData();
  printf("Read process finished. Starting write process...\n");
  writeData(input);
  printf("Data writing finished. Exiting...\n");
  return 0;
}

char readData() {
  printf("\nPlease enter a character name: ");
  scanf("%s", card.characterName);
  fflush(stdin);

  printf("\nPlease enter a card name: ");
  scanf("%s", card.cardName);
  fflush(stdin);

  printf("\nPlease enter a card type: ");
  scanf("%s", card.cardType);
  fflush(stdin);

  printf("\nPlease enter a damage type: ");
  scanf("%s", card.damageNumber);
  fflush(stdin);

  printf("\nPlease enter eventual afflictions: ");
  scanf("%s", card.afflictionType);
  fflush(stdin);
}

void writeData() {
  FILE *fp;
  if(!fp) {
    printf("Could not find file.");
  }
  else {
    // open and close the file with every write process so the previous entries arent overwritten
    fp = fopen("card_data.txt", "a+");      // a+ opens the file appended (pointer moves to eof)
    fwrite(card.characterName, 10, 1, fp);
    fwrite(card.cardName, 20, 1, fp);
    fwrite(card.cardType, 10, 1, fp);
    fwrite(card.damageNumber, 2, 1, fp);
    fwrite(card.afflictionType, 20, 1, fp);
    fclose(fp);
    }

}

Project
C-Programmieren
.git
Aufgaben
bier.c
kaffee.c
modulo11.c
osterdatum.c
Beispiele
beispiel.txt
bubble_sort.c
datensaetze_loeschen.c
doppelt_verkettete_liste_alt.c
doppelt_verkettete_liste.c
float_darstellung.c
highlevel_dateihandling.c
stringcopy.c
strukturen.c
tuerme_von_hanoi.c
Menü
main_menu.c
spiel_hinzufuegen.c
spiele.txt
temp.c
Mitschriebe
allgemein.c
cheatsheet.c
Refer Aufgaben
5.1.c
spiel_hinzufuegen.c
temp.c
spiele.txt
main_menu.c
doppelt_verkettete_liste.c
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
133
134
135
136
137
138
85
86
87
88
89
90
91
92
93
94
95
96
121
122
123
124
125
126
127
128
129
130
131
132
97
98
99
100
101
102
      f -> mom,
      f -> mom -> davor,
      f -> mom -> danach);

    f -> mom = f -> mom -> danach;
  }
}

void datei_schreiben (t_feld *f)
{
  FILE *datei;
  datei = fopen("spiele.txt", "a+");
  fwrite(f -> mom -> name, 20, 1, datei);
  fwrite(f -> mom -> genre, 20, 1, datei);
  fwrite(f -> mom -> preis, 2, 1, datei);
  fwrite(f -> mom -> datum, 20, 1, datei);
  fclose(datei);
}
    fgets(text, 200, datei);
    while (!feof(datei))
    {
      fgets(text, 200, datei);
      strncpy(f -> mom -> name, text, 20);
      strncpy(f -> mom -> genre, text+20, 20);
{
  strcpy(f -> mom -> name, f -> name);
  strcpy(f -> mom -> genre, f -> genre);
  f -> mom -> preis = f -> preis;
  strcpy(f -> mom -> datum, f -> datum);
}

void debug (t_feld *f)
{
  f -> mom = f -> erster;

  while (f -> mom)

void datei_lesen (t_feld *f)
{
  FILE *datei;
  char text[200+1];
  datei = fopen("spiele.txt", "r");
  if (!datei)
  {
    printf("Datei ist leer");
  }
  else
  {
  {
    printf("\n%s %s %s %s %x %x %x",
      f -> mom -> name,
      f -> mom -> genre,
      f -> mom -> preis,
      f -> mom -> datum,


Linter
Severity 	Provider 	Description	Line
Git
GitHub
Unstaged Changes
Stage All
Menü\compiling_error.txt
Menü\spiel_hinzufuegen.c
Menü\spiele.txt
Menü\temp.c
Staged Changes
Unstage All
See All Staged Changes

Commit message

Commit to master
72
timostroehlein@gmail.com's avatar'
10.01.19
Undo
2h
timostroehlein@gmail.com's avatar'
05.01.19
6d
timostroehlein@gmail.com's avatar'
14.12.18
1M
timostroehlein@gmail.com's avatar'
13.12.18
1M
timostroehlein@gmail.com's avatar'
13.12.18
1M
timostroehlein@gmail.com's avatar'
.
1M
timostroehlein@gmail.com's avatar'
13.12.18
1M
timostroehlein@gmail.com's avatar'
.
1M
timostroehlein@gmail.com's avatar'
.
1M
timostroehlein@gmail.com's avatar'
.
1M
Menü\spiel_hinzufuegen.c000106:1
CRLFUTF-8C
masterFetchGitHubGit (4)
C:\Users\TimoWIN7\OneDrive - Duale Hochschule Baden-W�rttemberg Stuttgart\GitHub\C-Programmieren\Men�\spiel_hinzufuegen.c: In function 'datei_schreiben':
C:\Users\TimoWIN7\OneDrive - Duale Hochschule Baden-W�rttemberg Stuttgart\GitHub\C-Programmieren\Men�\spiel_hinzufuegen.c:117:10: warning: passing argument 1 of 'fwrite' makes pointer from integer without a cast [-Wint-conversion]
fwrite(f -> mom -> preis, 2, 1, datei);
^
In file included from C:\Users\TimoWIN7\OneDrive - Duale Hochschule Baden-W�rttemberg Stuttgart\GitHub\C-Programmieren\Men�\spiel_hinzufuegen.c:1:0:
c:\mingw\include\stdio.h:735:41: note: expected 'const void ' but argument is of type 'int'
_CRTIMP cdecl MINGW_NOTHROW size_t fwrite (const void , size_t, size_t, FILE );
^~
C:\Users\TimoWIN7\OneDrive - Duale Hochschule Baden-W�rttemberg Stuttgart\GitHub\C-Programmieren\Men�\spiel_hinzufuegen.c: In function 'datei_lesen':
C:\Users\TimoWIN7\OneDrive - Duale Hochschule Baden-W�rttemberg Stuttgart\GitHub\C-Programmieren\Men�\spiel_hinzufuegen.c:139:15: warning: passing argument 1 of 'strncpy' makes pointer from integer without a cast [-Wint-conversion]
strncpy(f -> mom -> preis, text+40, 20);
^
In file included from C:\Users\TimoWIN7\OneDrive - Duale Hochschule Baden-W�rttemberg Stuttgart\GitHub\C-Programmieren\Men�\spiel_hinzufuegen.c:2:0:
c:\mingw\include\string.h:86:40: note: expected 'char ' but argument is of type 'int'
_CRTIMP cdecl MINGW_NOTHROW char strncpy (char , const char *, size_t);
^~~
