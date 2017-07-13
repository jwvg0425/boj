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

int main()
{
	int k, n;
	scanf("%d %d", &k, &n);

	int time = 0;

	for (int i = 0; i < n; i++)
	{
		int t;
		char c;
		scanf("%d %c", &t, &c);

		time += t;

		if (time >= 210)
		{
			printf("%d", k);
			return 0;
		}

		if (c == 'T')
			k = k % 8 + 1;
	}

	printf("%d", k);

	return 0;
}