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

using ii = std::pair<int, int>;

void solve()
{
	int n;
	scanf("%d", &n);

	std::vector<int> v;
	int sum = 0;
	int maxIdx = 0;

	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);

		v.push_back(k);

		sum += k;

		if (v[i] > v[maxIdx])
			maxIdx = i;
	}

	int count = 0;

	for (int i = 0; i < n; i++)
	{
		if (v[i] == v[maxIdx])
		{
			count++;
		}
	}

	if (count >= 2)
	{
		printf("no winner\n");
		return;
	}

	if (v[maxIdx] > sum / 2)
	{
		printf("majority winner %d\n", maxIdx + 1);
	}
	else
	{
		printf("minority winner %d\n", maxIdx + 1);
	}
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
		solve();

	return 0;
}