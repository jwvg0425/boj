#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <memory.h>

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

	if (!std::prev_permutation(arr.begin(), arr.end()))
	{
		printf("-1");
		return 0;
	}

	for (auto& a : arr)
		printf("%d ", a);

	return 0;
}