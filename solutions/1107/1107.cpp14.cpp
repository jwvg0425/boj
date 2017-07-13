#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

bool disable[10];
bool visited[2][1000001];

struct Node
{
	Node() {}
	Node(int chan_, bool numbering_, int count_)
		: chan(chan_), numbering(numbering_), count(count_) {}

	int chan = 100;
	bool numbering = false;
	int count = 0;

	Node plus()
	{
		Node next;
		next.chan = chan + 1;
		next.numbering = false;
		next.count = count + 1;

		return next;
	}

	Node minus()
	{
		Node next;
		next.chan = std::max(0, chan - 1);
		next.numbering = false;
		next.count = count + 1;

		return next;
	}

	Node number(int digit)
	{
		Node next;

		if (numbering)
			next.chan = chan * 10 + digit;
		else
			next.chan = digit;
		next.numbering = true;
		next.count = count + 1;

		return next;
	}
};

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int c;
		scanf("%d", &c);

		disable[c] = true;
	}

	std::queue<Node> q;

	q.emplace(100, false, 0);
	visited[0][100] = true;

	while (!q.empty())
	{
		auto now = q.front();
		q.pop();

		if (now.chan == n)
		{
			printf("%d", now.count);
			break;
		}

		std::vector<Node> nexts = { now.plus(), now.minus() };

		for(int i =0; i < 10; i++)
		{
			if (disable[i])
				continue;

			nexts.push_back(now.number(i));
		}

		for (auto& next : nexts)
		{
			if (next.chan >= 1000000 || visited[next.numbering?1:0][next.chan])
				continue;

			visited[next.numbering?1:0][next.chan] = true;

			q.push(next);
		}
	}

	return 0;
}