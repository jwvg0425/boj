#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <memory.h>

int main()
{
	int n;
	scanf("%d\n", &n);

	for (int i = 0; i < n; i++)
	{
		std::string str;
		std::getline(std::cin, str);

		int idx = 0;
		int blank = 0;

		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == ' ')
			{
				blank++;
				if (blank == 2)
				{
					idx = j;
					break;
				}
			}
		}

		std::cout << str.substr(idx + 1) << ' ' << str.substr(0, idx) << std::endl;
	}

	return 0;
}