#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>
#include <memory.h>
#include <math.h>

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	int table[1001] = { 0, };

	for (int i = 2; i <= n; i++)
	{
		if (table[i] != 0)
			continue;

		for (int j = i; j <= n; j += i)
		{
			if (table[j] == 1)
				continue;

			k--;
			table[j] = 1;

			if (k == 0)
			{
				printf("%d", j);
				return 0;
			}
		}
	}

	return 0;
}