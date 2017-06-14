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
	int n, m;
	scanf("%d %d", &n, &m);

	std::vector<int> arr;

	for (int i = 0; i < n + m; i++)
	{
		int a;
		scanf("%d", &a);
		arr.push_back(a);
	}

	std::sort(arr.begin(), arr.end());

	for (auto& a : arr)
	{
		printf("%d ", a);
	}
}