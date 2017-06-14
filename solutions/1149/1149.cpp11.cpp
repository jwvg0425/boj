#include<stdio.h>
#include <memory.h>
#include <algorithm>

int N;
int cost[1001][3];
int table[1001][4];

int answer(int n, int c)
{
	int& res = table[n][c];
	if (res != -1)
		return res;

	if (n == N)
		return res = cost[n][c];

	res = 987654321;

	for (int i = 0; i < 3; i++)
	{
		if (i != c)
			res = std::min(res, cost[n][c] + answer(n + 1, i));
	}

	return res;
}

int main()
{
	scanf("%d", &N);

	memset(table, -1, sizeof(table));

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
	}

	printf("%d", std::min({ answer(0,0),answer(0,1),answer(0,2) }));
}