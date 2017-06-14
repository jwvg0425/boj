#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>

int main()
{
	std::set<int> set;

	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		set.insert(a);
	}

	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int a;
		scanf("%d", &a);

		printf("%d ", set.find(a) != set.end() ? 1 : 0);
	}
}