#include <stdio.h>
#include <queue>
#include <memory.h>

int N;
int edge[1001][1001];
bool visited[1001];

void dfs(int start)
{
	visited[start] = true;

	printf("%d ", start);

	for (int i = 0; i <= N; i++)
	{
		if (edge[start][i] != 0 && !visited[i])
		{
			dfs(i);
		}
	}
}

void bfs(int start)
{
	std::queue<int> queue;
	queue.push(start);
	visited[start] = true;

	while(!queue.empty())
	{
		int top = queue.front();
		queue.pop();

		printf("%d ", top);

		for (int i = 0; i <= N; i++)
		{
			if (edge[top][i] != 0 && !visited[i])
			{
				visited[i] = true;
				queue.push(i);
			}
		}
	}
}

int main()
{
	int M, V;
	scanf("%d %d %d", &N, &M, &V);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		edge[a][b] = edge[b][a] = 1;
	}

	memset(visited, 0, sizeof(visited));
	dfs(V);
	puts("");
	memset(visited, 0, sizeof(visited));
	bfs(V);

	return 0;
}