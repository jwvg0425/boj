#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <deque>

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	int gold[1001];
	int silver[1001];
	int bronze[1001];

	for (int i = 0; i < n; i++)
	{
		int t, g, s, b;

		scanf("%d %d %d %d", &t, &g, &s, &b);

		gold[t] = g;
		silver[t] = s;
		bronze[t] = b;
	}

	int rank = 1;

	for (int i = 1; i <= n; i++)
	{
		if (gold[i] > gold[k])
			rank++;
		if (gold[i] == gold[k])
		{
			if (silver[i] > silver[k])
				rank++;

			if (silver[i] == silver[k])
			{
				if (bronze[i] > bronze[k])
					rank++;
			}
		}
	}

	printf("%d", rank);

	return 0;
}