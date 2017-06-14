#include <stdio.h>
#include <memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <tuple>
#include <time.h>

int main()
{
	int n, k, d;
	scanf("%d %d %d", &n, &k, &d);

	//d, known algorithm
	std::vector<std::pair<int, int>> student;

	for (int i = 0; i < n; i++)
	{
		int m, di;

		scanf("%d %d", &m, &di);
		int a = 0;

		for (int j = 0; j < m; j++)
		{
			int t;
			scanf("%d", &t);
			a |= 1 << (t - 1);
		}
		student.emplace_back(di, a);
	}

	std::sort(student.begin(), student.end());

	int l = 0;
	int r = 1;
	int maxE = 0;
	int algorithms[32] = { 0, };

	for (int i = 0; i < k; i++)
	{
		if ((student[0].second & (1 << i)) != 0)
		{
			algorithms[i]++;
		}
	}

	while (true)
	{
		int common = 0;
		int all = 0;
		int groupNum = r - l;

		for (int i = 0; i < k; i++)
		{
			if (algorithms[i] == groupNum)
				common++;

			if(algorithms[i] > 0)
				all++;
		}

		maxE = std::max(maxE, (all - common) * groupNum);

		if (r == student.size())
			break;

		if (student[r].first - student[l].first <= d)
		{
			for (int i = 0; i < k; i++)
			{
				if ((student[r].second & (1 << i)) != 0)
				{
					algorithms[i]++;
				}
			}
			r++;
		}
		else
		{
			for (int i = 0; i < k; i++)
			{
				if ((student[l].second & (1 << i)) != 0)
				{
					algorithms[i]--;
				}
			}
			l++;
		}
	}

	printf("%d", maxE);

	return 0;
}