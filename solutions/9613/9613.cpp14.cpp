#include<stdio.h>
#include<memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

void solve()
{
	int n;
	std::vector<int> arr;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		arr.push_back(a);
	}

	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			sum += gcd(arr[i], arr[j]);
		}
	}

	printf("%d\n", sum);
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		solve();
	}
	
	return 0;
}