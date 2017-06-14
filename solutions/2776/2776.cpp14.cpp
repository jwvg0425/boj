#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>

void solve()
{
	std::vector<int> s;

	int n, m;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		s.push_back(a);
	}

	std::sort(s.begin(), s.end());

	scanf("%d",&m);

	for (int i = 0; i < m; i++)
	{
		int a;
		scanf("%d", &a);

		printf("%d\n", std::binary_search(s.begin(), s.end(), a)? 1 : 0);
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