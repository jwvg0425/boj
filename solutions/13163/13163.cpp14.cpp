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
#include <time.h>

using ii = std::pair<int, int>;

int main()
{
	int n;
	scanf("%d\n", &n);

	for (int i = 0; i < n; i++)
	{
		std::string str;

		std::getline(std::cin, str);

		printf("god");

		int blank = 0;

		for (auto& c : str)
		{
			if (c == ' ')
			{
				blank++;
				continue;
			}

			if (blank >= 1)
				printf("%c", c);
		}

		printf("\n");
	}

	return 0;
}