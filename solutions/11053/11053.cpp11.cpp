#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>


std::vector<int> arr;
int table[1001];

int solve(int n)
{
	if (n == 0)
		return 1;

	if (table[n] != -1)
		return table[n];

	int& answer = table[n];
	answer = 1;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] >= arr[n])
			continue;

		answer = std::max(answer, 1 + solve(i));
	}

	return answer;
}

int main()
{
	int n;

	scanf("%d", &n);

	memset(table, -1, sizeof(table));

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);

		arr.push_back(a);
	}

	arr.push_back(1001);

	printf("%d", solve(n) - 1);
}