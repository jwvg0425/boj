#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <memory.h>

using ii = std::pair<int, int>;

void adjust(std::multiset<int>& left, std::multiset<int>& right)
{
	while (left.size() > right.size() + 1)
	{
		int pop = *left.rbegin();
		left.erase(left.find(pop));
		right.insert(pop);
	}

	while (right.size() > left.size())
	{
		int pop = *right.begin();
		right.erase(right.begin());
		left.insert(pop);
	}
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	std::vector<int> arr;

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		arr.push_back(a);
	}

	std::multiset<int> left = { -1 };
	std::multiset<int> right = { 65536 };

	for (int i = 0; i < k; i++)
	{
		if (arr[i] < *right.begin())
			left.insert(arr[i]);
		else
			right.insert(arr[i]);

		adjust(left, right);
	}

	long long int sum = *left.rbegin();

	for (int i = k; i < n; i++)
	{
		auto leftIter = left.find(arr[i - k]);
		if (leftIter != left.end())
			left.erase(leftIter);
		else
		{
			auto rightIter = right.find(arr[i - k]);
			right.erase(rightIter);
		}

		adjust(left, right);

		if (arr[i] < *right.begin())
			left.insert(arr[i]);
		else
			right.insert(arr[i]);

		adjust(left, right);

		sum += *left.rbegin();
	}

	printf("%lld", sum);

	return 0;
}