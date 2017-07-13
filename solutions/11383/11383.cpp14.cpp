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

int main()
{
	std::vector<std::string> small;

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		std::string str;
		std::cin >> str;
		small.push_back(str);
	}

	for (int i = 0; i < n; i++)
	{
		std::string str;
		std::cin >> str;

		for (int j = 0; j < m * 2; j++)
		{
			if (str[j] != small[i][j / 2])
			{
				printf("Not Eyfa");
				return 0;
			}
		}
	}

	printf("Eyfa");

	return 0;
}