#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>

int val[100001][2];

void solve()
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &val[j][i]);
		}
	}

	int up = val[0][0];
	int down = val[0][1];
	int both = 0;

	for (int i = 1; i < n; i++)
	{
		int newUp = val[i][0] + std::max(down, both);
		int newDown = val[i][1] + std::max(up, both);
		int newBoth = std::max(up, down);
		up = newUp;
		down = newDown;
		both = newBoth;
	}

	printf("%d\n", std::max({ up, down, both }));
}

int main()
{
	int t;

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		solve();
	}
}