#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>

int main()
{
	std::vector<std::pair<int, int>> vi;

	for (int i = 0; i < 8; i++)
	{
		int s;
		scanf("%d", &s);
		vi.emplace_back(i + 1, s);
	}

	std::sort(vi.begin(), vi.end(), [](const std::pair<int, int>& l, const std::pair<int, int>& r)
	{
		return l.second > r.second;
	});

	int sum = 0;
	std::vector<int> arr;
	for (int i = 0; i < 5; i++)
	{
		sum += vi[i].second;
		arr.push_back(vi[i].first);
	}

	std::sort(arr.begin(), arr.end());

	printf("%d\n", sum);

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}