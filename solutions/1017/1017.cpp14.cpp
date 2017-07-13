#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <memory.h>

using ii = std::pair<int, int>;
bool sieve[2001];

std::vector<int> a;
std::vector<int> b;
std::vector<int> edge[51]; // a -> b edge

bool visited[51];
int matched[51];

std::vector<int> firsts;

bool dfs(int now)
{
	if (visited[now])
		return false;

	visited[now] = true;

	for (auto& e : edge[now])
	{
		if (matched[e] == -1 || (e != 0 && dfs(matched[e])))
		{
			matched[e] = now;
			return true;
		}
	}

	return false;
}

void bimatch()
{
	int complete = 0;

	std::vector<int> lists;

	for (auto& e : firsts)
	{
		memset(matched, -1, sizeof(matched));
		matched[0] = e;

		int count = 0;

		for (int i = 0; i < a.size(); i++)
		{
			if (i == e)
				continue;

			memset(visited, false, sizeof(visited));
			if (dfs(i))
				count++;
		}

		if (count == a.size() - 1 && std::find(lists.begin(), lists.end(), matched[0]) == lists.end())
		{
			lists.push_back(matched[0]);
		}
	}

	std::sort(lists.begin(), lists.end(), [](int l, int r)
	{
		return a[l] < a[r];
	});

	if (lists.size() == 0)
		printf("-1");

	for (auto& l : lists)
		printf("%d ", a[l]);
}

int main()
{

	for (int i = 2; i <= 2000; i++)
	{
		if (sieve[i])
			continue;

		for (int j = i * 2; j <= 2000; j += i)
		{
			sieve[j] = true;
		}
	}

	int n;
	scanf("%d", &n);

	bool startEven = false;

	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);

		if (k % 2 == 0)
			a.push_back(k);
		else
			b.push_back(k);

		if (i == 0 && k % 2 == 0)
			startEven = true;
	}

	if (a.size() != b.size())
	{
		printf("-1");
		return 0;
	}

	if (startEven)
		std::swap(a, b);

	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			if (!sieve[a[i] + b[j]])
			{
				edge[i].push_back(j);
				if (j == 0)
					firsts.push_back(i);
			}
		}
	}

	bimatch();

	return 0;
}