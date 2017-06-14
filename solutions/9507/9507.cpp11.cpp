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
#include <functional>

int main()
{
	long long int table[70];

	table[0] = 1;
	table[1] = 1;
	table[2] = 2;
	table[3] = 4;

	for (int i = 4; i < 70; i++)
		table[i] = table[i - 1] + table[i - 2] + table[i - 3] + table[i - 4];

	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);

		printf("%lld\n", table[n]);
	}
	
	return 0;
}