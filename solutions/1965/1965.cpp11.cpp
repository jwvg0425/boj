#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>

int box[1001];
int table[1001];

int solve(int n)
{
	if (n == 0)
		return 1;

	if (table[n] != -1)
		return table[n];

	int& res = table[n];

	res = 1;

	for (int i = 0; i < n; i++)
	{
		if (box[n] <= box[i])
			continue;

		res = std::max(res, solve(i) + 1);
	}

	return res;
}

int main()
{
	int n;
	scanf("%d", &n);

	memset(table, -1, sizeof(table));
	
	int max = 0;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &box[i]);
	}
	box[n] = 987654321;

	printf("%d", solve(n)-1);
}