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
	int n;

	scanf("%d", &n);

	std::string maxName;
	int maxL = -1;

	for (int i = 0; i < n; i++)
	{
		std::string name;
		int l;

		std::cin >> name >> l;

		if (l > maxL)
		{
			maxL = l;
			maxName = name;
		}
	}

	std::cout << maxName << std::endl;
}

int main()
{
	int t;

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
		solve();

	return 0;
}