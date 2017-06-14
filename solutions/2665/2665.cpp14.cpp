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

int n;
int board[52][52];
int num[52][52];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		std::string line;

		std::cin >> line;

		for (int j = 0; j < line.size(); j++)
		{
			board[i + 1][j + 1] = 1 - line[j] + '0';
			num[i + 1][j + 1] = 987654321;
		}
	}

	std::queue<std::tuple<int, int, int>> q;

	q.emplace(1, 1, board[1][1]);
	num[1][1] = board[1][1];

	while (!q.empty())
	{
		int x, y, k;
		std::tie(x, y, k) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || nx > n || ny < 1 || ny > n)
				continue;

			if (k + board[nx][ny] >= num[nx][ny])
				continue;

			num[nx][ny] = k + board[nx][ny];

			q.emplace(nx, ny, k +  board[nx][ny]);
		}
	}

	printf("%d", num[n][n]);

	return 0;
}