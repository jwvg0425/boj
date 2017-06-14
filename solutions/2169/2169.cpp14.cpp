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

int table[1001][1001][3];
int map[1001][1001];

int n, m;

//(x,y)칸에서 시작해서 (m,n)칸까지 가는 최대 가치. dir = 0인 경우 왼,오른 다 이동 가능, 1인 경우 왼쪽 2인 경우 오른쪽
int solve(int x, int y, int dir)
{
	if (x == m && y == n)
		return map[x][y];

	if (table[x][y][dir] != -987654321)
		return table[x][y][dir];

	int& res = table[x][y][dir];

	//아래로 내려가는 경우
	if (y < n)
		res = map[x][y] + solve(x, y + 1, 0);

	//y n까지 왔는데 왼쪽으로 가면 목적지 도착 못함
	if (x > 1 && y < n && (dir == 0 || dir == 1))
		res = std::max(res, map[x][y] + solve(x - 1, y, 1));

	if (x < m && (dir == 0 || dir == 2))
		res = std::max(res, map[x][y] + solve(x + 1, y, 2));

	return res;
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= m; x++)
		{
			scanf("%d", &map[x][y]);
			table[x][y][0] = table[x][y][1] = table[x][y][2] = -987654321;
		}
	}

	printf("%d", solve(1, 1, 0));

	return 0;
}