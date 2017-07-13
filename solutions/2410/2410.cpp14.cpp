#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>
#include <time.h>
#define MOD 1000000000

using ii = std::pair<int, int>;
int table[1000001];

int main()
{
	int n;

	scanf("%d", &n);

	table[0] = 1;

	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 1)
			table[i] = table[i - 1];
		else
			table[i] = (table[i - 1] + table[i / 2]) % MOD;
	}

	printf("%d", table[n]);

	return 0;
}