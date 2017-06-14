#include<stdio.h>

int main(void)
{
	int n, a, m = 1000000, M = 0;

	scanf("%d", &n);

	while (n--)
	{
		scanf("%d", &a);
		if (a > M)M = a;
		if (a < m)m = a;
	}
	printf("%d", m*M);
}