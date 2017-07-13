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

bool isPrime(int k)
{
	if (k == 1)
		return false;

	for (int i = 2; i*i <= k; i++)
	{
		if (k%i == 0)
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
		int n;
		scanf("%d", &n);

		for (int j = n / 2; j >= 1; j--)
		{
			if (isPrime(j) && isPrime(n - j))
			{
				printf("%d %d\n", j, n - j);
				break;
			}
		}
	}
	return 0;
}