#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>
#include <time.h>

int distance[1000001];
bool police[1000001];

int main()
{
	int n, s, d, f, b, k;
	scanf("%d %d %d %d %d %d", &n, &s, &d, &f, &b, &k);

	for (int i = 0; i < k; i++)
	{
		int p;
		scanf("%d", &p);
		police[p] = true;
	}

	std::queue<int> q;

	distance[s] = true;

	q.push(s);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (now == d)
		{
			break;
		}

		if (now + f <= n && distance[now + f] == 0 && !police[now + f])
		{
			distance[now + f] = distance[now] + 1;
			q.push(now + f);
		}

		if (now - b > 0 && distance[now - b] == 0 && !police[now - b])
		{
			distance[now - b] = distance[now] + 1;
			q.push(now - b);
		}
	}

	if (distance[d] == 0)
	{
		printf("BUG FOUND");
	}
	else
	{
		printf("%d", distance[d] - 1);
	}

	return 0;
}