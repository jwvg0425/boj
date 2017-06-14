#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>

int table[100001];

int main()
{
	int n;
	scanf("%d", &n);

	table[0] = 0;
	table[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		table[i] = 987654321;

		for (int j = 1; j * j <= i; j++)
		{
			table[i] = std::min(table[i], 1 + table[i - j*j]);
		}
	}

	printf("%d", table[n]);

	return 0;
}