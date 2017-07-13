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

int main()
{
	int n;
	scanf("%d", &n);

	std::vector<int> rope;

	for (int i = 0; i < n; i++)
	{
		int w;
		scanf("%d", &w);
		rope.push_back(w);
	}

	std::sort(rope.begin(), rope.end());

	int max = 0;

	for (int i = 0; i < n; i++)
	{
		max = std::max(max, rope[i] * (n - i));
	}

	printf("%d",max);

	return 0;
}