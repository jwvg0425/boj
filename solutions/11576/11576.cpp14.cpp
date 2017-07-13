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

int main()
{
	int a, b;

	scanf("%d %d", &a, &b);

	int m;
	scanf("%d", &m);

	int n = 0;

	for (int i = 0; i < m; i++)
	{
		int k;
		scanf("%d", &k);

		n *= a;
		n += k;
	}

	std::vector<int> bs;

	while (n > 0)
	{
		bs.push_back(n % b);
		n /= b;
	}

	if (bs.empty())
		bs.push_back(0);

	std::reverse(bs.begin(), bs.end());

	for (auto& k : bs)
		printf("%d ", k);

	return 0;
}