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

std::string patterns[3]=
{
	"ABC",
	"BABC",
	"CCAABB"
};

std::string names[3]=
{
	"Adrian",
	"Bruno",
	"Goran"
};

int main()
{
	int scores[3] = { 0, };
	int n;
	scanf("%d", &n);

	std::string p;
	std::cin >> p;

	int max = 0;

	for (int i = 0; i < p.size(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (patterns[j][i%patterns[j].size()] == p[i])
				scores[j]++;

			max = std::max(scores[j], max);
		}
	}

	printf("%d\n", max);

	for (int j = 0; j < 3; j++)
	{
		if (scores[j] == max)
			std::cout << names[j] << std::endl;
	}

	return 0;
}