#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <memory.h>
#include <math.h>
#include <map>

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int m, n, x, y;
		scanf("%d %d %d %d", &m, &n, &x, &y);

		int a = 0, b = 0;

		while (m*a + x <= m*n)
		{
			if (m*a + x == n * b + y)
			{
				printf("%d\n", m*a + x);
				break;
			}
			else if (m*a + x > n*b + y)
			{
				b++;
			}
			else
			{
				a++;
			}
		}

		if (m*a + x > m*n)
			printf("-1\n");

	}

	return 0;
}