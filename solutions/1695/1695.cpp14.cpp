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

int table[5001][5001];	
std::vector<int> arr;

int solve(int left, int right)
{
	if (left >= right)
		return 0;

	if (table[left][right] != -1)
		return table[left][right];

	int& res = table[left][right];

	if (arr[left] == arr[right])
	{
		res = solve(left + 1, right - 1);
	}
	else
	{
		res = std::min(solve(left + 1, right), solve(left, right - 1)) + 1;
	}

	return res;
}

int main()
{
	memset(table, -1, sizeof(table));

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		arr.push_back(k);
	}

	printf("%d", solve(0, n - 1));

	return 0;
}