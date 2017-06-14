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
	int n, m;
	std::vector<std::string> rect;

	std::cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		std::string str;

		std::cin >> str;

		rect.push_back(str);
	}

	int maxSize = 1;

	for (int sx = 0; sx < m; sx++)
	{
		for (int sy = 0; sy < n; sy++)
		{
			for (int k = 1; k < std::min(m-sx,n-sy); k++)
			{
				int ex = sx + k;
				int ey = sy + k;
				if (rect[sy][sx] == rect[sy][ex] &&
					rect[sy][sx] == rect[ey][sx] &&
					rect[sy][sx] == rect[ey][ex])
				{
					maxSize = std::max(maxSize, k + 1);
				}
			}
		}
	}

	printf("%d", maxSize * maxSize);

	return 0;
}