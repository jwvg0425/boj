#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>

void solve()
{
	int n;
	scanf("%d", &n);

	std::vector<int> shop;

	for (int i = 0; i < n; i++)
	{
		int s;
		scanf("%d", &s);
		shop.push_back(s);
	}

	std::sort(shop.begin(), shop.end());

	printf("%d\n", 2* (shop.back() - shop[0]));
}

int main()
{
	int t;

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
		solve();

	return 0;
}