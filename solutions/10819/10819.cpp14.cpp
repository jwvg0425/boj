#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>

int main()
{
	int n;

	scanf("%d", &n);

	std::vector<int> vi;

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		vi.push_back(a);
	}

	int max = 0;

	std::sort(vi.begin(), vi.end());

	do
	{
		int sum = 0;

		for (int i = 1; i < n; i++)
		{
			sum += std::abs(vi[i] - vi[i - 1]);
		}

		max = std::max(max, sum);

	} while (std::next_permutation(vi.begin(), vi.end()));

	printf("%d", max);

	return 0;
}