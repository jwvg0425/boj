#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <memory.h>

int table[41];
bool vip[41] = { false, };

int solve(int k)
{
	if (k <= 1)
		return 1;

	if (table[k] != -1)
		return table[k];

	int& res = table[k];

	//못 바꿈
	if (vip[k] || vip[k - 1])
		res = solve(k - 1);
	else
		res = solve(k - 1) + solve(k - 2);

	return res;
}

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);
	memset(table, -1, sizeof(table));

	for (int i = 0; i < m; i++)
	{
		int k;
		scanf("%d", &k);
		vip[k] = true;
	}

	printf("%d", solve(n));

	return 0;
}