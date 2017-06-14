#include <stdio.h>
#include <vector>
#include <limits>

struct Edge
{
	Edge() = default;

	Edge(int g, int d, int c) : goal(g), distance(d), cost(c)
	{
	}

	int goal;
	int distance;
	int cost;
};

std::vector<Edge> edges[101];

// arr[n][m] 은 m 이하의 비용으로 1 ~ n 번 노드까지 진행하는 최단거리 값
int arr[101][10001];
int N, M;

//1 ~ n 번 노드까지 m 이하의 비용으로 가는 최단 거리
int find(int n, int m)
{
	// 음수 비용인 경우 - 가능한 케이스가 없다.
	// 이 경우는 계산은 된 건데 답은 없으므로 -2로(계산 안된 경우인 -1과 구분하기 위해).
	if (m < 0)
		return -2;

	if (arr[n][m] != -1)
		return arr[n][m];

	int min = std::numeric_limits<int>::max();

	for (int i = 0; i < edges[n].size(); i++)
	{
		int f = find(edges[n][i].goal, m - edges[n][i].cost);

		//앞쪽에 길이 없는 경우
		if (f == -2)
			continue;

		int distance = f  + edges[n][i].distance;
		if (distance < min)
			min = distance;
	}

	//가능한 길이 없음
	if (min == std::numeric_limits<int>::max())
	{
		arr[n][m] = -2;
	}
	else
	{
		arr[n][m] = min;
	}
	
	return arr[n][m];
}

void solve()
{
	int K;
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= N; i++)
		edges[i].clear();

	for (int c = 0; c <= M; c++)
	{
		arr[1][c] = 0;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int c = 0; c <= M; c++)
		{
			arr[i][c] = -1;
		}
	}

	for (int i = 0; i < K; i++)
	{
		int u, v, x, d;

		scanf("%d %d %d %d", &u, &v, &x, &d);

		edges[v].emplace_back(u, d, x);
	}

	int answer = find(N, M);

	if (answer == -2)
	{
		printf("Poor KCM\n");
	}
	else
	{
		printf("%d\n", answer);
	}
}

int main()
{
	int T;
	
	scanf("%d", &T);
	
	for (int t = 0; t < T; t++)
	{
		solve();
	}
}