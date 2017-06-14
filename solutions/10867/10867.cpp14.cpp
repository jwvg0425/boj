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

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		arr.push_back(a);
	}

	std::sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++)
	{
		if (i == 0 || arr[i - 1] != arr[i])
			printf("%d ", arr[i]);
	}

	return 0;
}