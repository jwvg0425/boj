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

char board[4][4];
using ii = std::pair<int, int>;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

struct State
{
	State()
	{
	}

	State(int x_, int y_, int capa_)
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				visited[i][j] = false;

		x = x_;
		y = y_;
		k = board[x_][y_] - '0';
		op = '_';
		capa = capa_ - 1;

		visited[x][y] = true;
		prev.emplace_back(x_, y_);
	}

	std::vector<State> nexts()
	{
		std::vector<State> res;

		if (capa == 0)
			return res;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx > 2 || ny < 0 || ny > 2 || visited[nx][ny])
				continue;

			State next;

			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					next.visited[i][j] = visited[i][j];
			next.x = nx;
			next.y = ny;
			next.k = k;
			next.capa = capa;

			if (board[nx][ny] >= '0' && board[nx][ny] <= '9')
			{
				next.capa--;
				if (op == '-')
					next.k -= board[nx][ny] - '0';
				else
					next.k += board[nx][ny] - '0';
			}
			else
			{
				next.op = board[nx][ny];
			}

			next.prev = prev;
			next.prev.emplace_back(nx, ny);
			next.visited[nx][ny] = true;

			res.push_back(next);
		}

		return res;
	}

	std::vector<ii> prev;
	int x, y;
	int k;
	int capa;
	char op;
	bool visited[4][4];
};

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	for (int y = 0; y < 3; y++)
	{
		std::string str;
		std::cin >> str;

		for (int x = 0; x < 3; x++)
		{
			board[y][x] = str[x];
		}
	}

	std::queue<State> q;

	q.emplace(0, 0, m);
	q.emplace(2, 0, m);
	q.emplace(1, 1, m);
	q.emplace(0, 2, m);
	q.emplace(2, 2, m);

	State ans;

	while (!q.empty())
	{
		auto top = q.front();

		q.pop();

		if (top.k == n && top.capa == 0)
		{
			ans = top;
			break;
		}

		auto nexts = top.nexts();

		for (auto& next : nexts)
		{
			q.push(next);
		}
	}

	printf("%d\n", ans.prev.empty() ? 0 : 1);

	for (auto& p : ans.prev)
	{
		printf("%d %d\n", p.first, p.second);
	}

	return 0;
}