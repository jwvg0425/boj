#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

bool isPrime(int k)
{
	for (int t = 2; t * t <= k; t++)
	{
		if (k%t == 0)
			return false;
	}

	return true;
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int k;
		scanf("%d", &k);

		bool isFind = false;

		for (int x = 2; x < k; x++)
		{
			if (!isPrime(x))
				continue;

			for (int y = 2; y < k - x; y++)
			{
				if (!isPrime(y))
					continue;

				if (!isPrime(k - x - y))
					continue;

				printf("%d %d %d\n", x, y, k - x - y);

				isFind = true;
				break;
			}

			if (isFind)
				break;
		}
	}

	return 0;
}