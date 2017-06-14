#include<stdio.h>
#include<memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
	int map[101][101] = { 0, };

	for (int i = 0; i < 4; i++)
	{
		int sx, sy, ex, ey;

		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);

		for (int x = sx; x < ex; x++)
			for (int y = sy; y < ey; y++)
				map[x][y] = 1;
	}

	int sum = 0;

	for (int x = 0; x <= 100; x++)
		for (int y = 0; y <= 100; y++)
			sum += map[x][y];

	printf("%d", sum);

	return 0;
}