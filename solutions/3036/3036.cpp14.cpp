#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <memory.h>

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	int n, r;
	scanf("%d %d", &n, &r);

	for (int i = 0; i < n - 1; i++)
	{
		int a;
		scanf("%d", &a);

		int g = gcd(r, a);

		printf("%d/%d\n", r / g, a / g);
	}

	return 0;
}