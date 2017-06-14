#include <stdio.h>
#include <algorithm>
#include <memory.h>

long long int table[101] = { 0, 1, 1, 1, 2, 2 };

int main()
{
	for (int n = 6; n <= 100; n++)
	{
		table[n] = table[n - 1] + table[n - 5];
	}

	int t;

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);

		printf("%lld\n", table[n]);
	}
}