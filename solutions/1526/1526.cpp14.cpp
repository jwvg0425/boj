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
	int n;

	scanf("%d", &n);

	int max = 0;

	for (int i = 1; i <= n; i++)
	{
		int k = i;

		bool isOk = true;

		while (k > 0)
		{
			if (k % 10 != 4 && k % 10 != 7)
			{
				isOk = false;
				break;
			}
			k /= 10;
		}

		if (!isOk)
			continue;

		max = i;
	}

	printf("%d", max);

	return 0;
}