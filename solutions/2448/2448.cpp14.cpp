#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

char board[3073][7145];
char tri[3][7] =
{
	"  *   ",
	" * *  ",
	"***** "
};

void star(int x, int y, int k)
{
	//base case
	if (k == 3)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				board[y + i][x + j] = tri[i][j];
			}
		}
		return;
	}

	star(x + k / 2, y, k / 2);
	star(x, y + k / 2, k / 2);
	star(x + k, y + k / 2, k / 2);
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n * 2; x++)
		{
			board[y][x] = ' ';
		}
	}
	
	star(0, 0, n);
	

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n * 2; x++)
		{
			printf("%c", board[y][x]);
		}
		printf("\n");
	}

	return 0;
}