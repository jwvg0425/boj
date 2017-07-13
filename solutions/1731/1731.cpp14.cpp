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

	if (arr[1] - arr[0] == arr[2] - arr[1])
	{
		printf("%d", arr.back() - arr[0] + arr[1]);
	}
	else
	{
		printf("%d", arr.back() * (arr[1] / arr[0]));
	}

	return 0;
}