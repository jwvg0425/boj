#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	int n;
	scanf("%d", &n);

	std::vector<int> arr;

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		arr.push_back(a);
	}

	int g = arr[0];

	for (int i = 1; i < n; i++)
	{
		g = gcd(g, arr[i]);
	}

	for (int i = 1; i <= g; i++)
	{
		if (g % i == 0)
			printf("%d\n", i);
	}

	return 0;
}