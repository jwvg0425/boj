#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>
#include <functional>


int r, c;
std::string board[21];

int dfs(std::set<char>& s, int x, int y)
{
	int res = 1;

	if (x > 0 && s.find(board[x - 1][y]) == s.end())
	{
		s.insert(board[x - 1][y]);
		res = std::max(res, 1 + dfs(s, x - 1, y));
		s.erase(board[x - 1][y]);
	}

	if (x < r - 1 && s.find(board[x + 1][y]) == s.end())
	{
		s.insert(board[x + 1][y]);
		res = std::max(res, 1 + dfs(s, x + 1, y));
		s.erase(board[x + 1][y]);
	}

	if (y > 0 && s.find(board[x][y - 1]) == s.end())
	{
		s.insert(board[x][y - 1]);
		res = std::max(res, 1 + dfs(s, x, y - 1));
		s.erase(board[x][y - 1]);
	}

	if (y < c - 1 && s.find(board[x][y + 1]) == s.end())
	{
		s.insert(board[x][y + 1]);
		res = std::max(res, 1 + dfs(s, x, y + 1));
		s.erase(board[x][y + 1]);
	}

	return res;
}

int main()
{
	scanf("%d %d", &r, &c);

	for (int i = 0; i < r; i++)
	{
		std::cin >> board[i];
	}

	std::set<char> s;

	s.insert(board[0][0]);

	printf("%d", dfs(s, 0, 0));

	return 0;
}