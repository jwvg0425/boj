#include <stdio.h>
#include <memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <tuple>

int main()
{
	std::vector<long long int> subject;
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		long long int sub = 0;
		int k;
		scanf("%d", &k);

		for (int j = 0; j < k; j++)
		{
			int t;
			scanf("%d", &t);
			sub |= 1LL << t;
		}

		subject.push_back(sub);
	}

	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int p;
		scanf("%d", &p);
		long long int empty = 0;
		for (int j = 0; j < p; j++)
		{
			int t;
			scanf("%d", &t);
			empty |= 1LL << t;
		}
		int count = 0;

		for (auto& sub : subject)
		{
			if ((sub & empty) == sub)
				count++;
		}

		printf("%d\n", count);
	}

	return 0;
}