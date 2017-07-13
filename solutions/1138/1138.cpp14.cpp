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

int main()
{
	int n;
	scanf("%d", &n);

	int order[11] = { 0, };

	for (int i = 1; i <= n; i++)
	{
		int left;
		scanf("%d", &left);

		for (int j = 0; j < n; j++)
		{
			if (order[j] != 0)
				continue;

			if (left == 0)
			{
				order[j] = i;
				break;
			}
			left--;
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d ", order[i]);

	return 0;
}