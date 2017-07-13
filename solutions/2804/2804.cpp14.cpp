#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

using ii = std::pair<int, int>;

int main()
{
	std::string a, b;

	std::cin >> a >> b;

	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			if (a[i] != b[j])
				continue;

			for (int y = 0; y < b.size(); y++)
			{
				for (int x = 0; x < a.size(); x++)
				{
					if (x == i)
						printf("%c", b[y]);
					else if (y == j)
						printf("%c", a[x]);
					else
						printf(".");
				}
				printf("\n");
			}

			return 0;
		}
	}

	return 0;
}