#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>
using namespace std;

bool called[5][5];
int board[5][5];

int bingo()
{
	int num = 0;

	for (int y = 0; y < 5; y++)
	{
		bool res = true;
		for (int x = 0; x < 5; x++)
		{
			if (!called[x][y])
				res = false;
		}

		if (res)
			num++;
	}

	for (int x = 0; x < 5; x++)
	{
		bool res = true;
		for (int y = 0; y < 5; y++)
		{
			if (!called[x][y])
				res = false;
		}

		if (res)
			num++;
	}

	bool res1 = true;
	bool res2 = true;

	for (int i = 0; i < 5; i++)
	{
		if (!called[i][i])
			res1 = false;

		if (!called[4 - i][i])
			res2 = false;
	}

	if (res1)
		num++;

	if (res2)
		num++;

	return num;
}

int main()
{
	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			scanf("%d", &board[x][y]);
		}
	}

	for (int i = 0; i < 25; i++)
	{
		int call;
		scanf("%d", &call);
		for (int x = 0; x < 5; x++)
		{
			for (int y = 0; y < 5; y++)
			{
				if (board[x][y] == call)
					called[x][y] = true;
			}
		}

		if (bingo() >= 3)
		{
			printf("%d", i + 1);
			return 0;
		}
	}
	return 0;
}