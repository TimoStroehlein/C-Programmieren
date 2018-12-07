#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main (void)
{
    int i = 0;
    char wert = 120;

    for (i = 0; i <= 20; i++, wert++)
    {
        printf("\n   %5d", wert);
    }
    /*
    int x = 72, y = 12;

    while (x != y)
    {
        if (x > y)
            x = x - y;
        else
            y = y - x;
    }
    printf("ggt = %i", x);
    */
    return 42;
}
