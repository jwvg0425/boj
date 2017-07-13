#include<stdio.h>

int main()
{
	while (true)
	{
		double a, b = 0;
		scanf("%lf", &a);

		if (a == 0.0)
			break;

		for (int n = 2;; n++)
		{
			b += (double)1 / n;
			if (b >= a)
			{
				printf("%d card(s)\n", n - 1);
				break;
			}
		}
	}

	return 0;
}