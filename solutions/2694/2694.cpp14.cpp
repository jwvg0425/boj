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

int p, n, m, i, j, k, s, a[10000];
int main()
{
	scanf("%d", &p);

	for (i = 0; i<p; i++)
	{
		scanf("%d", &m);
		for (j = 0, s = 0; j<m; s += a[j], j++)scanf("%d", a + j);

		for (j = 1; j <= s; j++)
		{
			if (s%j != 0)
			{
			A:
				continue;
			}

			for (k = 0, n = 0; k<m; k++)
			{
				n += a[k];

				if (n>j)
					goto A;

				if (n == j)
					n = 0;
			}

			break;
		}
		printf("%d\n", j);
	}
}