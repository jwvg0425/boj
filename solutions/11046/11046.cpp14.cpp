#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <deque>

std::vector<int> vi;
std::vector<int> table;

void manacher()
{
	int r = 0;
	int p = 0;

	for (int i = 1; i < vi.size(); i++)
	{
		if (i <= r)
			table[i] = std::min(table[2 * p - i], r - i);
		else
			table[i] = 0;

		while (i - table[i] - 1 > 0 && i + table[i] + 1 < vi.size() &&
			vi[i - table[i] - 1] == vi[i + table[i] + 1])
			table[i]++;

		if (r < i + table[i])
		{
			r = i + table[i];
			p = i;
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		vi.push_back(-1);

		int a;
		scanf("%d", &a);
		vi.push_back(a);

		table.push_back(0);
		table.push_back(0);
	}

	manacher();

	int m;
	scanf("%d", &m);
	
	for (int i = 0; i < m; i++)
	{
		int start, end;

		scanf("%d %d", &start, &end);

		start = start * 2 - 1;
		end = end * 2 - 1;

		int mid = (start + end) / 2;

		if (table[mid] >= mid - start)
		{
			printf("1\n");
		}
		else
		{
			printf("0\n");
		}
	}

	return 0;
}