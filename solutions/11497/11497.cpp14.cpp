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

using ii = std::pair<int, int>;

void solve()
{
	std::vector<int> logs;

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int l;
		scanf("%d", &l);

		logs.push_back(l);
	}

	std::sort(logs.begin(), logs.end());

	int max = logs[logs.size() - 1] - logs[logs.size() - 2];

	for (int i = 0; i < logs.size() - 2; i++)
	{
		max = std::max(max, logs[i + 2] - logs[i]);
	}

	printf("%d\n", max);

}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
		solve();

	return 0;
}