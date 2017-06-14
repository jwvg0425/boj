#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <stack>
#include <memory.h>

int height[502][502];
int table[502][502];

int n;

int solve(int x, int y)
{
	if (table[x][y] != -1)
		return table[x][y];

	int& res = table[x][y];
	res = 1;
	
	int dx[] = { -1,0,1,0 };
	int dy[] = { 0,-1,0,1 };

	for (int i = 0; i < 4; i++)
	{
		if (height[x + dx[i]][y + dy[i]] > height[x][y])
			res = std::max(res, 1 + solve(x + dx[i], y + dy[i]));
	}

	return res;
}

int main()
{

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &height[i][j]);
		}
	}

	memset(table, -1, sizeof(table));

	int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ans = std::max(ans, solve(i, j));
		}
	}

	printf("%d", ans);

	return 0;
}