#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>

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

	int v;
	scanf("%d", &v);

	int count = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == v)
			count++;
	}

	printf("%d", count);

	return 0;
}