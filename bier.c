#include<stdio.h>
#include<math.h>

int main(void)
{
	float volumen = (M_PI * (50 * 50) * 10) / 1000000;
	float liter = 0;

	for (int i = 0; i <= 200; i = i + 10)
	{
		printf("Bei einer Hoehe von %i mm betraegt das Volumen %.3f Liter!\n", i, liter);
		liter = liter + volumen;
	}
}
