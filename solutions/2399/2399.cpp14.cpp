#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>
#include <tuple>
#include<set>

int main()
{
	int n;
	scanf("%d", &n);

	std::vector<int> arr;
	long long int sum = 0;

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);

		arr.push_back(a);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum += abs(arr[i] - arr[j]);
		}
	}

	printf("%lld", sum);

	return 0;
}