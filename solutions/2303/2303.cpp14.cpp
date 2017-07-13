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
#include <time.h>
#include <bitset>

int calc(int arr[5])
{
	int max = 0;

	for (int i = 0; i < 5; i++)
		for (int j = i + 1; j < 5; j++)
			for (int k = j + 1; k < 5; k++)
				max = std::max(max, (arr[i] + arr[j] + arr[k]) % 10);

	return max;
}

int main()
{
	int n;
	int maxO = 0;
	int maxK = 1;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int arr[5];

		for (int j = 0; j < 5; j++)
			scanf("%d", &arr[j]);

		int c = calc(arr);

		if (c >= maxO)
		{
			maxO = c;
			maxK = i + 1;
		}
	}

	printf("%d", maxK);

	return 0;
}