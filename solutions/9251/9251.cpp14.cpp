#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <memory.h>

std::string a;
std::string b;

int table[1001][1001];

int lcs(int x, int y)
{
	if (x == 0 || y == 0)
		return 0;

	if (table[x][y] != -1)
		return table[x][y];

	int& res = table[x][y];

	if (a[x - 1] == b[y - 1])
		res = 1 + lcs(x - 1, y - 1);
	else
		res = std::max(lcs(x - 1, y), lcs(x, y - 1));

	return res;
}

int main()
{
	std::cin >> a >> b;

	memset(table, -1, sizeof(table));

	printf("%d", lcs(a.size(), b.size()));

	return 0;
}