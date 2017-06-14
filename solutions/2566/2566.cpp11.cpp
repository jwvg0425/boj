#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int sum(const std::vector<int>& vi)
{
	int s = 0;

	for (auto& i : vi)
		s += i;

	return s;
}

int main()
{
	int max = 0;
	int maxr;
	int maxc;

	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++)
		{
			int a;
			scanf("%d", &a);

			if (a > max)
			{
				max = a;
				maxr = r;
				maxc = c;
			}
		}
	}

	printf("%d\n%d %d", max, maxr + 1, maxc + 1);
}