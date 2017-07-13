#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <memory.h>

int dub(int now)
{
	return (now * 2) % 10000;
}

int sub(int now)
{
	now--;
	if (now < 0)
		now = 9999;

	return now;
}

int left(int now)
{
	int h = now / 1000;
	now -= h * 1000;
	now *= 10;
	now += h;

	return now;
}

int right(int now)
{
	int h = now % 10;
	now /= 10;
	now += h * 1000;
	return now;
}

std::string bfs(int start, int end)
{
	int prev[10000] = { 0, };
	char order[10000] = { 0, };

	memset(prev, -1, sizeof(prev));
	
	std::queue<int> q;

	q.push(start);

	prev[start] = -2;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (now == end)
			break;

		std::vector<std::pair<char, int>> adj = 
		{
			{ 'D', dub(now) },
			{ 'S', sub(now) },
			{ 'L', left(now) },
			{ 'R', right(now) },
		};

		for (auto& a : adj)
		{
			if (prev[a.second] != -1)
				continue;

			prev[a.second] = now;
			order[a.second] = a.first;
			q.push(a.second);
		}
	}

	std::string res;

	int now = end;

	while (prev[now] != -2)
	{
		res.push_back(order[now]);
		now = prev[now];
	}

	std::reverse(res.begin(), res.end());

	return res;
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int s, e;

		scanf("%d %d", &s, &e);

		std::cout << bfs(s, e) << std::endl;
	}

	return 0;
}