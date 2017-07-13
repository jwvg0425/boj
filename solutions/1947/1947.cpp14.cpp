#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>
#define MOD 1000000000ll

long long int table[1000001] = { 1, 0 };

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 2; i <= n; i++)
	{
		table[i] = ((i - 1) * (table[i - 1] + table[i - 2])) % MOD;
	}

	printf("%lld", table[n]);

	return 0;
}