#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <memory.h>
#include <math.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		std::string problem;
		std::cin >> problem;

		if (problem == "P=NP")
		{
			printf("skipped\n");
			continue;
		}

		int plus;

		for (int j = 0; j < problem.size(); j++)
		{
			if (problem[j] == '+')
			{
				plus = j;
				break;
			}
		}

		printf("%d\n", std::stoi(problem.substr(0, plus)) + std::stoi(problem.substr(plus + 1)));
	}

	return 0;
}