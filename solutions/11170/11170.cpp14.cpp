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

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int n, m;
		scanf("%d %d", &n, &m);

		int count = 0;

		for (int j = n; j <= m; j++)
		{
			int jcopy = j;

			if (jcopy == 0)
			{
				count++;
				continue;
			}

			while (jcopy > 0)
			{
				if (jcopy % 10 == 0)
					count++;
				jcopy /= 10;
			}
		}

		printf("%d\n", count);
	}

	return 0;
}