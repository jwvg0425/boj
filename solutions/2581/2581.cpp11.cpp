#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>

bool isPrime(int n)
{
	if (n == 1)
		return false;

	for (int i = 2; i*i <= n; i++)
	{
		if (n%i == 0)
			return false;
	}

	return true;
}

int main()
{
	int m, n;

	scanf("%d %d", &m, &n);

	int sum = 0;
	int min = 987654321;

	for (int i = m; i <= n; i++)
	{
		if (!isPrime(i))
			continue;

		sum += i;
		min = std::min(i, min);
	}

	if (sum == 0)
	{
		printf("-1");
	}
	else
	{
		printf("%d\n%d", sum, min);
	}
	
	return 0;
}