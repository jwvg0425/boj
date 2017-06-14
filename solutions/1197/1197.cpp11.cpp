#include<stdio.h>
#include<vector>
#include<algorithm>

struct Edge
{
	Edge() {}
	Edge(int s, int e, int w) : start(s), end(e), weight(w) {}
	int start;
	int end;
	int weight;
};

int set[10001];
std::vector<Edge> edges;
std::vector<int> setIndex[10001];

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);

		edges.emplace_back(s, e, w);
	}

	for (int i = 1; i <= n; i++)
	{
		set[i] = i;
		setIndex[i].push_back(i);
	}

	std::sort(edges.begin(), edges.end(), [](const Edge& l, const Edge& r)
	{
		return l.weight < r.weight;
	});

	int cost = 0;

	for (auto& e : edges)
	{
		if (set[e.start] == set[e.end])
			continue;

		cost += e.weight;

		int ss = set[e.start];
		int se = set[e.end];

		if (setIndex[ss].size() > setIndex[se].size())
		{
			for (int i = 0; i < setIndex[se].size(); i++)
			{
				set[setIndex[se][i]] = ss;
				setIndex[ss].push_back(setIndex[se][i]);
			}
			setIndex[se].clear();
		}
		else
		{
			for (int i = 0; i < setIndex[ss].size(); i++)
			{
				set[setIndex[ss][i]] = se;
				setIndex[se].push_back(setIndex[ss][i]);
			}
			setIndex[ss].clear();
		}
	}

	printf("%d", cost);

	return 0;
}