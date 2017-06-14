#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>

int main()
{
	int t;

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);
		int ans = 0;

		for (int a = 1; a * (a + 1) / 2 < n; a++)
		{
			int na = n - a * (a + 1) / 2;

			for (int b = 1; b * (b + 1) / 2 < n; b++)
			{
				int nb = na - b * (b + 1) / 2;

				for (int c = 1; c * (c + 1) / 2 <= n; c++)
				{
					int nc = nb - c * (c + 1) / 2;

					if (nc == 0)
					{
						ans = 1;
					}
				}
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}