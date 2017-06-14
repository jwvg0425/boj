#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
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

		for (int a = 1; a < n; a++)
		{
			for (int b = a + 1; b < n; b++)
			{
				if ((a*a + b*b + m) % (a*b) == 0)
					count++;
			}
		}

		printf("%d\n", count);
	}

	return 0;
}