#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>

int table[10000001];

int main()
{
	int n;

	scanf("%d", &n);

	table[0] = 1;
	table[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		table[i] = (table[i - 1] + table[i - 2]) % 10;
	}

	printf("%d", table[n]);

	return 0;
}