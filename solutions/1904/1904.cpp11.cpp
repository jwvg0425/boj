#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>

int table[1000001];

int main()
{
	int n;

	scanf("%d", &n);

	table[0] = 1;
	table[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		table[i] = (table[i - 1] + table[i - 2]) % 15746;
	}

	printf("%d", table[n]);
}