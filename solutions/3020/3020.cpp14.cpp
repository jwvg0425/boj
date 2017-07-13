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

using ii = std::pair<int, int>;

int ups[500001];
int downs[500001];

int main()
{
	int n, h;

	scanf("%d %d", &n, &h);

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);

		if (i % 2 == 0)
			downs[a]++;
		else
			ups[h - a + 1]++;
	}

	for (int i = 1; i <= h; i++)
		ups[i] += ups[i - 1];

	for (int i = h - 1; i > 0; i--)
		downs[i] += downs[i + 1];

	std::vector<int> cand;

	for (int i = 1; i <= h; i++)
		cand.push_back(downs[i] + ups[i]);

	std::sort(cand.begin(), cand.end());

	int minCount = 0;

	for (auto& c : cand)
	{
		if (c == cand[0])
			minCount++;
		else
			break;
	}

	printf("%d %d", cand[0], minCount);

	return 0;
}