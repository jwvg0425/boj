#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

int main()
{
	int n;

	scanf("%d", &n);

	std::string answer;

	std::cin >> answer;

	for (int i = 1; i < n; i++)
	{
		std::string next;

		std::cin >> next;

		for (int j = 0; j < answer.size(); j++)
		{
			if (answer[j] != next[j])
				answer[j] = '?';
		}
	}

	std::cout << answer;
}