#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <memory.h>

std::vector<long long int> arr;

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		long long int a;
		scanf("%lld", &a);
		arr.push_back(a);
	}

	std::sort(arr.begin(), arr.end());

	arr.push_back(arr.back() + 1);

	int prev = 0;
	int groupSize = 0;
	long long int max = 0;

	for (int i = 0; i < arr.size() - 1; i++)
	{
		if (arr[i] != arr[i + 1])
		{
			if (groupSize < i - prev + 1)
			{
				groupSize = i - prev + 1;
				max = arr[i];
			}
			prev = i + 1;
		}
	}

	printf("%lld", max);

	return 0;
}