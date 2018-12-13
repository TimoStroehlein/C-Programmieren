##include<stdio.h>
##include<string.h>

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
