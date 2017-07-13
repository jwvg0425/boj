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

void solve()
{
	int m;
	std::string type;

	std::cin >> m >> type;

	for (int i = 0; i < m; i++)
	{
		if (type == "N")
		{
			int k;
			scanf("%d", &k);
			printf("%c ", 'A' + k - 1);
		}
		else
		{
			std::string s;
			std::cin >> s;
			printf("%d ", s[0] - 'A' + 1);
		}
	}
	printf("\n");
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
		solve();

	return 0;
}