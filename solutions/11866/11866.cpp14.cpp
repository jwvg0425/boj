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
	int n, m;

	scanf("%d %d", &n, &m);

	std::vector<int> v;

	for (int i = 0; i < n; i++)
		v.push_back(i + 1);

	printf("<");

	int pos = 0;

	while (!v.empty())
	{
		pos += m - 1;
		pos %= v.size();
		if (v.size() > 1)
			printf("%d, ", v[pos]);
		else
			printf("%d>", v[pos]);
		v.erase(v.begin() + pos);
	}

	return 0;
}