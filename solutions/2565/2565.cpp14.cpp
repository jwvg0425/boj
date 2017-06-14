#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

int max;
int connect[501];
int table[501][501];

int solve(int a, int b)
{
	//끌까지 도달
	if (a == max + 1 || b == max + 1)
		return 0;

	if (table[a][b] != -1)
		return table[a][b];

	int& res = table[a][b];
	res = solve(a + 1, b + 1);

	if (connect[a] == b)
		res++;

	res = std::max({ res, solve(a + 1, b), solve(a, b + 1) });

	return res;
}

int main()
{
	int n;
	scanf("%d", &n);

	memset(table, -1, sizeof(table));

	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		connect[a] = b;

		max = std::max({ max,a,b });
	}

	printf("%d", n - solve(1, 1));

	return 0;
}