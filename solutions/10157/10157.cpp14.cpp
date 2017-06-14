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

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int board[1001][1001];

int main()
{
	int c, r, k;
	scanf("%d %d %d", &c, &r, &k);

	int sx = 1, sy = 1;
	int n = 1;

	if (k > c*r)
	{
		printf("0");
		return 0;
	}

	int dir = 0;

	while (n <= c*r)
	{
		if (n == k)
			break;
		
		board[sx][sy] = n;

		int nx = sx + dx[dir];
		int ny = sy + dy[dir];

		if (nx < 1 || nx > c || ny < 1 || ny > r || board[nx][ny] != 0)
			dir = (dir + 1) % 4;

		sx = sx + dx[dir];
		sy = sy + dy[dir];

		n++;
	}

	printf("%d %d", sx, sy);

	return 0;
}