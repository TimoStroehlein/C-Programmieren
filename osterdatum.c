#include<stdio.h>
#include<string.h>

int main (void)
{
	int a, b, c, d, e, tag;
	int jahr = 1900;

	while (jahr <= 2100)
	{
		if (jahr == 1954 || jahr == 1981)
		{
			printf("\n%i Ostern ist nicht berechenbar", jahr);
		}
		else
		{
			a = jahr % 19;
			b = jahr & 4;
			c = jahr % 7;
			d = (19 * a + 24) % 30;
			e = (2 * b + 4 * c + 6 * d + 5) % 7;
			tag = d + e + 22;

			if (tag <= 31)
			{
				printf("\n%i ist Ostern am %i.M\x84rz", jahr, tag);
			}
			else
			{
				tag = tag - 31;
				printf("\n%i ist Ostern am %i.April", jahr, tag);
			}
		}
		jahr++;
	}
	printf("\nProgrammende");

	char namen[3][5 + 1];

	strcpy(namen[0], "Max");
	printf("---%s---\n", namen[0]);

	strcpy(namen[1], "Elisabeth");
	printf("---%s---\n", namen[1]);

	strcpy(namen[2], "Horst");
	printf("---%s---\n", namen[2]);

	printf("---%s---\n", namen[1]);


	getchar();
}
