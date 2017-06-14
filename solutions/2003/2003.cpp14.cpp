#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>

int main()
{
	int n, m;
	std::vector<int> arr;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		arr.push_back(a);
	}
	int left = 0, right = 0;
	int count = 0, sum = 0;

	while (true)
	{
		if (sum == m)
		{
			count++;
		}

		if (sum > m)
		{
			sum -= arr[left];
			left++;
		}
		else if (right < n)
		{
			sum += arr[right];
			right++;
		}
		else
		{
			break;
		}
	}

	printf("%d", count);

	return 0;
}