#include <stdio.h>

void main (void)
{
  int mat[] = {42, 17, 93, 12, 83, 53, 44};
  int i, j, temp;
  for (i = 0; i < 7-1; i++)
  {
    for (j = 0; j < 7-1; j++)
    {
      if (mat[j] > mat[j+1])
      {
        temp = mat[j];
        mat[j] = mat[j+1];
        mat[j+1] = temp;
      }
      /*
      if (strcmp(f -> mom -> name, f -> mom -> danach -> name) > oder < 0)
      {
        //tausche
      }
      */
    }
  }
  for (i = 0; i < 7; i++)
  {
    printf("%i\n", mat[i]);
  }
}
