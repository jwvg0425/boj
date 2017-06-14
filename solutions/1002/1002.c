#include<stdio.h>

int main(void)
{
	int T;
	long long int x1, y1, x2, y2, r1, r2, d, a, b;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%lld %lld %lld %lld %lld %lld", &x1, &y1, &r1, &x2, &y2, &r2);
		if (x1 == x2&&y1 == y2&&r1 == r2)
		{
			printf("-1\n");
			continue;
		}
		d = (y2 - y1)*(y2 - y1) + (x2 - x1)*(x2 - x1);
		a = r1*r1 + r2*r2;
		b = 2 * r1*r2;
		if (a - b > d)
		{
			printf("0\n");
			continue;
		}
		if (a - b == d)
		{
			printf("1\n");
			continue;
		}
		if (d > a - b&&d < a + b)
		{
			printf("2\n");
			continue;
		}
		if (d == a + b)
		{
			printf("1\n");
			continue;
		}
		printf("0\n");
	}
}