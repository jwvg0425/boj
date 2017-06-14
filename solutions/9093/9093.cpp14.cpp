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

void solve()
{
	std::string str;

	std::getline(std::cin, str);

	std::vector<int> blankPos;
	blankPos.push_back(-1);

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
			blankPos.push_back(i);
	}

	blankPos.push_back(str.size());

	for (int i = 0; i < blankPos.size() - 1; i++)
	{
		for (int j = blankPos[i + 1] - 1; j > blankPos[i]; j--)
		{
			printf("%c", str[j]);
		}

		printf(" ");
	}

	printf("\n");
}

int main()
{
	int t;
	scanf("%d\n", &t);

	for (int i = 0; i < t; i++)
	{
		solve();
	}

	return 0;
}