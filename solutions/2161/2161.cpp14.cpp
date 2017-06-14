#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <stack>
#include <memory.h>

int main()
{
	int n;

	scanf("%d", &n);

	std::vector<int> arr;

	for (int i = 1; i <= n; i++)
	{
		arr.push_back(i);
	}

	while (!arr.empty())
	{
		printf("%d ", arr[0]);
		arr.erase(arr.begin());

		if (!arr.empty())
		{
			int k = arr[0];
			arr.erase(arr.begin());
			arr.push_back(k);
		}
	}
}