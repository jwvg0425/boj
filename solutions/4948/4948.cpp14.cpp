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

int primes[246913];

int main()
{
	for (int i = 2; i < 246913; i++)
		primes[i] = 1;

	for (int i = 2; i < 246913; i++)
	{
		if (primes[i] != 1)
			continue;

		for (int j = i * 2; j < 246913; j+=i)
		{
			primes[j] = 0;
		}
	}

	for (int i = 1; i < 246913; i++)
		primes[i] += primes[i - 1];

	while (true)
	{
		int n;
		scanf("%d", &n);

		if (n == 0)
			break;

		printf("%d\n", primes[2 * n] - primes[n]);
	}

	return 0;
}