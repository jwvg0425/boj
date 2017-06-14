#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#define UP 1
#define STRAIGHT 2
#define DOWN 3

std::vector<std::string> map;
int prev[50000][100];
int R, C;

bool isPipe(int sx, int sy)
{
	if (sx < 0 || sx >= C || sy < 0 || sy >= R)
		return false;

	if (map[sy][sx] != '.')
		return false;

	map[sy][sx] = 'X';

	return (sx == C - 1 || isPipe(sx + 1, sy - 1) || isPipe(sx + 1, sy) || isPipe(sx + 1, sy + 1));
}

int main()
{
	scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++)
	{
		std::string s;

		std::cin >> s;

		for (int j = 0; j < C; j++)
		{
			if (j != 0 && j != C - 1 && rand() % 100 == 0)
			{
				s.push_back('X');
			}
			else
			{
				s.push_back('.');
			}
		}

		map.push_back(s);
	}

	int count = 0;

	for (int y = 0; y < R; y++)
	{
		if (isPipe(0, y))
		{
			count++;
		}
	}

	printf("%d", count);
}