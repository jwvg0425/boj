#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <deque>

std::string a;
std::string b;

int table[4001][4001];

//a[aidx..]와 b[bidx..]의 최대 공통 접두사 길이
int prefix(int aidx, int bidx)
{
	if (aidx == a.size() || bidx == b.size())
		return 0;

	if (table[aidx][bidx] != -1)
		return table[aidx][bidx];

	int& res = table[aidx][bidx];

	res = 0;

	if (a[aidx] == b[bidx])
		res = 1 + prefix(aidx + 1, bidx + 1);

	return res;
}

int main()
{
	memset(table, -1, sizeof(table));
	std::cin >> a >> b;

	int m = 0;

	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			m = std::max(m, prefix(i, j));
		}
	}

	printf("%d", m);

	return 0;
}