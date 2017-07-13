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

int main()
{
	int t;
	scanf("%d\n", &t);

	for (int i = 0; i < t; i++)
	{
		std::string str;

		std::getline(std::cin, str);

		str.push_back(' ');

		int prev = 0;

		int sum = 0;

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == ' ')
			{
				sum += std::stoi(str.substr(prev, prev - i));
				prev = i + 1;
			}
		}

		printf("%d\n", sum);
	}

	return 0;
}