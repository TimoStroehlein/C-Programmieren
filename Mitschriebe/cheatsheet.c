//Einlesen
scanf("%i", &a);  int a;
scanf("%c", &bu); char bu;
scanf("%f", &f1); float f1;
scanf("%lf", &d1); double d1;
scanf("%s", text); char text[80+1];
fflush(stdin);  //Nach jedem scanf

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
