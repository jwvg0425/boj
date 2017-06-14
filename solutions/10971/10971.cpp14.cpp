#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>
#include <memory.h>
#include <math.h>
#define MAX 17000000

int table[17][1 << 17];
int weight[17][17];
int n;

//현재 도시 k, visited 도시들 방문했을 때 다 방문하고 1로 돌아가기 위한 최소 비용
int solve(int k, int visited)
{
	if (table[k][visited] != -1)
		return table[k][visited];

	int& res = table[k][visited];

	visited |= (1 << k);

	if (visited == (1 << n) - 1)
	{
		//base case - 1로 돌아가는 경우 검사
		if (weight[k][0] != 0)
		{
			res = weight[k][0];
		}
		else
		{
			res = MAX;
		}

		return res;
	}

	//그 외의 경우 - 방문 가능한 중간 도시 모두 검사

	res = MAX;

	for (int i = 0; i < n; i++)
	{
		if ((visited & (1 << i)) != 0)
			continue;

		if (weight[k][i] == 0)
			continue;

		res = std::min(res, weight[k][i] + solve(i, visited));
	}

	return res;
}

int main()
{
	memset(table, -1, sizeof(table));

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &weight[i][j]);
		}
	}

	printf("%d", solve(0, 1));

	return 0;
}