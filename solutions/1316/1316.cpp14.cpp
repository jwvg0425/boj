#include <stdio.h>
#include <memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <tuple>
#include <time.h>

int main()
{
	int n;
	scanf("%d", &n);

	int count = 0;

	for (int i = 0; i < n; i++)
	{
		std::string str;

		std::cin >> str;

		bool visit[26] = { false, };
		bool isGroup = true;

		for (int j = 0; j < str.size(); j++)
		{
			if (!visit[str[j] - 'a'])
				visit[str[j] - 'a'] = true;
			else if (str[j - 1] != str[j])
			{
				isGroup = false;
				break;
			}
		}

		if (isGroup)
			count++;
	}

	printf("%d", count);

	return 0;
}