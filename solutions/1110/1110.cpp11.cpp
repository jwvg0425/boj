#include <stdio.h>

int main()
{
	int n;

	scanf("%d", &n);

	int cycle = 0;
	int k = n;

	do
	{
		k = ((k % 10) * 10) + ((k / 10 + k % 10) % 10);

		cycle++;
	} while (n != k);

	printf("%d", cycle);
}