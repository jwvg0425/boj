#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>
#define MAX 987654321


long long int heights[100002];

int main()
{
	while (true)
	{
		long long int n;
		scanf("%lld", &n);

		if (n == 0)
			break;

		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &heights[i + 1]);
		}

		heights[n + 1] = 0;

		std::vector<long long int> s = { 0, };

		long long int maxSize = 0;

		long long int pos = 1;

		while (pos <= n + 1)
		{
			while (heights[pos] < heights[s.back()])
			{
				long long int b = s.back();
				s.pop_back();
				long long int size = heights[b] * (pos - s.back() - 1);

				maxSize = std::max(maxSize, size);
			}

			s.push_back(pos);
			pos++;
		}

		while (s.back() != 0)
		{
			long long int b = s.back();
			s.pop_back();
			long long int size = heights[b] * (pos - s.back() - 1);

			maxSize = std::max(maxSize, size);
		}

		printf("%lld\n", maxSize);
	}
}