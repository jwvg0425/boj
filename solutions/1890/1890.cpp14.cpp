#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>
#include <memory.h>
#include <math.h>

int board[101][101];
long long int table[101][101];
int n;

//(sx,sy)에서 끝위치가는 경우의 수
long long int solve(int sx, int sy)
{
	if (sx == n - 1 && sy == n - 1)
		return 1;

	if (sx >= n || sy >= n)
		return 0;

	//못 움직임
	if (board[sx][sy] == 0)
		return 0;

	if (table[sx][sy] != -1)
		return table[sx][sy];

	long long int& res = table[sx][sy];

	res = solve(sx + board[sx][sy], sy) + solve(sx, sy + board[sx][sy]);

	return res;
}

int main()
{
	memset(table, -1, sizeof(table));

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}

	printf("%lld", solve(0, 0));

	return 0;
}