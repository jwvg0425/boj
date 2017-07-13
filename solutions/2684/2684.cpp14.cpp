#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <memory.h>
#include <stack>

int main()
{
	int t;
	scanf("%d\n", &t);
	
	for (int i = 0; i < t; i++)
	{
		int counts[8] = { 0, };
		std::string str;
		std::cin >> str;

		for (int i = 0; i < str.size() - 2; i++)
		{
			int idx = 0;

			if (str[i + 2] == 'H')
				idx += 1;

			if (str[i + 1] == 'H')
				idx += 2;

			if (str[i] == 'H')
				idx += 4;

			counts[idx]++;
		}

		for (int i = 0; i < 8; i++)
			printf("%d ", counts[i]);

		printf("\n");
	}

	return 0;
}