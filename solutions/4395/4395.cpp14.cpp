#include <stdio.h>
#include <math.h>

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		long long int x, y;

		scanf("%lld %lld", &x, &y);
		y -= x;

		int count = 0;
		long long int n = sqrt(y);
		count += n;
		y -= n * (n + 1) / 2;

		if (y == 0)
		{
			printf("%d\n", count);
			continue;
		}

		n = sqrt(2 * y);
		y -= n * (n + 1) / 2;
		count += n;

		if (y > 0)
			count++;

		printf("%d\n", count);

	}

	return 0;
}