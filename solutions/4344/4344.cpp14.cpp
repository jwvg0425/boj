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

int main()
{
	int c;
	scanf("%d", &c);

	for (int i = 0; i < c; i++)
	{
		std::vector<int> score;

		int n;
		scanf("%d", &n);

		int sum = 0;

		for (int j = 0; j < n; j++)
		{
			int s;
			scanf("%d", &s);

			sum += s;
			score.push_back(s);
		}

		int count = 0;

		for (auto& s : score)
		{
			if (s * n > sum)
			{
				count++;
			}
		}

		printf("%.3f%%\n", static_cast<float>(count * 100) / n);
	}

	return 0;
}