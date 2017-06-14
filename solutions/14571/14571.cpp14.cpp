#include <stdio.h>
#include <memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <tuple>
#include <time.h>

int edge[201][201];
//각 간선에 대해 사이클을 이루게 되는 정점 번호들
//cycle[i] = i번 정점을 포함하는 사이클의 개수
int cycle[201];

//edge[i][j] = i-j 간선을 포함하는 사이클의 개수
int edgeCycle[201][201];

int main()
{
	int n;
	scanf("%d", &n);
	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		edge[u][v] = edge[v][u] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				continue;

			for (int k = j+1; k <= n; k++)
			{
				if (edge[i][j] == 1 &&
					edge[j][k] == 1 &&
					edge[k][i] == 1)
				{
					cycle[i]++;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = i+1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (k == i || k == j)
					continue;

				if (edge[i][j] == 1 &&
					edge[j][k] == 1 &&
					edge[k][i] == 1)
				{
					edgeCycle[i][j]++;
				}
			}
		}
	}

	long long int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		//각 점을 중심점으로 하는 싸이클 짝 짓는 경우의 수 구하기
		ans += cycle[i] * (cycle[i] - 1) / 2;
	}

	//여기서 싸이클 두 개 짝 지었는데, 모래 시계가 아닌 경우의 수를 빼주면 된다
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			ans -= edgeCycle[i][j] * (edgeCycle[i][j] - 1);
		}
	}

	printf("%lld", ans);

	return 0;
}