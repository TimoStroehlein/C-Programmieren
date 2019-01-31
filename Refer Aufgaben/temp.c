#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_entry();
void playlisteAdd();
void printPlayliste();

    typedef struct lied
    {
        char liedName[50+1];
        char bandName [30+1];
        char album [30+1];

        struct lied *davor;
        struct lied *danach;
    } lied;

    typedef struct
    {
        char liedName[50+1];
        char bandName[30+1];
        char album [30+1];

        lied *mom;
        lied *start;
        lied *zwischen;
    } t_feld;


    void playlisteAdd(t_feld *l)
{
    l -> mom = (lied *) malloc(sizeof(lied));
    add_entry(l);
    l -> mom -> davor = l -> zwischen;
    l -> mom -> danach = 0;

        if(l -> zwischen == 0) l -> start = l -> mom;
        else l -> zwischen -> danach = l -> mom;
        l -> zwischen = l -> mom;
}

void add_entry(t_feld *l)
{
    strcpy(l -> mom -> liedName, l->liedName);
    strcpy(l -> mom -> bandName, l ->bandName);
    strcpy(l -> mom -> album, l ->album);
}

void printPlayliste(t_feld *l)
{
    printf("Deine Playlist: ");
    l -> mom = l ->start;
    int i = 1;
    while(i <= 5)
    {
    printf("\nTrack %d - %s\n %s\n %s\n ", i, l -> mom -> liedName,
    l -> mom ->bandName, l -> mom ->album);
    l -> mom = l -> mom-> danach;
    i++;
    }

}

void loeschePlayliste(t_feld *l)
{

if(l -> start != NULL)
    {
    if(strcmp(l -> start = l -> mom)
    {
        l -> mom -> davor = NULL;
        free(l -> start);
        l -> mom = l -> start;
     }
    }
}

void main()
{
    int i;
    t_feld neuLied;
    t_feld *l = &neuLied;
    l -> mom = 0;
    l -> start = 0;
    l -> zwischen = 0;

    for(i=0; i<3;i++)
    {
        printf ("Gib %d Lied ein:", i+1);
        scanf("%s", l -> liedName);
        fflush(stdin);
        printf("Gib %d Band ein: ", i+1);
        scanf("%s", l -> bandName);
        fflush(stdin);
        printf("Gib %d Album ein: ", i+1);
        scanf("%s", l -> album);
        fflush(stdin);
        playlisteAdd(l);

    }
    printPlayliste(l);

    int loeschen = 1;
    printf("Loesche Playliste? 1-Ja/ 0-Nein \n");
    scanf("%s", loeschen);
    fflush(stdin);

    switch (loeschen)
    {
        case 1:
            loeschePlayliste(l);
            break;
        case 0:
            printPlayliste(l);
            break;
    }

}
