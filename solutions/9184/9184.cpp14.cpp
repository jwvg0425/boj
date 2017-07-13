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
#define IMPOSSIBLE -987654321

int table[21][21][21];

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;

	if (a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);

	if (table[a][b][c] != IMPOSSIBLE)
		return table[a][b][c];

	int& res = table[a][b][c];

	if (a < b && b < c)
		res = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else
		res = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);

	return res;
}

int main()
{
	for (int i = 0; i < 21; i++)
		for (int j = 0; j < 21; j++)
			for (int k = 0; k < 21; k++)
				table[i][j][k] = IMPOSSIBLE;

	while (true)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (a == -1 && b == -1 && c == -1)
			break;

		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
	}

	return 0;
}