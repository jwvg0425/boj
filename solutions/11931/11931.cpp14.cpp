#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>
#include <tuple>

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

	std::sort(arr.begin(), arr.end(), [](int l, int r)
	{
		return l > r;
	});

	for (auto& a : arr)
		printf("%d\n", a);

	return 0;
}