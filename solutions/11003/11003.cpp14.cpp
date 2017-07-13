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

int main()
{
	int n, l;
	scanf("%d %d", &n, &l);
	std::deque<std::pair<int, int>> d;

	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);

		while (!d.empty() && i - d.front().first >= l)
			d.pop_front();

		while (!d.empty() && d.back().second > k)
			d.pop_back();

		d.emplace_back(i, k);

		printf("%d ", d.front().second);
	}

	return 0;
}