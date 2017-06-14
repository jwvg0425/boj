#include<stdio.h>

int main(void)
{
	int a, b, T, i;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d %d", &a, &b);
		i = a;

		while (--b&&a != 1)
		{
			i *= a;
			i %= 10;
		}
		if (i == 0)i = 10;
		printf("%d\n", i);
	}
}