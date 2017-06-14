#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>
#include <queue>
#include <tuple>
#include <map>
#include <functional>

int main()
{
	int n, k;

	std::vector<int> arr;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);

		arr.push_back(a);
	}

	std::sort(arr.begin(), arr.end());

	printf("%d", arr[k - 1]);

	return 0;
}