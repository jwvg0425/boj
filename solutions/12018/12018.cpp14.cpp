#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <tuple>
#include <memory.h>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	std::vector<int> mins;

	for (int i = 0; i < n; i++)
	{
		int p, l;
		scanf("%d %d", &p, &l);
		
		std::vector<int> num;

		for (int j = 0; j < p; j++)
		{
			int k;
			scanf("%d", &k);
			num.push_back(k);
		}
		std::sort(num.begin(), num.end());

		if (p < l)
			mins.push_back(1);
		else
			mins.push_back(num[p - l]);
	}

	std::sort(mins.begin(), mins.end());

	int idx = 0;

	while (idx < mins.size() && mins[idx] <= m)
	{
		m -= mins[idx];
		idx++;
	}

	printf("%d", idx);

	return 0;
}