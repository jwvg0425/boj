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

using ii = std::pair<int, int>;

int main()
{
	int n;
	scanf("%d", &n);

	std::vector<int> arr;

	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);

		arr.push_back(k);
	}

	if (std::next_permutation(arr.begin(), arr.end()))
	{
		for (auto& k : arr)
		{
			printf("%d ", k);
		}
	}
	else
	{
		printf("-1");
	}

	return 0;
}