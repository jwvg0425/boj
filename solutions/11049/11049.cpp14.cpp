#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <memory.h>

int row[501];
int col[501];

int table[501][501];

//l..r까지 곱하는데 최소 횟수
int solve(int l, int r)
{
	if (l == r)
		return 0;

	if (table[l][r] != -1)
		return table[l][r];

	int& res = table[l][r];
	res = 987654321;

	for (int i = l; i < r; i++)
	{
		//i번째를 기준으로 양쪽을 나눠서 곱셈 먼저 하고,
		//그 곱셈 결과를 기준으로 양쪽 곱하는 경우
		int left = solve(l, i);
		int right = solve(i + 1, r);
		int mult = row[l] * col[i] * col[r];

		res = std::min(res, left + right + mult);
	}

	return res;
}

int main()
{
	memset(table, -1, sizeof(table));
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &row[i], &col[i]);
	}

	printf("%d", solve(0, n - 1));

	return 0;
}