#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>
#include <time.h>

int n;
int totalMax = 0;

struct Node
{
	int depth = 0;
	int map[21][21];
	int maxVal = 0;

	Node up()
	{
		Node res;
		res.depth = depth + 1;

		for (int x = 0; x < n; x++)
		{
			int prev = 0;
			int ny = 0;

			for (int y = 0; y < n; y++)
			{
				if (map[x][y] == 0)
					continue;

				if (prev == 0)
				{
					prev = map[x][y];
				}
				else if (prev == map[x][y])
				{
					res.map[x][ny] = 2 * prev;
					res.maxVal = std::max(res.maxVal, res.map[x][ny]);
					prev = 0;
					ny++;
				}
				else
				{
					res.map[x][ny] = prev;
					res.maxVal = std::max(res.maxVal, res.map[x][ny]);
					ny++;
					prev = map[x][y];
				}
			}

			res.map[x][ny] = prev;
			res.maxVal = std::max(res.maxVal, res.map[x][ny]);

			for (ny++; ny < n; ny++)
				res.map[x][ny] = 0;
		}

		return res;
	}

	Node down()
	{
		Node res;
		res.depth = depth + 1;

		for (int x = 0; x < n; x++)
		{
			int prev = 0;
			int ny = n - 1;

			for (int y = n - 1; y >= 0; y--)
			{
				if (map[x][y] == 0)
					continue;

				if (prev == 0)
				{
					prev = map[x][y];
				}
				else if (prev == map[x][y])
				{
					res.map[x][ny] = 2 * prev;
					res.maxVal = std::max(res.maxVal, res.map[x][ny]);
					prev = 0;
					ny--;
				}
				else
				{
					res.map[x][ny] = prev;
					res.maxVal = std::max(res.maxVal, res.map[x][ny]);
					ny--;
					prev = map[x][y];
				}
			}

			res.map[x][ny] = prev;
			res.maxVal = std::max(res.maxVal, res.map[x][ny]);

			for (ny--; ny >= 0; ny--)
				res.map[x][ny] = 0;
		}

		return res;
	}

	Node left()
	{
		Node res;
		res.depth = depth + 1;

		for (int y = 0; y < n; y++)
		{
			int prev = 0;
			int nx = n - 1;

			for (int x = n - 1; x >= 0; x--)
			{
				if (map[x][y] == 0)
					continue;

				if (prev == 0)
				{
					prev = map[x][y];
				}
				else if (prev == map[x][y])
				{
					res.map[nx][y] = 2 * prev;
					res.maxVal = std::max(res.maxVal, res.map[nx][y]);
					prev = 0;
					nx--;
				}
				else
				{
					res.map[nx][y] = prev;
					res.maxVal = std::max(res.maxVal, res.map[nx][y]);
					nx--;
					prev = map[x][y];
				}
			}

			res.map[nx][y] = prev;
			res.maxVal = std::max(res.maxVal, res.map[nx][y]);

			for (nx--; nx >= 0; nx--)
				res.map[nx][y] = 0;
		}

		return res;
	}

	Node right()
	{
		Node res;
		res.depth = depth + 1;

		for (int y = 0; y < n; y++)
		{
			int prev = 0;
			int nx = 0;

			for (int x = 0; x < n; x++)
			{
				if (map[x][y] == 0)
					continue;

				if (prev == 0)
				{
					prev = map[x][y];
				}
				else if (prev == map[x][y])
				{
					res.map[nx][y] = 2 * prev;
					res.maxVal = std::max(res.maxVal, res.map[nx][y]);
					prev = 0;
					nx++;
				}
				else
				{
					res.map[nx][y] = prev;
					res.maxVal = std::max(res.maxVal, res.map[nx][y]);
					nx++;
					prev = map[x][y];
				}
			}

			res.map[nx][y] = prev;
			res.maxVal = std::max(res.maxVal, res.map[nx][y]);

			for (nx++; nx < n; nx++)
				res.map[nx][y] = 0;
		}

		return res;
	}

	bool equal(const Node& r)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (map[i][j] != r.map[i][j])
					return false;
			}
		}

		return true;
	}

	void find()
	{
		totalMax = std::max(totalMax, maxVal);

		if (depth == 5)
			return;

		int b = totalMax / maxVal;

		//최대치 절대 못 넘음
		if ((1 << (10 - depth)) < b)
			return;

		Node nodes[4] = { left(),right(),up(),down() };

		for (int i = 0; i < 4; i++)
		{
			if (equal(nodes[i]))
				continue;

			nodes[i].find();
		}
	}
};

int main()
{
	scanf("%d", &n);

	Node start;
	start.depth = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &start.map[i][j]);
			start.maxVal = std::max(start.maxVal, start.map[i][j]);
		}
	}

	start.find();

	printf("%d", totalMax);

	return 0;
}