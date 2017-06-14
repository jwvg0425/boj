#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>

int main()
{
	int n;
	long long int table[21];

	table[0] = 0;
	table[1] = 1;

	scanf("%d", &n);

	for (int i = 2; i <= n; i++)
		table[i] = table[i - 1] + table[i - 2];

	printf("%lld", table[n]);

	return 0;
}