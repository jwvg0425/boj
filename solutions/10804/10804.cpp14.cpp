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

int main()
{
	std::vector<int> arr;

	for (int i = 1; i <= 20; i++)
		arr.push_back(i);

	for (int i = 0; i < 10; i++)
	{
		int s, e;

		scanf("%d %d", &s, &e);

		std::reverse(arr.begin() + (s - 1), arr.begin() + e);
	}

	for (auto& a : arr)
		printf("%d ", a);

	return 0;
}