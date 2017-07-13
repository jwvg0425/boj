#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <memory.h>
#include <stack>
#include <queue>
#include <map>
#include <set>

using ii = std::pair<int, long long int>;

std::vector<ii> bridge[10001];
long long int maximum[10001];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		bridge[a].emplace_back(b, c);
		bridge[b].emplace_back(a, c);
	}

	int s, e;
	scanf("%d %d", &s, &e);

	std::queue<int> q;

	q.push(s);

	maximum[s] = 1000000001;


	while (!q.empty())
	{
		int top = q.front();
		q.pop();

		if (top == e)
			continue;

		for (auto& b : bridge[top])
		{
			long long int m = std::min(maximum[top], b.second);
			if (maximum[b.first]  != 0 && maximum[b.first] >= m)
				continue;
			
			maximum[b.first] = m;

			q.push(b.first);
		}
	}

	printf("%lld", maximum[e]);

	return 0;
}