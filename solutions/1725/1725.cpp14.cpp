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


int heights[100002];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &heights[i + 1]);
	}

	std::vector<int> s = { 0, };

	int maxSize = 0;

	int pos = 1;

	while (pos <= n + 1)
	{
		if (heights[pos] >= heights[s.back()])
		{
			s.push_back(pos);
			pos++;
		}
		else
		{
			while (heights[pos] < heights[s.back()])
			{
				int size = heights[s.back()] * (pos - s[s.size() - 2] - 1);

				maxSize = std::max(maxSize, size);
				s.pop_back();
			}
		}
	}

	printf("%d", maxSize);
}