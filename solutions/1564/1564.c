#include<stdio.h>

int main(void)
{
	int n;
	long long int s = 1, i;

	scanf("%d", &n);

	for (i = 2; i <= n; i++)
	{
		s *= i;
		while(!(s%10))s /= 10;
		s %= 10000000000;
	}
	printf("%05lld", s%100000);
}