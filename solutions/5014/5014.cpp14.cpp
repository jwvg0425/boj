#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>
#include <queue>
#include <tuple>
#include <map>
#include <functional>
#include <stack>

int visited[1000001];

int main()
{
	int f, s, g, u, d;

	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

	int min = f + 1;

	std::queue<int> q;

	q.push(s);

	visited[s] = 1;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		
		if (now == g)
		{
			min = visited[now] - 1;
			break;
		}

		if (now + u <= f && visited[now + u] == 0)
		{
			visited[now + u] = visited[now] + 1;
			q.push(now + u);
		}

		if (now - d >= 1 && visited[now - d] == 0)
		{
			visited[now - d] = visited[now] + 1;
			q.push(now - d);
		}
	}

	if (min > f)
		printf("use the stairs");
	else
		printf("%d", min);

	return 0;
}