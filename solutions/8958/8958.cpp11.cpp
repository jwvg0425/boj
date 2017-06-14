#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>

int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		std::string s;

		std::cin >> s;

		int count = 0;
		int score = 0;

		for (auto& c : s)
		{
			if (c == 'O')
			{
				count++;
				score += count;
			}
			else
			{
				count = 0;
			}
		}

		printf("%d\n", score);
	}
}