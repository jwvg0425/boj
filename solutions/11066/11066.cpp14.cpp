#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>
using namespace std;

int table[501][501];
vector<int> files;
vector<int> sums;

//start ~ end까지 최소 덧셈 크기
int calc(int start, int end)
{
	if (start >= end)
		return 0;

	if (table[start][end] != -1)
		return table[start][end];

	int& res = table[start][end];
	res = 987654321;

	for (int i = start; i <= end; i++)
	{
		int merge = sums[end + 1] - sums[start];
		int left = calc(start, i);
		int right = calc(i + 1, end);

		res = std::min(res, merge + left + right);
	}

	return res;
}

void solve()
{
	memset(table, -1, sizeof(table));
	sums.clear();
	files.clear();
	
	int k;
	scanf("%d", &k);
	sums.push_back(0);

	for (int i = 0; i < k; i++)
	{
		int f;
		scanf("%d", &f);

		files.push_back(f);
		sums.push_back(f + sums.back());
	}

	printf("%d\n", calc(0, k - 1));
}

int main()
{
	int c;
	scanf("%d", &c);

	for (int i = 0; i < c; i++)
	{
		solve();
	}
	return 0;
}