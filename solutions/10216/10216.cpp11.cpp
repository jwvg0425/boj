#include <stdio.h>
#include <vector>
#include <queue>

struct Node
{
	Node() = default;
	Node(int x_, int y_, int r_) : x(x_), y(y_), r(r_)
	{}

	int x, y, r;
};

void calc()
{
	int N;
	scanf("%d", &N);

	std::vector<Node> nodes;

	for (int i = 0; i < N; i++)
	{
		int x, y, r;
		scanf("%d %d %d", &x, &y, &r);
		nodes.emplace_back(x, y, r);
	}

	//edge 생성
	std::vector<int> edges[3000];

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			int dx = nodes[i].x - nodes[j].x;
			int dy = nodes[i].y - nodes[j].y;
			int r = nodes[i].r + nodes[j].r;

			if (dx * dx + dy * dy <= r * r)
			{
				edges[i].push_back(j);
				edges[j].push_back(i);
			}
		}
	}

	//모든 edge 순회하면서 그룹되는거 체크
	int group = 0;
	bool visited[3000] = { false, };
	std::queue<int> queue;

	for (int i = 0; i < N; i++)
	{
		if (visited[i])
			continue;

		visited[i] = true;

		queue.push(i);

		while (!queue.empty())
		{
			int top = queue.front();
			queue.pop();

			for (auto& e : edges[top])
			{
				if (visited[e])
					continue;

				visited[e] = true;

				queue.push(e);
			}
		}

		group++;
	}

	printf("%d\n", group);
}

int main()
{
	int T;

	scanf("%d", &T);

	for (int t = 0; t < T; t++)
	{
		calc();
	}

	return 0;
}