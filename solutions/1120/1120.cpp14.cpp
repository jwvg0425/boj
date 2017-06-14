#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>
#include <tuple>
#include<set>

int main()
{
	std::string a, b;

	std::cin >> a >> b;

	int minGap = b.size();

	for (int off = 0; off <= b.size() - a.size(); off++)
	{
		int gap = 0;

		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] != b[i + off])
			{
				gap++;
			}
		}

		minGap = std::min(minGap, gap);
	}

	printf("%d", minGap);

	return 0;
}