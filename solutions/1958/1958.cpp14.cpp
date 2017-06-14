#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>
#include <tuple>

int table[101][101][101];

std::string x, y, z;

int solve(int a, int b, int c)
{
	if (a < 0 || b < 0 || c < 0)
		return 0;

	if (table[a][b][c] != -1)
		return table[a][b][c];

	int& res = table[a][b][c];
	
	if (x[a] == y[b] && y[b] == z[c])
		res = 1 + solve(a - 1, b - 1, c - 1);
	else
		res = std::max({ solve(a - 1,b,c),solve(a,b - 1,c),solve(a,b,c - 1) });

	return res;
}


int main()
{
	memset(table, -1, sizeof(table));

	std::cin >> x >> y >> z;

	printf("%d", solve(x.size() - 1, y.size() - 1, z.size() - 1));

	return 0;
}