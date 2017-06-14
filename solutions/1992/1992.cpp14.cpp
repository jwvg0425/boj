#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <memory.h>

std::vector<std::string> board;

void solve(int sx, int sy, int w, int h)
{
	int start = board[sx][sy];
	for (int x = sx; x < sx + w; x++)
	{
		for (int y = sy; y < sy + h; y++)
		{
			if (board[x][y] != start)
			{
				//분할해야함
				printf("(");
				solve(sx, sy, w / 2, h / 2);
				solve(sx, sy + h / 2, w / 2, h / 2);
				solve(sx + w / 2, sy, w / 2, h / 2);
				solve(sx + w / 2, sy + h / 2, w / 2, h / 2);
				printf(")");
				return;
			}
		}
	}

	printf("%c", start);
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		std::string str;
		std::cin >> str;
		board.push_back(str);
	}

	solve(0, 0, n, n);

	return 0;
}